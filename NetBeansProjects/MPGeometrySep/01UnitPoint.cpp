#include <iostream>
#include <string>
#include "MPTools.h"
#include "Point2D.h"

using namespace std;

TEST_F(_01_Basics,Point_Constructors) {
    string whatmustbe, whatis;
    Point2D p1, p2(10,5);
    whatmustbe="(0,0)";
    whatis=p1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Default constructor must initialize a point to (0,0)"<<endl;
    whatmustbe="(10,5)";
    whatis=p2.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Parameter constructor set to (10,5) must initialize a point to (10,5)"<<endl;
}

TEST_F(_01_Basics,Point_setX_Y) {
    string whatmustbe, whatis;
    Point2D p1;

    p1.setX(100);
    whatmustbe="(100,0)";
    whatis=p1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Method setX() is wrong"<<endl;
    p1.setY(50);
    whatmustbe="(100,50)";
    whatis=p1.inspect();
    SKIP_ASSERT_STREQ_R(whatmustbe.c_str(),whatis.c_str())<<"Method setY() is wrond" <<endl;
}

TEST_F(_01_Basics,Point_getX_Y) {
    int whatmustbe, whatis;
    Point2D p1;

    p1.setX(100);
    whatmustbe=100;;
    whatis=p1.getX();
    SKIP_ASSERT_EQ_R(whatmustbe,whatis)<<"Method getX() is wrong"<<endl;
    p1.setY(50);
    whatmustbe=50;
    whatis=p1.getY();
    SKIP_ASSERT_EQ_R(whatmustbe,whatis)<<"Method getY() is wrond" <<endl;
}

