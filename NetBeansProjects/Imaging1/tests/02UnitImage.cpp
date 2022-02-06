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
using namespace std;

string describeImage(const Image &i) {
    string res="";
    
    res=res+"Image "+std::to_string(i._width)+"x"+std::to_string(i._height);
    return res;
}

TEST_F(_01_Basics, Image_Constructor) {
    int w, h;
    w=0; h=0;
    Image I;
    SKIP_ASSERT_STREQ_R(I.inspect().c_str(), "0x0 37") << "A newly created instance " <<describeImage(I) << " gives "<<w<<"x"<<h<<" and empty data "<<endl;
    w=5; h=5;
    Image I2(w,h);
    SKIP_ASSERT_STREQ_R(I2.inspect().c_str(), "5x5 3486450967") << "A newly created instance " <<describeImage(I2) << " gives "<<w<<"x"<<h<<" and empty data "<<endl;
    w=100;h=100;
    Image I3(w,h);
    SKIP_ASSERT_STREQ_R(I3.inspect().c_str(), "100x100 1292816357") << "A newly created instance " <<describeImage(I3) << " gives "<<w<<"x"<<h<<" and empty data "<<endl;

}

TEST_F(_01_Basics, Image_Width) {
    int w, h;
    w=0; h=0;
    Image I;
    SKIP_ASSERT_EQ_R(I.width(),w) << "A newly created instance " <<describeImage(I) << " gives width "<<w<<endl;
    w=5; h=5;
    Image I2(w,h);
    SKIP_ASSERT_EQ_R(I2.width(),w) << "A newly created instance " <<describeImage(I2) << " gives width "<<w<<endl;
    w=100;h=100;
    Image I3(w,h);
    SKIP_ASSERT_EQ_R(I3.width(),w)<< "A newly created instance " <<describeImage(I3) << " gives width "<<w<<endl;

}

TEST_F(_01_Basics, Image_Height) {
    int w, h;
    w=0; h=0;
    Image I;
    SKIP_ASSERT_EQ_R(I.height(),h) << "A newly created instance " <<describeImage(I) << " gives height "<<h<<endl;
    w=5; h=w+2;
    Image I2(w,h);
    SKIP_ASSERT_EQ_R(I2.height(),h) << "A newly created instance " <<describeImage(I) << " gives height "<<h<<endl;
    w=100;h=w+2;
    Image I3(w,h);
    SKIP_ASSERT_EQ_R(I3.height(),h) << "A newly created instance " <<describeImage(I) << " gives height "<<h<<endl;

}

TEST_F(_01_Basics, Image_setPixel) {
    int w, h, v, x, y, whatis, whatmustbe;
    Byte b;
    w=5; h=5;
    Image I(w,h);
    
    v=65;x=0; y=0;
    b.setValue(v);
    I.setPixel(x,y,b);
    whatis = I._data[y*w+x]._data;
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in ("<<x<<","<<y<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
    v=255;x=4; y=4;
    b.setValue(v);
    I.setPixel(x,y,b);
    whatis = I._data[y*w+x]._data;
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in ("<<x<<","<<y<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
}

TEST_F(_01_Basics, Image_getPixel) {
    int w, h, v, x, y, whatis, whatmustbe;
    Byte b;
    w=5; h=5;
    Image I(w,h);
    
    v=65;x=0; y=0;
    b.setValue(v);
    I.setPixel(x,y,b);
    whatis = I.getPixel(x,y);
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in ("<<x<<","<<y<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
    v=255;x=4; y=4;
    b.setValue(v);
    I.setPixel(x,y,b);
    whatis = I.getPixel(x,y);
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in ("<<x<<","<<y<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
}

TEST_F(_01_Basics, Image_getPos) {
    int w, h, v, x, y, whatis, whatmustbe, pos;
    Byte b;
    w=5; h=5;
    Image I(w,h);
    
    v=65;x=0; y=0;pos=0;
    b.setValue(v);
    I.setPos(pos,v);
    whatis = I._data[pos].getValue();
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in linear position "<<pos<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
    b.setValue(v);
    I.setPos(pos,v);
    whatis = I._data[pos].getValue();
    whatmustbe=v;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "Insert value "<<v << " in linear position "<<pos<<") in " <<describeImage(I) << " gives "<<whatis<< " but should have been "<<whatmustbe<<endl;
}

TEST_F(_02_Intermediate, Image_flatten) {
    int w, h, v, x, y, whatis, whatmustbe, pos;
    char whatstringis[65], whatstringmustbe[65];
    Byte b;
    w=5; h=5;
    Image I(w,h);
    
    v=128; 
    b.setValue(v);
    I.flatten(b);
    strcpy(whatstringis, I.inspect().c_str());
    strcpy(whatstringmustbe, "5x5 902468759");
    SKIP_ASSERT_STREQ_R(whatstringmustbe, whatstringis) << "Flattening an "<<describeImage(I) <<" to value "<<v<<" is wrong"<<endl;
    v=255; 
    b.setValue(v);
    I.flatten(b);
    strcpy(whatstringis, I.inspect().c_str());
    strcpy(whatstringmustbe, "5x5 3583637442");
    SKIP_ASSERT_STREQ_R(whatstringmustbe, whatstringis) << "Flattening an "<<describeImage(I) <<" to value "<<v<<" is wrong"<<endl;
}

TEST_F(_02_Intermediate, Image_getHistogram) {
    int w, h, v, x, y, whatis, whatmustbe, pos, histogram[256];
    char whatstringis[65], whatstringmustbe[65];
    Byte b;
    w=5; h=5;
    Image I(w,h);
    
    v=128; 
    b.setValue(v);
    I.flatten(b);
    I.getHistogram(histogram);
    whatis=histogram[pos];
    whatmustbe=0;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The histogram["<<pos<<"] of an "<<describeImage(I) <<" flattened to " << v << " is wrong. It gives " << whatis << " but it should have been "<<whatmustbe<<endl;
    pos = v;
    whatis=histogram[pos];
    whatmustbe=w*h;
    SKIP_ASSERT_EQ_R(whatmustbe, whatis) << "The histogram["<<pos<<"] of an "<<describeImage(I) <<" flattened to " << v << " is wrong. It gives " << whatis << " but it should have been "<<whatmustbe<<endl;
}