# TESTS DOCUMENTATION FOR PROJECT Practica0

    
## _01_Basics 
    
###  UnitByte_onBit 
1. Given a byte 00000000, activating the 0-bit gives 1
1. Given a byte 00000000, activating the 1-bit gives 2
1. Given a byte 00000000, activating the 7-bit gives 128
    
###  UnitByte_offBit 
1. Given a byte 11111111, deactivating the 0-bit gives 254
1. Given a byte 11111111, deactivating the 1-bit gives 253
1. Given a byte 11111111, deactivating the 7-bit gives 127
    
###  UnitByte_getBit 
1. Given a byte 11111111, querying any bit always give true
1. Given a byte 00000000, querying any bit gives false
    
###  UnitByte_to_string 
1. A byte 11111111 prints as it is
1. A byte 00000000 prints as it is
    
###  UnitByte_shiftRByte 
1. A byte 11111111 shifted to the right gives 127
1. A byte 11111111 shifted twice to the right gives 63
1. A byte 00000001 shifted to the right gives 0
    
###  UnitByte_shiftLByte 
1. A byte 11111111 shifted to the left gives 254
1. A byte 11111111 shifted twice to the right gives 252
1. A byte 00000001 shifted to the right gives 2
    
###  INTEGRATION_Byte 
1. The output of the main program must match that of the assignment
    
## _02_Intermediate 
    
###  UnitByte_onByte 
1. Activating a Byte gives 255
    
###  UnitByte_offByte 
1. Deactivating a Byte gives 0
    
## _03_Advanced 
    
###  UnitByte_encodeByte 
1. Activating bits 0,1 and 7 gives 131
    
###  UnitByte_decodeByte 
1. A byte 131 gives true only in bits 0,1 and 7
1. A byte 131 gives true only in bits 0,1 and 7
1. A byte 131 gives true only in bits 0,1 and 7
1. A byte 131 gives true only in bits 0,1 and 7
1. A byte 131 gives true only in bits 0,1 and 7
    
###  UnitByte_decomposeByte 
1. Decomposing byte 131 gives 3 active bits
1. Decomposing byte 131 gives 3 active bits
1. Decomposing byte 131 gives 3 active bits
1. Decomposing byte 131 gives 3 active bits
