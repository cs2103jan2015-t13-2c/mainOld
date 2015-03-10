#include <iostream>
#include "Task.h"
#include "Logic.h"

using namespace std;

int main() {

	string command;
	getline(cin, command);
	Logic::main(command);
	cin.get();
	return 0;
}