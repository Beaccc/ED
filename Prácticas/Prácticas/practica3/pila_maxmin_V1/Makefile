# Mario Rodríguez Ruiz

SRC = src
DAT = datos
DOC = doc
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usocolas $(BIN)/usopilas_max $(BIN)/orden

# ************ Generación de documentación ******************
documentacion:
	doxygen $(DOC)/doxys/Doxyfile

$(BIN)/usocolas: $(OBJ)/usocolas.o
	$(CXX) -o $(BIN)/usocolas $(OBJ)/usocolas.o 
$(OBJ)/usocolas.o: $(INC)/cola.h $(SRC)/usocolas.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/usocolas.cpp  -o $(OBJ)/usocolas.o -I$(INC)

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o
$(OBJ)/usopilas_max.o: $(INC)/pila_maxmin.h $(SRC)/usopilas_max.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o -I$(INC) -I$(SRC)

$(BIN)/orden: $(OBJ)/orden.o
	$(CXX) -o $(BIN)/orden $(OBJ)/orden.o
$(OBJ)/orden.o: $(INC)/pila_maxmin.h $(SRC)/orden.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/orden.cpp -o $(OBJ)/orden.o -I$(INC) -I$(SRC)

# ************ Modos de ejecución ******************

run:
	$(BIN)/usopilas_max

orden:
	$(BIN)/orden $(DAT)/pru1.txt $(DAT)/pru2.txt

valgrind:
	valgrind --leak-check=full --track-origins=yes $(BIN)/usopilas_max

ddd:
	ddd $(BIN)/orden

# ************ Limpieza ************
clean:
	@echo "Borrando objetos..."
	-rm $(OBJ)/*

mrproper: clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/
