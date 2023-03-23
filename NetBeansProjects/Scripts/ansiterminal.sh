#!/bin/bash
echo "Loading ansiterminal..."
# Colors to be used in output of tests
ESC='\033'

# Dark foreground colors
BLACK=$ESC'[0;30m'
RED=$ESC'[0;31m'
GREEN=$ESC'[0;32m'
YELLOW=$ESC'[0;33m'
BLUE=$ESC'[0;34m'
MAGENTA=$ESC'[0;35m'
CYAN=$ESC'[0;36m'
LGRAY=$ESC'[0;37m'
# Bright foreground colors
GRAY=$ESC'[1;30m'
LRED=$ESC'[1;31m'
LGREEN=$ESC'[1;32m'
LYELLOW=$ESC'[1;33m'
LBLUE=$ESC'[1;34m'
LMAGENTA=$ESC'[1;35m'
LCYAN=$ESC'[1;36m'
WHITE=$ESC'[1;37m'
# Background colors
BBLACK=$ESC'[0;40m'
BRED=$ESC'[0;41m'
BGREEN=$ESC'[0;42m'
BYELLOW=$ESC'[0;43m'
BBLUE=$ESC'[0;44m'
BMAGENTA=$ESC'[0;45m'
BCYAN=$ESC'[0;46m'
BLGRAY=$ESC'[0;47m'
#defaults
BASECOLOR=$WHITE
ENDCOLOR=$LGRAY



function setCursorXY {
    #cout << ESC << "["<<y<<";"<<x<<"f"; 
    printf "${ESC}[$2;$1f"
}

function clearScreen {
    #cout << ESC << "[2J";
    #setCursorXY(1,1);
    printf "${ESC}[2J"
    seetText $BASECOLOR
    setCursorXY 1 1 
}

#function setBackground {
#}

# @deprecated
function setText {
	printf "${1}"
}

function colorBackground {
	printf "${ESC}[${BG}$1"
}

function colorText {
	printf "${ESC}[${FG}$1"
}


function setCursorOn {
    printf "${ESC}[?25h"    
}

function setCursorOff {
    printf "${ESC}[?25l"
}

function regular {
	setText $ENDCOLOR
	printf "$1"	
}


function label {
	setText $BASECOLOR
	printf "$1"
	setText $ENDCOLOR
}

function alert {
	setText $RED
	printf "$1"
	setText $ENDCOLOR
}

function highlight {
	setText $GREEN
	printf "$1"
	setText $ENDCOLOR
}

function inputLine {
	label "$1"
	read C
	eval "$2=$C"
}

function EndOfScript {
	if [ "$1" == "" ]
	then 
	   alert "End of Script "
	else
            label "$1"
	fi
	setText $ENDCOLOR
	setCursorOn
	printf "\n"
	exit 1
}

# @brief Asks for confirmation with a personalized message
# $1 message to show
function doConfirm {
	label "$1"
	
	read ans
	if [[ $ans == "$" ]] ;
	then
		EndOfScript
	fi
	if [[ $ans == "Y" ]]  || [[ $ans == "y" ]]  ;
	then
		return 0
	else
		return 1
	fi
}

# @brief Asks for confirmation with a personalized message
# $1 message to show
function doMenu {
	COUNTOPTIONS=0
	K=$#
	args=("$@")
	printf "\n${WHITE}Please choose:   "
	for (( i=0; i<$K; i+=2 ))
	do
		printf "${LBLUE}[${args[${i}]}]${WHITE}${args[${i}+1]}    "
	done
	setCursorOn
	while true;
	do
		read ans
		for (( i=0; i<$K; i+=2 ))
		do
			if [ "$ans" == "${args[${i}]}" ]
			then
				return $[i / 2]
			fi
		done
	done
}

function pressReturn {
    if [ "$INTERACTIVE" == "YES" ]
    then
        label "Press [INTRO] to continue"
        read tmp
    fi
}

# Progress bar
# Label at the left side
PB_LABEL="Progress: "
PB_COLOR=$BLUE
PB_BACKGROUND=$GRAY
PB_UNDONE="░"
PB_DONE="█"
PB_COUNT=5
PB_MAX=10
PB_WIDTH=50
PB_SHOWVALUE=YES
PB_X=1
PB_Y=1

# Sets the label
function PB_Set {
	if [ $1 ] && [ $2 ]
	then
		eval "$1=$2"
		return 0
	else
		echo "PB_Set Error, expected two parameters"
		return 1
	fi
}

# Shows the progress bar
function NOPB_Show {
	printf "\r${WHITE}$PB_LABEL\n"
	for (( pbi=1; pbi<=$PB_WIDTH; pbi++ ))
	do
		printf "$PB_BACKGROUND$PB_UNDONE"
	done	
	printf "${WHITE}"
	#PB_COUNT=$(( ($PB_COUNT < $PB_MAX)? $PB_COUNT : $PB_MAX ))
	Min $PB_COUNT $PB_MAX PB_COUNT
	PB_RATIO=$(echo "$PB_WIDTH * 1.0 / $PB_MAX" | bc -l)
	PB_ICOUNT=$(echo "$PB_COUNT*$PB_RATIO*10/10" | bc )
	if [ "$PB_SHOWVALUE" == "YES" ]
	then
		printf " $PB_COUNT / $PB_MAX    "
	fi
	for (( pbi=1; pbi<=$PB_ICOUNT; pbi++ ))
	do
		printf "$PB_COLOR$PB_DONE"
	done	
}

function PB_Show {
#	if [ $PB_COUNT -le 1 ]
#	then
		setCursorXY $PB_X $PB_Y
		printf "${WHITE}$PB_LABEL                    "
		PBY=$[PB_Y + 1]
		setCursorXY $PB_X $PBY
		for (( pbi=1; pbi<=$PB_WIDTH; pbi++ ))
		do
			printf "$PB_BACKGROUND$PB_UNDONE"
		done
#	fi	
	PB_Update
}

function PB_Update {
	#PB_COUNT=$(( ($PB_COUNT < $PB_MAX)? $PB_COUNT : $PB_MAX ))
	Min $PB_COUNT $PB_MAX PB_COUNT
	PB_RATIO=$(echo "$PB_WIDTH * 1.0 / $PB_MAX" | bc -l)
	PB_ICOUNT=$(echo "($PB_COUNT*$PB_RATIO+0.5)*10/10" | bc )
	setCursorXY $PB_X $[PB_Y + 1]
	for (( pbi=1; pbi<=$PB_ICOUNT; pbi++ ))
	do
		printf "$PB_COLOR$PB_DONE"
	done	
	setCursorXY $[PB_X + PB_WIDTH + 1] $[PB_Y + 1]
	if [ "$PB_SHOWVALUE" == "YES" ]
	then
		printf "${WHITE} $PB_COUNT / $PB_MAX    "
	fi
}





