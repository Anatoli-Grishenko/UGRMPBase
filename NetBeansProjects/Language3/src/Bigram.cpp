/*
 * Metodología de la Programación: Language3
 * Curso 2022/2023
 */

/** 
 * @file Bigram.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 12 February 2023, 10:40
 */

#include <string>
#include <cstring>

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
    
Bigram::Bigram(char first, char second) { 
    _text[0] = first;
    _text[1] = second;
    _text[2] = '\0';
}

Bigram::Bigram(const char* text)  { 
    if (strlen(text) == 2) {
        strcpy(_text, text);
    }
    else{
        strcpy(_text, "__");  // ¿Lanzar excepción?
    } 
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

std::string Bigram::getText() const{
    return string(_text);
}

std::string Bigram::toString() const {
    return string(_text);
}

void Bigram::toUpper() {
    at(0) = toupper(at(0));
    at(1) = toupper(at(1));
}

bool isValidCharacter(char character, const string& validCharacters) {
    return (validCharacters.find(character) < validCharacters.size());
}

