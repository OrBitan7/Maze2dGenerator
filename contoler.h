#pragma once
#include "CLI.h"
#include "model.h"
#include "Command.h"
//#include "contoler.h"

class Command;
class CLI;
class MazeModel;


class MazeController {

private:
	CLI* m_view;
	MazeModel* m_model;
	std::unordered_map<std::string, Command*>  data;

public:
	MazeController() {
		m_view = NULL;
		m_model = NULL;
	};
	void setView(CLI* view);
	void setModel(MazeModel* Model);
	CLI* getView();
	MazeModel* getModel();
	void genMaze();
	void prtintComannd();
	void doCommand(const std::string& commandName, const std::string& argument);
	void addCommand(const std::string name, Command* command);
	void printMaze(std::string mazeName);
	void mazeMove(std::string name);
};