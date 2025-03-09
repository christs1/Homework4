
/**
 * TODO: Complete this source file to get your program working correctly.
 */

//
#include "Executor.hpp"
#include "Parser.hpp"
#include <iostream>
#include <cstring>
#include <string>

//
int main()
{
	// TODO: Your code here
	std::cout << "Welcome to my command line interpreter (aka shell)" << std::endl;
	std::cout << "Written by Christian Rodriguez." << std::endl;

	Parser parser;
	Executor executor;

	while (true)
	{
		std::cout << std::endl;
		std::cout << "Enter next command" << std::endl;
		std::cout << "==> ";

		char buffer[8192];
		std::cin.getline(buffer, 8192);

		std::vector<std::string> parts = parser.parseCommand(buffer);
		if (parser.isCommandEmpty(parts))
		{
			continue;
		}

		if (parts[0] == "exit" || parts[0] == "quit")
		{
			parser.printParts(parts);
			std::cout << "Thanks for using my interpreter. Goodbye!" << std::endl;
			break;
		}

		parser.printParts(parts);
		if (!parser.isValidProgram(parts))
		{
			std::cout << "Invalid command!" << std::endl;
			continue;
		}

		std::string cmdString = parser.recombineParts(parts);
		char * cmd = new char[cmdString.size() + 1];
		strcpy(cmd, cmdString.c_str());
		executor.executeCommand(cmd);
		delete[] cmd;
	}

	return 0;
}
