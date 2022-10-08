#include "LectureTime.h"
#include <iostream>
#include <string>
using namespace std;

LectureTime::LectureTime() {
	firstday = "";
	secondday = "";
	time = 0;
}
LectureTime::LectureTime(std::string fday, std::string sday, int t) {
	firstday = fday;
	secondday = sday;
	time = t;
}
LectureTime::LectureTime(const LectureTime& other) {
	this->firstday = other.firstday;
	this->secondday = other.secondday;
	this->time = other.time;
}
void LectureTime::setfday(std::string fday) {
	firstday = fday;
}
void LectureTime::setsday(std::string sday) {
	secondday = sday;
}
void LectureTime::settime(int t) {
	time = t;
}
void LectureTime::printlecttime() {
	cout << "First day: " << this->getfday() << " Second day: " << this->getsday() << " Time: " << this->gettime() << endl;
}
std::string LectureTime::getfday() {
	return firstday;
}
void LectureTime:: operator= (const LectureTime& other) {
	if (this != &other) {
		this->firstday = other.firstday;
		this->secondday = other.secondday;
		this->time = other.time;
	}
}
std::string LectureTime::getsday() {
	return secondday;
}
int LectureTime::gettime() {
	return time;
}
LectureTime::~LectureTime() {
	std::cout << "Object of type LectureTime was deleted \n" << std::endl;
}
