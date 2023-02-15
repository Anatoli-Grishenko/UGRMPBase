/*
 * Metodolog�a de la Programaci�n: Language3
 * Curso 2022/2023
 */

/** 
 * @file Language.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andr�s Cano Utrera <acu@decsai.ugr.es>
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
 * @brief It defines a model for a given language. It contains a vector a pairs
 * Bigram-frequency (objects of the class BigramFreq) and an identifier 
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
     * @brief Sort the vector of BigramFreq in decreasing order of frequency.
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
     * @brief Loads the Language object stored in the given file into this
     * object. 
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
     * @brief Appends a copy of the given BigramFreq to this Language object.
     * If the bigram is found in this object, then its frequency is increased
     * with the one of the given BigramFreq object. If not, a copy of the 
     * given BigramFreq object is appended to the end of the list of
     * BigramFreq objects in this Language.
     * Modifier method
     * @param bigramFreq The BigramFreq to append to this object. Input parameter
     */
    void append(BigramFreq bigramFreq);
    
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
     * @brief Appends to this Language object, the list of pairs  
     * bigram-frequency contained in @p language. 
     * Modifier method
     * @param language A Language object. Input parameter
     */
    void join(Language language);
    
    /**
     * @brief Gets the distance between this Language object and the given 
     * one @p otherLanguage.
     * The distance between two Languages \\f$L_1\f$ and \f$L_2\f$ is 
     * calculated in the following way:
     * \f$d = \sum_{bigram(L_1)_i} \frac{\abs{rank_{bigram(L_1)_i}^{L_1} - 
     * rank_{bigram(L_1)_i}^{L_2}}}{size(L_1) * size{L_1}}\f$, 
     * where \f$bigram(L_j)_i\f$ is the bigram \f$i\f$ of the Language \f$L_j, 
     * j \in \{1, 2\}\f$ and \f$rank_{bigram(L_j)_i}^{L_k}\f$ is the ranking
     * of the bigram \f$i\f$ of the Language \f$L_j, j \in \{1, 2\}\f$ in the
     * Language \f$L_k\f$.
     * Query method
     * @param otherLanguage A Language object. Input parameter
     * @pre The list of bigrams of this and otherLanguage should be ordered in 
     * decreasing order of frequency. This is not checked in this method.
     * @return The distance between this Language object and the given 
     * one @p otherLanguage.
     */
    double getDistance(Language otherLanguage);
    
    
private:
    static const int DIM_VECTOR_BIGRAM_FREQ = 2000; ///< The capacity of the array _vectorBigramFreq
    std::string _languageId; ///< language identifier
    BigramFreq _vectorBigramFreq[DIM_VECTOR_BIGRAM_FREQ]; ///< array of BigramFreq
    int _size; ///< Number of elements in _vectorBigramFreq
    static const std::string MAGIC_STRING_T; ///< A const string with the magic string for text files
};

#endif /* LANGUAGE_H */