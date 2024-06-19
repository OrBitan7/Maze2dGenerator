#include "CLI.h"


CLI::CLI(std::istream& input, std::ostream& output) : in(input), out(output) {

}

/*
void CLI::addCommand(const std::string& name, Command* command) {
    data[name] = command;
}

void CLI::doCommand(const std::string& commandName, const std::string& argument) {
    auto it = data.find(commandName);
    if (it != data.end()) {
        it->second->execute(out, argument);
    } else {
        out << "Unknown command: " << commandName << std::endl;
    }
}

*/
void CLI::start() {
    std::string userInput;

    while (true) {
        out << "Enter a command: ";
        std::getline(in, userInput);

        if (userInput == "exit") {
            break;
        }
        /*
        std::istringstream iss(userInput);
        std::string commandName, argument;
        iss >> commandName >> std::ws;
        std::getline(iss, argument);
        */



        std::string commandName;
        std::string argument;
        size_t underscorePos = userInput.find(' ');
        if (underscorePos != std::string::npos) {
            commandName = userInput.substr(0, underscorePos);
            argument = userInput.substr(underscorePos + 1);
        }
        else {
            commandName = userInput;
        }

        m_control->doCommand(commandName, argument);
    }
}
void CLI::output(std::string output) {
    out << output;
}
