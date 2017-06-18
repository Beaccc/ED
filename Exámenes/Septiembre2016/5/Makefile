SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/test_diccionario

# ************ Generación de documentación ******************

documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************


$(BIN)/test_diccionario: $(OBJ)/test_diccionario.o $(OBJ)/Diccionario.o
	$(CXX) -o $(BIN)/test_diccionario $(OBJ)/test_diccionario.o $(OBJ)/Diccionario.o

$(OBJ)/test_diccionario.o: $(INC)/Diccionario.h $(SRC)/test_diccionario.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/test_diccionario.cpp -o $(OBJ)/test_diccionario.o

$(OBJ)/Diccionario.o: $(INC)/Diccionario.h $(SRC)/Diccionario.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o

# ************ Ejecución ************

run:
	bin/test_diccionario

ddd:
	ddd bin/test_diccionario

val:

	#valgrind bin/test_diccionario datos/refranes_español.txt
	valgrind --leak-check=full --track-origins=yes bin/test_diccionario datos/refranes_español.txt

# ************ Limpieza ************
clean :
	@echo "Borrando objetos..."
	-rm $(OBJ)/*

mrproper : clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/search doc/html doc/rtf
