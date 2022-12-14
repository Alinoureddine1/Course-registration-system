#pragma once
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
using namespace std;


class Student
{
private:
	std::string studentName;
	int studentId;
	int numbcredits; //max 15 to be implemented
	int counter;     // number of courses taken
	Course* courses[6];

public:
	Student();
	Student(std::string,int,int, Course *that[6]);
	Student(std::string, int);
	void setname(std::string);
	void setid(int);
	void setcredits(int);
	void setcounter(int);
	bool addcourse( Course&);
	bool isregistered(Course &);
	bool removecourse(Course&);
	void displaycourses();
	std::string getname();
	bool samestudent(Student*);
	int getid();
	int getcredits();
	Course returncourse(int); //choose which course to be returned (1 to 6)

	~Student();


};

