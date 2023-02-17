/*
 * Metodología de la Programación: Language0
 * Curso 2022/2023
 */

/** 
 * @file Bigram.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 2 February 2023, 11:00
 */

#include <string>
#include <cstring>

#include "Bigram.h"

using namespace std;

Bigram::Bigram(const std::string& text) {
    if (text.size() == 2) {
        _text = text;
    }
    else{
        _text = "__"; // ¿Lanzar excepción?
    }
}
    
Bigram::Bigram(char first, char second) :  
        Bigram(string(1,first)+string(1,second)) { // Delegating to Bigram(const std::string&): only valid with C++11 
    //_text=""+first+second;
}

const char& Bigram::at(int index) const{
    if(index<0 || index>1){
        throw std::out_of_range(string("const char& Bigram::at(int index) const: ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text.at(index);
    }
}

char& Bigram::at(int index){
    if(index<0 || index>1){
        throw std::out_of_range(string("char& Bigram::at(int index): ") +
                "invalid position " + to_string(index));
    }
    else{
        return _text.at(index);
    }
}

std::string Bigram::getText() const{
    return _text;
}

std::string Bigram::toString() const {
    return _text;
}

bool isValidCharacter(char character, const string& validCharacters) {
    return (validCharacters.find(character) < validCharacters.size());
}

void toUpper(Bigram &bigram){
    bigram.at(0) = toupper(bigram.at(0));
    bigram.at(1) = toupper(bigram.at(1));
}