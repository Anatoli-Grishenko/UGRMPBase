/*
 * Metodología de la Programación: Language4
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#include "Language.h"

using namespace std;

const string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";

Language::Language() {
    _languageId="unknown";
    _size = 0;
    _vectorBigramFreq = nullptr;
}

Language::Language(int numberBigrams)  {
    if(numberBigrams < 0){
        throw std::out_of_range(string("Language::Language(int numberBigrams): ") +
                "invalid numberBigrams=" + to_string(numberBigrams));
    }
    _languageId="unkown";
    allocate(numberBigrams);
}

Language::Language(const Language& orig) {
    allocate(orig._size);
    copy(orig);
}

Language::~Language() {
    deallocate();
}

Language& Language::operator=(const Language& orig) {
    if (this != &orig) {
        deallocate();
        allocate(orig._size );
        copy(orig);
    }
    return *this;
}

const string& Language::getLanguageId() const {
    return _languageId;
}

void Language::setLanguageId(const string& id) {
    _languageId = id;
}

const BigramFreq& Language::at(int index) const {    
    if (0 <= index && index < getSize()) 
        return _vectorBigramFreq[index];
    else    
        throw std::out_of_range(
                string("const BigramFreq& Language::at(int index) const: ") +
                "invalid position " + to_string(index));
}

BigramFreq& Language::at(int index) {    
    if (0 <= index && index < getSize()) /// Acceso seguro
        return _vectorBigramFreq[index];
    else
        throw std::out_of_range(string("BigramFreq& Language::at(int index): ") +
                "invalid position " + to_string(index));
}

int Language::getSize() const {
    return _size;
};

double Language::getDistance(const Language& otherLanguage) const {
    int posB;
    int posA = 0;
    double dist = 0.0;

    for (int i = 0; i < getSize(); ++i) {
        posB = otherLanguage.findBigram (this->at(i).getBigram()); // o bien posB = B.findBigram((*this)[i].getBigram());
        if (posB < 0) {
            posB = getSize();
        }

        dist += abs(posA - posB);
        posA++;
    }
    return dist / (getSize() * getSize()); 
}

int Language::findBigram(const Bigram& bigram) const { 
    for (int i = 0; i < getSize(); ++i) {
        if (bigram.getText() == this->at(i).getBigram().getText()) { // o bien if (bigrama == (*this)[i].getBigram()) {
            return i;
        }
    }
    return -1;    
}

std::string Language::toString() const{
    string outputString = this->getLanguageId() + "\n" + 
            to_string(this->getSize()) + "\n";
    
    for(int i=0; i<this->getSize(); i++){
        outputString += this->at(i).toString() + "\n";
    }
    return outputString;
}

void Language::sort()  {
    BigramFreq aux;
    int pos;
    for (int i=0; i<getSize(); i++)  {
        pos = i;
        for (int j=i+1; j<getSize(); j++)
            if ( (this->at(j).getFrequency() > this->at(pos).getFrequency()) ||
                    ((this->at(j).getFrequency() == this->at(pos).getFrequency())
                    && (this->at(j).getBigram().getText() < this->at(pos).getBigram().getText())) ) 
                pos = j;
        if (pos != i)  {
            aux = this->at(i); // o bien aux = (*this)[i];
            this->at(i) = this->at(pos);// o bien (*this)[i] = (*this)[pos]; antes: setPosicion(i,at(pos));
            this->at(pos) = aux; // o bien (*this)[pos] = aux; antes: setPosicion(pos,aux);
        }
    }
}

void Language::save(const char *fileName) const {
    ofstream stream(fileName, ios::out); 

    if (stream) {
        stream << Language::MAGIC_STRING_T << endl;
        stream << this->toString();           
        /*stream << getLanguageId() << endl;
        stream << getSize() << endl;
        for (int i = 0; i < getSize(); ++i) {
            stream <<  at(i).toString() << endl; 
        }*/


        if (stream)  {
            stream.close();
//            return true;
        }
        else{
            throw std::ios_base::failure(
                string("void Language::save(const char *fileName, char mode) const: ") +
                        "error writing to file " + fileName);
        }
//        cerr << "ERROR guardando datos en el fichero " << fileName << endl;
//        return false;
    }
    else{
        throw std::ios_base::failure(
                string("void Language::save(const char *fileName, char mode) const: ") +
                        "error opening file " + fileName);
    }
//    cerr << "ERROR abriendo fichero "<< fileName << endl;
//    return false;
}

void Language::load(const char *fileName) {
    string bigramString;
    int frequency;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in ); // antes ifstream flujo(fichero);
    
    string magicString;
    if (inputStream) {
        inputStream >> magicString;
        if (magicString ==  Language::MAGIC_STRING_T) { //Para ficheros texto
            int nBigrams;
            string languageId;

            inputStream >> languageId;
            this->setLanguageId(languageId);
                    
            inputStream >> nBigrams;
            if (nBigrams < 0) {
                throw std::out_of_range(
                        string("void Language::load(const char *fileName): ") +
                        "invalid number of bigrams=" + to_string(_size));
            }

            this->deallocate();
            this->allocate(nBigrams);

            for (int i = 0; i < this->getSize(); ++i) {
                inputStream >> bigramString;
                this->at(i).setBigram(Bigram(bigramString));
                inputStream >> frequency;
                this->at(i).setFrequency(frequency);
            }
        } 
        else{
            throw std::invalid_argument(
                    string("void Language::load(const char *fileName): ") + 
                    "the found magic string " + magicString + " in file " + 
                    fileName + " is not valid ");
        }
        if (inputStream) {
            inputStream.close();
        }
        else{
            throw std::ios_base::failure(
                string("void Language::load(const char *fileName): ") +
                        "error reading from file " + fileName);           
        }
    } 
    else{
        throw std::ios_base::failure(
                string("void Language::load(const char *fileName): ") +
                        "error opening file " + fileName);
    }
}

void Language::append(const BigramFreq& bigramFreq){
    this->reallocate(this->_size + 1);
//    this->_vectorBigramFreq[this->size-1] = bigramFreq;
    this->at(this->_size-1) = bigramFreq;
}

void Language::join(const Language& language){
    int pos;
    for(int i=0; i<language.getSize(); i++){
        pos = this->findBigram(language.at(i).getBigram().getText());
        if(pos>=0){ // If found
            this->at(pos).setFrequency(this->at(pos).getFrequency() + 
                    language.at(i).getFrequency());
        }
        else{ // If not found
            this->append(language.at(i));
        }
    }
}

// Private methods

void Language::setSize(int size){
    this->_size = size;
}

void Language::allocate(int nElements) {
    if (nElements > 0) {
        _size = nElements;
        _vectorBigramFreq = new BigramFreq[_size]; // cada pareja queda como "__", 0
    }
    else{
        _size = 0;
        _vectorBigramFreq = nullptr;
    }    
}

void Language::reallocate(int newSize) {
    if(newSize != this->_size){
        if(newSize > 0){
            BigramFreq *newVector = new BigramFreq[newSize];
            
            for(int i=0; i<newSize && i<_size; i++){
                newVector[i] = _vectorBigramFreq[i];       
            }
            delete[] _vectorBigramFreq;
            _vectorBigramFreq = newVector;
            _size = newSize;
        }
    }
}

void Language::deallocate() {
    //if (_vectorBigramFreq != nullptr) {
    delete[] _vectorBigramFreq;
    _vectorBigramFreq = nullptr;
    _size = 0;
    //}
}

void Language::copy(const Language& otherLanguage) {
    this->_languageId = otherLanguage.getLanguageId();
    this->_size = otherLanguage._size; // En principio, no sería necesario si se cumple la precondición
    for (int i = 0; i < otherLanguage.getSize(); ++i) {
        _vectorBigramFreq[i] = otherLanguage.at(i); // o bien: _vectorBigramFreq[i] = other[i];
    }
}