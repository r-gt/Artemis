CC      = gcc
FLAGS   = -Wall -Wextra
BUILD   = bin
EXE     = bin/program.out

make:
	mkdir -p $(BUILD)

	$(CC) $(FLAGS) -o $(BUILD)/artemis.o        -c artemis.c
	$(CC) $(FLAGS) -o $(BUILD)/validaciones.o   -c validaciones.c
	$(CC) $(FLAGS) -o $(BUILD)/simulacion.o     -c simulacion.c
	$(CC) $(FLAGS) -o $(BUILD)/main.o           -c main.c


	$(CC) $(FLAGS) -o $(EXE) $(BUILD)/artemis.o $(BUILD)/validaciones.o $(BUILD)/simulacion.o $(BUILD)/main.o -lm

clean:
	rm ./$(BUILD)/*

test: make
	$(EXE)
