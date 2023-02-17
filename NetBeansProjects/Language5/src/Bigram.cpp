/*
 * Metodología de la Programación: Language5
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
#include <sstream>

#include "Bigram.h"

using namespace std;

Bigram::Bigram(const std::string& text) {
    if (text.size() == 2) {
        strcpy(_text,text.c_str());
    }
    else{
        strcpy(_text, "__"); // ¿Lanzar excepción?
    }
}

Bigram::Bigram(const char* text)  { 
    if (strlen(text) == 2) {
        strcpy(_text, text);
    }
    else{
        strcpy(_text, "__");  // ¿Lanzar excepción?
    } 
}
    
Bigram::Bigram(char first, char second) { 
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';
}

const char& Bigram::at(int index) const{
    if(index<0 || index>1){
        throw std::out_of_range(string("const char& Bigram::at(int index) const: ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text[index];
    }
}

char& Bigram::at(int index){
    if(index<0 || index>1){
        throw std::out_of_range(string("char& Bigram::at(int index): ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text[index];
    }
}

std::string Bigram::getText() const {
    return string(_text);
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

void Bigram::toUpper() {
    at(0) = toupper(at(0));
    at(1) = toupper(at(1));
}

bool isValidCharacter(char character, const string& validCharacters) {
    return (validCharacters.find(character) < validCharacters.size());
}

std::ostream& operator<<(std::ostream& os, const Bigram& bigram) {
    os << bigram._text;   
    return os;
}

std::istream& operator>>(std::istream& is, Bigram& bigram) {
    char first, second;
//    if(is){
//        first = is.get();
//        second = is.get();
//    }
//    if(is){
//        bigram = Bigram(first, second);
//    }
//    else{
//        bigram = Bigram();
//    }
    is >> first >> second;
    bigram = Bigram(first, second);
    
    return is;
}

bool operator==(const Bigram& bigram1, const Bigram& bigram2){
    if(strcmp(bigram1._text, bigram2._text)==0){
        return true;
    }
    else{
        return false;
    }
}

bool operator<(const Bigram& bigram1, const Bigram& bigram2){
    return bigram1.getText() < bigram2.getText();
}

bool operator!=(const Bigram& bigram1, const Bigram& bigram2){
    return !(bigram1 == bigram2);
}

bool operator<=(const Bigram& bigram1, const Bigram& bigram2){
    return (bigram1<bigram2) || (bigram1==bigram2);
}

bool operator>(const Bigram& bigram1, const Bigram& bigram2){
    return !(bigram1<=bigram2);
}

bool operator>=(const Bigram& bigram1, const Bigram& bigram2){
    return !(bigram1 <bigram2);
}
