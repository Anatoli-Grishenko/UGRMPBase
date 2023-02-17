/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file learn.cpp
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


void showSpanishHelp() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el modelo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
//    cout << "-c|-a: operación crear nuevo fichero de idioma (-c) o añadir a fichero de idioma existente (-a)" << endl;
    cout << "-t|-b: modo texto o modo binario para el fichero de salida (-t por defecto)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (output.bgr por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

void showEnglishHelp() {
    cout << "Format:" << endl;
//    cout << "learn {-c|-a} [-t|-b] [-l languageId] [-f outputFilename] text1.txt text2.txt text3.txt .... " << endl;
    cout << "learn [-t|-b] [-l languageId] [-f outputFilename] <text1.txt> [<text2.txt> <text3.txt> .... ]" << endl;
    cout << "           learn the model for the language languageId from the text files <text1.txt> <text2.txt> <text3.txt> ..." << endl;
    cout << endl;
    cout << "Parameters:" << endl;
//    cout << "-c|-a: create new language file (-c) or append to existing language file (-a)" << endl;
    cout << "-t|-b: text mode or binary mode for the output file (-t by default)" << endl;
    cout << "-l languageId: language identifier (unknown by default)" << endl;
    cout << "-f outputFilename: name of the output file (output.bgr by default)" << endl;
    cout << "<text1.txt> <text2.txt> <text3.txt> ....: names of the input files (at least one is mandatory)" << endl;
}

/**
 * This program learns a Language model from a set of input tex files (tex1.txt,
 * tex2.txt, ...
 * Running example:
 * > learn [-t|-b] [-l languageId] [-f outputFilename] <text1.txt> [<text2.txt> <text3.txt> ....]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */

int main(int argc, char *argv[]) {   
    int languageArg = -1, 
            outputFileArg = -1, // position in argv of the name of the output file name
            firstInputFileArg = -1, // position in argv of the first input file name
            lastInputFileArg = -1; // position in argv of the last input file name
//    char operation = 'n'; // operation create language file ('c') or append to language file ('a')
    char mode = 't'; // text mode ('t') or binary ('b')
    bool hasBeenReadIinitialParametes = false; // true if all the parameters with - has been read
    string languageId = "unknown";
    // antes string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; /// Luis ???
    //string valid="abcdefghijklmnopqrstuvwxyz"; 
    
    for (int i = 1; i < argc; ++i) { // Loop to process the main() parameters
        if (argv[i][0] == '-' && !hasBeenReadIinitialParametes) {
//            if (strcmp(argv[i], "-a") == 0) {
//                operation = 'a';
//
//            }
//            else if (strcmp(argv[i], "-c") == 0) {
//                operation = 'c';
//
//            }
//            else 
            if(strcmp(argv[i], "-t") == 0){
                mode = 't';
            }
            else if(strcmp(argv[i], "-b") == 0){
                mode = 'b';
            }
            else if (strcmp(argv[i], "-l") == 0) {
                if ((i + 1) < argc) { // If at least another parameter is provided (language identifier)
                    languageArg = i + 1;
                    ++i; /// Luis ???
                }
            } 
            else if (strcmp(argv[i], "-f") == 0) {
                if ((i + 1) < argc) { // If at least another parameter is provided (output file name) 
                    outputFileArg = i + 1;
                    ++i; /// Luis ???
                }
            }   
        } else {
            hasBeenReadIinitialParametes = true;
            if (firstInputFileArg < 0) {
                firstInputFileArg = i;
                lastInputFileArg = i;
            } else {
                lastInputFileArg = i;
            }
        }
    }
    
//    if (operation != 'c' && operation != 'a') {
//        cout << "You have not provided any valid operation ({-c|-a})\n" << endl;
//        showEnglishHelp();
//        return 1;
//    }
    if (firstInputFileArg < 0) {
        cout << "Error, run with the following parameters:" << endl;
        showEnglishHelp();
    } else {
        BigramCounter bigramCounter;// antes BigramCounter bigramCounter(valid);
        Language language;

//        if (operation == 'c') {
        if (languageArg > 0) {
            languageId = argv[languageArg];
        }
//        } else { //operation=='a'
//            if (outputFileArg < 0) {
//                cout << "You have not provided the name of the input file (parameter -f outputFilename)" << endl;
//                showEnglishHelp();
//                return 1;
//            }
//            language.load(argv[outputFileArg]);
//            bigramCounter.fromLanguage(language);
//        }

        for (int i = firstInputFileArg; i <= lastInputFileArg; i++) {
            BigramCounter contadorBigramasAux; //antes BigramCounter contadorBigramasAux(valid);
            if (!contadorBigramasAux.calculateFrequencies(argv[i])) {
                cout << "The file cannot be read: " << argv[i] << endl;
            } else {
                bigramCounter += contadorBigramasAux;
            }
        }

        language = bigramCounter.toLanguage();
        language.setLanguageId(languageId);
        if (outputFileArg < 0) {
            language.save("output.bgr", mode);
        } else {
            language.save(argv[outputFileArg], mode);
        }
    }
    return 0;
}

