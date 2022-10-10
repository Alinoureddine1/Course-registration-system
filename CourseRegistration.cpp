#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegistration.h"
#include <iostream>
#include <string>
using namespace std;



CourseRegistration::CourseRegistration(int maxS, int CurrentS)
{
    MaxNumberOfStudents = maxS;
    NumberOfCurrentStudents = CurrentS;
    sptr = new Student * [MaxNumberOfStudents];

    for (int i = 0; i < MaxNumberOfStudents; i++) {
        sptr[i] = nullptr;
    }
    
    
}


  int CourseRegistration::getMaxS() 
  {
      return this->MaxNumberOfStudents;

  }

int CourseRegistration::getNumofS()
{
    return (this->NumberOfCurrentStudents );
}
void CourseRegistration::setMaxS(int max)
{
    this->MaxNumberOfStudents = max;
}
void CourseRegistration::setNumofS(int now)
{
    this->NumberOfCurrentStudents = now;
}

void CourseRegistration::addStudent(Student * temp) 
{
    if (NumberOfCurrentStudents < MaxNumberOfStudents) {
        this->sptr[NumberOfCurrentStudents] = temp;
        NumberOfCurrentStudents++;
    }
    else {
        cout << "Course is full\n" << endl;
    }
}
void CourseRegistration::setcourse(Course& crs) {
    this->c1 = crs;
}
Course& CourseRegistration::getcourse() {
    return this->c1;
}
bool CourseRegistration::lookforstudent(Student* temp) 
{
    for (int i = 0; i < NumberOfCurrentStudents + 1; i++) {

        if (this->sptr[i]->getid() == temp->getid() && this->sptr[i]->getname() == temp->getname()) {
            return true;
        }
    }
    return false;
}

void CourseRegistration::displaycourse() {
    this->c1.printcourse();
    cout << "Enrollments: " << this->getNumofS() << "\t Seats available: " << this->getMaxS() - this->getNumofS() << "\n"<< endl;

}

void CourseRegistration::removestudent(Student* temp) {
    for (int i = 0; i < NumberOfCurrentStudents; i++) {

        if (sptr[i]->samestudent(temp)) {
            sptr[i] = nullptr;
            
        }
    }
}


CourseRegistration::~CourseRegistration() 
{
    for (int i = 0; i < MaxNumberOfStudents; i++) {
        delete sptr[i];
    };
    
    cout << "Object of time CourseRegistration was deleted.\n" << endl;
}
