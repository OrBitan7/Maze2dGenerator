#pragma once
#include "vertex.h"
#include <iostream>
#include <string>
#include <vector>
#include "State.h"

#define WALL '#'
#define START 'S'
#define END 'E'
#define CLEAR ' '



class maze2d {
private:
    std::string m_name;
    char** m_mazemap;
    Vertex m_potion;
    Vertex m_start_potion;
    Vertex m_end_potion;
    int m_rows;
    int m_columns;
    void print_maze_move();


public:
    maze2d() :m_rows(0), m_columns(0),m_mazemap (NULL){ };
    maze2d(std::string name, int rows, int columns, char** maze, Vertex start, Vertex end);
    void print_maze();
    void move();
    Vertex getStart() {
        return 	m_start_potion;
    }
    Vertex getEnd() {
        return 	m_end_potion;
    }
    Vertex getSize() {
        return Vertex(m_rows, m_columns);
    };
    char** getData() { return m_mazemap; };
    int getRows() { return m_rows; };
    int getColumns() { return m_columns; };
    
    vector<Vertex> getAllPossiblePositions() {
        vector<Vertex> retVector;
        for (int i = 0; i < m_rows; i++)
        {
            for (int j = 0; j < m_columns; j++)
            {
                if (m_mazemap[i][j] == ' ')
                    retVector.push_back(Vertex(i, j));
            }
        }
    }
};