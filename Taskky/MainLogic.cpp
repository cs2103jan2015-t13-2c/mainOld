#include "MainLogic.h"


MainLogic::MainLogic(void)
{
}


MainLogic::~MainLogic(void)
{
}


/*
* ==================================================================== 
*  Main program 
* ====================================================================
*/

void MainLogic::main() {
	MainLogic::initializeProgram();
	string userInput = UIMain::getUserInput();
	Command command = MainLogic::parseUserInput(userInput);
	string feedback = MainLogic::executeCommand(command);
}

//initializing program
void MainLogic::initializeProgram(){
	bool isExitWithFailure = true;
	if(isExitWithFailure){
		vector<Command> allStoredCommands = MainLogic::getStoredCommands();
		MainLogic::revertToLastSavedState();
	}else{
		MainLogic::loadFromStorage();
	}
}

//Exiting the program with failure...
void MainLogic::exitWithFailure(string failureMessage){
}

//Exiting the program successfully!
void MainLogic::exitWithSuccess(){
	MainLogic::saveToStorage();
	MainLogic::eraseStoredCommands();
}


/*
* ==================================================================== 
*  For Program Initialization
* ====================================================================
*/
int main(){
	MainLogic::main();
	return 0;
}