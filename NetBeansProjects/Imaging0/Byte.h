/**
@file Byte.h
@brief Operaciones a nivel de bit
@author MP-DGIM - Grupo A
  */
  
  /**
  Repasar paso de parámetrs, por valor, por referencia, por referencia constante
  */

#ifndef _BYTE_H_
#define	_BYTE_H_

typedef unsigned char Byte; ///< A @c Byte contains the state of  8 Bits

#define MAX_BYTE 256 ///< Max number of values allowed
#define MAX_BYTE_VALUE 255 ///< Highest value allowed
#define MIN_BYTE_VALUE 0 ///< Lowest value allowed
#define NUM_BITS 8 ///< Number of bits
#define MIN_BIT 0 ///> Rightmost bit
#define MAX_BIT 8 ///> Leftmost bit
/**
@brief Turns on the @p position bit of @c Byte @p b, whenever the value of pos is in [0..7] otherwise
 * Byte remains unchanged.
@param b 	the @c Byte, output parameter
@param pos 	 the position @p b of the bit within the Byte (0 means the rightmost position)
*/
void onBit(Byte b, int pos);

/**
@brief Turns off the @p position bit of @c Byte @p b, , whenever the value of pos is in [0..7] otherwise
 * Byte remains unchanged.
@param b 	the @c Byte, output parameter
@param pos 	 the position @p b of the bit within the Byte (0 means the rightmost position)
*/
void offBit(Byte b, int pos);

/**
@brief It returns the state of a certain bit inside a Byte (on = true, off = false) at the position @p pos
@param b 	the @c Byte
@param pos 	 the position @p b of the bit within the Byte (0 means the rightmost position)
@retval true 	when the bit at the @p pos position is 1
@retval false	when the bit at the @p pos position is 0
*/
bool getBit(Byte b, int pos);


/**
@brief It returns a string with a sequence of 0 and 1 corresponding to the state of each bit. For instance,
 * the value 5 is represented as "00000101" since the bits 0 and 2 are set to 1
*/
std::string to_string(Byte b);

/**
@brief Turns all the bytes on
@param b 	the @c Byte
*/
void onByte(Byte b);

/**
@brief Turns all the bytes off
@param b 	the @c Byte
*/
void offByte(Byte b);

/**
@brief Turns on just the bits contained in the vector. That is, if vector[i] is true,
 * then the bit at the position @a i is turned on.
@param b 	the @c Byte
@param v A vector of 8 elements representing which bits are to be turned on. b output parameter
*/
void encodeByte(Byte b,  bool v[]);

/**
@brief It dumps the bits in the Byte into the vector, such as, if bit @a i is 1, then vector[i] is true
@param b 	the @c Byte
@param v A vector of 8 elements representing which bits are turned on. v output parameter
 */
void decodeByte(Byte b, bool v[]);

/**
@brief It returns a vector of int, such that if vector[i]=k, then the bit at the position @a k is 1
@param b 	the @c Byte
@param posits An array of positions that contains a bit set to 1, output parameter. 
@param n Number of bits 1 in the byte. output parameter.
*/
void decomposeByte(Byte b, int posits[], int &n);

/**
 * @brief Shifts the byte @a n bits to the right, overflowing the rightmost bits
 * @param b The byte
 * @param n The number of shifts
 */
void shiftRByte(Byte b, int n);

/**
 * @brief Shifts the byte @a n bits to the left, overflowing the leftmost bits
 * @param b The byte
 * @param n The number of shifts
 */
void shiftLByte(Byte b, int n);

/**
 * @brief It merges the byte @a merge into the byte @a carrier following
 * a linear combination carrier = (carrier *(100-percentage)+merge*percentage)/100
 * @param carrier The byte to absorb the merge
 * @param merge The byte to merge
 * @param percentage A value [0,100]
 */
void mergeByte(Byte carrier, Byte merge, int percentage);

#endif

