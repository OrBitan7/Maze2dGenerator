#include "contoler.h"


void MazeController::setView(CLI* view) {
	m_view = view;
};
void MazeController::setModel(MazeModel* Model) {
	m_model = Model;
};
CLI* MazeController::getView() { return m_view; };
MazeModel* MazeController::getModel() { return m_model; };
void MazeController::genMaze() {
	m_model->generateMaze();
};
void MazeController::prtintComannd() {
	for (const auto& pair : data) {
		std::cout << pair.first << std::endl;
	}
	std::cout << "exit" << std::endl;

};
void MazeController::doCommand(const std::string& commandName, const std::string& argument = " ") {

	auto it = data.find(commandName);
	if (it != data.end()) {
		it->second->execute(argument);
	}
	else {
		std::cout << "Unknown command: " << commandName << std::endl;
	}
};
void MazeController::addCommand(const std::string name, Command* command) {
	data[name] = command;
};
void MazeController::printMaze(std::string mazeName) {
	m_model->getMaze(mazeName).print_maze();
}

void MazeController::mazeMove(std::string name) {
	m_model->getMaze(name).move();
}