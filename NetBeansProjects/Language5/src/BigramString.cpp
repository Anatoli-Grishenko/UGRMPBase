/*
 * Metodología de la Programación: Práctica final
 * Curso 2022/2023
 */

/** 
 * @file Bigram.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include <string>
#include <cstring>

#include "Bigram.h"

using namespace std;

//Bigram::Bigram() {
//    _text = "__";
//}

Bigram::Bigram(const std::string& text) {
    if (size(text) == 2) {
        _text = text;
    }
    else{
        _text = "__"; // ¿Lanzar excepción?
    }
}

Bigram::Bigram(const char* text) : Bigram(string(text)) { // Delegating to Bigram(const std::string&): only valid with C++11 
    /*if (strlen(text) == 2) {
        _text = text;
    }
    else{
        _text = "__"; // ¿Lanzar excepción?
    }  */  
}
    
Bigram::Bigram(char first, char second) :  Bigram(string(1,first)+string(1,second)) { // Delegating to Bigram(const std::string&): only valid with C++11 
    //_text=""+first+second;
}

const char& Bigram::at(int index) const{
    if(index<0 || index>2){
        throw std::out_of_range(string("const char& Bigram::at(int index) const: ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text.at(index);
    }
}

char& Bigram::at(int index){
    if(index<0 || index>2){
        throw std::out_of_range(string("char& Bigram::at(int index): ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text.at(index);
    }
}

std::string Bigram::getText() const {
    return _text;
}

std::string Bigram::toString() const {
    ostringstream outputStream;
    outputStream << *this;
    
    return outputStream.str();
}

/*void Bigrama::setBigrama(const string& cadena) {
    if (size(cadena) == 2) {
        this->_bigrama = cadena;
    }
}

void Bigrama::setBigrama(const char cadena[]) {
    if (strlen(cadena) <= 2) {
        string s(cadena);
        setBigrama(s);
    }
}*/


const char& Bigram::operator[](int index) const {
    return _text[index];
}

char& Bigram::operator[](int index) { 
    return _text[index];
}

std::ostream& operator<<(std::ostream& os, const Bigram& bigram) {
    os << bigram._text;   
    return os;
}

std::istream& operator>>(std::istream& is, Bigram& bigram) {   
    char first, second;
    is >> first >> second;
    bigram = Bigram(first, second);
    
    return is;
}

bool operator==(const Bigram& bigram1, const Bigram& bigram2){
    return bigram1._text == bigram2._text;
}

/**
 * Checks if the given character is contained in @p validCharacters. That is, if
 * the given character can be consireded as part of a word.
 * @param character The character to check
 * @param validCharacters The set of characters that we consider as possible 
 * characters in a word. Any other character is considered as a separator.
 * @return true if the given character is contained in @p validCharacters; false
 * otherwise
 */
bool isValidCharacter(char character, const string& validCharacters) {
    return (validCharacters.find(character) < validCharacters.size());
}