#pragma once
#include "maze2d.h"
#include <unordered_map>
#include "Maze2dGenerator.h"
#include <iostream>
class MazeController;

class MazeModel {
private:
	std::unordered_map<std::string, maze2d>  m_data;
	SimpleMaze2dGenerator m_generator;
	MazeController* m_control;
public:
	Vertex GetMazeSize(std::string name);
	
	maze2d& getMaze(std::string name);
	
	void setController(MazeController* control);
	 
	void generateMaze();

};


