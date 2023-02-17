/*
 * Metodología de la Programación: Práctica final
 * Curso 2022/2023
 */

/** 
 * @file Bigram.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#ifndef BIGRAM_H
#define BIGRAM_H

#include <iostream>
#include <string>

/**
 * @class Bigram
 * @brief It represents a pair of characters. It is used to store pairs of 
 * consecutive characters from a text. 
 * It uses a string to store the pair of characters
 */
class Bigram {
public:
    /**
     * @brief Base constructor. It builds a Bigram object with "__" as the 
     * text of the bigram
     */
    //Bigram();
    
    /**
     * @brief It builds a Bigram object with @p text as the 
     * text of the bigram. If the string @p text contains a number of character 
     * other than two, then the text of the bigram will be initialized with
     * "__"
     * 
     * @param text the text for the bigram. It should be a string with just two
     * characters.
     */
    Bigram(const std::string& text="__");
    
    /**
     * @brief It builds a Bigram object using the two characters passed as
     * parameters of this constructor as the text of the bigram
     * 
     * @param first the first character for the bigram
     * @param second the second character for the bigram
     */
    Bigram(char first, char second);
    
    /**
     * @brief It builds a Bigram object with @p text (a c-string) as the 
     * text of the bigram. If the c-string @p text contains a number of character 
     * other than two, then the text of the bigram will be initialized with
     * "__"
     * 
     * @param text the text for the bigram
     */
    Bigram(const char* text);

    /**
     * @brief Obtains a copy of the text of this bigram as a string object
     * @return the text of this bigram as a string object
     */
    std::string getText() const;
    
    /**
     * @brief Obtains a copy of the text of this bigram as a string object
     * @return the text of this bigram as a string object
     */
    std::string toString() const;
    
    /**
     * @brief Gets the character at the given position
     * @param index the position to consider
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * index is not equals to 1 or 2
     * @return the character at the given position
     */
    const char& at(int index) const;
    
    /**
     * @brief Gets the character at the given position
     * @param index the position to consider
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * index is not equals to 1 or 2
     * @return the character at the given position
     */    
    char& at(int index);

    /**
     * @brief Overloading of the [] operator for Bigram class
     * @param index index of the element (character)
     * @return The character at position @p index
     */
    const char& operator[](int index) const;

    /**
     * @brief Overloading of the [] operator for Bigram class
     * @param index index of the element (character)
     * @return The character at position @p index
     */
    char& operator[](int index);
    
    friend std::ostream& operator<<(std::ostream& os, const Bigram& bigram);
    friend std::istream& operator>>(std::istream& is, Bigram& bigram);
    friend bool operator==(const Bigram& bigram1, const Bigram& bigram2);
    
private:    
    /**
     * The text in this Bigram. Should be a string with two characters
     */
    std::string _text;
};

/**
 * @brief Overloading of the stream insertion operator for Bigram class
 * @param os The output stream to be used
 * @param bigram the Bigram object
 * @return @p os the output stream
 */
std::ostream& operator<<(std::ostream& os, const Bigram& bigram);

/**
 * @brief Overloading of the stream extraction operator for Bigram class
 * @param is The input stream to be used
 * @param bigram the Bigram object
 * @return @p is the input stream
 */
std::istream& operator>>(std::istream& is, Bigram& bigram);


/**
 * @brief Overloading of the operator == for Bigram class
 * @param bigram1 a Bigram object
 * @param bigram2 a Bigram object
 * @return true if the two bigrams contains the same text, false otherwise
 */
bool operator==(const Bigram& bigram1, const Bigram& bigram2);

/**
 * Checks if the given character is contained in @p validCharacters. That is, if
 * the given character can be consireded as part of a word.
 * @param character The character to check
 * @param validCharacters The set of characters that we consider as possible 
 * characters in a word. Any other character is considered as a separator.
 * @return true if the given character is contained in @p validCharacters; false
 * otherwise
 */
bool isValidCharacter(char character, const std::string& validCharacters);

#endif /* BIGRAM_H */

