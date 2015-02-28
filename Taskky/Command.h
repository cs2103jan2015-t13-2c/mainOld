#pragma once

#include <string>

using namespace std;

class Command{

public:
	Command::Command(string commandType);
	Command::~Command(void);

	void Command::setCommandType(string commandType);
	string Command::getCommandType();

protected:
	string Command::_commandType;
};