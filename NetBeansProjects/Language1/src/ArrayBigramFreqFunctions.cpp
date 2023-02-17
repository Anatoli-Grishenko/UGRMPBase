/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/** 
 * @file ArrayBigramFreqFunctions.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 7 February 2023, 19:45
 */

#include <string>

#include "ArrayBigramFreqFunctions.h"

using namespace std;

void readArrayBigramFreq(BigramFreq array[], int dim, int &nElements) {
    string bigramString;
    int frecuency;
    BigramFreq bigramFreq;
    
    cin>>nElements; 
    if(nElements>dim)
        nElements=dim;
    else if(nElements<0) {
        nElements=0;
    }
    for(int i=0; i<nElements; ++i) {
        cin >> bigramString >> frecuency;
        Bigram bigram(bigramString);
        bigramFreq.setBigram(bigram);
        bigramFreq.setFrequency(frecuency);
        array[i] = bigramFreq;
    }
}

void printArrayBigramFreq(const BigramFreq array[], int nElements) {
    std::cout << nElements << std::endl;
    for(int i=0; i<nElements; i++) {
        std::cout << array[i].toString() << endl;
    }
}

void swapElementsArrayBigramFreq(BigramFreq array[], int nElements, int first,
        int second){
    BigramFreq aux;
    
    if(first<0 || first>(nElements-1)){
        throw std::out_of_range(string("void swapElementsArrayBigramFreq(") + 
                "BigramFreq array[], int nElements, int first, int second): " +
                "invalid position (first = " + to_string(first) + ")");
    }
    if(second<0 || second>(nElements-1)){
        throw std::out_of_range(string("void swapElementsArrayBigramFreq(") + 
                "BigramFreq array[], int nElements, int first, int second): " +
                "invalid position (second = " + to_string(second) + ")");
    }
    
    aux = array[first];
    array[first] = array[second];
    array[second] = aux;
}

int posMaxArrayBigramFreq(const BigramFreq array[],
        int initialPos, int finalPos) {
    int posMax=-1;
    int maxFrequency;

    if(finalPos>=initialPos){
        maxFrequency = array[initialPos].getFrequency();
        posMax = initialPos;
        for(int i=initialPos+1; i<=finalPos; ++i) {
            if((array[i].getFrequency() > maxFrequency) || 
                (array[i].getFrequency() == maxFrequency 
                && array[i].getBigram().getText() < array[posMax].getBigram().getText())) {
                maxFrequency = array[i].getFrequency();
                posMax=i;
            }
        }
    }

    return posMax;
}

void sortArrayBigramFreq(BigramFreq array[], int nElements){
    int posMax;

    for(int i=0; i<nElements-1; i++){
        posMax=posMaxArrayBigramFreq(array, i, nElements-1);
        swapElementsArrayBigramFreq(array, nElements, i, posMax);
    }
}

void toUpperArrayBigramFreq(BigramFreq array[], int nElements){
    Bigram bigram;
    for(int i=0; i<nElements; i++){
        bigram = array[i].getBigram();
        bigram.toUpper();
        array[i].setBigram(bigram);
    }
}