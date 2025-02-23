#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Task.h"

using namespace std;

class Logic {
public:
	enum COMMAND_TYPE {
		CREATE, READ, UPDATE, DELETE, CLEAR, SORT, SEARCH, EXIT, INVALID	//Add on to this as we expand our project
	};

	static void main(string command);

private:
	//Command Parsers
	static COMMAND_TYPE determineCommandType(string commandTypeString);
	static string determineContent(string command);
	static string removeWords(string command, string content);
	static string getFirstWord(string userCommand);
	static string removeFirstWord(string userCommand);
	static vector<string> splitParameters(string commandParametersString);

	static string processCommand(COMMAND_TYPE commandType, string content);

	//Processing Functions
	static string addTask(string userCommand);
	static string checkTask(string userCommand);
	static string updateTask(string userCommand);
	static string deleteTask(string userCommand);
	static string clear();
	static string sortTask();
	static string searchTask(string userCommand);

	//This is to indicate wrong user input
	static const string MESSAGE_INVALID_FORMAT;

	static const int INVALID_NUMBER_FORMAT = -1;

	static const int BUFFER_SIZE = 255;
	static char buffer[BUFFER_SIZE];

	//Useful functions
	static string trim_right(const string& s, const string& delimiters = " \f\n\r\t\v");
	static string trim_left(const string& s, const string& delimiters = " \f\n\r\t\v");
	static string trim(const string& s, const string& delimiters = " \f\n\r\t\v");
	static bool equalsIgnoreCase(const string& str1, const string& str2);
	static int parseInt(string str);
	static string replace(string a, string b, string c);
	template <typename T, size_t N> inline static size_t sizeOfArray(const T(&)[N]);

};