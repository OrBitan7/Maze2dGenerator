#include "vertex.h"
#include <iostream>
#include "CLI.h"
#include "Maze2dGenerator.h"
#include "maze2d.h"
#include "Command.h"

using namespace std;

int main() {
	CLI cli(std::cin, std::cout);
	MazeController mazeController;
	MazeModel mazeModel;


	mazeController.setModel(&mazeModel);
	mazeController.setView(&cli);
	cli.setController(&mazeController);
	
	DirCommand dirCommand(&mazeController);
	SaveMazeCommand savemaze(&mazeController);
	GenerateMazeCommand genMaze(&mazeController);
	DisplayCommand display(&mazeController);
	LoadMazeCommand load(&mazeController);
	MazeSizeCommand mazeSize(&mazeController);
	FileSizeCommand fileSize(&mazeController);
	SolveCommand solvMaze(&mazeController);
	DisplaySolutionCommand displaySolu(&mazeController);
	mazemove mazeMove(&mazeController);
	mazeController.addCommand("dir", &dirCommand);
	mazeController.addCommand("generatemaze", &genMaze);
	mazeController.addCommand("display", &display);
	mazeController.addCommand("savemaze", &savemaze);
	mazeController.addCommand("loadmaze", &load);
	mazeController.addCommand("mazesize", &mazeSize);
	mazeController.addCommand("filesize", &fileSize);
	mazeController.addCommand("solve", &solvMaze);
	mazeController.addCommand("displatsolution", &displaySolu);
	mazeController.addCommand("move", &mazeMove);
	mazeController.prtintComannd();
	cli.start();

	return 0;
}