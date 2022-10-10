#pragma once
#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegistration.h"

#include <iostream>
#include <string>
using namespace std;


class dataManager {

private:
	CourseRegistration* courseArray[100];
	Student* studentArray[2000];
	int positioncourse ;
	int positionstd ;


public:
	dataManager();
	bool insertCourseRegistration(CourseRegistration*);
	bool insertStudent(Student*);
	bool Delete(Student*);
	bool registering_to_Course(Student*, Course&);
	bool dropping_a_Course(Student*, Course&);
	int courseEnrollment(Course&);
	void studentCourses(int);
	bool samestudent(Student*, Student*); //used to delete a certain student
	bool studentinrecords(Student*);
	void print();
	~dataManager();








};
