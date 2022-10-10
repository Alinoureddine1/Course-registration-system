#include "Student.h"
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
using namespace std;


Student::Student() {
	this->studentName="";
	this-> studentId =0;
	this-> numbcredits=0; 
	this-> counter=0;

	

	for (int i = 0; i < 6; i++) {
		courses[i] = nullptr;
		
	
	}
	 
}
Student::Student(std::string name, int id, int credits,  Course* that[6]) {
	
	this->setname(name);
	this->setid(id);
	this->setcounter(0);
	this->setcredits(credits);

	for (int i = 0; i < 6; i++) {                //copying the array
		this->courses[i] = that[i];
	}


}
Student::Student(std::string name, int id) {

	this->setname(name);
	this->setid(id);
	this->numbcredits = 0;
	this->setcounter(0);
	

	for (int i = 0; i < 6; i++) {                
		this->courses[i] = nullptr;
	}


}
void Student::setcounter(int count) {
	this->counter = count;
		
}

void Student::setname(std::string name) {
	this->studentName = name;
}
void Student::setid(int id) {
	this->studentId = id;
}

std::string Student::getname() {
	return this->studentName;
}
void Student::setcredits(int credits) {
	if (numbcredits > 15) {
		std::cerr << "Error! You cant exceed 15 credits\n";
		return;
	}
	this->numbcredits = credits;
}
bool Student::addcourse( Course& that) {

	if (this->counter < 6 && this->numbcredits<15) {

		for (int i = 0; i < counter; i++) {
			if (this->courses[i]->overlap(that) ) {
				std::cerr << "Error! This course overlaps with another course\n" << endl;
				return false;
			}
		}
		courses[counter] =  new Course(that);
		counter++;
		numbcredits += that.getcedits();
		return true;

	}
	else {
		std::cerr << "Error! You are not allowed to exceed 6 courses or 15 credits\n";
		return false;
	}

}

bool Student::removecourse(Course& that) {
	for (int i = 0; i < 6; i++) {
		if (this->courses[i]->samecourse((that))) {
			this->numbcredits -= that.getcedits();
			this->courses[i] = nullptr;
			return true;
		
		}

	}
	return false;
}

void Student::displaycourses() {
	std::cout << "Student "<<this->getid()<<" is enrolled to the following courses:\n";
	for (int i = 0; i < 6; i++) {
		if (courses[i] != nullptr) {
			this->courses[i]->printcourse();
		};
	}
	cout << "Total number of credits: " << this->getcredits() << "\n" << endl;

}
int Student::getid() {
	return this->studentId;
}
int Student::getcredits() {
	return this->numbcredits;
}

bool Student::isregistered(Course &that) {
	for (int i = 0; i < 6; i++) {
		if (this->courses[i]->samecourse((that))) {
			return true;
		}

	}
	return false;
}
bool Student::samestudent(Student* that) {
	if (this->getname() != that->getname() || this->getid() != that->getid()) {
		return false;
	}
	return true;
}
Course Student::returncourse(int x) {
	return *(this->courses[x - 1]);
}
Student::~Student() {


	for (int i = 0; i < this->counter; i++) {
		delete courses[i];
	
	}
	
	std::cout << "object of type Student was deleted\n" << std::endl;

}
