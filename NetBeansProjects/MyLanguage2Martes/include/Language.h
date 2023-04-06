/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/** 
 * @file Language.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#ifndef LANGUAGE_H
#define LANGUAGE_H


#include <iostream>
#include "BigramFreq.h"

/**
 * @class Language
 * @brief It defines a model for a given language. It contains a vector of 
 * pairs Bigram-frequency (objects of the class BigramFreq) and an identifier 
 * (string) of the language. 
 */
class Language {
public:

    /**
     * @brief Base constructor. It builds a Language object with "unknown" as
     * identifier, and an empty vector of pairs Bigram-frequency. 
     */
    Language();

    /**
     * @brief It builds a Language object with "unknow" as
     * identifier, and a vector of @p numberBigrams pairs Bigram-frequency. 
     * Each pair will be initialized as "__" for the Bigram and 0 for the 
     * frequency.
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p numberBigrams > @p DIM_VECTOR_BIGRAM_FREQ or numberBigrams<0
     * @param numberBigrams The number of bigrams to use in this Language.
     * Input parameter
     */
    Language(int numberBigrams);

    /**
     * @brief Returns the identifier of this language object. 
     * Query method.
     * @return A const reference to the identifier of this language object.
     */
    std::string getLanguageId();

    /**
     * @brief Sets a new identifier for this language object. 
     * Modifier method.
     * @param id The new identifier. Input parameter 
     */
    void setLanguageId(std::string id);


    /**
     * @brief Gets a const reference to the BigramFreq at the given position 
     * of the vector in this object. 
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A const reference to the BigramFreq at the given position
     */
    BigramFreq at(int index); 

    /**
     * @brief Gets a reference to the BigramFreq at the given position of the 
     * vector in this object. 
     * Query and modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A reference to the BigramFreq at the given position
     */
    BigramFreq at(int index); 

    /**
     * @brief Gets the number of BigramFreq objects. 
     * Query method
     * @return The number of BigramFreq objects
     */
    int getSize();
    
    /**
     * @brief Searchs the given bigram in the list of bigrams in this
     * Language. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the one of the first 
     * bigram in the list of bigrams and this->getSize()-1 the one of the last 
     * bigram.
     * Query method
     * @param bigram A bigram. Input parameter
     * @pre The list of bigrams should be ordered in decreasing order of
     * frequency. This is not checked in this method. 
     * @return If found, it returns the position where the bigram 
     * was found. If not, it returns -1
     */
    int findBigram(Bigram bigram);

    /**
     * @brief Obtains a string with the following content:
     * - In the first line, the number of bigrams in this Language 
     * - In the following lines, each one of the pairs bigram-frequency 
     * (separated by a whitespace).
     * Query method
     * @return A string with the number of bigrams and the list of pairs of
     * bigram-frequency in the object
     */
    std::string toString();

    /**
     * @brief Sort the vector of BigramFreq in decreasing order of frequency.
     * If two BigramFreq objects have the same frequency, then the alphabetical 
     * order of the bigrams of those objects will be considered (the object 
     * with a bigram that comes first alphabetically will appear first)
     * Modifier method
     */
    void sort();

    /**
     * @brief Saves this Language object in the given file. 
     * Query method
     * @param fileName A c-string with the name of the file where this Language 
     * object will be saved. Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing
     * to the file
     */
    void save(char fileName[]);

    /**
     * @brief Loads into this object the Language object stored in the given 
     * file
     * Modifier method
     * @param fileName A c-string with the name of the file where the Language 
     * will be stored. Input parameter
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * number of bigrams in the given file, cannot be allocated in this Language
     * because it exceeds the maximum capacity
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while reading
     * from the file
     * @throw throw std::invalid_argument Throws a std::invalid_argument if
     * an invalid magic string is found in the given file
     */
    void load(char fileName[]);
    
    /**
     * @brief Appends a copy of the given BigramFreq to this Language object.
     * If the bigram is found in this object, then its frequency is increased
     * with the one of the given BigramFreq object. If not, a copy of the 
     * given BigramFreq object is appended to the end of the list of
     * BigramFreq objects in this Language.
     * @thow std::out_of_range Throws a std::out_of_range exception in case
     * that a new element must be appended to the end of the array and the
     * number of elements in the array of BigramFreq is equals to the capacity
     * of that array. In that case, the array is full, and no more elements
     * can be appended to the array.
     * Modifier method
     * @param bigramFreq The BigramFreq to append to this object. Input parameter
     */
    void append(BigramFreq bigramFreq);
    
    /**
     * @brief Appends to this Language object, the list of pairs  
     * bigram-frequency objects contained in the Language @p language. This
     * method uses the method append(BigramFreq bigramFreq) to
     * append the pairs bigram-frequency contained in the Language @p language
     * Modifier method
     * @param language A Language object. Input parameter
     */
    void join(Language language);
    
private:
    static const int DIM_VECTOR_BIGRAM_FREQ = 2000; ///< The capacity of the array _vectorBigramFreq
    std::string _languageId; ///< language identifier
    BigramFreq _vectorBigramFreq[DIM_VECTOR_BIGRAM_FREQ]; ///< array of BigramFreq
    int _size; ///< Number of elements in _vectorBigramFreq
    static const std::string MAGIC_STRING_T; ///< A const string with the magic string for text files
};

#endif /* LANGUAGE_H */