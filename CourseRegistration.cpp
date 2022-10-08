#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegistration.h"
#include <iostream>
#include <string>
using namespace std;


CourseRegistration::CourseRegistration()
{
   MaxNumberOfStudents = 0;
   NumberOfCurrentStudents = 0;
  
    sptr= new Student*[MaxNumberOfStudents]{nullptr};
}
CourseRegistration::CourseRegistration(int maxS, int CurrentS)
{
    MaxNumberOfStudents = maxS;
    NumberOfCurrentStudents = CurrentS;
    sptr = new Student * [MaxNumberOfStudents] {nullptr};
    
    
}


  int CourseRegistration::getMaxS() 
  {
      return this->MaxNumberOfStudents;

  }

int CourseRegistration::getNumofS()
{
    return (this->NumberOfCurrentStudents +1);
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
    cout << "Enrollments: " << this->getNumofS() << " Seats available: " << this->getMaxS() - this->getNumofS() << endl;

}

void CourseRegistration::removestudent(Student* temp) {
    for (int i = 0; i < NumberOfCurrentStudents; i++) {

        if (sptr[i]->samestudent(temp)) {
            delete sptr[i];
            sptr[i] = nullptr;
            
        }
    }
}


CourseRegistration::~CourseRegistration() 
{
    for (int i = 0; i < MaxNumberOfStudents; i++) {
        delete sptr[i];
    };
    delete[] sptr;
    cout << "Object of time CourseRegistration was deleted.\n" << endl;
}
