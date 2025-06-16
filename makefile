# Makefile para Wakawaka Wars

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
SRC = src/main.cpp src/Juego.cpp src/Pacman.cpp src/Ghost.cpp
BIN = bin/wakawaka

all: $(BIN)

$(BIN): $(SRC)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf bin/*
