SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/test_arbol

# ************ Generación de documentación ******************

documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************


$(BIN)/test_arbol: $(OBJ)/test_arbol.o
	$(CXX) -o $(BIN)/test_arbol $(OBJ)/test_arbol.o

$(OBJ)/test_arbol.o: $(INC)/ArbolGeneral.h $(SRC)/test_arbol.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/test_arbol.cpp -o $(OBJ)/test_arbol.o
	

# ************ Ejecución ************

run:
	bin/test_arbol

ddd:
	ddd bin/test_arbol

val:

	#valgrind bin/test_arbol datos/refranes_español.txt
	valgrind --leak-check=full --track-origins=yes bin/test_arbol
# 	valgrind --leak-check=full --track-origins=yes bin/test_arbol datos/refranes_español.txt
# ************ Limpieza ************
clean :
	@echo "Borrando objetos..."
	-rm $(OBJ)/*

mrproper : clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/search doc/html doc/rtf
