
/**
 * TODO:
 * You will need to implement the methods listed here.
 */

//
#include "Parser.hpp"
#include <iostream>
#include <vector>
#include <string>

/// Your welcome
Parser::Parser() {}

/**
 * The parseCommand method received a constant character pointer
 * representing a raw command line, and parses it into separate parts.
 * Each part represents one argument. For example, "ping -c 5 192.168.1.1"
 * would result in the following list of parts (aka arguments)
 * Arg[0] == ping
 * Arg[1] == -c
 * Arg[2] == 5
 * Arg[3] == 192.168.1.1
 *
 * The function will return the generated vector of arguments to the caller.
 */
std::vector<std::string> Parser::parseCommand(const char *command)
{
	// TODO: Your code here
	std::vector<std::string> parts;
	std::string current;
	bool inQuote = false;
	bool escaped = false;
	for (int i = 0; command[i] != '\0'; i++)
	{
		char c = command[i];
		if (!inQuote)
		{
			if (escaped)
			{
				current.push_back(c);
				escaped = false;
			}
			else
			{
				if (c == '\\')
				{
					escaped = true;
				}
				else if (c == '"')
				{
					inQuote = true;
				}
				else if (c == ' ')
				{
					if (!current.empty())
					{
						parts.push_back(current);
						current.clear();
					}
				}
				else
				{
					current.push_back(c);
				}
			}
		}
		else
		{
			if (escaped)
			{
				current.push_back(c);
				escaped = false;
			}
			else
			{
				if (c == '\\')
				{
					escaped = true;
				}
				else if (c == '"')
				{
					inQuote = false;
				}
				else
				{
					current.push_back(c);
				}
			}
		}
	}
	if (inQuote || escaped)
	{
		return std::vector<std::string>();
	}
	if (!current.empty())
	{
		parts.push_back(current);
	}
	return parts;
}

/**
 * The recombineParts method receives a constant reference to a vector-of-strings,
 * and recombines them into a command that system() can use.
 * The idea here is fairly easy:
 * - Start with an empty string.
 * - Iterate over each part.
 * - For each part, iterate over each character it contains.
 * - For each character, append it to the new string,
 *     making sure to add a backslash before any quote or backslash characters.
 * - Separate each part with a space
 *
 * You'll also want to quote each argument but the first.
 *
 * Example:
 * {"ping", "-c", "1", "192.168.1.1"} becomes: ping "-c" "1" "192.168.1.1"
 *
 * The function will return the string to the caller.
 */
std::string Parser::recombineParts(const std::vector<std::string> &parts)
{
	// TODO: Your code here
	if (parts.empty())
	{
		return "";
	}
	std::string combined = parts[0];
	for (int i = 1; i < (int)parts.size(); i++)
	{
		combined += " \"";
		for (int j = 0; j < (int)parts[i].size(); j++)
		{
			char c = parts[i][j];
			if (c == '"' || c == '\\')
			{
				combined.push_back('\\');
			}
			combined.push_back(c);
		}
		combined += "\"";
	}
	return combined;
}

/**
 * The isCommandEmpty takes a vector of parsed command parts
 * and decides if it is empty or not.
 * Return true is the incoming vector is empty, false otherwise
 */
bool Parser::isCommandEmpty(const std::vector<std::string> &parts)
{
	// TODO: Your code here
	return parts.empty();
}

/**
 * The isValidProgram function takes in a string representing the name or path
 * to a program to be executed.
 * If the program is in our list of valid/acceptable programs, it returns true
 * Otherwise, it returns false
 */
bool Parser::isValidProgram(std::string program)
{
	// TODO: Your code here
	if (program == "ls")
		return true;
	if (program == "df")
		return true;
	if (program == "pwd")
		return true;
	if (program == "ps")
		return true;
	if (program == "gedit")
		return true;
	if (program == "echo")
		return true;
	if (program == "ping")
		return true;
	return false;
}

/// Your welcome
bool Parser::isValidProgram(const std::vector<std::string> &parts)
{
	if (!parts.empty())
	{
		return Parser::isValidProgram(parts[0]);
	}

	return false;
}

/// Your welcome
bool Parser::isValidProgram(const char *program) { return Parser::isValidProgram(std::string(program)); }

/**
 * The printParts function simply prints out a list of command line parts (aka arguments)
 * First, print "Parts:" on a line.
 * Next, loop over each part and print "> [a] == b",
 *   where 'a' represents the part's index,
 *   and 'b' represents the part's value.
 */
void Parser::printParts(const std::vector<std::string> &parts)
{
	// TODO: Your code here
	std::cout << "Parts:" << std::endl;
	for (int i = 0; i < (int)parts.size(); i++)
	{
		std::cout << "> [" << i << "] == " << parts[i] << std::endl;
	}
}
