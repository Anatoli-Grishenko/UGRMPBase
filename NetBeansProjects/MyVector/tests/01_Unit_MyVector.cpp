/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "myvector.h"
#include "gtest/gtest.h"
#include "MPTests.h"

using namespace std;

TEST(_01_BasicPerformance, Constructor) {
    MyVector mv;
    SKIP_ASSERT_EQ_R(0, mv.size()) << "The size of a newly created instance of MyVector must be 0" << endl;  
    SKIP_ASSERT_STREQ_R("", mv.to_string().c_str()) << "The serialization of a newly created instance of MyVector must be an empty string" << endl;
    string result(MAXVECTOR,EMPTYCHAR);
    result ="0,"+result;
    SKIP_ASSERT_STREQ_R(result.c_str(), mv.reportData().c_str()) << "A newly created instance of MyVector contains all its values to EMPTYCHAR in its inspection" << endl;
}


TEST(_01_BasicPerformance, addLetter) {
    MyVector mv;
    char letter = 'A', another = 'B';
    mv.addLetter(letter);
    SKIP_ASSERT_EQ_R(1, mv.size()) << "Adding a letter to an empty MyVector gives a size equal to 1" << endl;
    SKIP_ASSERT_EQ_R(1, mv.to_string().length()) << "Adding a letter to an empty MyVector produces a to_string() whose length is 1" << endl;
    SKIP_ASSERT_EQ_R(letter, mv.to_string()[0]) << "Adding a letter to an empty MyVector produces a to_string() whose first element is that letter" << endl;
}

TEST(_01_BasicPerformance, addLetter_2) {
    MyVector mv;
    char letter = 'A', another = 'B';
    mv.addLetter(letter);
    mv.addLetter(letter);
    mv.addLetter(letter);
    mv.addLetter(another);
    SKIP_ASSERT_EQ_R(another, mv.to_string()[mv.to_string().length() - 1]) << "Adding a sequence of letters to an empty MyVector produces a to_string() whose last element matches the last letter" << endl;
}

TEST(_01_BasicPerformance, clear) {
    MyVector mv;

    mv.clear();
    SKIP_ASSERT_EQ_R(0, mv.size()) << "After clearing a newly created instance of MyVector its size must be 0" << endl;
    SKIP_ASSERT_STREQ_R("", mv.to_string().c_str()) << "After clearing a newly created instance of MyVector its serialization must be an empty string" << endl;
    string result(MAXVECTOR,EMPTYCHAR);
    result ="0,"+result;
    SKIP_ASSERT_STREQ_R(result.c_str(), mv.reportData().c_str()) << "After clearing a newly created instance of MyVector contains all its values to EMPTYCHAR in its inspection" << endl;

    char letter = 'A';
    mv.addLetter(letter);
    mv.addLetter(letter);
    mv.addLetter(letter);
    mv.clear();
    SKIP_ASSERT_EQ_R(0, mv.size()) << "Clearing a non-empty instance of MyVector gives a size of 0" << endl;
    SKIP_ASSERT_STREQ_R("", mv.to_string().c_str()) << "Clearing a non-empty instance of MyVector gives an empty string as its serialization" << endl;
    SKIP_ASSERT_STREQ_R(result.c_str(), mv.reportData().c_str()) << "Clearing a non-empty instance of MyVector contains all its values to EMPTYCHAR in its inspection" << endl;
}

int main() {

    MAIN_BODY() {
    }
    RETURN_MAIN(0);
}
