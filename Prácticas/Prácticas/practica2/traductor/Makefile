# Makefile
# Mario Rodríguez Ruiz

SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
DOC = doc
CXX = g++
CPPFLAGS = -g -Wall -pedantic -ansi -std=c++11 -I$(INC)

all: $(BIN)/pruebatrad_test

# ************ Generación de documentación ******************
documentacion:
	doxygen $(DOC)/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/pruebatrad_test: $(OBJ)/pruebatrad_test.o $(LIB)/libTraductor.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/pruebatrad_test $(OBJ)/pruebatrad_test.o -L$(LIB)/ -lTraductor

$(LIB)/libTraductor.a: $(OBJ)/conjuntofrases.o $(OBJ)/frases.o
	ar rsv $(LIB)/libTraductor.a $(OBJ)/conjuntofrases.o $(OBJ)/frases.o

$(OBJ)/pruebatrad_test.o: $(SRC)/pruebatrad_test.cpp $(INC)/conjuntofrases.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/pruebatrad_test.cpp -o $(OBJ)/pruebatrad_test.o -I$(INC)/

$(OBJ)/conjuntofrases.o: $(SRC)/conjuntofrases.cpp $(INC)/conjuntofrases.h $(INC)/frases.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/conjuntofrases.cpp -o $(OBJ)/conjuntofrases.o -I$(INC)/

$(OBJ)/frases.o: $(SRC)/frases.cpp $(INC)/frases.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/frases.cpp -o $(OBJ)/frases.o -I$(INC)/


# ************ Modos de ejecución ******************

run:
	$(BIN)/pruebatrad_test datos/frases_ingles_espanhol.txt

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/pruebatrad_test datos/frases_ingles_espanhol.txt

ddd:
	ddd $(BIN)/pruebatrad_test

# ************ Limpieza ************
clean :
	@echo "Borrando objetos..."
	-rm $(OBJ)/* $(LIB)/*

mrproper : clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/search doc/html doc/rtf
