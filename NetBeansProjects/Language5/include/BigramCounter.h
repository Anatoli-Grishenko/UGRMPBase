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
 * Created on 29 January 2023, 11:00
 */

#ifndef BIGRAM_COUNTER_H
#define BIGRAM_COUNTER_H

#include "Language.h"

/**
 * @class BigramCounter
 * @brief It is a helper class used to calculate the frecuency of each bigram in
 * a text file. It consists of a square matrix of integers. Each element contains
 * the frecuency of the bigram that defines that element: the bigram formed taking
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
     * part of a word.
     */
    BigramCounter(const std::string& validChars = DEFAULT_VALID_CHARACTERS);

    /**
     * @brief Copy constructor
     * @param orig the BigramCounter object used as source for the copy
     */
    BigramCounter(const BigramCounter & orig);

    /**
     * @brief Destructor
     */
    ~BigramCounter();

    /**
     * @brief Returns the number (size) of valid characters that are considered as part 
     * of a word in this BigramCounter object 
     * @return the number (size) of valid characters that are considered as part 
     * of a word in this BigramCounter object 
     */
    int getSize() const;

    /**
     * @brief Gets the number of bigrams with a frequency greater than 0
     * @return the number of bigrams with a frequency greater than 0
     */
    int getNumberActiveBigrams() const;

    /**
     * @brief Sets the frecuency of the given bigram using the value 
     * provided with @p frecuency. 
     * @param bigram The bigram in which the frequency will be set
     * @param frecuency The new frecuency
     * @return true if the bigram was found in this object. false otherwise
     */
    bool setFrecuency(const Bigram& bigram, int frecuency);


    /**
     * @brief Increases the current frecuency of the given bigram using the value 
     * provided with @p frecuency. If @p frecuency is 0 or frecuency is not 
     * provided, then 1 is added to the current frecuency of the bigram.
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception if the given bigram is not valid
     * @param bigram The bigram in which the frequency will be modified
     * @param frecuency The quantity that will be added to the current frecuency
     */
    void increaseFrecuency(const Bigram& bigram, int frecuency = 0);

    /**
     * @brief Overloading of the assignment operator
     * @param orig the BigramCounter object used as source for the assignment
     * @return A reference to this object
     */
    BigramCounter& operator=(const BigramCounter & orig);


    /**
     * @brief Overloading of the operator +=. It increases the current 
     * frecuencies of the bigrams of this object with the frecuencies of the 
     * bigrams of the given object
     * @param rhs a BigramCounter object 
     * @return A reference to this object
     */
    BigramCounter& operator+=(const BigramCounter & rhs);

    /**
     * @brief Reads the given text file and calculates the frequencies of each 
     * bigram in that file
     * @param fileName The name of the file to process
     * @return true if the file could be read; false otherwise
     */
    bool calculateFrequencies(const char* fileName);

    /**
     * @brief Builds a Language object from this BigramCounter object. The 
     * Language will contain the bigrams and frecuencies for those one with 
     * a frecuency greater than 0.
     * @return A Language object from this BigramCounter object
     */
    Language toLanguage() const;

    /**
     * @brief Sets the frecuencies of this bigram counter using the frecuencies
     * of each bigram in the given Language object. If a bigram in @p language
     * is not found in this object, then that bigram is not considered
     * @param language A Language object with the frecuencies for each
     * bigram
     */
    void fromLanguage(const Language & language);
private:
    int** _frequency; ///< 2D matrix with the frecuency of each bigram

    /**
     * Set of characters that are considered as part of a word. Any other 
     * character will be considered a separator of words. Only lowercase 
     * characters are included in this string 
     */
    std::string _validCharacters;

    /**
     * @brief Sets the frecuency of each bigram to 0, that is fill with 0 the 
     * matrix of frecuencies
     */
    void initFrecuencies();

    /**
     * @brief Allocates dynamic memory for the matrix of frecuencies
     * @param size The number of rows and columns for the dynamic matrix of
     * frecuencies
     */
    void allocate(int size);

    /**
     * @brief Deallocates the dynamic memory used by the matrix of frecuencies
     */
    void deallocate();


    /**
     * @brief Sets the set of characters that are considered as part of a word with the
     * one of the given object and copies the frecuencies in the matrix of the 
     * given object into the matrix of frecuencies of this object.
     * @pre This object should have a matrix of frecuencies with the same size
     * as the one of the given object
     * 
     * @param otherLanguage The source bigram counter
     */
    void copy(const BigramCounter & other);

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position
     * @param row Row of the element 
     * @param column Column of the element
     * @return A const reference to the element at the given position
     */
    const int& operator()(int row, int column) const;

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position
     * @param row Row of the element 
     * @param column Column of the element
     * @return A reference to the element at the given position
     */
    int& operator()(int row, int column);
};

#endif /* BIGRAM_COUNTER_H */
