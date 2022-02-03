#include "myvector.h"
#include "gtest/gtest.h"
#include "MPTests.h"

using namespace std;

#ifdef __INTEGRATION__


TEST(_04_BasicIntegration, REGULARSEQUENCE)  { 
    DEF_EXECUTION_ENVIRONMENT(REGULARSEQUENCE);
    FROM_KEYBOARD( "12345678@ "); 
    EXPECTED_TEXT_OUTPUT( "The result is: 87654");
    CALL_FROM_KEYBOARD( "")<< "Processing a regular sequence gives the last 5 chars of that sequence in reverse order" << endl;
}

TEST(_04_BasicIntegration, EMPTYSEQUENCE)  { 
    DEF_EXECUTION_ENVIRONMENT(EMPTYSEQUENCE);
    FROM_KEYBOARD("@ ");    
    EXPECTED_TEXT_OUTPUT("The result is: ");
    CALL_FROM_KEYBOARD("")<< "Processing an empty sequence will give an empty sequence" << endl;
}

TEST(_04_BasicIntegration, SHORTSEQUENCE)  { 
    DEF_EXECUTION_ENVIRONMENT(SHORTSEQUENCE);
    FROM_KEYBOARD("123@ ");    
    EXPECTED_TEXT_OUTPUT("The result is: 321");
    CALL_FROM_KEYBOARD("")<< "Processing a sequence shorter than 5 gives the reverse of that sequence" << endl;
}

TEST(_05_SafeIntegration, LONGSEQUENCE)  { 
    DEF_EXECUTION_ENVIRONMENT(LONGSEQUENCE);
    FROM_KEYBOARD( "abcdefghijklmno@ ");    
    EXPECTED_TEXT_OUTPUT( "The result is: jihgf");
    CALL_FROM_KEYBOARD( "") << "Processing a sequence that exceeds MAXVECTOR gives the last 5 chars of the first MAXVECTOR chars" << endl;
}

#endif

