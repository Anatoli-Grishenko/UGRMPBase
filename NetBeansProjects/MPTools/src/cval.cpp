/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "MPTools.h"
#include "cval.h"

using namespace std;

const char SEP = '.';
const string TOREMOVE = " \t\n\r";

bool isSEP(char c) {
    return TOREMOVE.find(c) != string::npos;
}
//string cleanUp(string s) {
//    string aux = "", remove = ;
//    int i = 0;
//    while (i < s.length()) {
//        if (remove.find(s[i]) == string::npos) {
//            aux += s[i];
//            i++;
//        } else {
//            while (i < s.length() && remove.find(s[i]) != string::npos)i++;
//            aux += SEP;
//        }
//    }
//    return aux;
//}

Cval cval;

Cval::Cval() {
    flush();
}

void Cval::flush() {
    buffer = "";
}

unsigned Cval::getHash() const {
    return mphash((unsigned char *) buffer.c_str(), buffer.length());
}

void Cval::validate(unsigned hash) const {
    if (getHash() != hash) {
        cout << endl << ErrorMessage("UNEXPECTED OUTPUT") << endl;
    } else
        cout << endl << ValidationMessage("THE OUTPUT IS RIGHT") << endl;

}

Cval& operator<<(Cval& os, const std::string & s) {
    for (int i = 0; i < s.length(); i++) {
        if (!isSEP(s[i])) {
            os.buffer += s[i];
        } else if (isSEP(s[i]) && os.buffer[os.buffer.length() - 1] != SEP) {
            os.buffer += SEP;
        }
    }
    cout << s;

    return os;
}

Cval& operator<<(Cval& os, const char* s) {
    string aux = s;
    os << aux;

    return os;
}

Cval& operator<<(Cval& os, int i) {
    string aux = std::to_string(i);
    os << aux;

    return os;
}

Cval& operator<<(Cval& os, double d) {
    string aux = std::to_string(d);
    os << aux;

    return os;
}

Cval& operator<<(Cval& os, char c) {
    string aux = "" + c;
    os << aux;

    return os;
}

string Cval::toString() const {
    return toUTF(buffer);
}



