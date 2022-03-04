
//#define __WINDOWS__
#define __TDD__


#ifndef MPTOOLS_H
#define MPTOOLS_H

#ifdef __WINDOWS__
    #define SLASH (std::string) "\\"
    #define CVAL std::clog 
    #define INSPECT(VAR) CVAL << std::endl<< "["<<#VAR<<"] "<< VAR.inspect() << std::endl;
#else
    #define SLASH (std::string) "/"
    #ifdef __TDD__
        #define __USE_MP_SCALE__
        #include "MPTests.h"
    #endif
#endif

unsigned mphash(const unsigned char * s, int size);
void mpDisplayImage(std::string filename, std::string windowtitle);
bool mpSavePGMImage(std::string filename, const unsigned char *buffer,int width, int height);

#endif /* MPTOOLS_H */


