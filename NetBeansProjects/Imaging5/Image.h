/**
@file Image.h
@brief Third version of class Image for management of black and white images in PGM format
@note To be implemented by students. Revise the prototype declaration in order 
 * to respect the condition for a correct communication among modules (input/output parameters as copy/ reference parameters...)
@author MP-DGIM, MP-IADE, MP-II (grupo B) 
 **/

#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <istream>
#include <fstream>
#include "Byte.h"
#include "Histogram.h"

/**
@brief A black and white image
 */
class Image {
public:
      static const int IMAGE_MAX_SIZE=300000; ///< Max number of bytes allowd for
      
// .......

    /**
     * @brief It seeks for a hidden image in plane k. In order to do that, it
     * must first check that the first letters match the cookieImage constant. 
     * If it does not, it must return false since it is not possible. Otherwise,
     * the next bytes contain the width and height of the image, values in [0..255]. Finally the following 
     * width*height bytes encode the content of the hidden image, returned as a result. Query method
     * @param k The plane. input param
     * @param result The found image. output param
     * @return True when a valid image is found, false otherwise
     */
    bool showImage(int k, Image &result) const;
    
    /**
     * @brief It hides the image @a from by encoding the sequence of values of its pixels
     * into the bits of plane @a k. In order to do that, it first hides the cookieImage constant
     * to identify this plane as containing an image. Then it hides the width and the height. Then
     * all the bytes from left to right and top down. The self image is modified. Modifier method.
     * @param k The plane. input param
     * @param from The image to hide. input param
     * @return  It return true if the process is successful, false otherwise. 
     */
    
    bool hideImage(int k, const Image &from);
    /**
     * @brief Steganography process.
     * It hides the cstring given within the k-plane especified. If no
     * plane is specified, the 0-plane is considered. If the cstring is too
     * large given the size of the original image, it must return false. Otherwise
     * the image hides the cstring and it returns true. In order to do that, it first
     * hides the cookieText constant, then the content of the cstring and finally,
     * the \0 delimiter converted in 00000000 encoded into the image. Modifier method.
     * @param the cstring to hide. input param
     * @param k the k-plane. input param
     * @return true if it has been possible, false otherwise
     */
    
    bool hideText(const char source [], int k=0);
    
    /**
     * @brief It checks that the k-plane contains a cstring if the first bytes 
     * of the image contains the cookieText constant. Afterwards, all the bytes
     * encided in plane k are extracted and the final one must be the \0 delimiter
     * @param hidden cstring to return the hidden string, if any
     * @param max size of the cstring, without including the \0 delimiter
     * @param k The plane
     * @return True if success, false otherwise.
     */
    bool showText(char hidden [], int max, int k =0) const;    
private:
    Byte ** _data; ///< Bytes of the image
    int _height; ///< number of rows
    int _width; ///< number of columms
    
// .......

    /**
     * @brief It copies an existing image into this one, resizing it accordingly
     * @param rhs The source Image to copy from
     */
    void copy(const Image &rhs);

    /**
     * @brief it resizes the Image to a new number of rows and columns, clearing
     * the previously existing data
     * @param 
     * @param 
     */
    void setSize(int , int );
};
#endif

