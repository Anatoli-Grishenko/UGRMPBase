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
#include "testingtools.h"

using namespace std;

TEST_F(_01_Basics, Image_Constructor) {
    int w, h;
    w = 0;
    h = 0;
    Image I;
    SKIP_ASSERT_STREQ_R(I.inspect().c_str(), "0x0 37") << "A newly created instance " << describeImage(I) << " gives " << w << "x" << h << " and empty data " << endl;
    w = 5;
    h = 5;
    Image I2(w, h);
    SKIP_ASSERT_STREQ_R(I2.inspect().c_str(), "5x5 3486450967") << "A newly created instance " << describeImage(I2) << " gives " << w << "x" << h << " and empty data " << endl;
    w = 100;
    h = 100;
    Image I3(w, h);
    SKIP_ASSERT_STREQ_R(I3.inspect().c_str(), "100x100 1292816357") << "A newly created instance " << describeImage(I3) << " gives " << w << "x" << h << " and empty data " << endl;

}

TEST_F(_01_Basics, Image_Width) {
    int w, h;
    w = 0;
    h = 0;
    Image I;
    SKIP_ASSERT_EQ_R(I.width(), w) << "A newly created instance " << describeImage(I) << " gives width " << w << endl;
    w = 5;
    h = 5;
    Image I2(w, h);
    SKIP_ASSERT_EQ_R(I2.width(), w) << "A newly created instance " << describeImage(I2) << " gives width " << w << endl;
    w = 100;
    h = 100;
    Image I3(w, h);
    SKIP_ASSERT_EQ_R(I3.width(), w) << "A newly created instance " << describeImage(I3) << " gives width " << w << endl;

}

TEST_F(_01_Basics, Image_Height) {
    int w, h;
    w = 0;
    h = 0;
    Image I;
    SKIP_ASSERT_EQ_R(I.height(), h) << "A newly created instance " << describeImage(I) << " gives height " << h << endl;
    w = 5;
    h = w + 2;
    Image I2(w, h);
    SKIP_ASSERT_EQ_R(I2.height(), h) << "A newly created instance " << describeImage(I) << " gives height " << h << endl;
    w = 100;
    h = w + 2;
    Image I3(w, h);
    SKIP_ASSERT_EQ_R(I3.height(), h) << "A newly created instance " << describeImage(I) << " gives height " << h << endl;

}

TEST_F(_01_Basics, Image_setPixel) {
    int w, h, v, x, y, whatis, whatmustbe;
    Byte b;
    w = 5;
    h = 5;
    Image I(w, h);

    v = 65;
    x = 0;
    y = 0;
    b.setValue(v);
    I.setPixel(x, y, b);
    whatis = I._data[y * w + x]._data;
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in (" << x << "," << y << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
    v = 255;
    x = 4;
    y = 4;
    b.setValue(v);
    I.setPixel(x, y, b);
    whatis = I._data[y * w + x]._data;
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in (" << x << "," << y << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
}

TEST_F(_01_Basics, Image_getPixel) {
    int w, h, v, x, y, whatis, whatmustbe;
    Byte b;
    w = 5;
    h = 5;
    Image I(w, h);

    v = 65;
    x = 0;
    y = 0;
    b.setValue(v);
    I.setPixel(x, y, b);
    whatis = I.getPixel(x, y);
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in (" << x << "," << y << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
    v = 255;
    x = 4;
    y = 4;
    b.setValue(v);
    I.setPixel(x, y, b);
    whatis = I.getPixel(x, y);
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in (" << x << "," << y << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
}

TEST_F(_01_Basics, Image_getPos) {
    int w, h, v, x, y, whatis, whatmustbe, pos;
    Byte b;
    w = 5;
    h = 5;
    Image I(w, h);

    v = 65;
    x = 0;
    y = 0;
    pos = 0;
    b.setValue(v);
    I.setPos(pos, v);
    whatis = I._data[pos].getValue();
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in linear position " << pos << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
    b.setValue(v);
    I.setPos(pos, v);
    whatis = I._data[pos].getValue();
    whatmustbe = v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value " << v << " in linear position " << pos << ") in " << describeImage(I) << " gives " << whatis << " but should have been " << whatmustbe << endl;
}

TEST_F(_02_Intermediate, Image_flatten) {
    int w, h, v, x, y, whatis, whatmustbe, pos;
    char whatstringis[6500], whatstringmustbe[6500];
    Byte b;
    w = 5;
    h = 5;
    Image I(w, h);

    v = 128;
    b.setValue(v);
    I.flatten(b);
    strcpy(whatstringis, I.inspect().c_str());
    strcpy(whatstringmustbe, "5x5 902468759");
    SKIP_ASSERT_STREQ_R(whatstringmustbe, whatstringis) << "Flattening an " << describeImage(I) << " to value " << v << " is wrong" << endl;
    v = 255;
    b.setValue(v);
    I.flatten(b);
    strcpy(whatstringis, I.inspect().c_str());
    strcpy(whatstringmustbe, "5x5 3583637442");
    SKIP_ASSERT_STREQ_R(whatstringmustbe, whatstringis) << "Flattening an " << describeImage(I) << " to value " << v << " is wrong" << endl;
}

TEST_F(_02_Intermediate, Image_getHistogram) {
    int w, h, v, x, y, whatis, whatmustbe, pos, histogram[256];
    char whatstringis[6500], whatstringmustbe[6500];
    Byte b;
    w = 16;
    h = 16;
    Image I = singlePixel256Image();
    Histogram hist = I.getHistogram();
    whatis = hist.getAverageLevel();
    whatmustbe = 1;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The single pixel image must have one pixel per each 256 gray level" << endl;
    whatis = hist.getMaxLevel();
    whatmustbe = 1;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The single pixel image must have a maximum histogram of 1" << endl;
    whatis = hist.getBalancedLevel();
    whatmustbe = 127;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The single pixel image must have a balanced level of 128" << endl;
    I = checkersImage();
    hist = I.getHistogram();
    whatis = hist.getAverageLevel();
    whatmustbe = 1;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The checkers image must have only 4 levels" << endl;
    whatis = hist.getMaxLevel();
    whatmustbe = 64;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The checkers image must have a maximum histogram of 64" << endl;
    whatis = hist.getBalancedLevel();
    whatmustbe = 85;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The checkers image must have a balanced level of 86" << endl;
}

TEST_F(_03_Advanced, Image_readFromFile) {
    int w, h, v, x, y, whatis, whatmustbe, pos, histogram[256];
    char whatstringis[6500], whatstringmustbe[6500];
    Byte b;
    w = 16;
    h = 16;
    Image I;

    whatis = I.readFromFile("./tests/validation/noone.pgm");
    whatmustbe = Image::IMAGE_ERROR_OPEN;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method readFromFIle must warn if a file could not be open" << endl;

    whatis = I.readFromFile("./tests/validation/baddata.pgm");
    whatmustbe = Image::IMAGE_ERROR_DATA;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method readFromFIle must warn if a file has a data error" << endl;

    whatis = I.readFromFile("./tests/validation/badformat.pgm");
    whatmustbe = Image::IMAGE_ERROR_FORMAT;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method readFromFIle must warn if a file does not follow the ASCII PGM format" << endl;

    whatis = I.readFromFile("./tests/validation/toolarge.pgm");
    whatmustbe = Image::IMAGE_TOO_LARGE;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method readFromFIle must warn if a file is too large" << endl;

    whatis = I.readFromFile("./tests/validation/singlepix.pgm");
    whatmustbe = Image::IMAGE_DISK_OK;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method readFromFIle must read valid files with ASCII PGM format" << endl;
    Image singlepix = singlePixel256Image();
    strcpy(whatstringmustbe, singlepix.inspect().c_str());
    strcpy(whatstringis, I.inspect().c_str());
    SKIP_ASSERT_STREQ_R(whatstringmustbe, whatstringis) << "Method readFromFIle does not read well  valid files with ASCII PGM format" << endl;
}

TEST_F(_03_Advanced, Image_saveToFile) {
    int w, h, v, x, y, whatis, whatmustbe, pos, histogram[256];
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    w = 16;
    h = 16;
    Image I = singlePixel256Image();
    ;

    whatis = I.saveToFile("./nonexistent/noone.pgm");
    whatmustbe = Image::IMAGE_ERROR_OPEN;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method saveToFiIle must warn if a file could not be open" << endl;

    whatis = I.saveToFile("./tests/output/singlepix.pgm");
    whatmustbe = Image::IMAGE_DISK_OK;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Method saveToFile must save to disk valid ASCII PGM images" << endl;
    LOAD(whatstringis, "./tests/output/singlepix.pgm");
    LOAD(whatstringmustbe, "./tests/validation/singlepix.pgm");
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "Method saveToFile must save to disk valid ASCII PGM images" << endl;
}

TEST_F(_02_Intermediate, Image_depictsHistogram) {
    int w, h, v, x, y, whatis, whatmustbe, pos, histogram[256];
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    w = 16;
    h = 16;
    Image I = singlePixel256Image();
    ;
    whatstringis = I.depictsHistogram().inspect();
    whatstringmustbe = "256x160 3252998949";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The histogram of singlepix Image is wrong" << endl;
    I.flatten(Byte(128));
    whatstringis = I.depictsHistogram().inspect();
    whatstringmustbe = "256x160 1519143717";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The histogram of a flat-128 Image is wrong" << endl;
}

TEST_F(_03_Advanced, Image_extractObjects) {
    int w, h, v, x, y, whatis, whatmustbe, pos, nimages, histogram[256], element;
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    Image images[4];
    w = 16;
    h = 16;
    Image I, Imelement;
    I = checkersImage();
    I.extractObjects(images, nimages, 4);
    whatis = nimages;
    whatmustbe = 4;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The checkers image should decompose into 4 objects" << endl;
    
    element=0;
    Imelement = images[element];
    whatstringis = Imelement.inspect();
    whatstringmustbe = "16x16 133122917";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The element "<<element << " of the objects found in checkers image is wrong" << endl;
    element=1;
    Imelement = images[element];
    whatstringis = Imelement.inspect();
    whatstringmustbe = "16x16 3209069605";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The element "<<element << " of the objects found in checkers image is wrong" << endl;
    element=2;
    Imelement = images[element];
    whatstringis = Imelement.inspect();
    whatstringmustbe = "16x16 3509076965";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The element "<<element << " of the objects found in checkers image is wrong" << endl;
    element=2;
    Imelement = images[element];
    whatstringis = Imelement.inspect();
    whatstringmustbe = "16x16 3509076965";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The element "<<element << " of the objects found in checkers image is wrong" << endl;

    I = flatImage();
    I.extractObjects(images, nimages, 4);
    whatis = nimages;
    whatmustbe = 1;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The flat image should decompose into 1 object" << endl;
}

TEST_F(_02_Intermediate, Image_threshold) {
   int w, h, v, x, y, whatis, whatmustbe, pos, nimages, histogram[256], element;
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    Image images[4];
    w = 16;
    h = 16;
    Image I, Imelement;
    
    x=127;
    I = checkersImage();
    I=I.threshold(x);
//    I.showInWindow("checkers");
    whatstringis = I.inspect();
    whatstringmustbe = "16x16 4214913957";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The threshold to " << x << " of checkers is wrong" << endl;
    
    I = singlePixel256Image();
    I=I.threshold(x);
//    I.showInWindow("singlepìx");
    whatstringis = I.inspect();
    whatstringmustbe = "16x16 4214913957";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The threshold to " << x << " of singlepix is wrong" << endl;

    I = checkersImage();
    I=I.threshold();
//    I.showInWindow("checkers");
    whatstringis = I.inspect();
    whatstringmustbe = "16x16 4214913957";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The balanced threshold  of checkers is wrong" << endl;
    
    I = singlePixel256Image();
    I=I.threshold();
//    I.showInWindow("singlepìx");
    whatstringis = I.inspect();
    whatstringmustbe = "16x16 4214913957";
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The balanced threshold  of singlepix is wrong" << endl;
    
 }

TEST_F(_03_Advanced, Image_copy) {
   int w, h, v, x, y, whatis, whatmustbe, pos, nimages, histogram[256], element;
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    Image I,part;
    
    I=checkersImage();
    INSPECT(I);
    w = I.width();
    h = I.height();
    Image flat(w/2,h/2);
    
    part=I.copyArea(-w/2,-h/2,w,h);
    flat.flatten(Byte(part.getPixel(0,0)));
    whatis=part.width();
    whatmustbe=I.width()/2;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"Copying the top left corner of chekers must have half width"<< endl;
    whatis=part.height();
    whatmustbe=h/2;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"Copying the top left corner of chekers must have half height"<< endl;
    whatstringis=part.inspect();
    whatstringmustbe=flat.inspect();
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The top left quarter of checkers is a flat image" << endl;
    
    part=I.copyArea(w/2,h/2,w,h);
    flat.flatten(Byte(part.getPixel(0,0)));
    whatis=part.width();
    whatmustbe=I.width()/2;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"Copying the bottom right corner of chekers must have half width"<< endl;
    whatis=part.height();
    whatmustbe=h/2;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis)<<"Copying the bottom right corner of chekers must have half height"<< endl;
    whatstringis=part.inspect();
    whatstringmustbe=flat.inspect();
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "The bottom right quarter of checkers is a flat image" << endl;
}
TEST_F(_03_Advanced, Image_paste) {
   int w, h, v, x, y, whatis, whatmustbe, pos, nimages, histogram[256], element;
    char whatcstringis[6500], whatcstringmustbe[6500];
    string whatstringis, whatstringmustbe;
    Byte b;
    Image I,dest;
    
    I=checkersImage();
    dest=I;
    dest.flatten(Byte(0));
    w = I.width();
    h = I.height();
    Image tl(w/2,h/2),tr(w/2,h/2),bl(w/2,h/2),br(w/2,h/2);

    tl.flatten(I.getPixel(0,0));
    tr.flatten(I.getPixel(w/2,0));
    bl.flatten(I.getPixel(0,h/2));
    br.flatten(I.getPixel(w/2,h/2));
    
    dest.pasteArea(0,0,tl);
    dest.pasteArea(w/2,0,tr);
    dest.pasteArea(0,h/2,bl);
    dest.pasteArea(w/2,h/2,br);
    whatstringis=dest.inspect();
    whatstringmustbe=I.inspect();
    SKIP_ASSERT_STREQ_R(whatstringmustbe.c_str(), whatstringis.c_str()) << "Checkers cannot be built by pastin each quadrant" << endl; 
}

    
