/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ustring.h
 * Author: lcv
 *
 * Created on 15 de febrero de 2023, 19:07
 */

#ifndef USTRING_H
#define USTRING_H

class ustring {
public:
    ustring();
    ustring(int k, char c);
    ustring(const char * s);
    ustring(const ustring &s);
    ustring(const std::string &s);
    bool operator==(const ustring &us);
    ustring & operator=(const ustring &us);
    ustring & operator=(const std::string &s);
    ustring & operator=(const char s[]);
    int size() const;
    const char &at(int i)const;
    char &at(int i);
    int find(const char c) const;
    char * c_str() const;
    std::string toString() const;
    std::string getText() const;
    friend std::ostream & operator<<(std::ostream & os, const ustring & us);
    friend std::istream & operator>>(std::istream & os, ustring & us);

private:
    std::string udata;

    void copy(const ustring & us);
    void copy(const std::string & s);
    void copy(const char s[]);


};

std::ostream & operator<<(std::ostream & os, const ustring & us);
std::istream & operator>>(std::istream & is, ustring & us);


#endif /* USTRING_H */

