#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegistration.h"
#include "dataManager.h"
#include <iostream>
#include <string>
using namespace std;



dataManager::dataManager() {

	 positioncourse = 0;
	 positionstd = 0;
	for (int i = 0; i < 100; i++) {
		courseArray[i] = nullptr;
	};

	for (int i = 0; i < 2000; i++) {
		studentArray[i] = nullptr;
	};
	
}

bool dataManager::insertCourseRegistration(CourseRegistration* that) {
	for (int i = 0; i < 100; i++) {
		if (courseArray[i] == nullptr) {
			courseArray[i] = that;
			break;
		
		}
	}
	if (positioncourse < 100) {
		cout << "CourseRegistration was added succesfully." << endl;
		positioncourse++;
		return true;
	}
	else {
		cout << "Error! You have reached the maximum number of CourseRegistration that can be added.\n" << endl;
		return false;
	 
	}
}

bool dataManager::insertStudent(Student* that) {

	if (positionstd < 2000) {
		studentArray[positionstd] = that;
		positionstd++;
		cout << "Student was added successfully.\n";
		return true;
	}
	else {
		cout << "Task failed,You cant add any more students!!!\n" << endl;
		return false;
	}

}

bool dataManager::Delete(Student* that) {
	bool res = false;
	for (int i = 0; i < positionstd; i++) {

		if (samestudent(studentArray[i], that)) {
			
			studentArray[i] = nullptr;
			res= true;
		}
		else { 
			continue;
		}
	}
	if (res) {
		cout << "Student Was Deleted Succesfully.\n";
		return res;
	}
	else {
		cout << "Student Was Not Found in our system.\n";
		return res;
	}
}

bool dataManager::samestudent(Student* first , Student* second) {
	if (first->getid() != second->getid() || first->getname() != second->getname()) {return false; }
	return true;
}

bool dataManager::registering_to_Course(Student* stud, Course& crs) {
	if (!(studentinrecords(stud))) {
		this->insertStudent(stud);
	}
	for (int i = 0; i < positioncourse; i++) {
		if (crs.samecourse(courseArray[i]->getcourse())) {

			if (stud->addcourse(crs)) {
				courseArray[i]->addStudent(stud);
				return true;
			
			}
			

		}
	
	}
	return false;

}
bool dataManager::dropping_a_Course(Student* stud, Course& crs) {

	if (stud->isregistered(crs)) {
		stud->removecourse(crs);
		for (int i = 0; i < positioncourse; i++) {
			if (crs.samecourse(courseArray[i]->getcourse())) {
				courseArray[i]->removestudent(stud);
				cout << "Course was dropped successfully\n" << endl;
				return true;
			}
		}

	}
	return false;
}

int dataManager::courseEnrollment(Course& crs) {
	for (int i = 0; i < positioncourse; i++) {
		if (crs.samecourse(courseArray[i]->getcourse())) {
			return courseArray[i]->getNumofS();
		}
		
	
	}
	return 0;
}
void dataManager::studentCourses(int id) {
	for (int i = 0; i < positionstd; i++) {
		if (studentArray[i]->getid() == id) {
			studentArray[i]->displaycourses();
		}
	}
}

bool dataManager::studentinrecords(Student* that) {
	for (int i = 0; i < positionstd; i++) {
		if (samestudent(studentArray[i], that) ){
			return true;
		}
	}
	return false;
}

void dataManager::print() {
	cout << "The following are all the courses available this semester: \n" << endl;
	for (int i = 0; i < positioncourse; i++) {
		courseArray[i]->displaycourse();
	}
}

dataManager::~dataManager() {
	for (int i = 0; i < positioncourse; i++) {
		delete courseArray[i];
	}
	for (int i = 0; i < positionstd; i++) {
		delete studentArray[i];
	}

	cout << "Object of type DataManager was deleted\n";
}
