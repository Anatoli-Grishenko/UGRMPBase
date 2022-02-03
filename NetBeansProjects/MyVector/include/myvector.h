/**
 * @file myvector.h
 * @author DECSAI
  */

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <string>

/**
 * @class MyVector
 * @brief Class to represent a sequence of letters in a static vector, by using 
 * an intenger value to mark the end of the used part of that vector,
 * therefore, it must be set to zero (0) since the beginning.
 */

/// Max size of the static vector
#define MAXVECTOR 10 
/// Terminator f the sequecne
#define ENDCHAR (char) '@' 
/// Used to mark empty spaces in the vector
#define EMPTYCHAR (char) '.' 
/// Used to higlight operations with an empty result
#define NOCHAR (char) '\0' 

class MyVector {
private:
    /// Static vector used to store the letters
    char letters[MAXVECTOR]; 
    /// Number of letters stored
    int nletters; 
public:
   
    /**
     * Main Constructor. 
     */
    MyVector();
    /**
     * Gives the number of chars stored in the vector
     * @return The number of chars, that is, @a nletters
     */
    int size() const;
    
    /**
     * Add a letter at the end of the sequence already stored, whenever there is 
     * available room for it
     * @param letter The char to be added at the end of the vector.
     */
    void addLetter(char letter);    
    /**
     * This method resets the storage to zero (0)
     */
    void clear();
    /**
     * If @a pos is a valid position, that is, 0<= pos < size(), it returns the 
     * char stored in that position
     * @param pos The position of the stored char that is queried
     * @return The char at that position. If the @position is not valid, it 
     * returns the empty char '\0'
     */
    char getLetter(int pos) const;    
    /**
     * It sets the char stored in the specified position, whenever this position 
     * is a valid one. Otherwise, the sequence will remain unchanged
     * @param pos The position that is to be updated
     * @param letter The new letter to be inserted at that position
     */
    void setLetter(int pos, char letter);
    /**
     * Transform the sequence of chars into a standar string
     * @return The string that is equivalent to the sequence of letters stored
     */
    std::string to_string() const;
    /**
     * Serialization of the class for testing purposes
     * @return a string which contains the size and chars stored
     */
    std::string reportData() const;
    
};

#endif /* MYVECTOR_H */

