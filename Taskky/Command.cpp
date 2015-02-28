#include "Command.h"


Command::Command(string commandType){
	Command::_commandType=commandType;
}


Command::~Command(void)
{
}

void Command::setCommandType(string commandType){
	Command::_commandType=commandType;
}

string Command::getCommandType(){
	return Command::_commandType;
}