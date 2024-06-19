#pragma once
#include <iostream>
#include <unordered_map>
#include <sstream>
#include "Command.h"
#include "contoler.h"
class MazeController;
class Command;
class CLI
{
private:
    std::istream& in;
    std::ostream& out;
    MazeController* m_control;
public:
    CLI(std::istream& input, std::ostream& output);
    ~CLI() {};
    void init();

    void setController(MazeController* control) {
        m_control = control;
    };
    void output(std::string output);
    void start();
};