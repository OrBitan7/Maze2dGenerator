#include "model.h"


Vertex MazeModel::GetMazeSize(std::string name) {
	auto maze = m_data.find(name);
	if (maze != m_data.end()) {
		Vertex size= maze->second.getSize();
		std::cout << "row:" << size.getRow() << " column:" << size.getColumn() << std::endl;
		return size;
	}
	else {
		std::cout << "you dont have this map" << std::endl;
	}
}
maze2d& MazeModel::getMaze(std::string name) {
	auto maze = m_data.find(name);
	if (maze != m_data.end()) {
		return maze->second;
	}
	else {
		maze2d temp;
		return temp;
	}
}
void MazeModel::setController(MazeController* control) {
	m_control = control;
};
void MazeModel::generateMaze() {
	int rows, columns;
	std::string name;
	std::cout << "Enter maze name: ";
	std::cin >> name;

	std::cout << "Enter number of rows: ";
	std::cin >> rows;

	std::cout << "Enter number of columns: ";
	std::cin >> columns;
	m_data[name] = m_generator.generate(name, rows, columns);
}