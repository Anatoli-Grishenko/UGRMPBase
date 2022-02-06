#ifndef TESTINGTOOLS_H
#define TESTINGTOOLS_H

#include "Byte.h"
#include "Histogram.h"
#include "Image.h"


std::string describeImage(const Image &i);
void generateHistogram(Histogram &h, int init, int increment);
std::string Histogram_to_string(const Histogram &h);
int Histogram_inspect(const Histogram &h);
Image singlePixel256Image();
Image checkersImage();
Image flatImage();


#endif /* TESTINGTOOLS_H */

