#pragma once
#include "Course.h"
#include "Student.h"
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
    Student* sptr{nullptr};

    public:
    CourseRegistration();
    CourseRegistration(int,int);
    int getMaxS();
    int getNumofS();
    void setMaxS(int);
    void setNumofS(int);



};
CourseRegistration::CourseRegistration()
{
    MaxNumberOfStudents=0;
    NumberOfCurrentStudents=0;
    sptr=new Student[MaxNumberOfStudents];
}
CourseRegistration::CourseRegistration(int maxS,int CurrentS)
{
    MaxNumberOfStudents=maxS;
    NumberOfCurrentStudents=CurrentS;
    sptr=new Student[MaxNumberOfStudents];
}
int CourseRegistration::getMaxS()
{
    return MaxNumberOfStudents;
}
int CourseRegistration::getNumofS()
{
    return NumberOfCurrentStudents;
}
void CourseRegistration::setMaxS(int max)
{
    MaxNumberOfStudents=max;
}
void CourseRegistration::setNumofS(int now)
{
    NumberOfCurrentStudents=now;
}