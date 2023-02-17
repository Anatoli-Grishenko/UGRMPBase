/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file joinLanguages.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include <cstring>

#include "BigramCounter.h"
#include "Language.h"

using namespace std;

void showEnglishHelp() {
    cout << "Format:" << endl;
    cout << "joinLanguages -f <outputFile.bgr> <file1.bgr> [<file2.bgr> ... <filen.bgr>] " << endl;
    cout << "       join the Languages files <file1.bgr> <file2.bgr> ... into <outputFile.bgr>" << endl;
    cout << endl;
    cout << "Parameters:" << endl;
    cout << "-f <outputFile.bgr>: name of the output file (output.bgr by default)" << endl;
    cout << "<file*.bgr>: each one of the file to be joined" << endl;
}

/**
 * This program reads an undefined number of Language objects from the files
 * passed as parameters to main(). It obtains as result the union of all the 
 * input Language objects. The result is then sorted by decreasing order of 
 * frequency and alphabetical order of bigrams when there is any tie in 
 * frequencies. Finally the result Language is saved in an output file. The 
 * program must have at least an input file and an output file. 
 * Running example:
 * >  joinLanguages -f <outputFile.bgr> <file1.bgr> [<file2.bgr> ... <filen.bgr>]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */
int main(int argc, char* argv[]) {
    Language inputLanguage, inputLanguageAux;
    string outputFileName = "output.bgr";
    int nInputFiles;
    int firstInputFile;

    if (argc < 3) {
        cout << "Error, run with the following parameters:" << endl;
        showEnglishHelp();
        return 1;
    }
    
    if (argv[1][0] == '-') { // Run with -f <outputFile.bgr>
        if (strcmp(argv[1], "-f") == 0) {
            outputFileName = argv[2];
            nInputFiles = argc-3;
            firstInputFile = 3;
        }
    }
    else{ // Run without -f <outputFile.bgr>
        nInputFiles = argc-2;
        firstInputFile = 1;
    }
    
    inputLanguage.load(argv[firstInputFile]);
    cout << "LENGUAGE LEÍDO:\n";
    cout << inputLanguage << endl;
    for (int i = 1; i < nInputFiles; i++) {
        inputLanguageAux.load(argv[firstInputFile+i]);
        if(inputLanguageAux.getLanguageId() == inputLanguage.getLanguageId()){
            inputLanguage+=inputLanguageAux;
        }
    }
    inputLanguage.sort();
    inputLanguage.save(outputFileName.c_str());
    return 0;
}

