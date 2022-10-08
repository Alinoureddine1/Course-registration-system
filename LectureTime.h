#pragma once
#include <string>
class LectureTime
{

public:
	LectureTime();
	LectureTime(std::string , std::string ,int  );
	LectureTime(const LectureTime &);
	void setfday(std::string);
	void setsday(std::string);
	void settime(int);
	std::string getfday();
	std::string getsday();
	int gettime();
	void printlecttime();
	void operator= (const LectureTime & temp);
	~LectureTime();
private:

	std::string firstday;
	std::string secondday;
	int time;


};

