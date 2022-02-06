/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <string>
#include <cstring>
#include "MPTools.h"
#define private public
#include "Byte.h"
#include "Image.h"
#include "Histogram.h"
#include "testingtools.h"

using namespace std;

TEST_F(_01_Basics, Histogram_Constructor) {
    string aux;
    int w, h, v, x, y, whatis, whatmustbe, pos;
    unsigned whatunsignedis, whatunsignedmustbe;
    char whatstringis[1000], whatstringmustbe[1000];
    Byte b;
    Histogram hist;
    aux = Histogram_to_string(hist);
    strcpy(whatstringis, aux.c_str());
    whatis = strlen(whatstringis);
    whatmustbe = 512;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<" A newly created instance of an histogram must be empty"<< endl;
    whatis = Histogram_inspect(hist);
    whatmustbe = 1818134095;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<" A newly created instance of an histogram must be empty hash"<< endl;
}

TEST_F(_01_Basics, Histogram_Size) {
    Histogram hist;
    int w, h, v, x, y, whatis, whatmustbe, pos;
    whatis=hist.size();
    whatmustbe=256;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"Any histogram must have a capacity for 256 values"<<endl;
}

TEST_F(_01_Basics, Histogram_Clear) {
    Histogram hist;
    int w, h, v, x, y, whatis, whatmustbe, pos;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    empty=Histogram_inspect(hist);
    generateHistogram(hist,0,10);
    full=Histogram_inspect(hist);
    whatunsignedmustbe=53702025;
    whatunsignedis=full;
    ASSERT_NE_R(empty,full)<<"Any modified histogram must not be empty"<<endl;
    SKIP_ASSERT_EQ_R(whatunsignedmustbe, whatunsignedis)<<"A crescent triangular histogram is wrong"<<endl;
    hist.clear();
    whatunsignedmustbe=empty;
    whatunsignedis=Histogram_inspect(hist);;
    SKIP_ASSERT_EQ_R(whatunsignedmustbe, whatunsignedis)<<"Once filled up, and cleared, an histogram must be empty again"<<endl;
}

TEST_F(_01_Basics, Histogram_getLevel) {
    Histogram hist;
    int w, h, v, x, y, level, whatis, whatmustbe, pos, init, incr;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    init=0;
    incr=10;
    generateHistogram(hist,init,incr);
    level=10;
    whatmustbe=init+incr*level;
    whatis=hist.getLevel(level);
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
    level=100;
    whatmustbe=init+incr*level;
    whatis=hist.getLevel(level);
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
}

TEST_F(_01_Basics, Histogram_setLevel) {
    Histogram hist;
    int w, h, v, x, y, level, whatis, whatmustbe, pos, init, incr;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    init=0;
    incr=10;
    generateHistogram(hist,init,incr);
    level=10;
    hist.setLevel(0,init);
    for (int i=1; i<256; i++){
        hist.setLevel(i,hist.getLevel(i-1)+incr);
    }
    full=Histogram_inspect(hist);
    whatunsignedmustbe=53702025;
    whatunsignedis=full;
    SKIP_ASSERT_EQ_R(whatunsignedmustbe, whatunsignedis)<<"A crescent triangular histogram is wrong"<<endl;
    
}

TEST_F(_01_Basics, Histogram_getMaxLevel) {
    Histogram hist;
    int w, h, v, x, y, level, whatis, whatmustbe, pos, init, incr;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    whatmustbe=0;
    whatis=hist.getMaxLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
    init=0;
    incr=10;
    generateHistogram(hist,init,incr);
     level=255;
    whatmustbe=init+incr*level;
    whatis=hist.getMaxLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
 
}

TEST_F(_01_Basics, Histogram_getAverageLevel) {
    Histogram hist;
    int w, h, v, x, y, level, whatis, whatmustbe, pos, init, incr;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    whatmustbe=0;
    whatis=hist.getAverageLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
    init=0;
    incr=10;
    generateHistogram(hist,init,incr);
    whatmustbe=((init+hist.getMaxLevel())/2*hist.size())/hist.size();
    whatis=hist.getAverageLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
 
}

TEST_F(_01_Basics, Histogram_getBalancedLevel) {
    Histogram hist;
    int w, h, v, x, y, level, whatis, whatmustbe, pos, init, incr;
    unsigned whatunsignedis, whatunsignedmustbe, empty, full;

    whatmustbe=0;
    whatis=hist.getAverageLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
    init=0;
    incr=10;
    generateHistogram(hist,init,incr);
    whatmustbe=181; 
    whatis=hist.getBalancedLevel();
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"A crescent triangular histogram has wrong values"<<endl;
 
}
