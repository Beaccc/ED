SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c

all: $(BIN)/usopilas_max
	@echo "Para generar la documentacion ejecutar make documentacion"


$(BIN)/usopilas_max: $(OBJ)/pila_max.o $(OBJ)/usopilas_max.o 
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o $(OBJ)/pila_max.o 

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/pila_max.h 
	$(CXX) $(CPPFLAGS)  $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

$(OBJ)/pila_max.o : $(SRC)/pila_max.cpp $(SRC)/pila_max_list.cpp $(INC)/pila_max.h $(INC)/pila_max_list.h $(INC)/pila_max_VD.h $(SRC)/pila_max_VD.cpp $(INC)/pila_max_cola.h $(SRC)/pila_max_cola.cpp 
	$(CXX) $(CPPFLAGS) $(SRC)/pila_max.cpp -o $(OBJ)/pila_max.o 


# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(BIN)/* doc/html/*



