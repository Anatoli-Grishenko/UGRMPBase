/*
 * Metodología de la Programación: Language4
 * Curso 2022/2023
 */

/** 
 * @file Language.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
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
     * @brief It builds a Language object with "unknown" as
     * identifier, and a vector of @p numberBigrams pairs Bigram-frequency. 
     * Each pair will be initialized as "__" for the Bigram and 0 for the 
     * frequency.
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p numberBigrams <0
     * @param numberBigrams The number of bigrams to use in this Language
     */
    Language(int numberBigrams);
    
    /**
     * @brief Copy constructor
     * @param orig the Language object used as source for the copy
     */
    Language(const Language& orig);
    
    /**
     * @brief Destructor of class Language
     */
    ~Language();
    
    /**
     * @brief Overloading of the assignment operator for Language class
     * @param orig the Language object used as source for the assignment
     * @return A reference to this object
     */
    Language& operator=(const Language& orig);

    /**
     * @brief Returns the identifier of this language object
     * @return A const reference to the identifier of this language object
     */
    const std::string& getLanguageId() const;

    /**
     * @brief Sets a new identifier for this language object
     * @param id The new identifier 
     */
    void setLanguageId(const std::string& id);


    /**
     * @brief Gets a const reference to the BigramFreq at the given position 
     * of the vector in this object
     * @param index the position to consider
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A const reference to the BigramFreq at the given position
     */
    const BigramFreq& at(int index) const; 

    /**
     * @brief Gets a reference to the BigramFreq at the given position of the 
     * vector in this object
     * @param index the position to consider
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A reference to the BigramFreq at the given position
     */
    BigramFreq& at(int index); 

    /**
     * @brief Gets the number of BigramFreq objects 
     * @return The number of BigramFreq objects 
     */
    int getSize() const;
    
    /**
     * @brief Gets the distance between this Language object (\f$L_1\f$) and 
     * the given one @p otherLanguage (\f$L_2\f$).
     * The distance between two Languages \f$L_1\f$ and \f$L_2\f$ is 
     * calculated in the following way:
     * \f$d = \frac{ \sum_{bigram_i(L_1)} | rank_{bigram_i(L_1)}^{L_1} - 
     * rank_{bigram_i(L_1)}^{L_2} | }{size(L_1) * size(L_1)}\f$, 
     * where \f$bigram_i(L_j)\f$ is the bigram \f$i\f$ of the Language \f$L_j, 
     * j \in \{1, 2\}\f$ and \f$rank_{bigram_i(L_j)}^{L_k}\f$ is the ranking
     * of the bigram \f$i\f$ of the Language \f$L_j, j \in \{1, 2\}\f$ in the
     * Language \f$L_k\f$. 
     * The rank of a bigram is the position in which it
     * appears in the list of BigramFreq. We consider 0 as the 
     * first position (rank equals to 0). When calculating 
     * \f$rank_{bigram_i(L_1)}^{L_2}\f$, if the bigram \f$bigram_i(L_1)\f$ 
     * does not appears in the Language \f$L_2\f$ we consider that the rank
     * is equals to the size of Language \f$L_1\f$. 
     * @param otherLanguage A Language object
     * @pre The list of bigrams of this and otherLanguage should be ordered in 
     * decreasing order of frequency. This is not checked in this method.
     * @throw Throws a std::invalid_argument exception if the implicit object
     * (*this) is empty, that is, it does not have any bigram.
     * @return The distance between this Language object and the given 
     * one @p otherLanguage.
     */
    double getDistance(const Language& otherLanguage) const;

    /**
     * @brief Searchs the given bigram in the list of bigrams in this
     * Language. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the one of the first 
     * bigram in the list of bigrams and this->getSize()-1 the one of the last 
     * bigram
     * @param bigram A bigram 
     * @return If found, it returns the position where the bigram 
     * was found. If not, it returns -1
     */
    int findBigram(const Bigram& bigram) const;

    /**
     * @brief Obtains a string with the following content:
     * - In the first line, the language identifier of this Language
     * - In the second line, the number of bigrams in this Language 
     * - In the following lines, each one of the pairs bigram-frequency 
     * (separated by a whitespace).
     * @return A string with the number of bigrams and the list of pairs of
     * bigram-frequency in the object
     */
    std::string toString() const;

    /**
     * @brief Sort the vector of BigramFreq in decreasing order of frequency.
     * If two BigramFreq objects have the same frequency, then the alphabetical 
     * order of the bigrams of those objects will be considered (the object 
     * with a bigram that comes first alphabetically will appear first)
     * Modifier method
     */
    void sort();

    /**
     * @brief Saves this Language object in the given file
     * @param fileName A c-string with the name of the file where this Language 
     * object will be saved
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing
     * to the file
     */
    void save(const char fileName[]) const;

    /**
     * @brief Loads into this object the Language object stored in the given 
     * file
     * @param fileName A c-string with the name of the file where the Language 
     * will be stored. 
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * number of bigrams read from the given file is negative.
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while reading
     * from the file
     * @throw throw std::invalid_argument Throws a std::invalid_argument 
     * exception if an invalid magic string is found in the given file
     */
    void load(const char fileName[]);
    
    /**
     * @brief Appends a copy of the given BigramFreq to this Language object.
     * If the bigram is found in this object, then its frequency is increased
     * with the one of the given BigramFreq object. If not, a copy of the 
     * given BigramFreq object is appended to the end of the list of
     * BigramFreq objects in this Language.
     * @param bigramFreq The BigramFreq to append to this object
     */
    void append(const BigramFreq& bigramFreq);
    
    /**
     * @brief Appends to this Language object, the list of pairs  
     * bigram-frequency contained in the Language @p language. This
     * method uses the method append(const BigramFreq& bigramFreq) to
     * append the pairs bigram-frequency contained in the Language @p language
     * @param language A Language object 
     */
    void join(const Language& language);
      
private:
    std::string _languageId; ///< language identifier
    BigramFreq* _vectorBigramFreq; ///< Dynamic array of BigramFreq
    int _size; ///< Number of elements in _vectorBigramFreq
    static const std::string MAGIC_STRING_T; ///< A const string with the magic string for text files

    /**
     * @brief Sets the number of BigramFreq objects 
     * @param size The size to set in this object
     */
    void setSize(int size);
    
    /**
     * @brief Allocates new memory for the vector of BigramFreq with a size 
     * equals to @p nElements.
     * @param nElements The number of elements to allocate in the vector of 
     * BigramFreq
     */
    void allocate(int nElements);
    
    /** 
     * @brief 
     * Frees the memory allocated in this object and then allocates new memory
     * for a vector of BigramFreq of size equals to @p newSize. 
     * If the new capacity is less than before, then the last elements of the 
     * old vector are lost.
     * If the new capacity is greater than
     * before, then the old elements of the old vector are placed at the 
     * begining of the new vector, and the last elements in the new vector, are 
     * filled with empty object (objects created with the default constructor 
     * of  BigramFreq).
     * @param newSize The new capacity for the vector of BigramFreq
     */
    void reallocate(int newSize);

    /**
     * Frees the memory allocated in this object
     * @pre The pointer _vectorBigramFreq should point to an array in dynamic
     * memory, that was previously allocated
     */
    void deallocate();

    /**
     * Copies the elements in the dynamic array of BigramFreq of the given object
     * (otherLanguage) into this object. Also, the identifier is copied.
     * @pre The dynamic array of BigramFreq in this object must be at least of 
     * the same size as the one in the given object otherLanguage; otherwise
     * access to invalid memory positions could be done
     * @param otherLanguage
     */
    void copy(const Language& otherLanguage);
};

#endif /* LANGUAGE_H */