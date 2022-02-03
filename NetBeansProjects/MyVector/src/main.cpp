/*
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */
#include <iostream>
#include "MPTools.h"
#include "myvector.h"

using namespace std;

/**
 * This application will make use of the class MyVector to read a sequence of 
 * chars from the keyboard, of unknown size, that ends with the char '@', which
 * is not stored. The application will reverse the sequence of char stored and 
 * build a new sequence made up of the firts 5 chars of the reversed sequence.
 * Should the reverse sequence has less than 5 chars, it will show the first 
 * chars in the reversed sequence
 * @param nargs Unused
 * @param args Unused
 * @return 0 
 */

int main() {
    // Step 1. Declare the needed variables
    MyVector initial, inverted, result;

    // Step 2. Read the sequence from keyboard.
    cout << "Please type a sequence of chars ended by '@': ";
    char c;
    cin >> c;
    while (c != ENDCHAR) {
        initial.addLetter(c);
        cin >> c;
    }
    cout << "La cadena leída es "<<initial.to_string()<< endl;
    // Step 3. Reverse the sequence 
    for (int i=initial.size()-1; i>=0; i--) {
        inverted.addLetter(initial.getLetter(i));
    }
    // Step 4. Obtain a new sequence with the first 5 chars of the reversed sequence and show it in the screen
    for (int i=0; i<5 && i<inverted.size() ; i++)
        result.addLetter(inverted.getLetter(i));
    
    //Step 5. Dump data for validation
    CVAL << endl<< "The result is: " << result.to_string()<<endl;
}

