# OUTCOME OF TESTS FOR PROJECT language1_template

As of Mar 22 2023 17:39:56

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Bigram_Bigram_ss_1 |  PASSED |```Bigram ab("ab");ab.inspectT()```|
| | | | should give ```"ab"```|
| 2 | T01_Basics.Bigram_Bigram_ss_2 |  PASSED |```Bigram gg("__");gg.inspectT();```|
| | | | should give ```"__"```|
| 3 | T01_Basics.Bigram_Bigram_sss_ |  PASSED |```Bigram b("abcd");b.inspectT();;```|
| | | | should give ```"__"```|
| 4 | T01_Basics.Bigram_Bigram___ |  PASSED |```Bigram b("");b.inspectT();;```|
| | | | should give ```"__"```|
| 5 | T01_Basics.Bigram_Bigram_c_c_ |  PASSED |```Bigram b('a', 'a');b.inspectT();```|
| | | | should give ```"aa"```|
| 6 | T01_Basics.Bigram_at_i1 |  PASSED |```Bigram b("ab");b.at(0);```|
| | | | should give ```"a"```|
| 7 | T01_Basics.Bigram_at_i2 |  PASSED |```Bigram b("ab");b.at(1);```|
| | | | should give ```"b"```|
| 8 | T01_Basics.Bigram_getText |  PASSED |```Bigram b("ab");b.getText();```|
| | | | should give ```"ab"```|
| 9 | T01_Basics.BigramFreq_BigramFreq_ |  PASSED |```BigramFreq bf;bf.inspectT()```|
| | | | should give ```"__ 0"```|
| 10 | T01_Basics.BigramFreq_toString_ |  PASSED |```BigramFreq bf;bf.toString()```|
| | | | should give ```"__ 0"```|
| 11 | T01_Basics.BigramFreq_getFreq_ |  PASSED |```BigramFreq bf;bf.getFrequency()```|
| | | | should give ```0```|
| 12 | T01_Basics.BigramFreq_getBigram_ |  PASSED |```BigramFreq bf;bf.getBigram().toString()```|
| | | | should give ```"__"```|
| 13 | T02_Intermediate.Bigram_at_i3 |  PASSED |```Bigram b("ab");b.at(20);```|
| | | | should THROW an exception std::out_of_range|
|
| 14 | T02_Intermediate.Bigram_at_i_var |  PASSED |```Bigram b("ab"); b.at(0) = 'd';b.inspectT();```|
| | | | should give ```"db"```|
| 15 | T02_Intermediate.Bigram_at_i_var2 |  PASSED |```Bigram b("ab"); b.at(1) = 'd';b.inspectT();;```|
| | | | should give ```"ad"```|
| 16 | T02_Intermediate.isValidChar_c |  PASSED |```char c='a';isValidCharacter(c,validCharacters);```|
| | | | should give ```true```|
| 17 | T02_Intermediate.isValidChar_X |  PASSED |```char c='@';isValidCharacter(c,validCharacters);```|
| | | | should give ```false```|
| 18 | T02_Intermediate.BigramFreq_setBigram_ |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b);bf.getBigram().toString()```|
| | | | should give ```"XY"```|
| 19 | T02_Intermediate.BigramFreq_setFrequency_ |  PASSED |```BigramFreq bf; bf.setFrequency(10);bf.getFrequency();```|
| | | | should give ```10```|
| 20 | T02_Intermediate.BigramFreq_setFrequency_exception |  PASSED |```BigramFreq bf;bf.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
|
| 21| T03_Advanced.Integration_SimpleTest-valgrind | PASSED | NO LEAKS |
| 21 | T03_Advanced.Integration_SimpleTest | PASSED | 11 Random bigrams with random frequencies|
| 22 | T03_Advanced.Integration_30Bigrams | PASSED | Process 30 random bigrams with random frequencies|
| 23 | T03_Advanced.Integration_36Bigrams | PASSED | Process 36 random bigrams with random frequencies|
| 24| T03_Advanced.Integration_miniquijote-valgrind | PASSED | NO LEAKS |
| 24 | T03_Advanced.Integration_miniquijote | PASSED | An excerpt of the universal novel El Quijote|
