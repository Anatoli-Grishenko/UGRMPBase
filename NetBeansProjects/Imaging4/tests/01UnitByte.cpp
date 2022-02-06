/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "MPTools.h"
#define private public
#include "Byte.h"

using namespace std;

TEST_F(_01_Basics, UnitByte_Constructor) {
    Byte b, b1(1), b2(128);
    SKIP_ASSERT_EQ_R(b._data, 0) << "Declaring a Byte gives 0 by default" << endl;
    SKIP_ASSERT_EQ_R(b1._data, 1) << "Declaring a Byte(1) gives 1"  << endl;
    SKIP_ASSERT_EQ_R(b2._data, 128) << "Declaring a Byte(128) gives 128"  << endl;
}

TEST_F(_01_Basics, UnitByte_getValue) {
    Byte b, b1(1), b2(128);
    SKIP_ASSERT_EQ_R(b.getValue(), 0) << "Declaring a Byte gives 0 by default" << endl;
    SKIP_ASSERT_EQ_R(b1.getValue(), 1) << "Declaring a Byte(1) gives 1"  << endl;
    SKIP_ASSERT_EQ_R(b2.getValue(), 128) << "Declaring a Byte(128) gives 128"  << endl;
}

TEST_F(_01_Basics, UnitByte_setValue) {
    Byte b, b1, b2;
    b.setValue(0);
    b1.setValue(1);
    b2.setValue(128);
    SKIP_ASSERT_EQ_R(b.getValue(), 0) << "Declaring a Byte and setting its value to 0 gives 0 by default" << endl;
    SKIP_ASSERT_EQ_R(b1.getValue(), 1) << "Declaring a Byte and setting its value to 1 gives 1"  << endl;
    SKIP_ASSERT_EQ_R(b2.getValue(), 128) << "Declaring a Byte and setting its value to 128 gives 128"  << endl;
}

TEST_F(_01_Basics, UnitByte_onBit) {
    Byte b;
    b.setValue(0);
    b.onBit(0);
    SKIP_ASSERT_EQ_R(b.getValue(), 1) << "Given a byte 00000000, activating the 0-bit gives 1" << endl;
    b.setValue(0);
    b.onBit(1);
    SKIP_ASSERT_EQ_R(b.getValue(), 2) << "Given a byte 00000000, activating the 1-bit gives 2" << endl;
    b.setValue(0);
    b.onBit(7);
    SKIP_ASSERT_EQ_R(b.getValue(), 128) << "Given a byte 00000000, activating the 7-bit gives 128" << endl;
}

TEST_F(_01_Basics, UnitByte_offBit) {
    Byte b;
    b.setValue(255);
    b.offBit(0);
    SKIP_ASSERT_EQ_R(b.getValue(), 254) << "Given a byte 11111111, deactivating the 0-bit gives 254" << endl;
    b.setValue(255);
    b.offBit(1);
    SKIP_ASSERT_EQ_R(b.getValue(), 253) << "Given a byte 11111111, deactivating the 1-bit gives 253" << endl;
    b.setValue(255);
    b.offBit(7);
    SKIP_ASSERT_EQ_R(b.getValue(), 127) << "Given a byte 11111111, deactivating the 7-bit gives 127" << endl;
}

TEST_F(_01_Basics, UnitByte_getBit) {
    Byte b, b2;
    b.setValue(255);
    b2.setValue(0);
    for (int i = 0; i < 8; i++){
        SKIP_ASSERT_TRUE_R(b.getBit( i)) << "Given a byte 11111111, querying any bit always give true" << endl;
                }
    for (int i = 0; i < 8; i++){
        SKIP_ASSERT_FALSE_R(b2.getBit(i)) << "Given a byte 00000000, querying any bit gives false" << endl;
    }
}

TEST_F(_01_Basics, UnitByte_to_string) {
    Byte b, b2;
    b.setValue(255);
    b2.setValue(0);
    SKIP_ASSERT_STREQ_R(b.to_string().c_str(), "11111111") << "A byte 11111111 prints as it is"<< endl;
    SKIP_ASSERT_STREQ_R(b2.to_string().c_str(), "00000000") << "A byte 00000000 prints as it is"<< endl;
}

TEST_F(_01_Basics, UnitByte_shiftRByte) {
    Byte b;
    b.setValue(255);
    b.shiftRByte(1);
    SKIP_ASSERT_EQ_R(b.getValue(),127) << "A byte 11111111 shifted to the right gives 127"<< endl;
    b.setValue(255);
    b.shiftRByte(2);
    SKIP_ASSERT_EQ_R(b.getValue(),63) << "A byte 11111111 shifted twice to the right gives 63"<< endl;
    b.setValue(1);
    b.shiftRByte(1);
    SKIP_ASSERT_EQ_R(b.getValue(),0) << "A byte 00000001 shifted to the right gives 0"<< endl;
}

TEST_F(_01_Basics, UnitByte_shiftLByte) {
    Byte b;
    b.setValue(255);
    b.shiftLByte(1);
    SKIP_ASSERT_EQ_R(b.getValue(),254) << "A byte 11111111 shifted to the left gives 254"<< endl;
    b.setValue(255);
    b.shiftLByte(2);
    SKIP_ASSERT_EQ_R(b.getValue(),252) << "A byte 11111111 shifted twice to the right gives 252"<< endl;
    b.setValue(1);
    b.shiftLByte(1);
    SKIP_ASSERT_EQ_R(b.getValue(),2) << "A byte 00000001 shifted to the right gives 2"<< endl;
}

TEST_F(_02_Intermediate, UnitByte_onByte) {
    Byte b=0;
    b.onByte();
    SKIP_ASSERT_EQ_R(b.getValue(),255) << "Activating a Byte gives 255"<< endl;
}

TEST_F(_02_Intermediate, UnitByte_offByte) {
    Byte b=255;
    b.offByte();
    SKIP_ASSERT_EQ_R(b.getValue(),0) << "Deactivating a Byte gives 0"<< endl;
}

TEST_F(_03_Advanced, UnitByte_encodeByte) {
    Byte b=0;
    bool bb[8]={true,false,false,false,false,false,true,true};
    b.encodeByte(bb);
    SKIP_ASSERT_EQ_R(b.getValue(),131) << "Activating bits 0,1 and 7 gives 131"<< endl;
}

TEST_F(_03_Advanced, UnitByte_decodeByte) {
    Byte b=131;
    bool bb[8]={false,false,false,false,false,false,false};
    b.decodeByte(bb);
    SKIP_ASSERT_TRUE_R(bb[0]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_TRUE_R(bb[1]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_FALSE_R(bb[2]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_FALSE_R(bb[6]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_TRUE_R(bb[7]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
}

TEST_F(_03_Advanced, UnitByte_decomposeByte) {
    Byte b=131;
    int pb[8]={-1,-1,-1,-1,-1,-1,-1,-1}, n;
    b.decomposeByte(pb,n);
    SKIP_ASSERT_EQ_R(n,3) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[0],0) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[1],1) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[2],7) << "Decomposing byte 131 gives 3 active bits"<< endl;
    
}

