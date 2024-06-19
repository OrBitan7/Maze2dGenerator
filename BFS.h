#pragma once

#include "vertex.h"
template <class T>
class BFS : public CommonSearcher<T>
{

public:
	virtual Solution<Vertex> search(const Searchable<T>& s) 
	{
        Solution<T> sol;
    // Ensure a clear path from start to end using BFS
    std::queue<Vertex> bfsQueue;
    bfsQueue.push(startVertex);
    bool foundPath = false;

    while (!bfsQueue.empty()) {
        Vertex current = bfsQueue.front();
        bfsQueue.pop();
        sol.pushback(Vertex(current.getRow(), current.setColumn()));
        if (current == endVertex) {

            foundPath = true;
            break;
        }

        Vertex neighbors[4];
        // Populate neighbors array similar to your maze generation code

        for (int i = 0; i < 4; ++i) {
            if (neighbors[i].getRow() != 0) {
                bfsQueue.push(neighbors[i]);
            }
        }
    }

    if (!foundPath) {
       
        return sol; // Regenerate the maze if no clear path is found
    }

    
		
		
		return ; 
	};
};
