/*
 * Metodología de la Programación: Language5
 * Curso 2022/2023
 */

/** 
 * @file BigramCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

#include "BigramCounter.h"
#include "Bigram.h"

using namespace std;

/**
 * DEFAULT_VALID_CHARACTERS is a c-string that contains the set of characters
 * that will be considered as part of a word (valid chars). 
 * The characters not in the c-string will be considered as separator of words.
 * The constructor of the class BigramCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const BigramCounter::DEFAULT_VALID_CHARACTERS="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF";


char readNextValidChar(istream& fe, const string& validChars);

BigramCounter::BigramCounter(const string& validChars) {
    //_frequency = nullptr;
    _validCharacters = validChars;
    allocate(_validCharacters.size());
    initFrecuencies();
}

BigramCounter::BigramCounter(const BigramCounter& orig) {
    allocate(orig.getSize());
    copy(orig);
}

BigramCounter::~BigramCounter() {
    deallocate();
}

int BigramCounter::getSize() const {
    return _validCharacters.size();
}

int BigramCounter::getNumberActiveBigrams() const {
    int cuantos = 0;
    for (int row = 0; row < getSize(); ++row) {
        for (int column = 0; column < getSize(); ++column) {
            if (_frequency[row][column] > 0)
                cuantos++;
        }
    }
    return cuantos;
}

bool BigramCounter::setFrecuency(const Bigram& bigram, int frecuency) { 
    int row, column;

    row = this->_validCharacters.find(bigram.at(0)); // o bien f = this->_validCharacters.find(bigram[0]);
    column = this->_validCharacters.find(bigram.at(1)); // o bien f = this->_validCharacters.find(bigram[1]);
    if (0 <= row && row < getSize() && 0 <= column && column < getSize()) {
        _frequency[row][column] = frecuency; 
        return true;
    }
    
    return false;
}

void BigramCounter::increaseFrecuency(const Bigram& bigram, int frecuency) { 
    int row, column;

    row = this->_validCharacters.find(bigram.at(0)); // o bien f = this->_validCharacters.find(bigram[0]);
    column = this->_validCharacters.find(bigram.at(1)); // o bien f = this->_validCharacters.find(bigram[1]);
    if (0 <= row && row < getSize() && 0 <= column && column < getSize()) {
        if (frecuency == 0)
            _frequency[row][column]++; 
        else
            _frequency[row][column] += frecuency;
    }
    else{
        throw std::invalid_argument(
                string("void BigramCounter::increaseFrecuency(const Bigram& bigram, int frecuency): ") +
                bigram.getText() + " is not a valid bigram");
    }
}

BigramCounter& BigramCounter::operator=(const BigramCounter& orig) {
    if (this != &orig) {  
        deallocate();
        allocate(orig.getSize());
        copy(orig);
    }
    return *this;
}

BigramCounter& BigramCounter::operator+=(const BigramCounter& rhs) {
    //Asumimos mismo conjunto de _caracteresValidos y en el mismo orden
    // En caso contrario habria que redimensionar las matrices
    if (_validCharacters == rhs._validCharacters) {
        for (int f = 0; f < getSize(); f++)
            for (int c = 0; c < getSize(); c++)
                _frequency[f][c] += rhs._frequency[f][c];
    }
    return *this;
}

const int& BigramCounter::operator()(int row, int column) const {
    return _frequency[row][column];
}

int& BigramCounter::operator()(int row, int column) {
    return _frequency[row][column];
}

bool BigramCounter::calculateFrequencies(const char* fileName) {
    ifstream fe;
    char bigramCstring[3];

    fe.open(fileName, ifstream::in);
    if (!fe) {
        cerr << "Error al abrir el fichero " << fileName << endl;
        return false;
    } else {
        bigramCstring[2] = '\0';
        
        // Leer hasta encontrar un primer carácter válido
        bigramCstring[0] = tolower(fe.get());
        while (fe && !isValidCharacter(bigramCstring[0], _validCharacters)){ 
            bigramCstring[0] = tolower(fe.get());
        }
        while (fe) {
            bigramCstring[1] = tolower(fe.get());
            if (fe) {
                if (isValidCharacter(bigramCstring[1], _validCharacters)){
                    Bigram bigram(bigramCstring);
                    this->increaseFrecuency(bigram);
                    bigramCstring[0] = bigramCstring[1];
                } 
                else{
                    // Leer hasta encontrar un primer carácter válido
                    bigramCstring[0] = tolower(fe.get());
                    while (fe && !isValidCharacter(bigramCstring[0], _validCharacters)){ 
                        bigramCstring[0] = tolower(fe.get());
                    }          
                }
            }
        }
        fe.close();
        cout << endl;
        return true;
    }
}

Language BigramCounter::toLanguage() const { // NOTA: Antiguo toIdioma()
    //char cadena[3];
    int frecuency;
    BigramFreq frecBigrama;
    Language language(this->getNumberActiveBigrams());

    for (int pos = 0, f = 0; f < getSize(); f++) {
        for (int c = 0; c < getSize(); c++) {
            frecuency = (*this)(f,c); // antes this->_frequency[f][c];
            if (frecuency > 0) {
                string cadena = string(1,this->_validCharacters.at(f)) +
                        string(1,this->_validCharacters.at(c));
                frecBigrama.setBigram(cadena);
                frecBigrama.setFrequency(frecuency);
                language.at(pos) = frecBigrama; // o bien idioma[pos] = frecBigrama; // antes: idioma.setPosicion(pos, frecBigrama);
                pos++;
            }
        }
    }
    language.sort();
    return language;
}

void BigramCounter::fromLanguage(const Language & language) {
    for (int i = 0; i < language.getSize(); i++){
        this->setFrecuency(language.at(i).getBigram(), // o bien this->increaseFrecuency(idioma[i].getBigram(),
            language.at(i).getFrequency()); // o bien idioma[i].getFrequency());
    }
}

/// Private nethods

void BigramCounter::allocate(int size) {
    if (size > 0) {
        _frequency = new int*[size];
        _frequency[0] = new int[size * size];
        for (int i = 1; i < size; ++i)
            _frequency[i] = _frequency[i - 1] + size;
        /*for (int row = 0; row < getSize(); ++row) {
            for (int column = 0; column < getSize(); ++column) {
                _frequency[row][column] = 0;
            }
        }*/
    }
    else{
        _frequency = nullptr;
    }
}

void BigramCounter::initFrecuencies() {
    for (int row = 0; row < getSize(); ++row) {
        for (int column = 0; column < getSize(); ++column) {
            _frequency[row][column] = 0;
        }
    }
}

void BigramCounter::deallocate() {
    //if (_frequency != nullptr) {
    delete[] _frequency[0];
    delete[] _frequency;
    _frequency = nullptr;
    //}
}

void BigramCounter::copy(const BigramCounter& otro) {
    _validCharacters = otro._validCharacters;
    
    for (int f = 0; f < getSize(); ++f) {
        for (int c = 0; c < getSize(); ++c) {
            (*this)(f,c) = otro(f,c); // antes _frequency[f][c] = otro._frequency[f][c];
        }
    }
}

char readNextValidChar(istream& inputStream, const string& validChars) {
    // TODO Ineficiente. Podría mejorarse usando un map como hace Huete                                                           
    // suponiendo que los caracteres en cadena están ordenados por orden alfabético
    char character, result = '\0';
    bool stop = false;
    while (inputStream && !stop) {
        character = tolower(inputStream.get());
        if (inputStream) {
            if (validChars.find(character) < validChars.size()) {
                result = character;
                stop = true;
            }
        }
    }
    return result;
}

