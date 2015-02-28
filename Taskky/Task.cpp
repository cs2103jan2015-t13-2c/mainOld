#include "Task.h"



Task::Task(string taskDescription, string taskDetails, ptime taskStartTime, ptime taskEndTime, 
		   ptime taskReminder, TaskRecurrence taskRecurrence, TaskPriority taskPriority){
	Task::setDescription(taskDescription);
	Task::setDetails(taskDetails);
//	Task::setStartTime(taskStartTime);
//	Task::setEndTime(taskEndTime);
//	Task::setReminder(taskReminder);
	Task::setRecurrence(taskRecurrence);
	Task::setPriority(taskPriority);
}


Task::Task(string taskDescription){
	Task::setDescription(taskDescription);
	Task::setDetails("");
//	Task::setStartTime(posix_time::second_clock::local_time());
//	Task::setEndTime(posix_time::second_clock::local_time());
//	Task::setReminder(posix_time::second_clock::local_time());
	Task::setRecurrence(TaskRecurrence::NONE);
	Task::setPriority(TaskPriority::LOW);
	}


Task::~Task(void) {
	
};


//Definition of Task getters

string Task::getDescription() {
	return Task::_taskDescription;
}

string Task::getDetails() {
	return Task::_taskDetails;
}

ptime Task::getStartTime() {
	return Task::_taskStartTime;
}

ptime Task::getEndTime() {
	return Task::_taskEndTime;
}

ptime Task::getReminder() {
	return Task::_taskReminder;
}

Task::TaskRecurrence Task::getRecurrence() {
	return Task::_taskRecurrence;
}

Task::TaskPriority Task::getPriority() {
	return Task::_taskPriority;
}


//Definition of Task setters

void Task::setDescription(string taskDescription) {
	Task::_taskDescription = taskDescription;
}

void Task::setDetails(string taskDetails) {
	Task::_taskDetails = taskDetails;
}

void Task::setStartTime(ptime taskStartTime) {
	Task::_taskStartTime = taskStartTime;
}

void Task::setEndTime(ptime taskEndTime) {
	Task::_taskEndTime = taskEndTime;
}

void Task::setReminder(ptime taskReminder) {
	Task::_taskReminder = taskReminder;
}

void Task::setRecurrence(TaskRecurrence taskRecurrence) {
	Task::_taskRecurrence = taskRecurrence;
}

void Task::setPriority(TaskPriority taskPriority) {
	Task::_taskPriority = taskPriority;
}


//Finding type of task (not implemented yet!)
bool Task::isFloatingTask(){
	return true;
}

bool Task::isTimedTask(){
	return true;
}

bool Task::isRecurringTask(){
	return true;
}