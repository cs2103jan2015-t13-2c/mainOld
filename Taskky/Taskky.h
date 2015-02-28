// This is to safeguard the class to prevent redefined
#ifndef TASKKY_H_
#define TASKKY_H_

// Download the Boost library from http://www.boost.org/users/download/
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp" 
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"

#include "Task.h"

#include <string>
#include <vector>

using namespace std;
using namespace boost;
using namespace boost::posix_time;
using namespace boost::gregorian;


class Taskky {
public:
	// These are the possible command types
	enum CommandType {
		Add, Check, Update, Delete, Exit, Invalid
	};

	static void Taskky::main();
	static string executeCommand(string userCommand, vector<Task> &);

private:
	static CommandType determineCommandType(string commandTypeString);
	static string addTask(string userCommand, vector<Task> &);
	static string checkTask(string userCommand, vector<Task> &);
	static string updateTask(string userCommand, vector<Task> &);
	static string deleteTask(string userCommand, vector<Task> &);
	
	static string removeFirstWord(string userCommand);
	static string getFirstWord(string userCommand);
	static vector<string> splitParameters(string commandParametersString, string delimiter);
	static string trim_right(const string& s, const string& delimiters = " \f\n\r\t\v" );
	static string trim_left(const string& s, const string& delimiters = " \f\n\r\t\v" );
	static string trim(const string& s, const string& delimiters = " \f\n\r\t\v" );
	static bool equalsIgnoreCase(const string& str1, const string& str2);
	static int parseInt(string str);
	static string replace(string a ,string b , string c);

	static const string WELCOME_MESSAGE;
	static const string MESSAGE_ADDED;
	static const string MESSAGE_UPDATED;
	static const string MESSAGE_DELETED;
	static const string INVALID_MESSAGE_FORMAT;
	static const string MESSAGE_PROGRAM_TERMINATION;

	static const string ERROR_UNRECOGNISED_COMMAND_TYPE;
	static const int INVALID_NUMBER_FORMAT = -1;

	static void printWelcomeMessage();
	static void showToUser(string text);

	static char buffer[255];
};




#endif