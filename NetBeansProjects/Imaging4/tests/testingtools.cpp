#include <cstring>
#include <string>
#include <cmath>
#include "MPTools.h"
#define private public
#include "Byte.h"
#include "Histogram.h"
#include "Image.h"
#include "testingtools.h"

using namespace std;

string describeImage(const Image &i) {
    string res="";
    
    res=res+"Image "+std::to_string(i._width)+"x"+std::to_string(i._height);
    return res;
}

void generateHistogram(Histogram &h, int init, int increment) {
    h._data[0]=init;
    for (int i=1; i<256; i++){
        h._data[i]=h._data[i-1]+increment;
    }
    
}

string Histogram_to_string(const Histogram &h) {
    string result="";
    for (int i=0; i<256; i++){
        result += std::to_string((int) h._data[i])+" ";
    }
    return result;
}

int Histogram_inspect(const Histogram &h) {
    string what = Histogram_to_string(h);
    return mphash((const unsigned char *)what.c_str(), what.length()-1);
}

Image singlePixel256Image() {
    Image aux(16,16);
    int p=0;
    for (int y = 0; y < aux.height(); y++) {
        for (int x = 0; x < aux.width(); x++) {
            aux.setPixel(x, y, Byte(p++));
        }
    }
//    aux.saveToFile("./tests/validation/singlepix.pgm");
//    aux.depictsHistogram().saveToFile("./tests/validation/singlepixhistogram.pgm");
    return aux;
}

Image checkersImage() {
    int w=16,h=16,factor=2, nlevels=4, level, gray;
    Image aux(w,h);
    int p=0;
    for (int y = 0; y < aux.height(); y++) {
        for (int x = 0; x < aux.width(); x++) {
            if (x<w/2) {
                if (y<h/2)
                    level=0;
                else
                    level=2;
            } else {
                if (y<h/2)
                    level=1;
                else
                    level=3;
            }
            gray=255*level/(nlevels-1);
            aux.setPixel(x, y, Byte(gray));
        }
    }
//    aux.saveToFile("./tests/validation/checkers.pgm");
//    aux.depictsHistogram().saveToFile("./tests/validation/checkershistogram.pgm");
    return aux;
}

Image flatImage() {
    int w=16,h=16,factor=2, nlevels=4, level, gray;
    Image aux(w,h);
    int p=0;
    for (int y = 0; y < aux.height(); y++) {
        for (int x = 0; x < aux.width(); x++) {
            aux.setPixel(x,y,Byte(128));
        }
    }
//    aux.saveToFile("./tests/validation/flat.pgm");
//    aux.depictsHistogram().saveToFile("./tests/validation/flathistogram.pgm");
    return aux;
}