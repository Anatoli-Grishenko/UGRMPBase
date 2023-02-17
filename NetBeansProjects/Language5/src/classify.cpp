/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file classify.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include "BigramCounter.h"
#include "Language.h"

using namespace std;

void showSpanishHelp() {
    cout << "Formato:" << endl;
    cout << " classify  <texto.txt> <leng1.bgr> <leng2.bgr> <leng3.bgr> .... " << endl;
    cout << "          Devuelve el lenguaje más cercano al texto de entrada" << endl;
    cout << endl;
}

void showEnglishHelp() {
    cout << "Format:" << endl;
    cout << " classify <text.txt> <lang1.bgr> [<lang2.bgr> <lang3.bgr> ....]" << endl;
    cout << "          Obtains the identifier of the closest language to the input text file" << endl;
    cout << endl;
}

/**
 * This program print the language identifier of the closet language 
 * for an input text file (<text.txt>) among the set of models provided in 
 * files <lang1.bgr>, <lang2.bgr>, ...
 * 
 * Running example:
 * > classify  <text.txt> <lang1.bgr> [<lang2.bgr> <lang3.bgr> ...]
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Error, run with the following parameters:" << endl;
        showEnglishHelp();
        return 1;
    } else {
        BigramCounter bigramCounter;
        bigramCounter.calculateFrequencies(argv[1]);
        Language language;
        Language unknownLanguage=bigramCounter.toLanguage();
       
        double minDistance = 10000, currentDistance;
        string languageId = "unknown";
        for (int i = 2; i < argc; i++) {
            language.load(argv[i]);
            currentDistance = unknownLanguage.getDistance(language);
            if (currentDistance < minDistance) {
                minDistance = currentDistance;
                languageId = language.getLanguageId(); 
            }
        }
        cout << "Final decision: language " << languageId << " with a distance of " << minDistance << endl;
    }
    return 0;
}

