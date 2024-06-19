#include "Maze2dGenerator.h"
#include <cstdlib>
#include <ctime>
#include <stack>
#include <queue>
#include <algorithm>
#include <random>
#include <unordered_map>


maze2d SimpleMaze2dGenerator::generate(std::string name, int rows, int columns) {

    char** m_mazemap = new char* [rows];
    for (int i = 0; i < rows; ++i) {
        m_mazemap[i] = new char[columns];
    }

    // Initialize maze with walls
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            m_mazemap[i][j] = WALL;
        }
    }

    // Generate maze using Depth-First Search
    std::stack<Vertex> stack;
    Vertex start(1, 1); // Start from an odd position inside the border
    Vertex end(1, 1); // End at the opposite corner inside the border
    std::unordered_map<int, int> disHashMap;
    disHashMap[cantorPair(start.getRow(), start.getColumn())] = 0;//Cantor’s pairing
    int maxDist = 0;

    m_mazemap[start.getRow()][start.getColumn()] = CLEAR;

    stack.push(start);

    while (!stack.empty()) {
        Vertex current = stack.top();
        stack.pop();
        m_mazemap[current.getRow()][current.getColumn()] = CLEAR;
        int currentDist = 0;
        int searchPair = cantorPair(current.getRow(), current.getColumn());
        if (disHashMap.find(searchPair) != disHashMap.end()) {
            currentDist = disHashMap[searchPair];
        }
        if (currentDist > maxDist) {
            maxDist = currentDist;
            end.setRow(current.getRow());
            end.setColumn(current.getColumn());
        }


        std::vector<Vertex> neighbors;

        // Check North neighbor
        Vertex north(current.getRow() - 2, current.getColumn());
        if (north.getRow() > 0 && m_mazemap[north.getRow()][north.getColumn()] == WALL) {
            neighbors.push_back(north);
        }
        // Check South neighbor
        Vertex south(current.getRow() + 2, current.getColumn());
        if (south.getRow() < rows - 1 && m_mazemap[south.getRow()][south.getColumn()] == WALL) {
            neighbors.push_back(south);
        }
        // Check West neighbor
        Vertex west(current.getRow(), current.getColumn() - 2);
        if (west.getColumn() > 0 && m_mazemap[west.getRow()][west.getColumn()] == WALL) {
            neighbors.push_back(west);
        }
        // Check East neighbor
        Vertex east(current.getRow(), current.getColumn() + 2);
        if (east.getColumn() < columns - 1 && m_mazemap[east.getRow()][east.getColumn()] == WALL) {
            neighbors.push_back(east);
        }

        if (!neighbors.empty()) {
            stack.push(current);

            int randIndex = rand() % neighbors.size();
            Vertex chosenNeighbor = neighbors[randIndex];

            int wallRow = (current.getRow() + chosenNeighbor.getRow()) / 2;
            int wallCol = (current.getColumn() + chosenNeighbor.getColumn()) / 2;

            stack.push(chosenNeighbor);
            m_mazemap[wallRow][wallCol] = CLEAR;
            disHashMap[cantorPair(chosenNeighbor.getRow(), chosenNeighbor.getColumn())] = currentDist + 1;
        }
    }
    /*
    // Set random start and end vertices in the first and last rows
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> randomCol(2, columns - 3);
    */



    // Create a maze2d object with the generated maze data and vertices
    maze2d generatedMaze(name, rows, columns, m_mazemap, start, end);


    



    return generatedMaze;
}


