#include "Course.h"
#include "LectureTime.h"
#include <iostream>
#include <string>
using namespace std;

Course::Course() {
	this->courseName = "";
	this->courseNumber = "";
	this->numbcredits = 0;
	
}
Course::Course(std::string cname, std::string cnumb, const LectureTime& that, int credits) {
	this->courseName = cname;
	this->courseNumber = cnumb;
	this->numbcredits =credits;
	this->lecturetime =that;
}
Course::Course(const Course& that) {
	this->courseName = that.courseName;
	this->courseNumber = that.courseNumber;
	this->numbcredits = that.numbcredits;
	this->lecturetime = that.lecturetime;
}
void Course::setcnumber(std::string cnumb) {
	this->courseNumber = cnumb;
}
void Course::setcname(std::string cname) {
	this->courseName = cname;
}
void Course::setlectime(const LectureTime& that) {
	this->lecturetime = LectureTime(that);
}
void Course::setcredits(int cred) {
	this->numbcredits = cred;
}
std::string Course::getcourseNumber() {
	return this->courseNumber;
}
std::string Course::getcourseName() {
	return this->courseName;
}
int Course::gettime() {
	return this->lecturetime.gettime();
}
bool Course::overlap( Course& that) {

	if (this->courseName == that.courseName) { return true; };
	if (this->lecturetime.getfday() == that.lecturetime.getfday() || this->lecturetime.getfday() == that.lecturetime.getsday() || this->lecturetime.getsday() == that.lecturetime.getfday() || this->lecturetime.getsday() == that.lecturetime.getsday()) {
		if (that.lecturetime.gettime() < this->lecturetime.gettime()|| that.lecturetime.gettime()>  this->lecturetime.gettime()+50){
			return false;
		}
		else { return true; }
	}
	return true;
}
LectureTime Course::getlectime() {
	return this->lecturetime;
}
int Course::getcedits() {
	return this->numbcredits;
}
Course::~Course() {
	std::cout << "Object of type Course was deleted \n" << std::endl;
}