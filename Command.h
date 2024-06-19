#pragma once
#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include "maze2d.h"
#include "contoler.h"
class MazeController;

class Command {
protected:
    MazeController* m_control;
public:
    Command(MazeController* new_control) :m_control(new_control) {};
    virtual void  execute(std::string arg) = 0;
};

class DirCommand : public Command {
private:
public:
    DirCommand(MazeController* new_control) : Command::Command(new_control) { };

    void execute(std::string arg)override;
     
};

class GenerateMazeCommand : public Command {
private:
public:
    GenerateMazeCommand(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override;
    
};

class DisplayCommand : public Command {
public:
    DisplayCommand(MazeController* new_control) : Command::Command(new_control) { };

    void execute(std::string arg)override;
   
};

class SaveMazeCommand : public Command {
private:
public:
    SaveMazeCommand(MazeController* new_control) : Command::Command(new_control) { };

    void execute(std::string arg) override;
};

class LoadMazeCommand : public Command {
public:
    LoadMazeCommand(MazeController* new_control) : Command::Command(new_control) { };

    void execute(std::string arg)override {};
};

class MazeSizeCommand : public Command {
private:
public:
    MazeSizeCommand(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override;
};

class FileSizeCommand : public Command {
public:
    FileSizeCommand(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override;
};

class SolveCommand : public Command {
public:
    SolveCommand(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override {};//didnt do the solving
};

class mazemove : public Command {
public:
    mazemove(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override ;
};

class DisplaySolutionCommand : public Command {
public:
    DisplaySolutionCommand(MazeController* new_control) : Command::Command(new_control) { };
    void execute(std::string arg)override {};//dont have this solutions
};