#include "maze2d.h"


maze2d::maze2d(std::string name, int rows, int columns, char** maze, Vertex start, Vertex end) {
	m_name = name;
	m_rows = rows;
	m_columns = columns;
	m_mazemap = maze;
	m_start_potion = start;
	m_end_potion = end;
	m_potion = start;
	m_mazemap[start.getRow()][start.getColumn()] = START;
	m_mazemap[end.getRow()][end.getColumn()] = END;
}


void maze2d::print_maze() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_columns; j++) {
			std::cout << m_mazemap[i][j];
		}
		std::cout << std::endl;
	}
}



void maze2d::print_maze_move() {
	for (int i = 0; i < m_rows; i++) {
		for (int j = 0; j < m_columns; j++) {
			if (m_potion.getRow() == i && m_potion.getColumn() == j) {
				std::cout << "\033[31m" << '@' << "\033[0m";
			}
			else {
				if (m_mazemap[i][j] == 'S' || m_mazemap[i][j] == 'E')
					std::cout << "\033[32m" << m_mazemap[i][j] << "\033[0m";
				else
					std::cout << m_mazemap[i][j];

			}
		}
		std::cout << std::endl;
	}
}
void maze2d::move() {
	m_potion = m_start_potion;
	char input = ' ';
	bool flag = true;

	while (flag) {
		print_maze_move();
		std::cout << "w=up, s=down, d=right, a=left, x=exit" << std::endl << "input:";
		std::cin >> input;
		switch (input)
		{
		case'w':
			if (m_mazemap[m_potion.getRow() - 1][m_potion.getColumn()] != '#') {
				m_potion.setRow(m_potion.getRow() - 1);
			}
			break;
		case's':
			if (m_mazemap[m_potion.getRow() + 1][m_potion.getColumn()] != '#') {
				m_potion.setRow(m_potion.getRow() + 1);
			}
			break;
		case'd':
			if (m_mazemap[m_potion.getRow()][m_potion.getColumn() + 1] != '#') {
				m_potion.setColumn(m_potion.getColumn() + 1);
			}
			break;
		case'a':
			if (m_mazemap[m_potion.getRow()][m_potion.getColumn() - 1] != '#') {
				m_potion.setColumn(m_potion.getColumn() - 1);
			}
			break;
		case 'x':
			flag = false;
			break;
		}
		if ((m_potion.getRow() == m_end_potion.getRow()) && (m_potion.getColumn() == m_end_potion.getColumn())) {
			flag = false;
		}
	}
	if (input != 'x') {
		std::cout << "you reached the end!" << std::endl;
	}
}