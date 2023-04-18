# OUTCOME OF TESTS FOR PROJECT language2_template

As of Apr 18 2023 09:00:54

| ID | NAME | RESULT | DESCRIPTION | 
| :--- | :--- | :--- | :--- |
| 1 | T01_Basics.Bigram_Bigram_ss_1 |  PASSED |```Bigram ab("ab");ab.inspectT()```|
| | | | should give ```"ab"```|
| 2 | T01_Basics.Bigram_Bigram_ss_2 |  PASSED |```Bigram gg("__");gg .inspectT();```|
| | | | should give ```"__"```|
| 3 | T01_Basics.Bigram_Bigram_sss_ |  PASSED |```Bigram b("abcd");b .inspectT();;```|
| | | | should give ```"__"```|
| 4 | T01_Basics.Bigram_Bigram___ |  PASSED |```Bigram b("");b .inspectT();;```|
| | | | should give ```"__"```|
| 5 | T01_Basics.Bigram_Bigram_c_c_ |  PASSED |```Bigram b('a', 'a');b .inspectT();```|
| | | | should give ```"aa"```|
| 6 | T01_Basics.Bigram_at_i1 |  PASSED |```Bigram b("ab");b.at(0);```|
| | | | should give ```"a"```|
| 7 | T01_Basics.Bigram_at_i2 |  PASSED |```Bigram b("ab");b.at(1);```|
| | | | should give ```"b"```|
| 8 | T01_Basics.Bigram_getText |  PASSED |```Bigram b("ab");b.getText();```|
| | | | should give ```"ab"```|
| 9 | T01_Basics.BigramFreq_BigramFreq_ |  PASSED |```BigramFreq bf;bf.inspectT()```|
| | | | should give ```"__ 0"```|
| 10 | T01_Basics.BigramFreq_toString_ |  PASSED |```BigramFreq bf;bf.inspectT()```|
| | | | should give ```"__ 0"```|
| 11 | T01_Basics.BigramFreq_getFreq_ |  PASSED |```BigramFreq bf;bf.getFrequency()```|
| | | | should give ```0```|
| 12 | T01_Basics.BigramFreq_getBigram_ |  PASSED |```BigramFreq bf;bf.getBigram().inspectT()```|
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
| 32 | T02_Intermediate.Bigram_at_i3 |  PASSED |```Bigram b("ab");b.at(20);```|
| | | | should THROW an exception std::out_of_range|
| 33 | T02_Intermediate.Bigram_at_i_var |  PASSED |```Bigram b("ab"); b.at(0) = 'd';b .inspectT();```|
| | | | should give ```"db"```|
| 34 | T02_Intermediate.Bigram_at_i_var2 |  PASSED |```Bigram b("ab"); b.at(1) = 'd';b .inspectT();;```|
| | | | should give ```"ad"```|
| 35 | T02_Intermediate.isValidChar_c |  PASSED |```char c='a';isValidCharacter(c,validCharacters);```|
| | | | should give ```true```|
| 36 | T02_Intermediate.isValidChar_X |  PASSED |```char c='@';isValidCharacter(c,validCharacters);```|
| | | | should give ```false```|
| 37 | T02_Intermediate.toUpper_b |  PASSED |```Bigram bigram("ab");bigram.toUpper();bigram .inspectT();```|
| | | | should give ```"AB"```|
| 38 | T02_Intermediate.BigramFreq_setBigram_ |  PASSED |```Bigram b("XY");BigramFreq bf;bf.setBigram(b);bf.getBigram().inspectT()```|
| | | | should give ```"XY"```|
| 39 | T02_Intermediate.BigramFreq_setFrequency_ |  PASSED |```BigramFreq bf; bf.setFrequency(10);bf.getFrequency();```|
| | | | should give ```10```|
| 40 | T02_Intermediate.BigramFreq_setFrequency_exception |  PASSED |```BigramFreq bf;bf.setFrequency(-10);```|
| | | | should THROW an exception std::out_of_range|
| 41 | T02_Intermediate.Language_controlSize_append_3 |  PASSED |```const int DIM_VECTOR_BIGRAM_FREQ = 2000; Language lang; int i; int n= DIM_VECTOR_BIGRAM_FREQ; BigramFreq bf; bf.setFrequency(10); for ( i = 0; i < n; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);} lang.append(bf);lang._size```|
| | | | should give ```2000```|
| 42 | T02_Intermediate.Language_append_4 |  PASSED |```const int DIM_VECTOR_BIGRAM_FREQ = 2000; int i; int n= DIM_VECTOR_BIGRAM_FREQ; Language lang; BigramFreq bf; bf.setFrequency(10); for ( i = 0; i < n; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf); } Bigram b2(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b2);lang.append(bf);```|
| | | | should THROW an exception std::out_of_range|
| 43 | T02_Intermediate.Language_out_of_range_at_4 |  PASSED |```Language lang; BigramFreq bf; bf.setFrequency(10); for (int i = 0; i < 10; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);}lang.at(-1);```|
| | | | should THROW an exception std::out_of_range|
| 44 | T02_Intermediate.Language_out_of_range_at_5 |  PASSED |```Language lang; BigramFreq bf; bf.setFrequency(10); for (int i = 0; i < 10; i++) { Bigram b1(char((i/100)+'A'),char((i MOD 100)+'A')); bf.setBigram(b1); lang.append(bf);}lang.at(10);```|
| | | | should THROW an exception std::out_of_range|
| 45 | T02_Intermediate.Language_append2_toString |  PASSED |```Bigram b1("XY"); Bigram b2("ZZ"); BigramFreq bf; bf.setBigram(b1); bf.setFrequency(10); Language lang; lang.append(bf); lang.append(bf); bf.setBigram(b2); lang.append(bf);lang.inspectT()```|
| | | | should give ```"unknown 2 XY 20 ZZ 10 "```|
| 46 | T02_Intermediate.Language_join_intersection_empy_1 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language l2; bf.setBigram(b1); l1.append(bf); bf.setBigram(b2); l1.append(bf); bf.setBigram(b3); l2.append(bf); bf.setBigram(b4); l2.append(bf); int initialSize = l1.getSize(); l1.join(l2);l1._size```|
| | | | should give ```4```|
| 47 | T02_Intermediate.Language_joinShouldIncreaseFrequencyWhenBigramIsAlreadyInLanguage_2 |  PASSED |```Bigram b1("aa"); Bigram b2("bb"); Bigram b3("cc"); Bigram b4("dd"); BigramFreq bf; bf.setFrequency(10); Language l1; Language l2; bf.setBigram(b1); l1.append(bf); l2.append(bf); bf.setBigram(b2); l1.append(bf); l2.append(bf); bf.setBigram(b3); l1.append(bf); l2.append(bf); bf.setBigram(b4); l1.append(bf); l2.append(bf); l1.join(l2); int sum=0; for (int i= 0; i < l1.getSize(); i++) sum += l1.at(i).getFrequency();l1._size*20```|
| | | | should give ```80```|
| 48 | T02_Intermediate.Language_saveLoad_10 |  PASSED |```Language l1; Language l2; l1.setLanguageId("Test1"); char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=0; i < 10; i++) { bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); b.at(1)=c+i; bf.setBigram(b); bf.setFrequency(10-i); l1.append(bf); } l1.sort(); const char* fileName = "data/test_save1.bgr"; l1.save(fileName); l2.load(fileName); bool iguales=true; iguales = l1.inspectT() == l2.inspectT();iguales```|
| | | | should give ```true```|
| 49 | T02_Intermediate.sort_2_tieByFreq |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10); l1.append(bf); b.at(1)=c+i; } l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 3 aa 10 ab 10 ac 10 "```|
| 50 | T02_Intermediate.sort_3_mixed |  PASSED |```Language l1; char c='a'; BigramFreq bf; Bigram b(c,c); for(int i=1; i < 4; i++) { bf.setBigram(b); bf.setFrequency(10*i); l1.append(bf); b.at(1)=c+i; } bf.setBigram(b); l1.append(bf); l1.sort();l1.inspectT();```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 51| T03_Advanced.Integration_10bigrams_10bigrams-valgrind | PASSED | NO LEAKS |
| 51 | T03_Advanced.Integration_10bigrams_10bigrams | PASSED | Join of data/10bigrams.bgr + data/10bigrams.bgr|
| 51 | T03_Advanced.Integration_10bigrams_10bigrams |  PASSED |```Join of data/10bigrams.bgr + data/10bigrams.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 52| T03_Advanced.Integration_OnlyOneInputFile-valgrind | PASSED | NO LEAKS |
| 52 | T03_Advanced.Integration_OnlyOneInputFile | PASSED | Only one input file: data/30bigrams.bgr|
| 52 | T03_Advanced.Integration_OnlyOneInputFile |  PASSED |```Only one input file: data/30bigrams.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 53| T03_Advanced.Integration_30bigrams_30bigrams2-valgrind | PASSED | NO LEAKS |
| 53 | T03_Advanced.Integration_30bigrams_30bigrams2 | PASSED | Join of data/30bigrams.bgr and data/30bigrams2.bgr|
| 53 | T03_Advanced.Integration_30bigrams_30bigrams2 |  PASSED |```Join of data/30bigrams.bgr and data/30bigrams2.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 54| T03_Advanced.Integration_30bigrams_36bigrams-valgrind | PASSED | NO LEAKS |
| 54 | T03_Advanced.Integration_30bigrams_36bigrams | PASSED | Join of data/30bigrams.bgr and data/36bigrams.bgr|
| 54 | T03_Advanced.Integration_30bigrams_36bigrams |  PASSED |```Join of data/30bigrams.bgr and data/36bigrams.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 55| T03_Advanced.Integration_30bigrams_lesMiserables_changedMan_30bigrams-valgrind | PASSED | NO LEAKS |
| 55 | T03_Advanced.Integration_30bigrams_lesMiserables_changedMan_30bigrams | PASSED | Join of data/30bigrams.bgr data/Books/lesMiserables.bgr data/Books/changedMan.bgr and data/30bigrams.bgr|
| 55 | T03_Advanced.Integration_30bigrams_lesMiserables_changedMan_30bigrams |  PASSED |```Join of data/30bigrams.bgr data/Books/lesMiserables.bgr data/Books/changedMan.bgr and data/30bigrams.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 56| T03_Advanced.Integration_english-valgrind | PASSED | NO LEAKS |
| 56 | T03_Advanced.Integration_english | PASSED | Join of data/Books/aliceWonder.bgr and data/Books/changedMan.bgr|
| 56 | T03_Advanced.Integration_english |  PASSED |```Join of data/Books/aliceWonder.bgr and data/Books/changedMan.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 57| T03_Advanced.Integration_french-valgrind | PASSED | NO LEAKS |
| 57 | T03_Advanced.Integration_french | PASSED | Join of data/Books/diderot.bgr and data/Books/lesMiserables|
| 57 | T03_Advanced.Integration_french |  PASSED |```Join of data/Books/diderot.bgr and data/Books/lesMiserables```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 58| T03_Advanced.Integration_german-valgrind | PASSED | NO LEAKS |
| 58 | T03_Advanced.Integration_german | PASSED | Join of data/Books/Faust_part1_Der_Tragodie_erster_Teil.Goethe.German.bgr and data/Books/Faust_part2_Der_Tragodie_zweiter_Teil.Goethe.German.bgr|
| 58 | T03_Advanced.Integration_german |  PASSED |```Join of data/Books/Faust_part1_Der_Tragodie_erster_Teil.Goethe.German.bgr and data/Books/Faust_part2_Der_Tragodie_zweiter_Teil.Goethe.German.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
| 59| T03_Advanced.Integration_spanish-valgrind | PASSED | NO LEAKS |
| 59 | T03_Advanced.Integration_spanish | PASSED | Join of data/Books/BodasdeSangre_FedericoGarciaLorca.bgr and data/Books/quijote.bgr|
| 59 | T03_Advanced.Integration_spanish |  PASSED |```Join of data/Books/BodasdeSangre_FedericoGarciaLorca.bgr and data/Books/quijote.bgr```|
| | | | should give ```"unknown 4 ac 30 ad 30 ab 20 aa 10 "```|
