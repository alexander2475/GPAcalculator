
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include "readFile.h"

class Course
{
public:
    Course();
    Course(std::string term, std::string coursePrefix, std::string courseNumber, float credits, std::string grade);
    void coursePrint();
    float overallGPA(std::vector<Course*>);
    float csGPA(std::vector<Course*>);
    int courseCount(std::vector<Course*>);
    int coursesIP(std::vector<Course*>);
    int coursesNC(std::vector<Course*> courses);
    int coursesRC(std::vector<Course*> courses);
    int creditHE(std::vector<Course*> courses);
    std::string getGrade();
    void printAll(std::vector<Course*> courses);

private:
    std::string term, coursePrefix, courseNumber, grade;
    float credits;
};
#endif //Course