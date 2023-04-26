/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/* 
 * @file:   BigramCounter.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 12 February 2023, 11:00
 */

#ifndef BIGRAM_COUNTER_H
#define BIGRAM_COUNTER_H

#include "Language.h"

/**
 * @class BigramCounter
 * @brief It is a helper class used to calculate the frequency of each bigram in
 * a text file. It consists of a square matrix of integers. Each element contains
 * the frequency of the bigram that defines that element: the bigram formed taking
 * the characters defined by the row and column of that element. 
 */
class BigramCounter {
public:

    /**
     * A const c-string with the set of characters that are considered as 
     * part of a word. Any other character will be considered a separator  
     * Only lowercase characters are included in this string. This c-string
     * is used in the constructor of this class, as the default value to assign
     * to the field _validChars
     */
    static const char* const DEFAULT_VALID_CHARACTERS;

    /**
     * @brief Constructor of the class. The object will contain a matrix of integers
     * with as many rows and colums as the number of characters in @p validChars
     * Each element of the matrix will be set to 0
     * @param validChars The set of characters that are considered as 
     * part of a word. Input parameter
     */
    BigramCounter(std::string validChars = DEFAULT_VALID_CHARACTERS);

    /**
     * @brief Copy constructor
     * @param orig the BigramCounter object used as source for the copy. Input
     * parameter
     */
    BigramCounter(BigramCounter orig);

    /**
     * @brief Destructor
     */
    ~BigramCounter();

    /**
     * @brief Returns the number (size) of valid characters that are considered as part 
     * of a word in this BigramCounter object. Query method
     * @return the number (size) of valid characters that are considered as part 
     * of a word in this BigramCounter object 
     */
    int getSize();

    /**
     * @brief Gets the number of bigrams with a frequency greater than 0.
     * Query method
     * @return the number of bigrams with a frequency greater than 0
     */
    int getNumberActiveBigrams();

    /**
     * @brief Sets the frequency of the given bigram using the value 
     * provided with @p frequency. Modifier method
     * @param bigram The bigram in which the frequency will be set. Input
     * parameter
     * @param frequency The new frequency. Input parameter
     * @return true if the bigram was found in this object. false otherwise
     */
    bool setFrequency(Bigram bigram, int frequency);

    /**
     * @brief Increases the current frequency of the given bigram using the value 
     * provided with @p frequency. If @p frequency is 0 or frequency is not 
     * provided, then 1 is added to the current frequency of the bigram.
     * Modifier method
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception if the given bigram is not valid
     * @param bigram The bigram in which the frequency will be modified.
     * Input parameter
     * @param frequency The quantity that will be added to the current frequency.
     * Input parameter
     */
    void increaseFrequency(Bigram bigram, int frequency = 0);

    /**
     * @brief Overloading of the assignment operator
     * @param orig the BigramCounter object used as source for the assignment.
     * Input parameter
     * @return A reference to this object
     */
    BigramCounter operator=(BigramCounter orig);


    /**
     * @brief Overloading of the operator +=. It increases the current 
     * frequencies of the bigrams of this object with the frequencies of the 
     * bigrams of the given object. 
     * Modifier method
     * @param rhs a BigramCounter object 
     * @return A reference to this object
     */
    BigramCounter operator+=(BigramCounter rhs);

    /**
     * @brief Reads the given text file and calculates the frequencies of each 
     * bigram in that file.
     * Modifier method
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception
     * if the given file cannot be opened
     * @param fileName The name of the file to process. Input parameter
     * @return true if the file could be read; false otherwise
     */
    void calculateFrequencies(char* fileName);

    /**
     * @brief Builds a Language object from this BigramCounter object. The 
     * Language will contain the bigrams and frequencies for those one with 
     * a frequency greater than 0.
     * Query method
     * @return A Language object from this BigramCounter object
     */
    Language toLanguage();

private:
    int** _frequency; ///< 2D matrix with the frequency of each bigram

    /**
     * Set of characters that are considered as part of a word. Any other 
     * character will be considered a separator of words. Only lowercase 
     * characters are included in this string 
     */
    std::string _validCharacters;

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position
     * Query method
     * @param row Row of the element. Input parameter
     * @param column Column of the element. Input parameter
     * @return A const reference to the element at the given position
     */
    int operator()(int row, int column);

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position
     * Query/Modifier method.
     * @param row Row of the element. Input parameter 
     * @param column Column of the element. Input parameter
     * @return A reference to the element at the given position
     */
    int operator()(int row, int column);
};

#endif /* BIGRAM_COUNTER_H */
