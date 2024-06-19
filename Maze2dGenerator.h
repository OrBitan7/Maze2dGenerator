#pragma once
#include "vertex.h"
#include "maze2d.h"
#include <iostream>

class Maze2dGenerator {
public:
	virtual maze2d generate(std::string name, int rows, int columns) = 0;
};

class SimpleMaze2dGenerator : public Maze2dGenerator {
public:
	bool isValidCell(const Vertex& cell, int rows, int columns) {
		return cell.getRow() >= 0 && cell.getRow() < rows && cell.getColumn() >= 0 && cell.getColumn() < columns;
	}
	maze2d generate(std::string name, int rows, int columns);

	// Cantor's pairing function
	int cantorPair(int x, int y) {
		return (x + y) * (x + y + 1) / 2 + y;
	}
};