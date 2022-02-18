/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#define __USE_MP_SCALE__
#include "MPTests.h"
#include "Byte.h"

using namespace std;

TEST_F(_01_Basics, UnitByte_onBit) {
    Byte b;
    b = 0;
    onBit(b, 0);
    SKIP_ASSERT_EQ_R(b, 1) << "Given a byte 00000000, activating the 0-bit gives 1" << endl;
    b = 0;
    onBit(b, 1);
    SKIP_ASSERT_EQ_R(b, 2) << "Given a byte 00000000, activating the 1-bit gives 2" << endl;
    b = 0;
    onBit(b, 7);
    SKIP_ASSERT_EQ_R(b, 128) << "Given a byte 00000000, activating the 7-bit gives 128" << endl;
}

TEST_F(_01_Basics, UnitByte_offBit) {
    Byte b;
    b = 255;
    offBit(b, 0);
    SKIP_ASSERT_EQ_R(b, 254) << "Given a byte 11111111, deactivating the 0-bit gives 254" << endl;
    b = 255;
    offBit(b, 1);
    SKIP_ASSERT_EQ_R(b, 253) << "Given a byte 11111111, deactivating the 1-bit gives 253" << endl;
    b = 255;
    offBit(b, 7);
    SKIP_ASSERT_EQ_R(b, 127) << "Given a byte 11111111, deactivating the 7-bit gives 127" << endl;
}

TEST_F(_01_Basics, UnitByte_getBit) {
    Byte b, b2;
    b = 255;
    b2 = 0;
    for (int i = 0; i < 8; i++){
        SKIP_ASSERT_TRUE_R(getBit(b, i)) << "Given a byte 11111111, querying any bit always give true" << endl;
                }
    for (int i = 0; i < 8; i++){
        SKIP_ASSERT_FALSE_R(getBit(b2, i)) << "Given a byte 00000000, querying any bit gives false" << endl;
    }
}

TEST_F(_01_Basics, UnitByte_to_string) {
    Byte b, b2;
    b = 255;
    b2 = 0;
    SKIP_ASSERT_STREQ_R(to_string(b).c_str(), "11111111") << "A byte 11111111 prints as it is"<< endl;
    SKIP_ASSERT_STREQ_R(to_string(b2).c_str(), "00000000") << "A byte 00000000 prints as it is"<< endl;
}

TEST_F(_01_Basics, UnitByte_shiftRByte) {
    Byte b;
    b = 255;
    shiftRByte(b,1);
    SKIP_ASSERT_EQ_R(b,127) << "A byte 11111111 shifted to the right gives 127"<< endl;
    b = 255;
    shiftRByte(b,2);
    SKIP_ASSERT_EQ_R(b,63) << "A byte 11111111 shifted twice to the right gives 63"<< endl;
    b = 1;
    shiftRByte(b,1);
    SKIP_ASSERT_EQ_R(b,0) << "A byte 00000001 shifted to the right gives 0"<< endl;
}

TEST_F(_01_Basics, UnitByte_shiftLByte) {
    Byte b;
    b = 255;
    shiftLByte(b,1);
    SKIP_ASSERT_EQ_R(b,254) << "A byte 11111111 shifted to the left gives 254"<< endl;
    b = 255;
    shiftLByte(b,2);
    SKIP_ASSERT_EQ_R(b,252) << "A byte 11111111 shifted twice to the left gives 252"<< endl;
    b = 1;
    shiftLByte(b,1);
    SKIP_ASSERT_EQ_R(b,2) << "A byte 00000001 shifted to the left gives 2"<< endl;
}

TEST_F(_02_Intermediate, UnitByte_onByte) {
    Byte b=0;
    onByte(b);
    SKIP_ASSERT_EQ_R(b,255) << "Activating a Byte gives 255"<< endl;
}

TEST_F(_02_Intermediate, UnitByte_offByte) {
    Byte b=255;
    offByte(b);
    SKIP_ASSERT_EQ_R(b,0) << "Deactivating a Byte gives 0"<< endl;
}

TEST_F(_03_Advanced, UnitByte_encodeByte) {
    Byte b=0;
    bool bb[8]={true,false,false,false,false,false,true,true};
    encodeByte(b,bb);
    SKIP_ASSERT_EQ_R(b,131) << "Activating bits 0,1 and 7 gives 131"<< endl;
}

TEST_F(_03_Advanced, UnitByte_decodeByte) {
    Byte b=131;
    bool bb[8]={false,false,false,false,false,false,false};
    decodeByte(b,bb);
    SKIP_ASSERT_TRUE_R(bb[0]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_TRUE_R(bb[1]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_FALSE_R(bb[2]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_FALSE_R(bb[6]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
    SKIP_ASSERT_TRUE_R(bb[7]) << "A byte 131 gives true only in bits 0,1 and 7"<< endl;
}

TEST_F(_03_Advanced, UnitByte_decomposeByte) {
    Byte b=131;
    int pb[8]={-1,-1,-1,-1,-1,-1,-1,-1}, n;
    decomposeByte(b,pb,n);
    SKIP_ASSERT_EQ_R(n,3) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[0],0) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[1],1) << "Decomposing byte 131 gives 3 active bits"<< endl;
    SKIP_ASSERT_EQ_R(pb[2],7) << "Decomposing byte 131 gives 3 active bits"<< endl;
    
}

