/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "myvector.h"
#include "gtest/gtest.h"
#include "MPTests.h"
using namespace std;


TEST(_02_Modifiers, getLetter) {
    MyVector mv;

    for (int i = 0; i <= MAXVECTOR / 2; i++)
        mv.addLetter('A' + i);
    int pos = 0;
    SKIP_ASSERT_EQ_R(mv.to_string()[pos],mv.getLetter(pos)) << "Getting the position 0 of MyVector gives the same char that the position 0 of its serialization" << endl;
    pos = MAXVECTOR / 2;
    SKIP_ASSERT_EQ_R(mv.to_string()[pos],mv.getLetter(pos)) << "Getting the last position of MyVector gives the same char that the last of its serialization" << endl;
}

TEST(_02_Modifiers, setLetter) {
    MyVector mv;

    for (int i = 0; i < MAXVECTOR / 2; i++)
        mv.addLetter('A' + i);
    char letter = '1';
    int pos = 0;
    mv.setLetter(pos, letter);
    SKIP_ASSERT_EQ_R(letter, mv.getLetter(pos)) << "Setting a char on any valid position of MyVector allows to get the same char in the same position" << endl;
    pos = mv.size()-1;
    letter='2';
    mv.setLetter(pos, letter);
    SKIP_ASSERT_EQ_R(letter, mv.getLetter(pos)) << "Setting a char on any valid position of MyVector allows to get the same char in the same position" << endl;
}

TEST(_03_SafeAccess, addLetter_safe) {
    MyVector mv;
    for (int i = 0; i <= MAXVECTOR; i++)
        mv.addLetter('A');
    SKIP_ASSERT_EQ_R(MAXVECTOR, mv.size()) << "No more than MAXVECTOR letters can be never added" << endl;
}

TEST(_03_SafeAccess, getLetter_safe) {
    MyVector mv;

    for (int i = 0; i <= MAXVECTOR / 2; i++)
        mv.addLetter('A' + i);
    int pos = MAXVECTOR / 2 + 1;
    SKIP_ASSERT_EQ_R('\0', mv.getLetter(pos)) << "Accesing MyVector beyond its number of stored letters gives a '\\0' char" << endl;
    pos = MAXVECTOR + 1;
    SKIP_ASSERT_EQ_R('\0', mv.getLetter(pos)) << "Accesing MyVector beyond MAXVECTOR gives a '\\0' char" << endl;
    pos = -10;
    SKIP_ASSERT_EQ_R('\0', mv.getLetter(pos)) << "Accesing MyVector with a negative index gives a '\\0' char" << endl;
}

TEST(_03_SafeAccess, setLetter_safe) {
    MyVector mv;

    for (int i = 0; i < MAXVECTOR / 2; i++)
        mv.addLetter('A' + i);
    char letter = '1';
    int pos = 0;    
    string last = mv.reportData();
    mv.setLetter(mv.size()+1, '!');
    SKIP_ASSERT_STREQ_R(last.c_str(), mv.reportData().c_str()) << "Setting a char beyond its number of stored letters gives MaxVector unaltered" << endl;
    mv.setLetter(-1, '!');
    SKIP_ASSERT_STREQ_R(last.c_str(), mv.reportData().c_str()) << "Setting a char in a negative positoin gives MaxVector unaltered" << endl;
}

