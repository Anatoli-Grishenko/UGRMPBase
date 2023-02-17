/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 12 February 2023, 10:40
 */


#include <iostream>
#include <cstring>

#include "Language.h"

using namespace std;

const char MIN_OPERATION = 'n';
const char MAX_OPERATION = 'x';

int posMinMaxLanguage(const Language& language, const Language array[], 
        int initialPos, int finalPos, char operation) {
    int posMinMax=-1;
    double minMaxDistance, distance;

    if(finalPos>=initialPos) {
        minMaxDistance = language.getDistance(array[initialPos]); 
        posMinMax = initialPos;
        for(int i=initialPos; i<=finalPos; ++i) {
            distance = language.getDistance(array[i]);

            if (operation == MIN_OPERATION) { // Operation is finding minimum
                if (distance < minMaxDistance) {
                    minMaxDistance = distance;
                    posMinMax = i;
                }
            } else { // Operation is finding maximum
                if (distance > minMaxDistance) {
                    minMaxDistance = distance;
                    posMinMax = i;
                }
            }
        }
    }

    return posMinMax;
}

void showEnglishHelp() {
    cerr << "Error, run with the following parameters:" << endl;
    cerr << "language3 [-t min|max] <file1.bgr> <file2.bgr> [ ... <filen.bgr>]" << endl;
}

/**
 * This program reads an undefined number of Language objects from the set of 
 * files passed as parameters to main(). All the Languages object, except the 
 * first one, must be stored in a dynamic array of Language objects. Then, 
 * for each Language in the dynamic array, this program prints to the 
 * standard output the name of the file of that Language and the distance from 
 * the first Language to the current Language. 
 * Finally, the program should print in the standard output, the name of 
 * the file with the Language with the minimum|maximum  distance to the Language 
 * of the first file and its language identifier.
 * 
 * At least, two Language files are required to run this program.
 * Running example:
 * > language3 [-t min|max] <file1.bgr> <file2.bgr> [  ... <filen.bgr>] 
 */
int main(int argc, char* argv[]) {

    Language *arrayLanguage=nullptr; // The pointer to the dynamic array of Language
    Language sourceLanguage; // First Language
//    int nElements = argc-2;
    int nElements; // The number of elements to put in the dynamic array
    int first; // Position in argv of the first Language file

    char operation = MIN_OPERATION; // min by default
    
    if(argc<3){
        cout << "You must provide at least two Language files" << endl;
        showEnglishHelp();
        return 1;       
    }
    if (argv[1][0] == '-') { // Run with -t min|max
        if (strcmp(argv[1], "-t") == 0) {
            if(strcmp(argv[2], "min") == 0){
                operation = MIN_OPERATION;                
            }
            else if(strcmp(argv[2], "max") == 0){
                operation = MAX_OPERATION;
            }
            else{
                showEnglishHelp(); 
                return 0;
            }
            nElements = argc-4;
            first = 3;
        }
    }
    else{ // Run without -t min|max
        nElements = argc-2;
        first = 1;
    }
    
    if(nElements<1){
        cout << "You must provide at least two Language files" << endl;
        showEnglishHelp();
        return 1;
    }
    arrayLanguage = new Language[nElements];
    
    sourceLanguage.load(argv[first]);
    for(int i=0; i<nElements; i++){
        arrayLanguage[i].load(argv[i+first+1]);
    }
    for(int i=0; i<nElements; i++){
        cout << "Distance to: " << argv[i+first+1] << ": " << 
                sourceLanguage.getDistance(arrayLanguage[i]) << endl;
    }
    int positionMinMax = posMinMaxLanguage(sourceLanguage, arrayLanguage,
            0, nElements-1, operation);
    
    if(operation == MIN_OPERATION){
       cout << "Nearest language file: " << argv[positionMinMax+first+1] << 
            ". Identifier of the nearest language: "<< arrayLanguage[positionMinMax].getLanguageId() << endl;
    }
    else{
       cout << "Farthest language file: " << argv[positionMinMax+first+1] << 
            ". Identifier of the farthest language: "<< arrayLanguage[positionMinMax].getLanguageId() << endl;        
    }
    
    delete[] arrayLanguage;
}

