#include "Command.h"


void DirCommand::execute(std::string arg) {
    std::filesystem::path the_path;
    if (arg == "") the_path = std::filesystem::current_path();
    try {
        for (const auto& entry : std::filesystem::directory_iterator(the_path)) {
            if (std::filesystem::is_directory(entry)) {
                std::cout << "[DIR] " << entry.path().filename() << std::endl;
            }
            else {
                std::cout << "[FILE] " << entry.path().filename() << std::endl;
            }
        }
    }
    catch (const std::filesystem::filesystem_error& err)
    {
        std::cout << err.what() << std::endl;
    }
}

void GenerateMazeCommand::execute(std::string arg) {
    m_control->getModel()->generateMaze();
}

void DisplayCommand::execute(std::string arg) {
    m_control->printMaze(arg);
};

void SaveMazeCommand::execute(std::string arg)  {
    std::cout << "Maze name:";
    std::string maze_name;
    std::cin >> maze_name;
    std::cout << "Maze file name:";
    std::string filename;
    std::cin >> filename;
    maze2d temp = m_control->getModel()->getMaze(maze_name);
    if (temp.getColumns() == 0) {
        std::cout << "maze not exist" << std::endl;
        return;
    }

    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    int rows = temp.getRows();
    int columns = temp.getColumns();
    char** map = temp.getData();
    outFile << rows << "\n";
    outFile << columns << "\n";
    outFile << temp.getStart().getRow() << "\n" << temp.getStart().getColumn() << "\n";
    outFile << temp.getEnd().getRow() << "\n" << temp.getEnd().getColumn() << "\n";

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            outFile << map[i][j];
        }
        outFile << "\n";
    }

    outFile.close();
}

void MazeSizeCommand::execute(std::string arg) {
    m_control->getModel()->GetMazeSize(arg);
    
};

void FileSizeCommand::execute(std::string arg) {
    std::ifstream inFile(arg);

    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << arg << std::endl;
        return;
    }
    int rows, columns;
    std::string line;

    // Read the first line (rows)
    if (std::getline(inFile, line)) {
        rows = std::stoi(line);
    }
    else {
        std::cerr << "Error reading rows from file." << std::endl;
        return;
    }

    // Read the second line (columns)
    if (std::getline(inFile, line)) {
        columns = std::stoi(line);
    }
    else {
        std::cerr << "Error reading columns from file." << std::endl;
        return;
    }
    std::cout << "rows=" << rows << " clumns=" << columns << std::endl;
    inFile.close();
};





void mazemove::execute(std::string arg) {
    std::cout << "Enter maze name:";
    std::string name;
    std::cin >> name;
    m_control->mazeMove(name);
}