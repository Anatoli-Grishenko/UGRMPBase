/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "MPTools.h"
#include "Point2D.h"

using namespace std;

#ifdef __INTEGRATION__

TEST_F(_03_Advanced, INTEGRATION_v_0inside)  { 
    string saux, whatstringmustbe, whatstringis, file;
    DEF_EXECUTION_ENVIRONMENT(INTEGRATION_ImageP2);
    FROM_KEYBOARD("4 3 8 0 0 0 1 1 -1 0");
    EXPECTED_OUTPUT(
            [A] [(2,5),(5,2)] [B] [(4,3),(8,0)] [Intersection] [(4,3),(5,2)] The intersection is: None of them falls within the intersection);
    CALL_FROM_KEYBOARD("")<<"The execution of the program does not produce the expected output"<<endl;
}

TEST_F(_03_Advanced, INTEGRATION_v_1inside)  { 
    string saux, whatstringmustbe, whatstringis, file;
    DEF_EXECUTION_ENVIRONMENT(INTEGRATION_ImageP2);
    FROM_KEYBOARD("5 5 8 0  0 0 1 1 2 2  3 3  4 4  5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12  13 13 14 14 15 15 -1 0");
    EXPECTED_OUTPUT(
[A] [(2,5),(5,2)] [B] [(5,5),(8,0)] [Intersection] [(5,5),(5,2)] The intersection is: fall within the intersection (1 total)
            );
    CALL_FROM_KEYBOARD("")<<"The execution of the program does not produce the expected output"<<endl;
}

TEST_F(_03_Advanced, INTEGRATION_v_4inside)  { 
    string saux, whatstringmustbe, whatstringis, file;
    DEF_EXECUTION_ENVIRONMENT(INTEGRATION_ImageP2);
    FROM_KEYBOARD("1 6 6 1  0 0 1 1 2 2  3 3  4 4  5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12  13 13 14 14 15 15 -1 0");
    EXPECTED_OUTPUT(
[A] [(2,5),(5,2)] [B] [(1,6),(6,1)] [Intersection] [(2,5),(5,2)] The intersection is: fall within the intersection (4 total)           );
    CALL_FROM_KEYBOARD("")<<"The execution of the program does not produce the expected output"<<endl;
}


TEST_F(_03_Advanced, INTEGRATION_v_empty)  { 
    string saux, whatstringmustbe, whatstringis, file;
    DEF_EXECUTION_ENVIRONMENT(INTEGRATION_ImageP2);
    FROM_KEYBOARD("15 5 20 0 0 0 1 1 2 2  3 3  4 4  5 5 6 6 7 7 8 8 9 9 10 10 11 11 12 12  13 13 14 14 15 15 -1 0");
    EXPECTED_OUTPUT(
[A] [(2,5),(5,2)] [B] [(15,5),(20,0)] [Intersection] [(15,5),(5,2)] Empty intersection
            );
    CALL_FROM_KEYBOARD("")<<"The execution of the program does not produce the expected output"<<endl;
}


#endif