# Makefile
# Mario Rodríguez Ruiz

SRC = src
INC = include
OBJ = obj
LIB = lib
BIN = bin
DOC = doc
CXX = g++
CPPFLAGS = -g -Wall -I$(INC)

all: $(BIN)/pruebatraductor $(BIN)/traductor_inverso $(BIN)/concatenar $(BIN)/sumar

# ************ Generación de documentación ******************
documentacion:
	doxygen $(DOC)/doxys/Doxyfile
	
# ************ Compilación de módulos ************
$(BIN)/pruebatraductor: $(OBJ)/pruebatraductor.o $(LIB)/libTraductor.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/pruebatraductor $(OBJ)/pruebatraductor.o -L$(LIB)/ -lTraductor

$(BIN)/traductor_inverso: $(OBJ)/traductor_inverso.o $(LIB)/libTraductor.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/traductor_inverso $(OBJ)/traductor_inverso.o -L$(LIB)/ -lTraductor

$(BIN)/concatenar: $(OBJ)/concatenar.o $(LIB)/libTraductor.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/concatenar $(OBJ)/concatenar.o -L$(LIB)/ -lTraductor

$(BIN)/sumar: $(OBJ)/sumar.o $(LIB)/libTraductor.a
	$(CXX) $(CPPFLAGS) -o $(BIN)/sumar $(OBJ)/sumar.o -L$(LIB)/ -lTraductor

$(LIB)/libTraductor.a: $(OBJ)/traductor.o $(OBJ)/frases.o $(OBJ)/traductor_inverso.o $(OBJ)/concatenar.o $(OBJ)/sumar.o
	ar rsv $(LIB)/libTraductor.a $(OBJ)/traductor.o $(OBJ)/frases.o $(OBJ)/traductor_inverso.o $(OBJ)/concatenar.o $(OBJ)/sumar.o

$(OBJ)/pruebatraductor.o: $(SRC)/pruebatraductor.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/pruebatraductor.cpp -o $(OBJ)/pruebatraductor.o -I$(INC)/

$(OBJ)/traductor.o: $(SRC)/traductor.cpp $(INC)/traductor.h $(INC)/frases.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/traductor.cpp -o $(OBJ)/traductor.o -I$(INC)/

$(OBJ)/frases.o: $(SRC)/frases.cpp $(INC)/frases.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/frases.cpp -o $(OBJ)/frases.o -I$(INC)/

$(OBJ)/traductor_inverso.o: $(SRC)/traductor_inverso.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/traductor_inverso.cpp -o $(OBJ)/traductor_inverso.o -I$(INC)/

$(OBJ)/concatenar.o: $(SRC)/concatenar.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/concatenar.cpp -o $(OBJ)/concatenar.o -I$(INC)/

$(OBJ)/sumar.o: $(SRC)/sumar.cpp $(INC)/traductor.h
	$(CXX) $(CPPFLAGS) -c $(SRC)/sumar.cpp -o $(OBJ)/sumar.o -I$(INC)/

# ************ Modos de ejecución ******************

traductor:
	$(BIN)/pruebatraductor datos/frases_ingles_espanhol.txt

inverso:
	$(BIN)/traductor_inverso datos/frases_ingles_espanhol.txt frases_espanhol_ingles.txt

concatenar:
	$(BIN)/concatenar datos/frases_ingles_espanhol.txt datos/frases_español_frances.txt frases_ingles_frances.txt

sumar:
	$(BIN)/sumar datos/frases_español_frances.txt datos/frases_español_frances_2.txt frases_español_frances_suma.txt

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/pruebatraductor datos/frases_ingles_espanhol.txt

ddd:
	ddd $(BIN)/concatenar

# ************ Limpieza ************
clean :
	@echo "Borrando objetos..."
	-rm $(OBJ)/* $(LIB)/*

mrproper : clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/search doc/html doc/rtf
