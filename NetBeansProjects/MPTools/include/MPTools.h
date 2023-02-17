
//#define __WINDOWS__


#ifndef MPTOOLS_H
#define MPTOOLS_H
#ifdef __WINDOWS__
    #define SLASH (std::string) "\\"
    #define CVAL std::clog 
    #define INSPECT(VAR) CVAL << std::endl<< "["<<#VAR<<"] "<< VAR.inspect() << std::endl;
#else
    #define SLASH (std::string) "/"
    #ifdef __TDD__
//        #define __USE_MP_SCALE__
        #include "MPTests.h"
    #endif
#endif
#include "cval.h"

unsigned mphash(const unsigned char * s, int size);
void mpDisplayImage(std::string filename, std::string windowtitle);
bool mpSavePGMImage(std::string filename, const unsigned char *buffer,int width, int height);

std::string toUTF(char in);
std::string toUTF(const std::string &s);
std::string toUTF(const char * i);

std::string toISO(const char * in);
std::string toISO(const std::string &h);
bool isUTF8(const char * string);
#define ESC (std::string)" \u001b["
#define DARKGRAY ESC+"90m"
#define GREEN ESC+"32;1m"
#define RED ESC+"31;1m"
#define ErrorMessage(S)  RED+(S)+DARKGRAY
#define ValidationMessage(S)  GREEN+(S)+DARKGRAY

#endif /* MPTOOLS_H */
