/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 2 de febrero de 2023, 12:23
 */

#include <iostream>
#include <string>

#include "Bigram.h"

using namespace std;



/**
 * This program reads a text (without spaces) with a undefined number of 
 * characters and a text with two characters (bigram). It finds the bigrams 
 * contained in the first text, storing them in an array of Bigram. 
 * After that, the bigrams of the array are shown in the standard output. 
 * Then it converts to uppercase the bigrams in the array that are equals to the 
 * bigram of the second text. Finally the bigrams of the array are shown again 
 * in the standard output. 
 * Running example:
 * > language0 < data/SimpleText.txt
 */
int main(int argc, char* argv[]) {
    // This string contains the list of characters that are considered as
    // valid within a word. The rest of characters are considered as
    // separators
    const string validCharacters = "abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";
    char character1, character2;

    const int DIM_ARRAY_BIGR = 1000;
    Bigram arrayBigr[DIM_ARRAY_BIGR];
    int nBigrams = 0;
    string inputString, bigramString;

    cin >> inputString >> bigramString;

    if (inputString.size() > 0) {
        character1 = tolower(inputString.at(0));
    }
    for (int i = 1; i < inputString.size(); i++) {
        character2 = tolower(inputString.at(i));
        if (isValidCharacter(character1, validCharacters) &&
                isValidCharacter(character2, validCharacters)) {
            arrayBigr[nBigrams] = Bigram(character1, character2);
            nBigrams++;
        }
        character1 = character2;
    }

    // Show the list of bigrams
    cout <<  nBigrams << endl; 
    for (int i = 0; i < nBigrams; i++) {
        cout << arrayBigr[i].toString() << endl;
    }

    // Convert to uppercase the given bigram
    for (int i = 0; i < nBigrams; i++) {
        if(bigramString == arrayBigr[i].toString()){
            toUpper(arrayBigr[i]);
        }
    }
    
    cout << endl;
    
    // Show the list of bigrams
    cout << nBigrams << endl; 
    for (int i = 0; i < nBigrams; i++) {
        cout << arrayBigr[i].toString() << endl;
    }
    
    return 0;
}

