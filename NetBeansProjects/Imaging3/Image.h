/**
@file Image.h
@brief First class for management of black and white images in PGM format
@note To be implemented by students. Revise the prototype declaration in order 
 * to respect the condition for a correct communication among modules (input/output parameters as copy/ reference parameters...)
@author MP-DGIM, MP-IADE, MP-II (grupo B) 
 **/
 
 /// Addtional methods
 
     /**
      * It returns a binarization of the original image. All pixels  strictly greater than the value @a t
      * are set to 11111111 and the others to 00000000. Query method.
      * @param t The threshold. This value must be within [0,255]. In the case 
      * that the threshold is not within these bounds, an automatic threshold is chosen,
      * that is, the first level that leaves, at least the half of points less that
      * or equal to it. Input parameter, default value is set to -1.
      * @return A copy of the original image
      */
     Image threshold(int t = -1);
     /**
      * @brief It returns a subimage of the original image given by the parameters.
      * If the parameters exceed  the dimensions of the original image, then 
      * the cut image should not exceed those limits. Query method.
      * @param x x-coordinate of the top left corner.
      * @param y y-coordinate of the topt left corner
      * @param w width of the subimage
      * @param h height of the subimage. x,y,w, are input parameters.
      * @return The subimage cut
      */
     Image copyArea(int x, int y, int w, int h);
    
     /**
      * @brief It pastes a secondary image into the original image, at the given position,
      * into the same original image, which results modified. 
      * This operation should maintain the limits of the original image
      * @param x x-coordinate of the top left corner. input param
      * @param y y-coordinate of the topt left corner. input param
      * @param from The second image. input param
      * @param toneup value. input param
      * @param merge value for the combination of the 2 images. input param
      */
     void pasteArea(int x, int y, Image from, int toneup=-1, int merge=100);

 
 
 
 
