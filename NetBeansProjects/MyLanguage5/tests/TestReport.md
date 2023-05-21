# OUTCOME OF TESTS FOR PROJECT language5_template

As of Apr 28 2023 14:08:44

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Bigram_Bigram_ss_1 |  PASSED |```Bigram ab("ab");ab.toString()```|
| | | | should give ```"ab"```|
| 2 | T01_Basics.Bigram_Bigram_ss_2 |  PASSED |```Bigram gg("__");gg.toString();```|
| | | | should give ```"__"```|
| 3 | T01_Basics.Bigram_Bigram_sss_ |  PASSED |```Bigram b("abcd");b.toString();;```|
| | | | should give ```"__"```|
| 4 | T01_Basics.Bigram_Bigram___ |  PASSED |```Bigram b("");b.toString();;```|
| | | | should give ```"__"```|
| 5 | T01_Basics.Bigram_Bigram_c_c_ |  PASSED |```Bigram b('a', 'a');b.toString();```|
| | | | should give ```"aa"```|
| 6 | T01_Basics.Bigram_at_i1 |  PASSED |```Bigram b("ab");b.at(0);```|
| | | | should give ```"a"```|
| 7 | T01_Basics.Bigram_at_i2 |  PASSED |```Bigram b("ab");b.at(1);```|
| | | | should give ```"b"```|
| 8 | T01_Basics.Bigram_getText |  PASSED |```Bigram b("ab");b.getText();```|
| | | | should give ```"ab"```|
| 9 | T01_Basics.BigramFreq_BigramFreq_ |  PASSED |```BigramFreq bf;bf.toString()```|
| | | | should give ```"__ 0"```|
| 10 | T01_Basics.BigramFreq_toString_ |  PASSED |```BigramFreq bf;bf.toString()```|
| | | | should give ```"__ 0"```|
| 11 | T01_Basics.BigramFreq_getFreq_ |  PASSED |```BigramFreq bf;bf.getFrequency()```|
| | | | should give ```0```|
| 12 | T01_Basics.BigramFreq_getBigram_ |  PASSED |```BigramFreq bf;bf.getBigram().toString()```|
| | | | should give ```"__"```|
| 13 | T01_Basics.Language_Language_00 |  PASSED |```Language lang;lang._languageId```|
| | | | should give ```"unknown"```|
| 14 | T01_Basics.Language_Language_01 |  PASSED |```Language lang;lang._size```|
| | | | should give ```0```|
| 15 | T01_Basics.Language_Language_02 |  PASSED |```Language lang;lang.inspectT()```|
| | | | should give ```"unknown 0 "```|
| 16 | T01_Basics.Language_Language_10 |  PASSED |```Language lang(2);lang._languageId```|
| | | | should give ```"unknown"```|
| 17 | T01_Basics.Language_Language_11 |  PASSED |```Language lang(2);lang._size```|
| | | | should give ```2```|
| 18 | T01_Basics.Language_Language_22 |  PASSED |```Language lang(2);lang.inspectT()```|
| | | | should give ```"unknown 2 __ 0 __ 0 "```|
| 19 | T01_Basics.Language_setLanguageId_ |  PASSED |```Language lang; lang.setLanguageId("english");lang._languageId```|
| | | | should give ```"english"```|
| 20 | T01_Basics.Language_append_0 |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); Language lang; lang.append(bf);lang._size```|
| | | | should give ```1```|
| 21 | T01_Basics.Language_append_1 |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); Language lang; lang.append(bf);lang.append(bf);lang._size```|
| | | | should give ```1```|
| 22 | T01_Basics.Language_append_2 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang._size```|
| | | | should give ```2```|
| 23 | T01_Basics.Language_findBigram_0 |  PASSED |```Bigram b("XY"); Language lang;lang.findBigram(b);```|
| | | | should give ```-1```|
| 24 | T01_Basics.Language_findBigram_1 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.findBigram(b1);```|
| | | | should give ```0```|
| 25 | T01_Basics.Language_findBigram_2 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.findBigram(b2);```|
| | | | should give ```1```|
| 26 | T01_Basics.Language_findBigram_3 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ");Bigram bx("YY"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.findBigram(bx);```|
| | | | should give ```-1```|
| 27 | T01_Basics.Language_at_0 |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); Language lang; lang.append(bf);lang.at(0).inspectT()```|
| | | | should give ```"XY 10"```|
| 28 | T01_Basics.Language_at_1 |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); Language lang; lang.append(bf);lang.append(bf);lang.at(0).inspectT()```|
| | | | should give ```"XY 20"```|
| 29 | T01_Basics.Language_at_2 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.at(0).inspectT()```|
| | | | should give ```"XY 10"```|
| 30 | T01_Basics.Language_at_3 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.at(1).inspectT()```|
| | | | should give ```"ZZ 10"```|
| 31 | T01_Basics.sort_1_orderbyFreq |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10*i); l1.append(bf); b.at(1)=c+i; } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 ac 30 ab 20 aa 10 "```|
| 32 | T01_Basics.Counter_Counter_0 |  PASSED |```BigramCounter bc;bc._validCharacters==BigramCounter::DEFAULT_VALID_CHARACTERS```|
| | | | should give ```true```|
| 33 | T01_Basics.Counter_Counter_1 |  PASSED |```const string validChars = "ABCD"; BigramCounter bc(validChars);bc._validCharacters==validChars```|
| | | | should give ```true```|
| 34 | T01_Basics.Counter_Counter_2 |  PASSED |```const string validChars = "ABCD"; BigramCounter bc(validChars);bc.inspectT()```|
| | | | should give ```"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 35 | T01_Basics.Counter_Counter_Copy01 |  PASSED |```const string validChars = "ABCD"; Bigram b("AA"); BigramCounter bi(validChars); BigramCounter bc(bi);bc.setFrequency(b,10)bi.inspectT();```|
| | | | should give ```"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 36 | T01_Basics.Counter_Counter_Copy02 |  PASSED |```const string validChars = "ABCD"; Bigram b("AA"); BigramCounter bi(validChars); BigramCounter bc(bi);bc.setFrequency(b,10)bc.inspectT();```|
| | | | should give ```"10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 37 | T01_Basics.Counter_assign_01 |  PASSED |```const string validChars = "ABCD"; Bigram b("AA"); BigramCounter bi(validChars); BigramCounter bc; bc = bi; bc.setFrequency(b,10)bi.inspectT();```|
| | | | should give ```"0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 38 | T01_Basics.Counter_assign_02 |  PASSED |```const string validChars = "ABCD"; Bigram b("AA"); BigramCounter bi(validChars); BigramCounter bc; bc = bi; bc.setFrequency(b,10);bc.inspectT();```|
| | | | should give ```"10 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 "```|
| 39 | T01_Basics.Counter_getNumberActive_01 |  PASSED |```const string validChars = "ABCD"; Bigram b("AA"); BigramCounter bi(validChars);bi.getNumberActiveBigrams();```|
| | | | should give ```0```|
| 40 | T01_Basics.Counter_getNumberActive_02 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); for(int i=0; i < bi.getSize(); i++) { Bigram b(validChars[i],validChars[i]); bi.setFrequency(b,10); }bi.getNumberActiveBigrams();```|
| | | | should give ```4```|
| 41 | T01_Basics.Counter_setFrecuency_01 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); int isInside=0; for(int i=0; i < bi.getSize(); i++) { Bigram b(validChars[i],validChars[i]); if (bi.setFrequency(b,10)) isInside++; }isInside```|
| | | | should give ```4```|
| 42 | T01_Basics.Counter_setFrecuency_02 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); int isInside=0; for(int i=0; i < bi.getSize(); i++) { Bigram b(validChars[i]+validChars.size(),validChars[i]+ validChars.size()); if (bi.setFrequency(b,10)) isInside++; }isInside```|
| | | | should give ```0```|
| 43 | T01_Basics.Counter_increaseFrequency_01 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); for(int i=0; i < bi.getSize(); i++) { Bigram b(validChars[i],validChars[i]); bi.increaseFrequency(b,5); }bi.inspectT();```|
| | | | should give ```"5 0 0 0 0 5 0 0 0 0 5 0 0 0 0 5 "```|
| 44 | T01_Basics.Counter_increaseFrequency_2 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); for(int i=0; i < bi.getSize(); i++) for(int j=0; j < bi.getSize(); j++) { Bigram b(validChars[i],validChars[j]); bi.increaseFrequency(b); }bi.inspectT()```|
| | | | should give ```"1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 "```|
| 45 | T02_Intermediate.Bigram_at_i3 |  PASSED |```Bigram b("ab");b.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 46 | T02_Intermediate.Bigram_at_i_var |  PASSED |```Bigram b("ab"); b.at(0) = 'd';b.toString();```|
| | | | should give ```"db"```|
| 47 | T02_Intermediate.Bigram_at_i_var2 |  PASSED |```Bigram b("ab"); b.at(1) = 'd';b.toString();;```|
| | | | should give ```"ad"```|
| 48 | T02_Intermediate.isValidChar_c |  PASSED |```char c='a';isValidCharacter(c,validCharacters);```|
| | | | should give ```true```|
| 49 | T02_Intermediate.isValidChar_X |  PASSED |```char c='@';isValidCharacter(c,validCharacters);```|
| | | | should give ```false```|
| 50 | T02_Intermediate.toUpper_b |  PASSED |```Bigram bigram("ab");bigram.toUpper();bigram.toString();```|
| | | | should give ```"AB"```|
| 51 | T02_Intermediate.BigramFreq_setBigram_ |  PASSED |```Bigram b("XY");BigramFreq bf;bf.setBigram(b);bf.getBigram().toString()```|
| | | | should give ```"XY"```|
| 52 | T02_Intermediate.BigramFreq_setFrequency_ |  PASSED |```BigramFreq bf; bf.setFrequency(10);bf.getFrequency();```|
| | | | should give ```10```|
| 53 | T02_Intermediate.BigramFreq_setFrequency_exception |  PASSED |```BigramFreq bf;bf.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
| 54 | T02_Intermediate.Language_controlSize_append_3 |  PASSED |```const int DIM_VECTOR_BIGRAM_FREQ = 2000; Language lang; int i; int n= DIM_VECTOR_BIGRAM_FREQ; BigramFreq bf; bf.setFrequency(10); for ( i = 0; i < n; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);} lang.append(bf);lang._size```|
| | | | should give ```2000```|
| 55 | T02_Intermediate.Language_append_4 |  PASSED |```const int DIM_VECTOR_BIGRAM_FREQ = 2000; int i; int n= DIM_VECTOR_BIGRAM_FREQ; Language lang; BigramFreq bf; bf.setFrequency(10); for ( i = 0; i < n; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf); } Bigram b2(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b2); lang.append(bf);lang._size```|
| | | | should give ```2001```|
| 56 | T02_Intermediate.Language_out_of_range_at_4 |  PASSED |```Language lang; BigramFreq bf; bf.setFrequency(10); for (int i = 0; i < 10; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);}lang.at(-1);```|
| | | | should THROW an exception std::out_of_range|
| 57 | T02_Intermediate.Language_out_of_range_at_5 |  PASSED |```Language lang; BigramFreq bf; bf.setFrequency(10); for (int i = 0; i < 10; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);}lang.at(10);```|
| | | | should THROW an exception std::out_of_range|
| 58 | T02_Intermediate.Language_append2_toString |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.inspectT()```|
| | | | should give ```"unknown 2 XY 20 ZZ 10 "```|
| 59 | T02_Intermediate.Language_join_intersection_empy_1 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language l2; bf.setBigram(b1); l1.append(bf); bf.setBigram(b2); l1.append(bf); bf.setBigram(b3); l2.append(bf); bf.setBigram(b4); l2.append(bf); int initialSize = l1.getSize(); l1 += l2;l1._size```|
| | | | should give ```4```|
| 60 | T02_Intermediate.Language_joinShouldIncreaseFrequencyWhenBigramIsAlreadyInLanguage_2 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language l2; bf.setBigram(b1); l1.append(bf); l2.append(bf); bf.setBigram(b2); l1.append(bf); l2.append(bf); bf.setBigram(b3); l1.append(bf); l2.append(bf); bf.setBigram(b4); l1.append(bf); l2.append(bf); l1+=l2; int sum=0; for (int i= 0; i < l1.getSize(); i++) sum += l1.at(i).getFrequency();l1._size*20```|
| | | | should give ```80```|
| 61 | T02_Intermediate.Language_saveLoad_10 |  PASSED |```Language l1; Language l2; l1.setLanguageId("Test1"); char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=0; i < 10; i++) { bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); b.at(1)=c+i; bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); } l1.sort(); const char* fileName = "tests/output/test_save1.bgr"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 62 | T02_Intermediate.sort_2_tieByFreq |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 63 | T02_Intermediate.sort_3_mixed |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10*i); l1.append(bf); b.at(1)=c+i; } bf.setBigram(b); l1.append(bf); l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 64 | T02_Intermediate.Language_getDistance_lg2lg_0 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; bf.setBigram(b1); l1.append(bf); bf.setBigram(b2); l1.append(bf); bf.setBigram(b3); l1.append(bf); bf.setBigram(b4); l1.append(bf);l1.getDistance(l1)```|
| | | | should give ```0.000000```|
| 65 | T02_Intermediate.Language_getDistance_otherToEmpy_2 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language empty; bf.setBigram(b1); l1.append(bf); bf.setBigram(b2); l1.append(bf); bf.setBigram(b3); l1.append(bf); bf.setBigram(b4); l1.append(bf);l1.getDistance(empty)```|
| | | | should give ```0.625000```|
| 66 | T02_Intermediate.Language_getDistance_allPresentButInReverseOrder_3 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language l2; bf.setBigram(b1); l1.append(bf); bf.setBigram(b2); l1.append(bf); bf.setBigram(b3); l1.append(bf); bf.setBigram(b4); l1.append(bf); bf.setBigram(b4); l2.append(bf); bf.setBigram(b3); l2.append(bf); bf.setBigram(b2); l2.append(bf); bf.setBigram(b1); l2.append(bf);l1.getDistance(l2)```|
| | | | should give ```0.500000```|
| 67 | T02_Intermediate.Language_Assign_1 |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } Language lc; lc=l1; lc.at(0).setFrequency(20);lc.inspectT();```|
| | | | should give ```"unknown 3 aa 20 ab 10 ac 10 "```|
| 68 | T02_Intermediate.Language_Assign_2 |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } Language lc; lc=l1; lc.at(0).setFrequency(20);l1.inspectT();```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 69 | T02_Intermediate.Language_Ctor_Copy_1 |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } Language lc(l1); lc.at(0).setFrequency(20);l1.inspectT();```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 70 | T02_Intermediate.Language_Ctor_Copy_2 |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } Language lc(l1); lc.at(0).setFrequency(20);lc.inspectT();```|
| | | | should give ```"unknown 3 aa 20 ab 10 ac 10 "```|
| 71 | T02_Intermediate.Counter_operator_joinCounter_1 |  PASSED |```const string validChars = "ABCD"; BigramCounter bi(validChars); for(int i=0; i < bi.getSize(); i++) for(int j=0; j < bi.getSize(); j++) { Bigram b(validChars[i],validChars[j]); bi.setFrequency(b,3); } bi += bi;bi.inspectT()```|
| | | | should give ```"6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 "```|
| 72 | T02_Intermediate.Counter_calculateFrequencies_EN_0 |  PASSED |```const char nfE[50] = "../Books/test_EN.txt"; const char nfS[50] = "../Books/test_EN.bgr"; BigramCounter bi; bi.calculateFrequencies(nfE); Language l; l.load(nfS); string s; int posi; int posj; int freq; int freql; bool iguales = true; if (bi.getNumberActiveBigrams() != l.getSize()) iguales= false; for(int i=0; i < l.getSize() && iguales; i++){ s = l.at(i).getBigram().toString(); posi = bi._validCharacters.find(s[0]); posj = bi._validCharacters.find(s[1]); freql = l.at(i).getFrequency(); freq = bi._frequency[posi][posj]; if (freq != freql) iguales = false; }iguales```|
| | | | should give ```true```|
| 73 | T02_Intermediate.Counter_calculateFrequencies_ES_0 |  PASSED |```const char nfE[50] = "../Books/test_ES.txt"; const char nfS[50] = "../Books/test_ES.bgr"; BigramCounter bi; bi.calculateFrequencies(nfE); Language l; l.load(nfS); string s; int posi; int posj; int freq; int freql; bool iguales = true; if (bi.getNumberActiveBigrams() != l.getSize()) iguales= false; for(int i=0; i < l.getSize() && iguales; i++){ s = l.at(i).getBigram().toString(); posi = bi._validCharacters.find(s[0]); posj = bi._validCharacters.find(s[1]); freql = l.at(i).getFrequency(); freq = bi._frequency[posi][posj]; if (freq != freql) iguales = false; }iguales```|
| | | | should give ```true```|
| 74 | T02_Intermediate.Counter_toLanguage_1 |  PASSED |```const char nfE[50] = "../Books/test_EN.txt"; const char nfS[50] = "../Books/test_EN.bgr"; BigramCounter bi; bi.calculateFrequencies(nfE); Language lr; Language lo; lr.load(nfS); lo = bi.toLanguage(); bool iguales = true; if (lr.getSize() != lo.getSize()) iguales= false; for(int i=0; i < lo.getSize() && iguales; i++){ if ((lr.at(i).getBigram().toString() != lo.at(i).getBigram().toString()) || (lr.at(i).getFrequency() != lo.at(i).getFrequency())) iguales =false; }iguales```|
| | | | should give ```true```|
| 75 | T02_Intermediate.Counter_fromLanguage_1 |  PASSED |```const char nfS[50] = "../Books/test_EN.bgr"; BigramCounter bi; bool iguales = true; string s; int posi; int posj; int freq; int freql; Language lr; lr.load(nfS); bi.fromLanguage(lr); if (bi.getNumberActiveBigrams() != lr.getSize()) iguales= false; for(int i=0; i < lr.getSize() && iguales; i++){ s = lr.at(i).getBigram().toString(); posi = bi._validCharacters.find(s[0]); posj = bi._validCharacters.find(s[1]); freql = lr.at(i).getFrequency(); freq = bi._frequency[posi][posj]; if (freq != freql) iguales = false; }iguales```|
| | | | should give ```true```|
| 76 | T03_Advanced.Counter_operatorAt_1 |  PASSED |```const string validChars = "ABCD"; Bigram b("AD"); BigramCounter bi(validChars); bi.setFrequency(b,10);bi(validChars.find('A') ,validChars.find('D'))```|
| | | | should give ```10```|
| 77 | T03_Advanced.BigramFreq_operatorGreaterThan_1 |  PASSED |```Bigram b1("AA"); Bigram b2("FF"); BigramFreq bf1; BigramFreq bf2; bf1.setBigram(b1); bf2.setBigram(b2); bf1.setFrequency(10); bf2.setFrequency(20);bf2>bf1```|
| | | | should give ```true```|
| 78 | T03_Advanced.BigramFreq_operatorGreaterThan_2 |  PASSED |```Bigram b1("AA"); Bigram b2("FF"); BigramFreq bf1; BigramFreq bf2; bf1.setBigram(b1); bf2.setBigram(b2); bf1.setFrequency(10); bf2.setFrequency(10);bf1>bf2```|
| | | | should give ```true```|
| 79 | T03_Advanced.BigramFreq_operatorEqual_1 |  PASSED |```Bigram b1("AA"); BigramFreq bf1; BigramFreq bf2; bf1.setBigram(b1); bf2.setBigram(b1); bf1.setFrequency(10); bf2.setFrequency(10);bf1==bf2```|
| | | | should give ```true```|
| 80 | T03_Advanced.Bigram_read_ |  PASSED |```Bigram b; std::string sin="aa"; istringstream ssin(sin); ssin >> b;b.toString()```|
| | | | should give ```"aa"```|
| 81 | T03_Advanced.BigramFreq_read_ |  PASSED |```BigramFreq bfr; std::string sin="aa 10"; istringstream ssin(sin); ssin >> bfr;bfr.toString()```|
| | | | should give ```"aa 10"```|
| 82 | T03_Advanced.Language_read_ |  PASSED |```Language l; std::string sin="unknown 3 aa 10 ab 10 ac 10 "; istringstream ssin(sin); ssin >> l;l.inspectT()```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 83 | T03_Advanced.bigram_print_ |  PASSED |```std::string sout; ostringstream ssout; Bigram b("aa"); ssout << b; sout = ssout.str();sout```|
| | | | should give ```"aa"```|
| 84 | T03_Advanced.bigramFreq_print_ |  PASSED |```std::string sout; ostringstream ssout; Bigram b("aa"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); ssout << bf; sout = ssout.str();sout```|
| | | | should give ```"aa 10"```|
| 85 | T03_Advanced.language_print_ |  PASSED |```std::string sout; ostringstream ssout; Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); lang.append(bf); bf.setBigram(b2); lang.append(bf); std::streambuf *old = std::cout.rdbuf(ssout.rdbuf()); ssout << lang; sout = ssout.str(); sout = std::regex_replace(sout, std::regex("\n"), " "); std::cout.rdbuf(old);sout```|
| | | | should give ```"unknown 2 XY 20 ZZ 10 "```|
| 86 | T03_Advanced.Language_operatorat_0 |  PASSED |```Bigram b("XY"); BigramFreq bf; bf.setBigram(b); bf.setFrequency(10); Language lang; lang.append(bf);lang[0].inspectT()```|
| | | | should give ```"XY 10"```|
| 87 | T03_Advanced.Language_operatorat_2 |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); bf.setBigram(b2); lang.append(bf);lang[0].inspectT()```|
| | | | should give ```"XY 10"```|
| 88 | T03_Advanced.Language_saveLoad_parameter_t |  PASSED |```Language l1; Language l2; l1.setLanguageId("Test1"); char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=0; i < 10; i++) { bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); b.at(1)=c+i; bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); } l1.sort(); const char* fileName = "tests/output/test_save1.bgr"; l1.save(fileName,'t'); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 89 | T03_Advanced.Language_saveLoad_parameter_b |  PASSED |```Language l1; Language l2; l1.setLanguageId("Testb"); char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=0; i < 10; i++) { bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); b.at(1)=c+i; bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); } l1.sort(); const char* fileName = "tests/output/testb_save.bgr"; l1.save(fileName,'b'); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 90| T03_Advanced.Integration_JOIN_MissingArguments-valgrind | PASSED | NO LEAKS |
| 90 | T03_Advanced.Integration_JOIN_MissingArguments | PASSED | Run without arguments [JOIN]|
| 91| T03_Advanced.Integration_JOIN_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 91 | T03_Advanced.Integration_JOIN_RunWithInvalidArguments1 | PASSED | Run with invalid arguments [JOIN -O tests/output/30bigrams.bgr ../Books/30bigrams.bgr]|
| 92| T03_Advanced.Integration_JOIN_RunWithInvalidArguments2-valgrind | PASSED | NO LEAKS |
| 92 | T03_Advanced.Integration_JOIN_RunWithInvalidArguments2 | PASSED | Run with invalid arguments [JOIN -B -o tests/output/30bigrams.bgr ../Books/30bigrams.bgr]|
| 93| T03_Advanced.Integration_JOIN_10bigrams_10bigrams-valgrind | PASSED | NO LEAKS |
| 93 | T03_Advanced.Integration_JOIN_10bigrams_10bigrams | PASSED | Join of 10bigrams.bgr + 10bigrams.bgr [JOIN -o tests/output/10bigrams_10bigrams.bgr ../Books/10bigrams.bgr ../Books/10bigrams.bgr]|
| 93 | T03_Advanced.Integration_JOIN_10bigrams_10bigrams |  PASSED |```Join of 10bigrams.bgr + 10bigrams.bgr [JOIN -o tests/output/10bigrams_10bigrams.bgr ../Books/10bigrams.bgr ../Books/10bigrams.bgr]```|
| | | | should give ```true```|
| 94| T03_Advanced.Integration_JOIN_OnlyOneInputFile-valgrind | PASSED | NO LEAKS |
| 94 | T03_Advanced.Integration_JOIN_OnlyOneInputFile | PASSED | Only one input file [JOIN -o tests/output/30bigrams.bgr ../Books/30bigrams.bgr]|
| 94 | T03_Advanced.Integration_JOIN_OnlyOneInputFile |  PASSED |```Only one input file [JOIN -o tests/output/30bigrams.bgr ../Books/30bigrams.bgr]```|
| | | | should give ```true```|
| 95| T03_Advanced.Integration_JOIN_30bigrams_30bigrams2-valgrind | PASSED | NO LEAKS |
| 95 | T03_Advanced.Integration_JOIN_30bigrams_30bigrams2 | PASSED | Join of 30bigrams.bgr and 30bigrams2.bgr [JOIN -o tests/output/30bigrams_30bigrams2.bgr ../Books/30bigrams.bgr ../Books/30bigrams2.bgr]|
| 95 | T03_Advanced.Integration_JOIN_30bigrams_30bigrams2 |  PASSED |```Join of 30bigrams.bgr and 30bigrams2.bgr [JOIN -o tests/output/30bigrams_30bigrams2.bgr ../Books/30bigrams.bgr ../Books/30bigrams2.bgr]```|
| | | | should give ```true```|
| 96| T03_Advanced.Integration_JOIN_30bigrams_36bigrams-valgrind | PASSED | NO LEAKS |
| 96 | T03_Advanced.Integration_JOIN_30bigrams_36bigrams | PASSED | Join of 30bigrams.bgr and 36bigrams.bgr [JOIN -o tests/output/30bigrams+36bigrams.bgr ../Books/30bigrams.bgr ../Books/36bigrams.bgr]|
| 96 | T03_Advanced.Integration_JOIN_30bigrams_36bigrams |  PASSED |```Join of 30bigrams.bgr and 36bigrams.bgr [JOIN -o tests/output/30bigrams+36bigrams.bgr ../Books/30bigrams.bgr ../Books/36bigrams.bgr]```|
| | | | should give ```true```|
| 97| T03_Advanced.Integration_JOIN_english-valgrind | PASSED | NO LEAKS |
| 97 | T03_Advanced.Integration_JOIN_english | PASSED | Join of aliceWonder.bgr and changedMan.bgr [JOIN -o tests/output/english.bgr ../Books/aliceWonder.bgr ../Books/changedMan.bgr]|
| 97 | T03_Advanced.Integration_JOIN_english |  PASSED |```Join of aliceWonder.bgr and changedMan.bgr [JOIN -o tests/output/english.bgr ../Books/aliceWonder.bgr ../Books/changedMan.bgr]```|
| | | | should give ```true```|
| 98| T03_Advanced.Integration_JOIN_spanish-valgrind | PASSED | NO LEAKS |
| 98 | T03_Advanced.Integration_JOIN_spanish | PASSED | Join of BodasdeSangre_FedericoGarciaLorca.bgr and quijote.bgr[JOIN -o tests/output/spanish.bgr ../Books/BodasdeSangre_FedericoGarciaLorca.bgr ../Books/quijote.bgr]|
| 98 | T03_Advanced.Integration_JOIN_spanish |  PASSED |```Join of BodasdeSangre_FedericoGarciaLorca.bgr and quijote.bgr[JOIN -o tests/output/spanish.bgr ../Books/BodasdeSangre_FedericoGarciaLorca.bgr ../Books/quijote.bgr]```|
| | | | should give ```true```|
| 99| T03_Advanced.Integration_JOIN_convertToBinary-valgrind | PASSED | NO LEAKS |
| 99 | T03_Advanced.Integration_JOIN_convertToBinary | PASSED | Convert an input language to a binary language [JOIN -b -o tests/output/10bigrams_binary.bgr ../Books/10bigrams.bgr]|
| 99 | T03_Advanced.Integration_JOIN_convertToBinary |  PASSED |```Convert an input language to a binary language [JOIN -b -o tests/output/10bigrams_binary.bgr ../Books/10bigrams.bgr]```|
| | | | should give ```true```|
| 100| T03_Advanced.Integration_LEARN_missingParameters-valgrind | PASSED | NO LEAKS |
| 100 | T03_Advanced.Integration_LEARN_missingParameters | PASSED | Learn with missing parameters [LEARN]|
| 101| T03_Advanced.Integration_LEARN_RunWithInvalidArguments1-valgrind | PASSED | NO LEAKS |
| 101 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments1 | PASSED | Learn with invalid arguments [LEARN -T -l spanish -o tests/output/quijote.bgr ../Books/quijote.txt]|
| 102| T03_Advanced.Integration_LEARN_RunWithInvalidArguments2-valgrind | PASSED | NO LEAKS |
| 102 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments2 | PASSED | Learn with invalid arguments [LEARN -L spanish -o tests/output/quijote.bgr ../Books/quijote.txt]|
| 103| T03_Advanced.Integration_LEARN_RunWithInvalidArguments3-valgrind | PASSED | NO LEAKS |
| 103 | T03_Advanced.Integration_LEARN_RunWithInvalidArguments3 | PASSED | Learn with invalid arguments [LEARN -t -l spanish -O tests/output/quijote.bgr ../Books/quijote.txt]|
| 104| T03_Advanced.Integration_LEARN_changedMan-valgrind | PASSED | NO LEAKS |
| 104 | T03_Advanced.Integration_LEARN_changedMan | PASSED | Learn from changedMan.txt book [LEARN ../Books/changedMan.txt]|
| 104 | T03_Advanced.Integration_LEARN_changedMan |  PASSED |```Learn from changedMan.txt book [LEARN ../Books/changedMan.txt]```|
| | | | should give ```true```|
| 105| T03_Advanced.Integration_LEARN_test_ES-valgrind | PASSED | NO LEAKS |
| 105 | T03_Advanced.Integration_LEARN_test_ES | PASSED | Learn from test_ES.txt book [LEARN -l spanish -o tests/output/test_ES.bgr ../Books/test_ES.txt]|
| 105 | T03_Advanced.Integration_LEARN_test_ES |  PASSED |```Learn from test_ES.txt book [LEARN -l spanish -o tests/output/test_ES.bgr ../Books/test_ES.txt]```|
| | | | should give ```true```|
| 106| T03_Advanced.Integration_LEARN_quijote-valgrind | PASSED | NO LEAKS |
| 106 | T03_Advanced.Integration_LEARN_quijote | PASSED | Learn from quijote.txt book [LEARN -l spanish -o tests/output/quijote.bgr ../Books/quijote.txt]|
| 106 | T03_Advanced.Integration_LEARN_quijote |  PASSED |```Learn from quijote.txt book [LEARN -l spanish -o tests/output/quijote.bgr ../Books/quijote.txt]```|
| | | | should give ```true```|
| 107| T03_Advanced.Integration_LEARN_aliceWonder-valgrind | PASSED | NO LEAKS |
| 107 | T03_Advanced.Integration_LEARN_aliceWonder | PASSED | Learn from aliceWonder.txt book [LEARN -l english -o tests/output/aliceWonder.bgr ../Books/aliceWonder.txt]|
| 107 | T03_Advanced.Integration_LEARN_aliceWonder |  PASSED |```Learn from aliceWonder.txt book [LEARN -l english -o tests/output/aliceWonder.bgr ../Books/aliceWonder.txt]```|
| | | | should give ```true```|
| 108| T03_Advanced.Integration_LEARN_spanish-valgrind | PASSED | NO LEAKS |
| 108 | T03_Advanced.Integration_LEARN_spanish | PASSED | Learn spanish language from quijote.txt and fortunata.txt books [LEARN -l spanish -o tests/output/spanish_quijote+fortunata.bgr ../Books/quijote.txt ../Books/fortunata.txt]|
| 108 | T03_Advanced.Integration_LEARN_spanish |  PASSED |```Learn spanish language from quijote.txt and fortunata.txt books [LEARN -l spanish -o tests/output/spanish_quijote+fortunata.bgr ../Books/quijote.txt ../Books/fortunata.txt]```|
| | | | should give ```true```|
| 109| T03_Advanced.Integration_LEARN_spanish_binary-valgrind | PASSED | NO LEAKS |
| 109 | T03_Advanced.Integration_LEARN_spanish_binary | PASSED | Learn spanish language in binary format from quijote.txt and fortunata.txt books [LEARN -b -l spanish -o tests/output/spanish_binary.bgr ../Books/quijote.txt ../Books/fortunata.txt]|
| 109 | T03_Advanced.Integration_LEARN_spanish_binary |  PASSED |```Learn spanish language in binary format from quijote.txt and fortunata.txt books [LEARN -b -l spanish -o tests/output/spanish_binary.bgr ../Books/quijote.txt ../Books/fortunata.txt]```|
| | | | should give ```true```|
| 110| T03_Advanced.Integration_CLASSIFY_missingParameters1-valgrind | PASSED | NO LEAKS |
| 110 | T03_Advanced.Integration_CLASSIFY_missingParameters1 | PASSED | Classify with missing parameters [CLASSIFY]|
| 111| T03_Advanced.Integration_CLASSIFY_missingParameters2-valgrind | PASSED | NO LEAKS |
| 111 | T03_Advanced.Integration_CLASSIFY_missingParameters2 | PASSED | Classify with missing parameters [CLASSIFY ../Books/lesMiserables.txt]|
| 112| T03_Advanced.Integration_CLASSIFY_quijote-valgrind | PASSED | NO LEAKS |
| 112 | T03_Advanced.Integration_CLASSIFY_quijote | PASSED | Classify quijote.txt book using esp.bgr [CLASSIFY ../Books/quijote.txt ../Books/esp.bgr]|
| 113| T03_Advanced.Integration_CLASSIFY_BodasSangre-valgrind | PASSED | NO LEAKS |
| 113 | T03_Advanced.Integration_CLASSIFY_BodasSangre | PASSED | Classify BodasdeSangre_FedericoGarciaLorca.txt book using 4 languages [CLASSIFY ../Books/BodasdeSangre_FedericoGarciaLorca.txt ../Books/changedMan.bgr ../Books/lesMiserables.bgr ../Books/fortunata.bgr ../Books/Die_Verwandlung.Franz_Kafka.German.bgr]|
| 114| T03_Advanced.Integration_CLASSIFY_Die-valgrind | PASSED | NO LEAKS |
| 114 | T03_Advanced.Integration_CLASSIFY_Die | PASSED | Classify Die_Verwandlung.Franz_Kafka.German.txt book using 4 languages [CLASSIFY ../Books/Die_Verwandlung.Franz_Kafka.German.txt ../Books/changedMan.bgr ../Books/lesMiserables.bgr ../Books/fortunata.bgr ../Books/aliceWonder.bgr]|
