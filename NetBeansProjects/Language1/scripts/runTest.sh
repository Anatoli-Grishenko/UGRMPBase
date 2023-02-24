#!  /bin/bash
# Author: Luis Castillo Vidal L.Castillo@decsai.ugr.es
# Pass test file $1

function toUTF8 {
    iconv -t UTF-8 -f ISO-8859-15 < $1 > $1.utf8
}

function toISO {
    iconv -f UTF-8 -t ISO-8859-15 < $1 > $1.iso
}

function doTest  {
    printf "\n${WHITE}Testing $1 \t\t"
    if [ ! -f $1 ]
    then
        return 1
    fi
    # Parse the codes for the call
    if grep --quiet $CALL_MARK $1; # Cond1
    then 
        MYCALL=$(grep $CALL_MARK $1 | sed s/$CALL_MARK//)
        # Parse the expected output from the test
        DUE_OUTPUT=$(sed -n /$OUTPUT_MARK/,\$p $1)
        # Parse possible  Valgrind request
        if  grep --quiet $VALGRIND_MARK $1; 
        then
            FORCE_VALGRIND=YES
        else
            FORCE_VALGRIND=NO
        fi
        # Compose the call and execute it
        if [ $USE_VALGRIND == "YES" ] || [ $FORCE_VALGRIND == "YES" ]
        then 
            VALGRIND="valgrind --leak-check=full "
        else
            VALGRIND=" "
        fi
        FULL_BINARY=$VALGRIND$PROJECT_FOLDER/$BINARY
        echo "Test #$k [$1] $VALGRIND $BINARY $MYCALL" > $TESTS_FOLDER/.call$k
        # Auto-compose a shell for the purpose of trying the binary
        # uses the .timeout file as a lock to detect that the program has ended
        echo "touch $TESTS_FOLDER/.timeout">$TESTS_FOLDER/.run.sh
        echo "CMD=\"$VALGRIND $FULL_BINARY $MYCALL 1> $TESTS_FOLDER/.out$k 2>&1\"">> $TESTS_FOLDER/.run.sh
        echo "eval \$CMD">>$TESTS_FOLDER/.run.sh
        echo "rm $TESTS_FOLDER/.timeout">>$TESTS_FOLDER/.run.sh
        chmod u+x $TESTS_FOLDER/.run.sh
        # Runs the shell with a timeout to prevent hanging
        timeout --preserve-status -k $SECS_WAIT $SECS_WAIT sh $TESTS_FOLDER/.run.sh
        #rm $TESTS_FOLDER/.run.sh
        
        # Check the output both the program and Valgrind
        if [ $USE_VALGRIND == "YES" ] || [ $FORCE_VALGRIND == "YES" ]
        then 
            VALGRIND_OUTPUT="\n        "$(grep -a "ERROR SUMMARY" $TESTS_FOLDER/.out$k | sed s/==[0-9]*==//)
            if grep -a "ERROR SUMMARY" $TESTS_FOLDER/.out$k | grep --quiet " 0 errors";
            then 
                VALGRIND_LEAKS=FALSE
            else
                VALGRIND_LEAKS=TRUE
            fi
        else
            VALGRIND_OUTPUT=""
            VALGRIND_LEAKS=FALSE
        fi
        # Tentative writing of the due output to check ISO/UTF format
        echo "$DUE_OUTPUT" > $TESTS_FOLDER/.due$k
        if   file $TESTS_FOLDER/.due$k | grep -a --quiet ISO;
        then
            toUTF8 $TESTS_FOLDER/.due$k
            cp $TESTS_FOLDER/.due$k.utf8 $TESTS_FOLDER/.due$k
            toUTF8 $TESTS_FOLDER/.out$k
            cp $TESTS_FOLDER/.out$k.utf8 $TESTS_FOLDER/.out$k
            DUE_OUTPUT=$(cat $TESTS_FOLDER/.due$k)
        fi 
        # If the real output of the program cotains %%%OUTPUT marks, then only those marks
        # are compared for validity. Otherwise, the full output is compared
        if  grep -a --quiet $OUTPUT_MARK $TESTS_FOLDER/.out$k; 
        then
            REAL_OUTPUT=$(grep -a -v == $TESTS_FOLDER/.out$k | sed -n /$OUTPUT_MARK/,\$p )
        else
            if  grep --quiet $OUTPUTFILE_MARK $1; 
            then
                FILE_OUTPUT=$(grep $OUTPUTFILE_MARK $1 | sed s/$OUTPUTFILE_MARK//)
                REAL_OUTPUT=$(echo $OUTPUT_MARK;cat $FILE_OUTPUT )
            else
                REAL_OUTPUT=$(echo  $OUTPUT_MARK; grep -v == $TESTS_FOLDER/.out$k)
            fi
        fi
        # Save due and real outputs in disk for further use
        # echo "$DUE_OUTPUT" > $TESTS_FOLDER/.due$k
        echo "$REAL_OUTPUT" > $TESTS_FOLDER/.real$k
        # When both outputs (expected and real) differ or valgrind detects leaks of memory
        # the test FAILS
        if [ -f $TESTS_FOLDER/.timeout ]
        then
            rm $TESTS_FOLDER/.timeout
            printf  "\r${RED}[ HANG ] Test #$k [$1] ($VALGRIND $BINARY $MYCALL) $VALGRIND_OUTPUT"
            cp $TESTS_FOLDER/.out$k $TESTS_FOLDER/.fail$k
            FAILED_TESTS=YES
        elif [ ! "$DUE_OUTPUT" == "$REAL_OUTPUT" ] || [ "$VALGRIND_LEAKS" == "TRUE" ]
        then
            
            printf  "\r${RED}[FAILED] Test #$k [$1] ($VALGRIND $BINARY $MYCALL) $VALGRIND_OUTPUT"
            cp $TESTS_FOLDER/.out$k $TESTS_FOLDER/.fail$k
            FAILED_TESTS=YES
        else
            printf  "\r${GREEN}[  OK  ] Test #$k [$1] ($VALGRIND $BINARY $MYCALL) $VALGRIND_OUTPUT"
        fi
    else # Cond1
        printf "${RED}[ SKIP ] Test #$k [$1] CALL MARK not found in $1 . ${GRAY}\n"
    fi # Cond 1
}
#
# Main Body
#
# Load configuration & moves to the project root folder
if [ -d ../Scripts ]
then
    source ../Scripts/doConfig.sh
else
   if [ -d ../../Scripts ]
   then
       source ../../Scripts/doConfig.sh
   else
    printf "\n${RED}Unable to find Scripts library${WHITE}\n\n"
    exit
   fi
fi
VERSION=2.0
printf "\n${WHITE}VALIDATION TOOL v"$VERSION"\n"
# First sorted tests
if [ $1 ]
then
   if [ "$1" == "ALL" ]
   then
      TESTS=$TESTS_FOLDER/*.test
   else
       TESTS=$1
   fi
else
          TESTS=$TESTS_FOLDER/*.test
#    printf "${RED}Missing test file. Please use ${WHITE}runTest.sh <testfile>\n"
#    exit
fi
printf "${WHITE}Checking tests folder \t\t"

if [ -z "$(ls -A $TESTS_FOLDER/*.test)" ]
then
    printf "${RED} No test found. Abort${WHITE}\n"
    exit
else
    printf "${GREEN}OK ${WHITE}\n"
fi
printf "Setting everything up \t\t"
# Marks to parse .test files
CALL_MARK="%%%CALL"
DESCRIPTION_MARK="%%%DESCRIPTION"
OUTPUT_MARK="%%%OUTPUT"
OUTPUTFILE_MARK="%%%FROMFILE"
VALGRIND_MARK="%%%VALGRIND"
# Auxiliary files
# .out* Raw output of the run
# .due* Expected predefined output
# .real* Real predefined output
# .fail* Output of every failed test
# .call* Description of the call
# .report Full report of failed tests when bacth mode
rm -f $TESTS_FOLDER/.out* $TESTS_FOLDER/.due* $TESTS_FOLDER/.real* $TESTS_FOLDER/.fail* $TESTS_FOLDER/.call*
# Flag to detect FAILED tests
FAILED_TESTS=NO
k=1
# Prebuild the command line for the call 
printf "${GREEN}OK ${WHITE}\n"
MAKEOUT=$TESTS_FOLDER/.outmake
if [ "$DO_INTERACTIVE" == "YES" ]
then
    printf "${WHITE}Generating fresh binaries\t${GRAY}"
    make clean &> $MAKEOUT
   # make build | tee make.out
    make build &>> $MAKEOUT
else
    printf "${WHITE}Generating fresh binaries\t${GRAY}"
    make clean &> $MAKEOUT 
    make &>> $MAKEOUT
fi
if  grep -i Error $MAKEOUT;
then
       printf "${RED} Failed build${WHITE}\n"
        exit
else
BINARY=$(grep "g++[^ ]*[ \t]*-o" $MAKEOUT | sed "s/^.*-o //;s/ build.*$//")
printf "${GREEN}"$BINARY"${WHITE}\n"
fi
# Execute tests
k=1
for test in $TESTS
do
   DESCRIPTION=$(grep  $DESCRIPTION_MARK $test| sed "s/^$DESCRIPTION_MARK/Test #$k /")
   printf "${WHITE}$DESCRIPTION\n"
   k=$[k + 1]
done
k=1
for test in $TESTS
do
   doTest $test
   k=$[k + 1]
done

# Analyzes the results
printf "${WHITE}\n"
if [ "$FAILED_TESTS" == "YES" ] 
then 
    if [ "$DO_INTERACTIVE" == "YES" ]
    then
        echo "Press [y] for SHORT REPORTS, [f] for LONG REPORTS, other to skip"
        read REVIEW
    fi
    if [ "$REVIEW" == "y" ] || [ "$REVIEW" == "f" ]
    then
        if [ "$DO_INTERACTIVE" == "YES" ]
        then
            clear
        fi
        printf "\n${WHITE}SHORT REPORT"
        for test in $TESTS_FOLDER/.fail*
        do
            NUMBER=$(echo $test | sed s/^.*fail//)
            printf "\n${RED} FAILED ${WHITE}$(head -1 $TESTS_FOLDER/.call$NUMBER)${WHITE}"
            printf "\n${WHITE}Differences found between ${GREEN}DUE${WHITE} and ${RED}REAL${WHITE} outputs:\n${WHITE}"
            DIFF=$(diff $TESTS_FOLDER/.due$NUMBER $TESTS_FOLDER/.real$NUMBER | sed s/^\>/'\\033[0;31m'\>/ | sed s/^\</'\\033[0;32m'\</ | sed s/$/'\\033[1;30m'/)
#            DIFF=$(diff $TESTS_FOLDER/.due$NUMBER $TESTS_FOLDER/.real$NUMBER)
            printf "$DIFF"
            printf "\n"
        done 
    fi
    if [ "$REVIEW" == "f" ]
    then
        for test in $TESTS_FOLDER/.fail*
        do
            NUMBER=$(echo $test | sed s/^.*fail//)
            printf "\n${RED} FAILED ${WHITE}$(head -1 $TESTS_FOLDER/.call$NUMBER)${WHITE}"
            cat $test
            printf "\n"
        done 
    fi
    if [ "$DO_INTERACTIVE" == "NO" ]
    then
        printf "" > $TESTS_FOLDER/.report
        for test in $TESTS_FOLDER/.fail*
        do
            NUMBER=$(echo $test | sed s/^.*fail//)
            printf "\n${RED} FAILED ${WHITE}$(head -1 $TESTS_FOLDER/.call$NUMBER)${WHITE}" >> $TESTS_FOLDER/.report
            printf "\n${GRAY}Differences found between ${GREEN}DUE${WHITE} and ${RED}REAL${WHITE} outputs:\n${WHITE}" >> $TESTS_FOLDER/.report
            DIFF=$(diff $TESTS_FOLDER/.due$NUMBER $TESTS_FOLDER/.real$NUMBER | sed s/^\>/'\\033[0;31m'\>/ | sed s/^\</'\\033[0;32m'\</ | sed s/$/'\\033[1;30m'/)
#            DIFF=$(diff $TESTS_FOLDER/.due$NUMBER $TESTS_FOLDER/.real$NUMBER)
            printf "\n$DIFF\n" >> $TESTS_FOLDER/.report
            cat $test >> $TESTS_FOLDER/.report
            printf "\n" >> $TESTS_FOLDER/.report
        done 
    fi
fi
# Remove auxiliary files
rm -f $TESTS_FOLDER/.out* $TESTS_FOLDER/.due* $TESTS_FOLDER/.real* $TESTS_FOLDER/.fail* $TESTS_FOLDER/.call*
printf "${WHITE}"
if [ "$FAILED_TESTS" == "YES" ]
then
    exit 1
fi
