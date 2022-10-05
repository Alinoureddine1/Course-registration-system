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
	Student(std::string,int,int,int,const Course *that[6]);
	void setname(std::string);
	void setid(int);
	void setcredits(int);
	void setcounter(int);
	void addcourse( Course&);
	void displaycourses();
	std::string getname();
	int getid();
	int getcredits();
	Course returncourse(int); //choose which course to be returned (1 to 6)

	~Student();


};

