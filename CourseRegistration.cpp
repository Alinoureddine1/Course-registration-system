
#include "Course.h"
#include "Student.h"
#include "LectureTime.h"
#include "CourseRegsitration.h"
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
    return this->NumberOfCurrentStudents;
}
void CourseRegistration::setMaxS(int max)
{
    this->MaxNumberOfStudents = max;
}
void CourseRegistration::setNumofS(int now)
{
    this->NumberOfCurrentStudents = now;
}
