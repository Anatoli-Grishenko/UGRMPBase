/**
 * @file MyVector.cpp
 * @author DECSAI
 * @note This is the implementation of MyVector.h
 */
#include <string>
#include "myvector.h"
using namespace std;

MyVector::MyVector() {
    clear();
}

void MyVector::addLetter(char letter) {
    if (nletters < MAXVECTOR) {
        nletters++;
        setLetter(nletters-1, letter);
    }

}

char MyVector::getLetter(int pos) const {
    if (0 <= pos && pos < size())
        return letters[pos];
    else
        return NOCHAR;
}

void MyVector::setLetter(int pos, char letter) {
    if (0 <= pos && pos < size())
        letters[pos] = letter;
}

void MyVector::clear() {
    nletters = 0;
    for (int i = 0; i < MAXVECTOR; i++)
        letters[i] = EMPTYCHAR;
}

//
// Provided BY INSPECTION
// 

int MyVector::size() const {
    return nletters;
}

string MyVector::to_string() const {
    std::string res = "";
    for (int i = 0; i < size(); i++)
        res.push_back(getLetter(i));
    return res;
}

string MyVector::reportData() const {
    std::string res = "";
    for (int i = 0; i < MAXVECTOR; i++)
        res.push_back(letters[i]);
    return std::to_string(size()) + "," + res;
}

