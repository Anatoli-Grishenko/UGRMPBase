/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "MPTools.h"
#include "Point2D.h"
#include "Rectangle.h"

using namespace std;

TEST_F(_02_Intermediate,Rectangle_Constructors) {
    string whatmustbe, whatis;
    Rectangle r1, r2(10,5,10,3);
    whatmustbe="[(0,0),(0,0)]";
    whatis=r1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Default constructor is wrong"<<endl;
    whatmustbe="[(10,5),(20,2)]";
    whatis=r2.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Parameter constructor is wrong"<<endl;
}

TEST_F(_02_Intermediate,Rectangle_setGeometry) {
    string whatmustbe, whatis;
    Point2D p1(10,5), p2(20,2);
    Rectangle r1;
    r1.setGeometry(10,5,10,3);
    whatmustbe="[(10,5),(20,2)]";
    whatis=r1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"setGeometry(int,int,int,int) is wrong"<<endl;
    r1.setGeometry(p1,p2);
    whatmustbe="[(10,5),(20,2)]";
    whatis=r1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"setGeometry(Point2D, Point2D) is wrong"<<endl;
}

TEST_F(_02_Intermediate,Rectangle_getTopLeft) {
    string whatmustbe, whatis;
    Point2D p1;
    Rectangle r1;
    r1.setGeometry(10,5,10,3);
    whatmustbe="(10,5)";
    whatis=r1.getTopLeft().inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"getTopLeft is wrong"<<endl;
    whatmustbe="(20,2)";
    whatis=r1.getBottomRight().inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"getBottomRight is wrong"<<endl;
}

TEST_F(_02_Intermediate,Rectangle_isEmpty) {
    Rectangle r1;
    Point2D p1(10,10),p2(20,2);
    r1.setGeometry(p1,p2);
    SKIP_ASSERT_FALSE_R(r1.isEmpty())<<"isEmpty is wrong"<<endl;
    r1.setGeometry(p2,p1);
    SKIP_ASSERT_TRUE_R(r1.isEmpty())<<"isEmpty is wrong"<<endl;
}


TEST_F(_03_Advanced,Rectangle_doOverlap) {
    Point2D p1(10,10),p2(20,2), pmid(15,6), porigin(0,20);
    Rectangle r1, r2, r3, result;
    string whatmustbe, whatis;
    r1.setGeometry(p1,p2);
    r2.setGeometry(pmid, p2);
    result = doOverlap(r1,r2);
    SKIP_ASSERT_FALSE_R(result.isEmpty())<<"doOverlap is wrong"<<endl;
    whatmustbe = r2.inspect();
    whatis = result.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(), whatis.c_str()) << "doOverlap is wrong"<<endl;

    r1.setGeometry(porigin,p1);
    r2.setGeometry(pmid,p2);
    result = doOverlap(r1,r2);
    SKIP_ASSERT_TRUE_R(result.isEmpty())<<"doOverlap is wrong"<<endl;
}


