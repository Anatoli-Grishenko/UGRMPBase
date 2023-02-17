/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file BigramFreq.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <string>

#include "BigramFreq.h"

using namespace std;

BigramFreq::BigramFreq():_bigram("__"), _frequency(0) {
    //_frequency = 0;
}


const Bigram& BigramFreq::getBigram() const {
    return _bigram;
}
int BigramFreq::getFrequency() const {
    return _frequency;
}

void BigramFreq::setBigram(const Bigram& bigram) {
    this->_bigram = bigram;
}

void BigramFreq::setFrequency(int frequency) {
    if(frequency<0){
        throw  std::out_of_range(string("void BigramFreq::setFrequency(int frequency): ") +
                "invalid frecuency " + to_string(frequency));
    }
    this->_frequency = frequency;
}


string BigramFreq::toString() const {
    return _bigram.toString() + " " + to_string(_frequency);
}

std::ostream& operator<<(std::ostream& os, const BigramFreq& bigramFreq) {
    os << bigramFreq.getBigram() << " " << bigramFreq.getFrequency();   
    return os;
}

std::istream& operator>>(std::istream& is, BigramFreq& bigramFreq) {
    is >> bigramFreq._bigram ;
    is >> bigramFreq._frequency;   
   
    return is;
}

bool operator==(const BigramFreq &bigramFreq1, const BigramFreq &bigramFrec2) {
    return (bigramFreq1.getFrequency() == bigramFrec2.getFrequency()) && 
            (bigramFreq1.getBigram() == bigramFrec2.getBigram()); 
}

bool operator>(const BigramFreq &bigramFreq1, const BigramFreq &bigramFrec2) {
    return (bigramFreq1.getFrequency() > bigramFrec2.getFrequency()) || 
            ((bigramFreq1.getFrequency() == bigramFrec2.getFrequency()) && 
            (bigramFreq1.getBigram() < bigramFrec2.getBigram())); 
}

bool operator!=(const BigramFreq& bigramFreq1, const BigramFreq& bigramFreq2){
    return !(bigramFreq1 == bigramFreq2);
}

bool operator>=(const BigramFreq& bigramFreq1, const BigramFreq& bigramFreq2){
    return (bigramFreq1>bigramFreq2) || (bigramFreq1==bigramFreq2) ;
}

bool operator<(const BigramFreq& bigramFreq1, const BigramFreq& bigramFreq2){
    return !(bigramFreq1>=bigramFreq2);
}

