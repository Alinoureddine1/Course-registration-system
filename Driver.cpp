
#include "Student.h"
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
#include <string>
using namespace std;

int main()
{
   LectureTime lect("M","T",950);
   LectureTime lect1("W", "T", 1000);
   
    Course lec("coen","21",lect,3);
    Course lec2("math", "212", lect1, 3);
    LectureTime l(lec.getlectime());
    cout << l.getfday() << endl;

    Student s;
    string name = "name";
    
    s.setname(name);
    s.addcourse(lec);
    s.addcourse(lec2);
    s.displaycourses();
   
    return 0;
}
