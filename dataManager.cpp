#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegistration.h"
#include "dataManager.h"
#include <iostream>
#include <string>
using namespace std;



dataManager::dataManager() {
	int positioncourse=0;
	int positionstd=0;
}

bool dataManager::insertCourseRegistration(CourseRegistration* that) {
	for (int i = 0; i < 100; i++) {
		if (courseArray[i] == nullptr) {
			courseArray[i] = that;
			break;
		
		}
	}
	if (positioncourse < 100) {
		cout << "CourseRegistration was added succesfully.\n" << endl;
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
		return true;
	}
	else {
		cout << "Task failed,You cant add any more students!!!\n" << endl;
		return false;
	}

}

bool dataManager::Delete(Student* that) {

	for (int i = 0; i < positionstd; i++) {
		if (samestudent(studentArray[i], that)) {
			delete studentArray[i];
			studentArray[i] = nullptr;
			cout << "Student " << that->getid() << " Was Deleted Succesfully.\n";
			return true;
		}
	}
	 cout << "Student " << that->getid() << " Was Not Found in our system.\n";
	return false;
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
	cout << "The following are all the courses available this semester: " << endl;
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

	delete[] courseArray;
	delete[] studentArray;
	cout << "Object of type DataManager was deleted\n";
}
