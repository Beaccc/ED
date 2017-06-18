SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c --std=c++11

all:$(BIN)/test_refranes $(BIN)/estudio_prefijo $(BIN)/adivina

# ************ Generación de documentación ******************

documentacion:
	doxygen doc/doxys/Doxyfile
	
# ************ Compilación de módulos ************

$(BIN)/test_refranes: $(OBJ)/test_refranes.o
	$(CXX) -o $(BIN)/test_refranes $(OBJ)/test_refranes.o

$(OBJ)/test_refranes.o: $(INC)/cual_compila.h $(SRC)/test_refranes.cpp
	$(CXX) $(CPPFLAGS)  $(SRC)/test_refranes.cpp -o $(OBJ)/test_refranes.o -I$(INC) -I$(SRC)
	
$(BIN)/adivina: $(OBJ)/adivina.o
	$(CXX) -o $(BIN)/adivina $(OBJ)/adivina.o

$(OBJ)/adivina.o: $(SRC)/adivina.cpp $(INC)/refranes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/adivina.cpp -o $(OBJ)/adivina.o -I$(INC) -I$(SRC)
		
$(BIN)/estudio_prefijo: $(OBJ)/estudio_prefijo.o
	$(CXX) -o $(BIN)/estudio_prefijo $(OBJ)/estudio_prefijo.o

$(OBJ)/estudio_prefijo.o: $(SRC)/estudio_prefijo.cpp $(INC)/refranes.h
	$(CXX) $(CPPFLAGS)  $(SRC)/estudio_prefijo.cpp -o $(OBJ)/estudio_prefijo.o -I$(INC) -I$(SRC)

# ************ Ejecución ************

run:
	#bin/test_refranes datos/refranes_español.txt
	bin/estudio_prefijo datos/refranes_español.txt estudio_esp.csv
# 	bin/adivina datos/refranes_español.txt 50
# 	bin/test_refranes datos/refranes_español.txt

val:

	#valgrind bin/test_refranes datos/refranes_español.txt
	valgrind --leak-check=full --track-origins=yes bin/adivina datos/refranes_español.txt 50
# 	valgrind --leak-check=full --track-origins=yes bin/test_refranes datos/refranes_español.txt
# ************ Limpieza ************
clean :
	@echo "Borrando objetos..."
	-rm $(OBJ)/*

mrproper : clean
	@echo "Limpiando..."
	-rm $(BIN)/*
	-rm -R doc/html/search doc/html doc/rtf
