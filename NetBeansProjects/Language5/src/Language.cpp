/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstring>

#include "Language.h"

using namespace std;

const string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";
const string Language::MAGIC_STRING_B="MP-LANGUAGE-B-1.0";

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
    _languageId="unknown";
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
    if (0 <= index && index < getSize()) /// Acceso seguro
        return _vectorBigramFreq[index];
    else    
        throw std::out_of_range(string("const BigramFreq& Language::at(int index) const: ") +
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
}

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

int Language::findBigram(const Bigram& bigram) const { // const string& bg) const  {
    for (int i = 0; i < getSize(); ++i) {
        if (bigram == this->at(i).getBigram()) { // o bien if (bigrama == (*this)[i].getBigram()) {
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
            if (this->at(j)>this->at(pos)) // o bien if ((*this)[j]>(*this)[pos])
                pos = j;
        if (pos != i)  {
            aux = this->at(i); // o bien aux = (*this)[i];
            this->at(i) = this->at(pos);// o bien (*this)[i] = (*this)[pos]; antes: setPosicion(i,at(pos));
            this->at(pos) = aux; // o bien (*this)[pos] = aux; antes: setPosicion(pos,aux);
        }
    }
}

void Language::save(const char *fileName, char mode) const {
    ofstream stream(fileName, ios::out | ios::binary); // antes ofstream flujo(fichero, ios::out);

    if (stream) {
        if (mode == 't') {
            stream << Language::MAGIC_STRING_T << endl;
            stream << *this << endl;
        }
        else{ // mode == 'b'
            char bigram[3];
            stream << Language::MAGIC_STRING_B << endl;
            stream << this->getLanguageId() << endl;
            stream << this->getSize() << endl;
            
            stream.write(reinterpret_cast<char *>(_vectorBigramFreq),
                    sizeof(BigramFreq)*this->getSize());
            /*
            for(int i=0; i< this->getSize(); i++){
//                strcpy(bigram, _vectorBigramFreq[i].getBigram().getText().c_str());
                strcpy(bigram, this->at(i).getBigram().getText().c_str());
                stream.write(bigram, sizeof(bigram));
//                stream.write(reinterpret_cast<char *> (_vectorBigramFreq[i].getFrequency()), 
//                        sizeof(int));
                stream.write(reinterpret_cast<char *> (this->at(i).getFrequency()),
                        sizeof(int)); Esto estaría mal. Parámetro 1 debe ser puntero               
            }    */    
        }
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
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in | ios::binary); // antes ifstream flujo(fichero);
    string magicString;

    if (inputStream) {
        inputStream >> magicString;
        if (magicString == Language::MAGIC_STRING_T) { //Para ficheros texto
            inputStream >> *this;
        } else if (magicString == Language::MAGIC_STRING_B){ //Para ficheros binarios
            char bigram[3];
            int frequency;
            int nBigrams;
            string languageId;
                        
//            inputStream>>_languageId; // Leer idioma
            inputStream >> languageId;
            this->setLanguageId(languageId); 
            
//            inputStream>>_size; // Leer número de bigramas
            inputStream >> nBigrams;
            if (nBigrams < 0) {
                throw std::out_of_range(
                        string("void Language::load(const char *fileName): ") +
                        "invalid number of bigrams=" + to_string(_size));
            }
            inputStream.get(); // Leer \n que hay tras _nBigramas
            
            deallocate();
//            allocate(_size);
            allocate(nBigrams);
            
            inputStream.read(reinterpret_cast<char *>(_vectorBigramFreq),
                    sizeof(BigramFreq)*this->getSize());
            
//            for(int i=0; i<this->getSize(); i++){
//                inputStream.read(bigram, sizeof(bigram)); // Read bigram as a c-string
//                inputStream.read(reinterpret_cast<char *> (&frequency), sizeof(int)); // Read frequency
//                this->at(i).setBigram(string(bigram));
//                this->at(i).setFrequency(frequency);               
//            }
        }
        else {
            throw std::invalid_argument(
                string("void Language::load(const char *fileName): ") + 
                "the found magic string " + magicString + " in file " + 
                fileName + " is not valid ");       
        }
        if (inputStream) {
            inputStream.close();
//            return true;
        }
        else{
            throw std::ios_base::failure(
                string("void Language::load(const char *fileName): ") +
                        "error reading from file " + fileName);           
        }        
//        cerr << "ERROR cargando datos del fichero " << fileName << endl;
//        return false;
    } 
    else{
        throw std::ios_base::failure(
                string("void Language::load(const char *fileName): ") +
                        "error opening file " + fileName);
    }    
//    cerr << "ERROR abriendo fichero "<< fileName << endl;
//    return false;
}

BigramFreq& Language::operator[](int index) const {
    return _vectorBigramFreq[index];
}

BigramFreq& Language::operator[](int index) { 
    return _vectorBigramFreq[index];
}

Language& Language::operator+=(const BigramFreq& bigramFreq){
    this->reallocate(this->_size + 1);
    this->at(this->_size-1) = bigramFreq;
    
    return *this;
}

Language& Language::operator+=(const Language& language){
    int pos;
    for(int i=0; i<language.getSize(); i++){
        pos = this->findBigram(language.at(i).getBigram().getText());
        if(pos>=0){ // If found
            this->at(pos).setFrequency(this->at(pos).getFrequency() + 
                    language.at(i).getFrequency());
        }
        else{ // If not found
            (*this)+=language.at(i);
        }
    }
    
    return *this;
}

ostream& operator<<(ostream& os, const Language & language) {
    os << language.getLanguageId() << endl;
    //cout << "Idioma " << idioma.getLanguage() << endl;
    os << language.getSize() << endl;
    //cout << "Escribiendo " << idioma.getSize() << " bigramas" << endl;
    for (int i = 0; i < language.getSize(); ++i) {
        os <<  language.at(i) << endl; // o bien os <<  idioma[i] << endl;
    }
    return os;
}

istream& operator>>(istream& is, Language& language) {
    string languageId;
    int numberBigrams;
    BigramFreq bgr;
    
    language.deallocate();
    
    is >> languageId; // Read language identifier
    is >> numberBigrams; // Read the number of bigrams
    if (numberBigrams < 0) {
        throw std::out_of_range(
                string("istream& operator>>(istream& is, Language& language): ") +
                "the number of bigrams read " + to_string(numberBigrams) + " is not valid ");
    }
    language.allocate(numberBigrams);
    
    Language iaux(numberBigrams);
    iaux.setLanguageId(languageId);
    for (int i = 0; i < iaux.getSize(); ++i) {
        is >> bgr;
        iaux.at(i) = bgr; // o bien iaux[i] = bgr; antes: iaux.setPosicion(i,bgr);
    }
    language = iaux;
    return is;
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