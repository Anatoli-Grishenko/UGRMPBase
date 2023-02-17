
#SRC = src
#INC = include
#OBJ = obj
#LIB = lib
#BIN = bin

SRC = ./src
INC = ./include
OBJ = ./makeFiles/obj
LIB = ./makeFiles/lib
BIN = ./makeFiles/bin

CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/learn  $(BIN)/classify 


#Ejecutables

$(BIN)/learn: $(LIB)/liblanguages.a $(OBJ)/learn.o 
	g++ -o $(BIN)/learn $(OBJ)/learn.o -llanguages -L$(LIB)


$(BIN)/classify: $(LIB)/liblanguages.a $(OBJ)/classify.o 
	g++ -o $(BIN)/classify $(OBJ)/classify.o -llanguages -L$(LIB)

# ************ Generación de documentación ******************
documentation:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************

$(OBJ)/Bigram.o : $(SRC)/Bigram.cpp $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/Bigram.cpp -o $(OBJ)/Bigram.o
	
$(OBJ)/BigramFreq.o : $(SRC)/BigramFreq.cpp $(INC)/BigramFreq.h $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/BigramFreq.cpp -o $(OBJ)/BigramFreq.o

$(OBJ)/BigramCounter.o : $(SRC)/BigramCounter.cpp $(INC)/BigramCounter.h $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/BigramCounter.cpp -o $(OBJ)/BigramCounter.o

$(OBJ)/Language.o : $(SRC)/Language.cpp $(INC)/Language.h $(INC)/BigramCounter.h $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/Language.cpp -o $(OBJ)/Language.o
	
#Objetos de los mains

$(OBJ)/learn.o : $(SRC)/learn.cpp $(INC)/Language.h $(INC)/BigramCounter.h  $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/learn.cpp -o $(OBJ)/learn.o

$(OBJ)/classify.o : $(SRC)/classify.cpp $(INC)/Language.h $(INC)/BigramCounter.h  $(INC)/Bigram.h
	$(CXX) $(CPPFLAGS) $(SRC)/classify.cpp -o $(OBJ)/classify.o

	
# ************ Generación de la biblioteca  ************
$(LIB)/liblanguages.a: $(OBJ)/Bigram.o $(OBJ)/BigramFreq.o $(OBJ)/BigramCounter.o $(OBJ)/Language.o 
	ar rsv $(LIB)/liblanguages.a  $(OBJ)/Bigram.o $(OBJ)/BigramFreq.o $(OBJ)/BigramCounter.o $(OBJ)/Language.o 


# ************ Limpieza ************
clean :
	-rm $(OBJ)/*.o $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/learn  $(BIN)/classify doc/html/*
