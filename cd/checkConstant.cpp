#include <iostream>
#include <string>
#include <sstream>

bool isVariableDeclaration(const std::string& line) {
    std::istringstream iss(line);
    std::string type, varName, equalSign;
    
    if (iss >> type >> varName >> equalSign) {
        return (equalSign == "=");
    }
    return false;
}

bool isConstantDefinition(const std::string& line) {
    return line.find("#define") == 0;
}

void checkInput(const std::string& line) {
    if (isVariableDeclaration(line)) {
        std::istringstream iss(line);
        std::string type, varName;
        iss >> type >> varName;
        std::cout << varName << " - variable" << std::endl;
    } else if (isConstantDefinition(line)) {
        std::istringstream iss(line);
        std::string define, constName;
        iss >> define >> constName;
        std::cout << constName << " - constant" << std::endl;
    } else {
        std::cout << "Invalid input format." << std::endl;
    }
}

int main() {
    std::string inputLine;

    std::cout << "Enter a line of code (variable declaration or constant definition): ";
    std::getline(std::cin, inputLine);

    checkInput(inputLine);

    return 0;
} 
