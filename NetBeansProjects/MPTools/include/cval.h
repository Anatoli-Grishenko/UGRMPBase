/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   cval.h
 * Author: lcv
 *
 * Created on 16 de febrero de 2023, 13:12
 */

#ifndef CVAL_H
#define CVAL_H

#include <ostream>

class Cval : public std::streambuf {
private:
    std::string buffer;

public:
    Cval();
    void flush();
    void validate(unsigned hash) const;
    unsigned getHash() const;
    std::string toString() const;
    friend Cval& operator<<(Cval& os, const std::string & s);
    friend Cval& operator<<(Cval& os, const char* s);
    friend Cval& operator<<(Cval& os, int i);
    friend Cval& operator<<(Cval& os, double d);
    friend Cval& operator<<(Cval& os, char c);


};

Cval& operator<<(Cval& os, const std::string & s);
Cval& operator<<(Cval& os, const char* s);
Cval& operator<<(Cval& os, int i);
Cval& operator<<(Cval& os, double d);
Cval& operator<<(Cval& os, char c);

extern Cval cval;
#define endl "\n"


#endif /* CVAL_H */

