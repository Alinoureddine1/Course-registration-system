
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
#include "Student.h"
using namespace std;

int main()
{
    LectureTime lect("M","T",12);
   
    Course lec("coen","21",lect,19);
    LectureTime l(lec.getlectime());
    cout << l.getfday() << endl;
    Student s;
    s.setname("Ali");
    
    return 0;
}
