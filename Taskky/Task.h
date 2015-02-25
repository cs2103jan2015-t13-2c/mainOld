#pragma once

#include <string>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp" 

class Task {

public:
	enum class TaskPriority {PRIORITY_LOW,PRIORITY_NORMAL,PRIORITY_HIGH};
	
	Task(std::string taskDescription);
	Task(std::string taskDescription, 
		std::string taskDetails,
		boost::posix_time::ptime taskDeadline,
		boost::posix_time::time_duration taskReminder,
		boost::gregorian::date_duration taskRecurrance,
		Task::TaskPriority taskPriority);

	~Task(void);

	//attribute getters
	std::string Task::getTaskDescription();
	std::string Task::getTaskDetails();
	boost::posix_time::ptime Task::getTaskDeadline();
	boost::posix_time::time_duration Task::getTaskReminder();
	boost::gregorian::date_duration Task::getTaskRecurrance();
	Task::TaskPriority Task::getTaskPriority();
	
	//attribute setters
	void Task::setTaskDescription(std::string taskDescription);
	void Task::setTaskDetails(std::string taskDetails);
	void Task::setTaskDeadline(boost::posix_time::ptime taskDeadline);
	void Task::setTaskReminder(boost::posix_time::time_duration taskReminder);
	void Task::setTaskRecurrance(boost::gregorian::date_duration taskRecurrance);
	void Task::setTaskPriority(TaskPriority taskPriority);


private:
	std::string _taskDescription;

	std::string _taskDetails;

	boost::posix_time::ptime _taskDeadline;
	//if no deadline it is just a floating task
	//ptime will be not_a_date_time if no arguments, jsut ptime p;

	boost::posix_time::time_duration _taskReminder;

	boost::gregorian::date_duration _taskRecurrance;

	Task::TaskPriority _taskPriority;

};

