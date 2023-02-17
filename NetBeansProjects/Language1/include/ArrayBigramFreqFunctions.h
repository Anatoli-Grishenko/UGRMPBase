
/*
 * Metodología de la Programación: Language1
 * Curso 2022/2023
 */

/** 
 * @file ArrayBigramFreqFunctions.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 7 February 2023, 19:45
 */
#ifndef ARRAYBIGRAMFREQFUNCTIONS_H
#define ARRAYBIGRAMFREQFUNCTIONS_H

#include "BigramFreq.h"

/**
 * @brief Reads the number of used elements and the elements of an array of
 * BigramFreq
 * @param array The array where the elements will be stored
 * @param dim The capacity of the array
 * @param nElements The number of elements used by the array
*/
void readArrayBigramFreq(BigramFreq array[], int dim, int &nElements);

/**
 * @brief Prints in the standard output the number of used elements and the 
 * elements of an array of BigramFreq 
 * @param array The array of BigramFreq to be printed
 * @param nElements The number of elements used by the array
*/
void printArrayBigramFreq(const BigramFreq array[], int nElements);

/**
 * @brief Swaps the elements at positions @p first and @p second in the given
 * array of BigramFreq
 * @param array The array of BigramFreq 
 * @param nElements The number of elements used by the array
 * @param first the position of the first element to be swaped
 * @param second the position of the second element to be swaped
*/
void swapElementsArrayBigramFreq(BigramFreq array[], int nElements, int first,
                int second);
/**
 * @brief Finds the position of the elements with maximum frequency in the
 * subarray of @p array that begins at position @p initialPos and ends at position
 * @p finalPos (both included)
 * @param array The array of BigramFreq 
 * @param initialPos The initial position of the subarray 
 * @param finalPos The final position of the subarray 
 * @return the position of the element with maximum frequency in the subarray 
 * that begins at position @p initialPos and ends at position @p finalPos 
 * (both included). If no element can be retrieved, it returns -1
*/
int posMaxArrayBigramFreq(const BigramFreq array[],
        int initialPos, int finalPos);

/**
 * @brief Sorts the given array of BigramFreq in decreasing order of 
 * frequency using the selection sort algorithm
 * @param array The array of BigramFreq 
 * @param nElements The number of elements used by the array
*/
void sortArrayBigramFreq(BigramFreq array[], int nElements);

/**
 * @brief Converts to uppercase all the bigrams within the given array
 * @param array An array of BigramFreq objects
 * @param nElements The number of elements in the array
 */
void toUpperArrayBigramFreq(BigramFreq array[], int nElements);

#endif /* ARRAYBIGRAMFREQFUNCTIONS_H */

