#pragma once

#include "Task.h"
#include <string>
#include <vector>

#include "../UI/UIMain.h"
//#include "../Storage/MainStorage.h"
//#include "../Temp/MainTemp.h"

using namespace std;

class MainLogic{

public:
	enum class Command {ADD, CHECK, UPDATE, DELETE, EXIT};
	//command should not be just a simple enum, should be more complex than it
	//Command class
	//AddCommand class inherits, etc
	//CheckCommand
	//so can store all these commands
	//this is to support easy undoing

	MainLogic::MainLogic(void);
	MainLogic::~MainLogic(void);


	//Show flow of my program
	static void MainLogic::main();
	static void MainLogic::initializeProgram();
	//UI::getUserInput
	static Command MainLogic::parseUserInput(string userInput);
	static string MainLogic::executeCommand(Command commandType);




	//Exiting the program with failure...
	static void MainLogic::exitWithFailure(string failureMessage);

	//Exiting the program successfully!
	static void MainLogic::exitWithSuccess();

	//Helping to revert to last saved state
	static void MainLogic::revertToLastSavedState()



	//getters
	static vector<Task> MainLogic::getAllCurrentTasks();
	static string MainLogic::getStorageFileName();

	//setters
	static void MainLogic::setAllCurrentTasks(vector<Task> allCurrentTasks);
	static void MainLogic::setStorageFileName();

	//======================================================================//
	//Loading and saving to storage
	//======================================================================//

	//loads the file from a storage location given the file name
	//function is defined and implemented in :Storage
	static void MainLogic::loadFromStorage();

	//save the file with a given file name to the storage location
	//function is defined and implemented in :Storage
	static void MainLogic::saveToStorage();

	 
	//======================================================================//
	//Loading and saving to temp
	//======================================================================//
	
	//to support undo function
	static void MainLogic::storeCurrentCommand(Command currentCommand);
	static Command MainLogic::getPreviousCommand();

	//to support rebooting from failed exit
	static vector<Command> MainLogic::getStoredCommands();

	//for exiting with success
	static void MainLogic::eraseStoredCommands();


private:

	//vector representing all the current tasks stored in the system
	static vector<Task> MainLogic::_allCurrentTasks;

	//the name of the temp file that you will save commands to after every command
	//this is mainly to support the undo and backup functions
	//This file name cannot be changed
	const static string MainLogic::_tempFileName;

	//Name of the storage file name (json file or xml file) that we will save Taskky in
	//Only saves upon exit
	//File name can be changed to save to a different file name
	static string MainLogic::_storageFileName;

};

