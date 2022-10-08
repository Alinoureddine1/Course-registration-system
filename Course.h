#pragma once
#include "LectureTime.h"
#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
	Course();
	Course(std::string, std::string, const LectureTime&, int);
	Course(const Course&);
	void setcnumber(std::string);
	void setcname(std::string);
	void setlectime(const LectureTime&);
	void setcredits(int);
	std::string getcourseNumber();
	std::string getcourseName();
	LectureTime getlectime();
	int gettime();
	bool overlap( Course&); //testing if it overlaps
	int getcedits();
	bool samecourse(Course&);
	void printcourse();
	void operator= (const Course& temp);
	~Course();


private:
	std::string courseNumber;
	std::string courseName;
	LectureTime lecturetime;
	int numbcredits;

};

