# TESTS DOCUMENTATION FOR PROJECT MyVectorDEMO
1. ## Suite  _01_BasicPerformance

   A. ## Test  Constructor

      1. The size of a newly created instance of MyVector must be 0

      1. The serialization of a newly created instance of MyVector must be an empty string

      1. A newly created instance of MyVector contains all its values to EMPTYCHAR in its inspection

   A. ## Test  addLetter

      1. Adding a letter to an empty MyVector gives a size equal to 1

      1. Adding a letter to an empty MyVector produces a to_string() whose length is 1

      1. Adding a letter to an empty MyVector produces a to_string() whose first element is that letter

   A. ## Test  addLetter_2

      1. Adding a sequence of letters to an empty MyVector produces a to_string() whose last element matches the last letter

   A. ## Test  clear

      1. After clearing a newly created instance of MyVector its size must be 0

      1. After clearing a newly created instance of MyVector its serialization must be an empty string

      1. After clearing a newly created instance of MyVector contains all its values to EMPTYCHAR in its inspection

      1. Clearing a non-empty instance of MyVector gives a size of 0

      1. Clearing a non-empty instance of MyVector gives an empty string as its serialization

      1. Clearing a non-empty instance of MyVector contains all its values to EMPTYCHAR in its inspection

1. ## Suite  _02_Modifiers

   A. ## Test  getLetter

      1. Getting the position 0 of MyVector gives the same char that the position 0 of its serialization

      1. Getting the last position of MyVector gives the same char that the last of its serialization

   A. ## Test  setLetter

      1. Setting a char on any valid position of MyVector allows to get the same char in the same position

      1. Setting a char on any valid position of MyVector allows to get the same char in the same position

1. ## Suite  _03_SafeAccess

   A. ## Test  addLetter_safe

      1. No more than MAXVECTOR letters can be never added

   A. ## Test  getLetter_safe

      1. Accesing MyVector beyond its number of stored letters gives a '\\0' char

      1. Accesing MyVector beyond MAXVECTOR gives a '\\0' char

      1. Accesing MyVector with a negative index gives a '\\0' char

   A. ## Test  setLetter_safe

      1. Setting a char beyond its number of stored letters gives MaxVector unaltered

      1. Setting a char in a negative positoin gives MaxVector unaltered

1. ## Suite  _04_BasicIntegration

   A. ## Test  REGULARSEQUENCE

      1. Processing a regular sequence gives the last 5 chars of that sequence in reverse order

   A. ## Test  EMPTYSEQUENCE

      1. Processing an empty sequence will give an empty sequence

   A. ## Test  SHORTSEQUENCE

      1. Processing a sequence shorter than 5 gives the reverse of that sequence

1. ## Suite  _05_SafeIntegration

   A. ## Test  LONGSEQUENCE

      1. Processing a sequence that exceeds MAXVECTOR gives the last 5 chars of the first MAXVECTOR chars

