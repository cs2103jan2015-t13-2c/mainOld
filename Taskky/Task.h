#pragma once

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

class Task {

public:
	enum class TaskRecurrence {NONE, DAY, WEEK, MONTH, YEAR};
	enum class TaskPriority {LOW,NORMAL,HIGH};

	//Deault constructor
	Task::Task(string taskDescription, string taskDetails, ptime taskStartTime, ptime taskEndTime, 
		ptime taskReminder, TaskRecurrence taskRecurrence, TaskPriority taskPriority);

	Task::Task(string taskDescription);

	Task::~Task(void);

	//attribute getters
	string Task::getDescription();
	string Task::getDetails();
	ptime Task::getStartTime();
	ptime Task::getEndTime();
	ptime Task::getReminder();
	Task::TaskRecurrence Task::getRecurrence();
	Task::TaskPriority Task::getPriority();
	
	//attribute setters
	void Task::setDescription(string taskDescription);
	void Task::setDetails(string taskDetails);
	void Task::setStartTime(ptime taskStartTime);
	void Task::setEndTime(ptime taskEndTime);
	void Task::setReminder(ptime taskReminder);
	void Task::setRecurrence(TaskRecurrence taskRecurrence);
	void Task::setPriority(TaskPriority taskPriority);

	//finding type of task
	bool Task::isFloatingTask();
	bool Task::isTimedTask();
	bool Task::isRecurringTask();

private:
	string Task::_taskDescription;
	string Task::_taskDetails;
	ptime Task::_taskStartTime;
	ptime Task::_taskEndTime;
	ptime Task::_taskReminder;
	Task::TaskRecurrence Task::_taskRecurrence;
	Task::TaskPriority Task::_taskPriority;
};