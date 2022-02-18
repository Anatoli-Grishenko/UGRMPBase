/**
 * @file main.cpp
 * @note To be completed by students 
 * @author MP-DGIM, MP-IADE, MP-II (grupo B)
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"

using namespace std;


/**
 * @brief It takes an histogram and transform it into an image
 * @param values The histogram. input parameter. height = 160 width = 256, foot_tone_c = 9, border = 1
 * @return The image of the histogram
 */
Image transformHistogram( int values[]);

/**
 * @brief It waits until the key [INTRO] [RETURN] is pressed
 */
void pressReturnToContinue();


int main() {
    Image flat(Byte::MAX_BYTE,Byte::MAX_BYTE), gradient(Byte::MAX_BYTE,Byte::MAX_BYTE), histogram;
    int values[Byte::MAX_BYTE]; // histogram vector


    flat.flatten(Byte(128));			// build  image
    flat.showInWindow("flat"); 		// display on window
    flat.getHistogram(values); 		// compute the histogram vector from the image
    histogram = transformHistogram(values);	// build the histogram image
    histogram.showInWindow("histoflat");	// display histogram
    INSPECT(flat);				// check image
    INSPECT(histogram);
    
    for (int x = 0; x < gradient.width(); x++)
        for (int y = 0; y < gradient.height(); y++)
            gradient.setPixel(x, y, ((x + y)*255) / (255 + 255));
            
    gradient.showInWindow("gradient");
    gradient.getHistogram(values);
    histogram = transformHistogram(values);
    histogram.showInWindow("histograd");
    INSPECT(gradient);
    INSPECT(histogram);
    pressReturnToContinue();
    return 0;
}

void pressReturnToContinue() {
    char aux[10];
    cout << "Press [RETURN] to continue ...";
    cin.getline(aux, 1, '\n');
}

     /**
     *   @brief It takes an histogram and transform it into a new image with the
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
     * width = 256, height = 160, border = 1, foot_tone = 9
     * width X height segmented in two parts: width X (foot_tone+1) (foot) and width X a, where a = height -(border+foot_tone)-2
  
     * @param values The histogram. input parameter. 
     * @brief It takes the histogram of the image and depicts
     * @return The image of the histogram
     */
Image transformHistogram( int values[]) {
    int width = 256, height = 160, border = 1, foot_tone = 9, a = height -(border+foot_tone)-2;

    Image result(width, height);
    
    // compute max
    // build white image

    for (int x = 0; x <256; x++) {
    
    	// compute the relative point from which the pixel is black on the image
    	// set the pixel
    	
        for (int y = 0; y < foot_tone; y++) { // the foot tone in the image
            result.setPixel(x, height-border-y, x);
        }
 
    }
    return result;
}
