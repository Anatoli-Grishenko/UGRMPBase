/**
 * @file main.cpp
 * @author MP
 */
#include <iostream>
#include <cstring>
#include "MPTools.h"
#include "Byte.h"
#include "Image.h"
#include "Histogram.h"

using namespace std;

/**
 * @brief It waits until the key [INTRO] [RETURN] is pressed
 */
void pressReturnToContinue();

/**
 * @brief It breaks the program due to some error and shows a message
 * @param errorcode The type of error as declared in Image.h
 * @param errordata A message trying to describe the error
 */
void errorBreak(int errorcode, const string & errordata);

int main() {
    string input = "data"+SLASH+"telediario.pgm", 
            copy = "data"+SLASH+"kfc.pgm", output = "data"+SLASH+"new.pgm";
    Image im_input, im_output, im_copyfrom, im_bin, im_cut, im_histogram, im_collection[10], im_aux;
    int res, n, w, h;
    res = im_input.readFromFile(input.c_str());
    if (res != Image::IMAGE_DISK_OK) {
        errorBreak(res, input);
    }
    im_input.showInWindow("input");
//        im_input.depictsHistogram().showInWindow("histoinput");
//        im_aux = im_input.threshold(128);
//        im_aux.showInWindow("input128");
//        im_aux.depictsHistogram().showInWindow("histo128");
//        
//        im_aux=im_input.threshold();
//        im_aux.showInWindow("inputbalance");
//        im_aux.depictsHistogram().showInWindow("histobalance");

    INSPECT(im_input);
    if (copy.length() > 0) {
        res = im_copyfrom.readFromFile(copy.c_str());
        if (res != Image::IMAGE_DISK_OK) {
            errorBreak(res, input);
        }
        im_copyfrom.showInWindow("copyfrom");
        im_copyfrom.depictsHistogram().showInWindow("copyhisto");
        INSPECT(im_copyfrom);
        w = im_copyfrom.width() + 5;
        h = im_copyfrom.height() + 5;
        im_bin = im_copyfrom.threshold();
        im_bin.showInWindow("threshold");
        INSPECT(im_bin);
        int x = 0;
        im_input.pasteArea(x, 0, im_copyfrom);
        im_copyfrom.extractObjects(im_collection, n, 3);
        im_cut = im_collection[0];
        im_collection[0].showInWindow("segmented");
        INSPECT(im_collection[0]);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut);
        im_input.pasteArea(x, h, im_bin);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64);
        im_input.pasteArea(x, h, im_bin, 64);
        x = x + w;
        im_input.pasteArea(x, 0, im_cut, 64, 50);
        im_input.pasteArea(x, h, im_bin, 64, 50);
    }
    im_output = im_input;
    if (output.length() > 0) {
        im_output.saveToFile(output.c_str());
    }
    im_output.showInWindow("output");
    INSPECT(im_output);
    pressReturnToContinue();
    return 0;
}
        

void pressReturnToContinue() {
    char aux[10];
    cout << "Press [RETURN] to continue ...";
    cin.getline(aux, 1, '\n');
}

void errorBreak(int errorcode, const string & errordata) {
    switch (errorcode) {
        case Image::IMAGE_ERROR_OPEN:
            CVAL << endl << "Error opening file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_DATA:
            CVAL << endl << "Data error in file " << errordata << endl;
            break;
        case Image::IMAGE_ERROR_FORMAT:
            CVAL << endl << "Unrecognized format in file " << errordata << endl;
            break;
    }
    std::exit(1);
}
