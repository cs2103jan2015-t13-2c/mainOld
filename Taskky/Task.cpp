#include "Task.h"


Task::Task(std::string taskDescription){
	Task::setTaskDescription(taskDescription);
	Task::setTaskPriority(TaskPriority::PRIORITY_NORMAL);
}

Task::Task(std::string taskDescription, 
		std::string taskDetails,
		boost::posix_time::ptime taskDeadline,
		boost::posix_time::time_duration taskReminder,
		boost::gregorian::date_duration taskRecurrance,
		Task::TaskPriority taskPriority){
	Task::setTaskDescription(taskDescription);
	Task::setTaskDetails(taskDetails);
	Task::setTaskDeadline(taskDeadline);
	Task::setTaskReminder(taskReminder);
	Task::setTaskRecurrance(taskRecurrance);
	Task::setTaskPriority(taskPriority);
}

Task::~Task(void)
{
}

std::string Task::getTaskDescription(){
	return _taskDescription;
}
std::string Task::getTaskDetails(){
	return _taskDetails;
}
boost::posix_time::ptime Task::getTaskDeadline(){
	return _taskDeadline;
}
boost::posix_time::time_duration Task::getTaskReminder(){
	return _taskReminder;
}
boost::gregorian::date_duration Task::getTaskRecurrance(){
	return _taskRecurrance;
}
Task::TaskPriority Task::getTaskPriority(){
	return _taskPriority;
}

void Task::setTaskDescription(std::string taskDescription){
	_taskDescription=taskDescription;
}
void Task::setTaskDetails(std::string taskDetails){
	_taskDetails=taskDetails;
}
void Task::setTaskDeadline(boost::posix_time::ptime taskDeadline){
	_taskDeadline=taskDeadline;
}
void Task::setTaskReminder(boost::posix_time::time_duration taskReminder){
	_taskReminder=taskReminder;
}
void Task::setTaskRecurrance(boost::gregorian::date_duration taskRecurrance){
	_taskRecurrance=taskRecurrance;
}
void Task::setTaskPriority(TaskPriority taskPriority){
	_taskPriority=taskPriority;
}

int main(void){
	return 0;
}