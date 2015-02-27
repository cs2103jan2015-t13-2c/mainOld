#include "Taskky.h"

/*
* ==================================================================== 
*  Main program 
* ====================================================================
*/
void Taskky::main() {
	printWelcomeMessage();

	vector<Task> taskList[100];

	while (true) {
		cout << "command: ";
		string userCommand;
		getline (cin, userCommand);
		string feedback = executeCommand(userCommand, *taskList);
		showToUser(feedback);	
	}
}


/*
* ==================================================================== 
*  Command line parse
* ====================================================================
*/
void Taskky::printWelcomeMessage() {
	sprintf_s(buffer, WELCOME_MESSAGE.c_str());
	cout << buffer << "\n";
}

void Taskky::showToUser(string text) {
	cout << text << "\n";
}

string Taskky::executeCommand(string userCommand, vector<Task> &taskList) {
	if(trim(userCommand) == "") {
		sprintf_s(buffer, INVALID_MESSAGE_FORMAT.c_str(), "");
		return buffer;
	}

	string commandTypeString = getFirstWord(userCommand);
		
	CommandType commandType = determineCommandType(commandTypeString);

	switch (commandType) {
	case Add: 
		return addTask(userCommand, taskList);
	case Check:
		return checkTask(userCommand, taskList);
	case Update: 
		return updateTask(userCommand, taskList);
	case Delete:
		return deleteTask(userCommand, taskList);
	case Invalid: {
		sprintf_s(buffer, INVALID_MESSAGE_FORMAT.c_str(), userCommand.c_str());
		return buffer;
		}
	case Exit:
		exit(0);
	default:
		//Generates an error message and terminates the program
		showToUser(ERROR_UNRECOGNISED_COMMAND_TYPE);
		showToUser(MESSAGE_PROGRAM_TERMINATION);

		getchar();
		exit(EXIT_FAILURE);
	}
}


/*
* ==================================================================== 
*  Main functions
* ====================================================================
*/

//This operation determines which of the supported command types the user
//wants to perform (commandTypeString is the first word of the user command)
Taskky::CommandType Taskky::determineCommandType(string commandTypeString) {
	if(equalsIgnoreCase(commandTypeString, "add")) {
		return CommandType::Add;
	} else if (equalsIgnoreCase(commandTypeString, "check")) {
		return CommandType::Check;
	} else if (equalsIgnoreCase(commandTypeString, "update")) {
		return CommandType::Update;
	} else if (equalsIgnoreCase(commandTypeString, "delete")) {
		return CommandType::Delete;
	} else if (equalsIgnoreCase(commandTypeString, "exit")) {
		return CommandType::Exit;
	} else {
		return CommandType::Invalid;
	}
}

string Taskky::addTask(string userCommand, vector<Task> &taskList) {

/* User can enter task in 3 different formats:

   1. timed tasks
   e.g. add 19 February, to 21 February, chinese new year

   2. tasks with deadlines
   e.g add 10 July, 5pm-6pm, project meeting

   3. floating tasks
   e.g add finish coding assignment
*/
	Task newTask;
	newTask.setNumber(taskList.size());
  	string text = removeFirstWord(userCommand);

	vector<string> info = splitParameters(text, ",");

	vector<string>::iterator iter;
	for(iter=info.begin(); iter!=info.end(); iter++) {		
		string keyWord = getFirstWord(*iter);
	
	}

	return "0";
}

string Taskky::checkTask(string userCommand, vector<Task> &taskList) {
	return "0";
}

string Taskky::updateTask(string userCommand, vector<Task> &taskList) {
	return "0";
}

string Taskky::deleteTask(string userCommand, vector<Task> &taskList) {
	return "0";
}

/*
* ==================================================================== 
*  Additional functions
* ====================================================================
*/
string Taskky::removeFirstWord(string userCommand) {
	return trim(replace(userCommand, getFirstWord(userCommand), ""));
}

string Taskky::getFirstWord(string userCommand) {
	string commandTypeString = splitParameters(userCommand, " ")[0];
	return commandTypeString;
}

vector<string> Taskky::splitParameters(string commandParametersString, string delimiter) {
	vector<string> tokens;
	
	split(tokens, commandParametersString, is_any_of(delimiter), token_compress_on); 

	return tokens;
}

inline string Taskky::trim_right(const string& s, const string& delimiters) {
	return s.substr( 0, s.find_last_not_of( delimiters ) + 1 );
}

inline string Taskky::trim_left(const string& s, const string& delimiters) {
	return s.substr( s.find_first_not_of( delimiters ) );
}

inline string Taskky::trim(const string& s, const string& delimiters) {
	if(!s.empty())
		return trim_left( trim_right( s, delimiters ), delimiters );
	else
		return s;
}

bool Taskky::equalsIgnoreCase(const string& str1, const string& str2) {
    if (str1.size() != str2.size()) {
        return false;
    }	
    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2) {
        if (tolower(*c1) != tolower(*c2)) {
            return false;
        }
    }
    return true;
}

int Taskky::parseInt(string str) {
	char c;
	int i=0;
    std::stringstream ss(str);
    ss >> i;
    if (ss.fail() || ss.get(c)) {
		return INVALID_NUMBER_FORMAT;
    } else {
		return i;
	}
}

string Taskky::replace(string a, string b, string c) {
    int pos ;
    do {
        pos = a.find(b);
        if (pos!=-1)  a.replace(pos, b.length(), c);
    }
    while (pos!=-1);
    return a;
}


/*
* ==================================================================== 
*  Program Messages
* ====================================================================
*/
// These are the static variables that cannot be initialized in header file
const string Taskky::WELCOME_MESSAGE = "Welcome to T.A.S.K.K.Y. This is v0.1.";
const string Taskky::MESSAGE_ADDED = "Added Task #%d: \n%s";
const string Taskky::MESSAGE_UPDATED = "Updated Task #%d: \n%s";
const string Taskky::MESSAGE_DELETED = "Deleted Task #%d";
const string Taskky::INVALID_MESSAGE_FORMAT = "Invalid command format: %s";
const string Taskky::MESSAGE_PROGRAM_TERMINATION = "Press any key to terminate the program . . .";

const string Taskky::ERROR_UNRECOGNISED_COMMAND_TYPE = "ERROR: Unrecognised command type";

char Taskky::buffer[255];


/*
* ==================================================================== 
*  Functions used in Task class
* ====================================================================
*/
Task::Task() {
	Task::setDescription("");
	Task::setDetails("");
//	Task::setStartTime(ptime taskStartTime);
//	Task::setEndTime(ptime taskEndTime);
//	Task::setReminder(ptime taskReminder);
	Task::setRecurrence(TaskRecurrence::NONE);
	Task::setPriority(TaskPriority::LOW);
}

Task::~Task(void) {
};

int Task::getNumber() {
	return _Number;
}

string Task::getDescription() {
	return _Description;
}

string Task::getDetails() {
	return _Details;
}

ptime Task::getStartTime() {
	return _startTime;
}

ptime Task::getEndTime() {
	return _endTime;
}

ptime Task::getReminder() {
	return _Reminder;
}

Task::TaskRecurrence Task::getRecurrence() {
	return _Recurrence;
}

Task::TaskPriority Task::getPriority() {
	return _Priority;
}

void Task::setNumber(int taskNumber) {
	_Number = taskNumber;
}

void Task::setDescription(string taskDescription) {
	_Description = taskDescription;
}

void Task::setDetails(string taskDetails) {
	_Details = taskDetails;
}

void Task::setStartTime(ptime taskStartTime) {
	_startTime = taskStartTime;
}

void Task::setEndTime(ptime taskEndTime) {
	_endTime = taskEndTime;
}

void Task::setReminder(ptime taskReminder) {
	_Reminder = taskReminder;
}

void Task::setRecurrence(TaskRecurrence taskRecurrence) {
	_Recurrence = taskRecurrence;
}

void Task::setPriority(TaskPriority taskPriority) {
	_Priority = taskPriority;
}


/*
* ==================================================================== 
*  For Program Initialization
* ====================================================================
*/
int main(){
	Taskky::main();

	return 0;
}