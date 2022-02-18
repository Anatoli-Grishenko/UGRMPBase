/**
@file Byte.h
@brief Operators for bit level
@note To be implemented by students 
@author MP-DGIM, MP-IADE, MP-II (grupo B)
 */

#ifndef _BYTE_H_
#define _BYTE_H_

/**
 * @brief Encapsulated representation of a byte and its associated operations
 */
class Byte {
private:
    unsigned char _data; ///< A @c Byte contains the state of  8 Bits
public:

    static const int MAX_BYTE = 256; ///< Max number of values allowed
    static const Byte MAX_BYTE_VALUE; ///< Highest value allowed
    static const Byte MIN_BYTE_VALUE; ///< Lowest value allowed
    static const int NUM_BITS = 8; ///< Number of bits
    static const int MIN_BIT = 0; ///< Rightmost bit
    static const int MAX_BIT = 8; ///< Leftmost bit

    /**
     * @brief Base constructor. Modifier method.
     */
    Byte() {
        _data = 0;
    }

    /**
     * @brief Constructor with parameters. Modifier method.
     * @param value The initial value
     */
    Byte(int value) {
        _data = (unsigned char) value;
    }

    /**
     * @brief It returns the real value of the byte. Query method.
     * @return The value
     */
    inline int getValue() const { return (int) _data;}
    
    /**
     * @brief It sets a new value. Modifier method.
     * @param v The new value
     * @return  The new instance with the new value
     */
    inline void setValue(unsigned char v){_data=v;}

    /**
    @brief Turns on the bit at plane @a pos, whenever the value of pos is in [0..7] otherwise
     *  Byte remains unchanged.  (0 means the rightmost position). Modifier method.
    @param pos 	 the position @p b of the bit within the Byte
     */
    void onBit(int pos);

    /**
    @brief Turns off the bit at plane @a pos, whenever the value of pos is in [0..7] otherwise
 * Byte remains unchanged.  (0 means the rightmost position). Modifier method.
    @param pos 	 the position @p b of the bit within the Byte
     */
    void offBit(int pos);

    /**
    @brief It returns the state of a certain bit inside a Byte (on = true, off = false) at the position @p pos.  Query method.
    @param pos 	 the position @p b of the bit within the Byte (0 means the rightmost position).
    @retval true 	when the bit at the @p pos position is 1
    @retval false	when the bit at the @p pos position is 0
     */
    bool getBit(int pos) const;


    /**
    @brief It returns a string with a sequence of 0 and 1 corresponding to the state of each bit. For instance,
     * the value 5 is represented as "00000101" since the bits 0 and 2 are set to 1.  Query method.
     */
    std::string to_string() const;

    /**
    @brief Turns all the bits on. Modifier method.
     */
    void onByte();

    /**
    @brief Turns all the bits off. Modifier method.
     */
    void offByte();

    /**
    @brief Turns on just the bits contained in the vector. That is, if vector[i] is true,
    then the bit at the position @a i is turned on. Modifier method.
    @param v A vector of 8 boolean elements representing which bits are to be turned on
     */
    void encodeByte(const bool v[]);

    /**
    @brief It dumps the bits in the Byte into the vector, such as, if bit @a i is 1, then vector[i] is true. Query method.
    @param v A vector of 8 elements representing which bits are turned on
     */
    void decodeByte(bool v[]) const;

    /**
    @brief It returns a vector of int, such that if vector[i]=k, then the bit at the position @a k is 1. Query method.
    @param posits An array of positions that contains a bit set to 1, output parameter.
    @param n Number of bits 1 in the byte. output parameter.
     */
    void decomposeByte(int posits[], int &n) const;

    /**
     * @brief Shifts the byte @a n bits to the right, overflowing the rightmost bits. Modifier method.
     * @param n The number of shifts
     */
    void shiftRByte(int n);

    /**
     * @brief Shifts the byte @a n bits to the left, overflowing the leftmost bits. Modifier method.
     * @param n The number of shifts
     */
    void shiftLByte(int n);

    /**
     * @brief It merges the byte @a merge into the existing byte following
     * a linear combination _data = (_data *(100-percentage)+merge*percentage)/100. Modifier method.
     * @param merge The byte to merge
     * @param percentage A value [0,100]
     */
    void mergeByte(Byte merge, int percentage);
};

#endif
