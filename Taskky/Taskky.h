// This is to safeguard the class to prevent redefined
#ifndef TASKKY_H_
#define TASKKY_H_

// Download the Boost library from http://www.boost.org/users/download/
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp" 
#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string/classification.hpp"

#include <string>
#include <vector>

using namespace std;
using namespace boost;
using namespace boost::posix_time;
using namespace boost::gregorian;


//This is the class used to store each Task object
class Task {
public:
	enum class TaskRecurrence {NONE, DAY, WEEK, MONTH, YEAR};
	enum class TaskPriority {LOW,NORMAL,HIGH};

	Task();

	~Task(void);

	//attribute getters
	static int getNumber();
	static string getDescription();
	static string getDetails();
	static ptime getStartTime();
	static ptime getEndTime();
	static ptime getReminder();
	static Task::TaskRecurrence getRecurrence();
	static Task::TaskPriority getPriority();
	
	//attribute setters
	static void setNumber(int taskNumber);
	static void setDescription(string taskDescription);
	static void setDetails(string taskDetails);
	static void setStartTime(ptime taskStartTime);
	static void setEndTime(ptime taskEndTime);
	static void setReminder(ptime taskReminder);
	static void setRecurrence(TaskRecurrence taskRecurrence);
	static void setPriority(TaskPriority taskPriority);

private:
	static int _Number;
	static string _Description;
	static string _Details;
	static ptime _startTime;
	static ptime _endTime;
	static ptime _Reminder;
	static Task::TaskRecurrence _Recurrence;
	static Task::TaskPriority _Priority;
};

	int Task::_Number = 0;
	string Task::_Description = "";
	string Task::_Details = "";
	ptime Task::_startTime = posix_time::second_clock::local_time();
	ptime Task::_endTime = posix_time::second_clock::local_time();
	ptime Task::_Reminder = posix_time::second_clock::local_time();
	Task::TaskRecurrence Task::_Recurrence = TaskRecurrence::NONE;
	Task::TaskPriority Task::_Priority = TaskPriority::LOW;


//This is the class used to run the Taskky program
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