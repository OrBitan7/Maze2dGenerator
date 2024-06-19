#pragma once

#include "Searchable.h"
#include "maze2d.h"
#include "State.h"
#include "vertex.h"
#include <vector>

class Adapter : public Searchable<Vertex> {
private:
	maze2d maze;
public:
	Adapter(maze2d new_maze) : maze(new_maze) {};
	~Adapter() {};
	State<Vertex>* getStartState() {

		Vertex start = maze.getStart();
		State<Vertex>* startST = new State<Vertex>(start);
		return startST;
	};
	State<Vertex>* getGoalState() {

		Vertex endVerstex = maze.getStart();
		State<Vertex>* endST = new State<Vertex>(endVerstex);
		return endST;
	};
	std::vector<State<Vertex>> getAllPossibleStates(State<Vertex>& s) {
		vector<Vertex> posVec = maze.getAllPossiblePositions();
		vector<State<Vertex>> stateVec;
		for (Vertex& pos : posVec)
		{
			double new_cost = 0;
			stateVec.push_back(State<Vertex>(pos, 1));
		}
		return stateVec;
	};
};