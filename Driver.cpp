
#include "Student.h"
#include <iostream>
#include "Course.h"
#include "LectureTime.h"
#include <string>
#include "CourseRegistration.h"
#include "dataManager.h"
using namespace std;

int main()
{
   //Creating object of type dataManager dynamically
   dataManager* conU = new dataManager;

   //Creating objects of type LectureTime dynamically
   LectureTime* lect1 = new LectureTime("M","T",950); //Note here time is in the format Hour-minute in 24 hours format 
   LectureTime* lect2= new LectureTime("M", "F", 1200);
   LectureTime* lect3 = new LectureTime("M", "W", 1300);
   LectureTime* lect4 = new LectureTime("W", "TH", 1000);
   
   
   //Creating objects of type Course dynamically
    Course* course1 = new Course("coen","212",*lect1,3);
    Course* course2 = new Course("elec", "273", *lect1, 4);
    Course* course3 = new Course("phys", "212", *lect2, 3);
    Course* course4 = new Course("math", "205", *lect3, 6);
    Course* course5 = new Course("geog", "220", *lect4, 4);
    
   
    //Creating objects of type Student dynamically
    Student* s1 = new Student("Max", 123);
    Student* s2 = new Student("Jake", 240);
    Student* s3 = new Student("Sasha", 217);
    Student* s4 = new Student("nibal", 230);
    Student* s5 = new Student("Elie", 299);
     
    //Creating objects of type CourseRegistration dynamically
    CourseRegistration* c1 = new CourseRegistration(70,0);
    CourseRegistration* c2 = new CourseRegistration(30, 0);
    CourseRegistration* c3 = new CourseRegistration(35, 0);
    CourseRegistration* c4 = new CourseRegistration(70, 0);
    CourseRegistration* c5 = new CourseRegistration(20, 0);
   
   
    //Assigning the course to each CourseRegistration object
    c1->setcourse(*course1);
    c2->setcourse(*course2);
    c3->setcourse(*course3);
    c4->setcourse(*course4);
    c5->setcourse(*course5);
   
    //Inserting students to the dataManager object 
    conU->insertStudent(s1);
    conU->insertStudent(s2);
    conU->insertStudent(s3);
    conU->insertStudent(s4);
   


    //Inserting CourseRegistration objects to the dataManager object 
    conU->insertCourseRegistration(c1);
    conU->insertCourseRegistration(c2);
    conU->insertCourseRegistration(c3);
    conU->insertCourseRegistration(c4);
    conU->insertCourseRegistration(c5);


    //Registering student 1 to courses 1, 2, and 3
    conU->registering_to_Course(s1, *course1);
    conU->registering_to_Course(s1, *course2); //Should give an error since it overlaps with course 1
    conU->registering_to_Course(s1, *course3);
    
    //diaplaying the courses registered by student 1 
    s1->displaycourses();

    //Registering student 2 to courses 1, 3, and 5
    conU->registering_to_Course(s2, *course1);
    conU->registering_to_Course(s2, *course3); 
    conU->registering_to_Course(s2, *course5);//Should give an error since it overlaps with course 1

    //displaying the courses registered by student 2 using the DataManager
    conU->studentCourses(240);

    //Dropping off course 1 from student 2
    conU->dropping_a_Course(s2, *course1);

    //diaplaying the courses registered by student 2 Again to see if the course was dropped properly 
    s2->displaycourses();

    //Enrolling more students to course 3
    conU->registering_to_Course(s3, *course3);
    conU->registering_to_Course(s4, *course3);

    //Displaying the number of students enrolled to course 3
    cout << "Course 3 has " << conU->courseEnrollment(*course3) << " Students Enrolled.\n";

    //Checking to see if student 5 is the university's records
    if (conU->studentinrecords(s5)) {
        cout << "Student is in our records.\n" << endl;
    
    }
    else {
        cout << "Student was not Found in our records.\n" << endl;   //We are expecting this result
    }

    //Displaying the courses offered by Concordia this term
    conU->print();


   

    //Deleting objects of type LectureTime 
    delete lect1;
    delete lect2;
    delete lect3;
    delete lect4;

    //Deleting objects of type Course 
    delete course1;
    delete course2;
    delete course3;
    delete course4;
    delete course5;


    //Deleting objects of type Student 
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;

    //Deleting objects of type CourseRegistration 
    delete c1;
    delete c2;
    delete c3;
    delete c4;
    delete c5;

    //Deleting object of type dataManager 
    delete conU;

    return 0;
}
