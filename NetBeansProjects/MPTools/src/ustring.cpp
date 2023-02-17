/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "MPTools.h"
#include "ustring.h"
using namespace std;

ustring::ustring() {
    udata = "";
}

ustring::ustring(int k, char c) {
    udata = toISO(string(k, c));
}

void ustring::copy(const ustring &us) {
    udata = us.udata;
}

void ustring::copy(const string &s) {
    udata = toISO(s);
}

void ustring::copy(const char s[]) {
    udata = toISO(s);
}

ustring::ustring(const ustring &us) {
    copy(us);
}

ustring::ustring(const std::string &us) {
    udata = toISO(us);
}

ustring::ustring(const char * s) {
    copy(s);
}

ustring & ustring::operator=(const ustring &us) {
    copy(us);
    return *this;
}

ustring & ustring::operator=(const string & s) {
    copy(s);
    return *this;
}

ustring & ustring::operator=(const char  s[]) {
    copy(s);
    return *this;
}

int ustring::size() const {
    return udata.size();
}

 const char &ustring::at(int i) const {
    return udata.at(i);
}

 char &ustring::at(int i)  {
    return udata.at(i);
}

int ustring::find(const char c) const{
    return udata.find(c);
}

ostream & operator<<(ostream & os, const ustring & us) {
    os << us.toString()<<".....";
    return os;
}

std::istream & operator>>(std::istream & is, ustring & us) {
    string aux;
    is >> aux;
    us = aux;
    return is;
}
    bool   ustring::operator==(const ustring &us) {
        return udata==us.udata;
    }

std::string ustring::toString() const {
    return toUTF(udata);
}

std::string ustring::getText() const {
    return udata;
}
