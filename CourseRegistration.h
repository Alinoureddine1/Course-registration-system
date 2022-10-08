#pragma once
#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include <iostream>
#include <string>
using namespace std;


// static int MaxNumberOfStudents=2;
class CourseRegistration
{
private:
    Course c1;
    int MaxNumberOfStudents;
    int NumberOfCurrentStudents;
    Student** sptr;
    

public:
    CourseRegistration();
    CourseRegistration(int, int);
    int getMaxS();
    int getNumofS();
    void setMaxS(int);
    void setNumofS(int);



};
