/**
@file Image.h
@brief Second version of class Image for management of black and white images in PGM format
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
    static const int IMAGE_MAX_SIZE=200000; ///< Max number of bytes allowd for
    static const int IMAGE_DISK_OK=0; ///< Image read/write successful
    static const int IMAGE_ERROR_OPEN=1; ///< Error opening the file
    static const int IMAGE_ERROR_DATA=2; ///< Missing data in the file
    static const int IMAGE_ERROR_FORMAT=3; ///< Unknown image format
    static const int IMAGE_TOO_LARGE=4; ///< The image is too large and does not fit into memory
    
    
    /**
     * @brief It builds an empty, image. Modifier method
     */
    Image();
    /**
     * @brief It builds a fully black image with @a width columns and @a height rows. Modifier method
     * @param height number of rows. input param
     * @param width number of columns. input param
     */
    Image(int width, int height);
    /**
    @brief It gives the number of rows of the image. Query method
    @return number of rows
     */
    int height() const;
    /**
    @brief It gives the number of columns of the image. Query method
    @return The number of rows
     */
    int width() const;
    /**
     * @brief It assigns the value @a v to the position(x,y) of the image.It must check that
     * the values x and y are valid, otherwise, it does not do anything. Modifier method
     * @param x The column
     * @param y the row
     * @param v The new value
     */
    void setPixel(int x, int y, Byte v);
    /**
     * @brief It returns the value of the requested (x,y) position. It must check that
     * the values x and y are valid, otherwise, it returns a negative value. Please note that
     * the value returned is a int. Query method
     * @param x The column. input param
     * @param y the row. input param
     * @return The value of the pixel in [0-256] or -1 if there is an access error
     */
    int getPixel(int x, int y) const;
    /**
     * @brief It assigns the value @a v to the linear position i of the image. It must check that
     * the values i is valid, otherwise, it does not do anythig. Modifier method
     * @param i The linear position. input param
     * @param v The new value. input param
     */
    void setPos(int i, Byte v);
    /**
     * @brief It returns the value of the requested linear position. It must check that
     * the value i is valid, otherwise, it returns a negative value. Please note that
     * the value returned is a int. Query method
     * @param i The linear position
     * @return The value of the pixel in [0-256] or -1 if there is an access error
     */
    int getPos(int i) const;
    /**
     * @brief  It sets all pixels of the image to the value given. Modifier method
     * @param b The value
     */
    void flatten(Byte b);
    /**
     * @brief It produces a mesh of vertical and horizontal stripes all along the
     * image. Every prim pixels it is set to 255 anad every sec pixels
     * it is set to 127
     * @param prim Gap between primary mesh
     * @param sec Gap between secondary mesh, Default value is 0
     */
    void mesh(int prim, int sec=0);

    /**
     * @brief It shows an image in an external window, ready for inspection. It uses
     * the program display (ImageMagick) to display every image. For an easier identification 
     * process of all images shown are labeled with a title. Query method
     * @param title The title on top of the window. input param
     */
    void showInWindow(std::string title) const;
    /**
     * @brief It calculates the hash value of the image and returns it inside a string,
     * together with its dimension. Query method
     * @param binary Its default value is true and then it shows the hash code of the image
     * otherwise (false) it shows its values as a string
     * @return a string that contains the dimension and the hash value of the image
     */
    std::string inspect() const;

    /**
     * @brief It opens a file that contains a PGM Image and reads the data into
     * a iname in memmory. Modifier method
     * @param filename Name of the file. input param
     * @return a code that means the following: 0 - Successful operation. 
     * 1 - Error opening the file
     * 2 - Error reading the data
     * 3 - The detected data does not follow the PGM techincal description
     */
    int readFromFile(const char filename[]);
    
    /**
     * @brief It writes the Image on disk, in PGM ascii format. Query method
     * @param filename The name of the disk file which will contain the image. input param
     * @return The same code that readFromFile()
     */
    int saveToFile(const char filename[]) const;
    /**
     * @brief It calculates the histogram of the image, and returns it into an
     * instance of the class Histogram. Query method
     * @param values
     */
    Histogram getHistogram() const;
    /**
     * @brief It takes the histogram of the image and depicts a new image with the
     * visualization of the histogram according to these rules 
     * ~~~~
     *   +-     +-----------------------------o 
     *   |      |                             | --- 1 pix white line
     *   |      |   *                         | -+
     *   |      |   **                        |  |
     *   |      |   **                        | 
     *   |      |   ***                   *   |   Normalized histogram
     *          |   ***                  **   |     150 pix
     *   h=160  |   ****    *            **   |  |
     *          |   *****  ***          ****  |  |
     *   |      |  ************************** | -+
     *   |      |-----------------------------|  1 pix  white line
     *   |      |-----------------------------| -+
     *   |      |                             |  8 pix Scale of gray levels
     *   +-     o-----------------------------+ -+
     *
     *          |                             |
     *          +--------- w  = 256 ----------+
     * ~~~~
     * Query method
     * @return 
     */
    Image depictsHistogram() const;
    
    /**
     * @brief It segments the histogram by groups whose value is higher than the admitted tolerance and returns
     * an array of images, each of which corresponds to one of these objects. Query method
     * Given the following histogram, cut by the tolerance level. The method find 4 groups.
     * ~~~~
     *   +-     +-----------------------------o 
     *   |      |                             | --- 1 pix white line
     *   |      |   *                         | -+
     *   |      |   **                        |  |
     *   |      |   **                        | 
     *   |      |   ***                   *   |   Normalized histogram
     *          |   ***                  **   |     150 pix
     *   h=160  |   ****    *            **   |  |
     *          |   *****  ***          ****  |  |
     *   |      |  ******  ***   *     ****** | -+
     *   |      |-----------------------------|  tolerance level 
     *   |      |-----------------------------| -+
     *   |      |-----------------------------| -+                        
     *   +-     o-----------------------------+ -+
     *          |                             |
     *          +--------- w  = 256 ----------+
     * ~~~~
     * @param set The array of images. input/out param
     * @param nimages The number of images found. output param
     * @param maximages The max number of images to be found. input param
     * @param tolerance The tolerance admitted. input param
     */
    void extractObjects(Image set [], int &nimages, int maximages, double tolerance=Histogram::HISTOGRAM_TOLERANCE) const;
    /**
     * It returns a binarization of the original image. All pixels  strictly greater than the value @a t
     * are set to 11111111 and the others to 00000000. Query method.
     * @param t The threshold. This value must be within [0,255]. In the case 
     * that the threshold is not within these bounds, an automatic threshold is chosen,
     * that is, the first level that leaves, at least the half of points less that
     * or equal to it
     * @return A copy of the original image
     */
    Image threshold(int t = -1) const;
    /**
     * @brief It returns a subimage of the original image given by the parameters.
     * If the parameters exceed  the dimensions of the original image, then 
     * the cut image should not exceed those limits. Query method
     * @param x x-coordinate of the top left corner. input param
     * @param y y-coordinate of the topt left corner. input param
     * @param w width of the subimage. input param
     * @param h height of the subimage. input param
     * @return The subimage cut
     */
    Image copyArea(int x, int y, int w, int h) const;
   
    /**
     * @brief It pastes a secondary image into the original image, at the given position,
     * into the same original image, which results modified. 
     * This operation should maintain the limits of the original image. Modifier method.
     * @param x x-coordinate of the top left corner. input param
     * @param y y-coordinate of the topt left corner. input param
     * @param from The second image. input param
     * @param toneup value. input param
     * @param merge value for the combination of the 2 images. input param
     */
    void pasteArea(int x, int y, const Image &from, int toneup=-1, int merge=100);
    
   /**
    @brief Destroyes the object and frees the memory. Modifier method.
     */
    ~Image();
    /**
     * @brief Copy constructor. Creates a new Image, copying or duplicating an existing one. Modifier method.
     * @param from the image to duplicate. input param.
     */
    Image(const Image & from);
    
    /**
     * @brief Assignment operator. Modifier method
     * @param rhs The right hand side of the assignment expresion. input param
     * @return The new instance returned by reference.
     */
    Image & operator=(const Image &rhs);
     /**
     * @brief It zooms the image in. Query method
     * @return The zoomed image
     */
    Image zoomIn() const;
    /**
     * @brief Ti zooms the image out. Query method
     * @return The zoomed image
     */
    Image zoomOut() const;
private:
    Byte * _data; ///< Bytes of the image
    int _height; ///< number of rows
    int _width; ///< number of columms
    
    /**
     * @brief It frees the allocated memory. Modifier method.
     */
    void clear();

    /**
     * @brief It copies an existing image into this one, resizing it accordingly. Modifier method.
     * @param rhs The source Image to copy from. Input parameter 
     */
    void copy(const Image &rhs);

    /**
     * @brief it resizes the Image to a new number of rows and columns, clearing
     * the previously existing data. Modifier method.
     * @param newheight value. intput param
     * @param newwidth value. intput param
     */
    void setSize(int , int );
};
#endif

