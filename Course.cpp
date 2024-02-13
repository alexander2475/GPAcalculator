
#include "Course.h"
#include <iostream>
#include <fstream>
#include <sstream>

Course::Course(std::string term, std::string coursePrefix, std::string courseNumber, float credits, std::string grade)
{
    this->term = term;
    this->coursePrefix = coursePrefix;
    this->courseNumber = courseNumber;
    this->credits = credits;
    this->grade = grade;
}

void Course::coursePrint()
{
    std::cout << term << " | " << coursePrefix << " | " << courseNumber << " | " << credits << " | " << grade << "\n";
}

//showing slighly incorrect GPA. 
float Course::overallGPA(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0.0;
    }

    float GPA = 0.0;
    float creditHrs = 0.0;
    float counter = 0.0;
    for (Course* course : courses)
    {
        if (course->getGrade() == "A" || course->getGrade() == "B" || course->getGrade() ==  "C" || course->getGrade() == "F"){
            creditHrs += course->credits;
            counter++;
        }
    }

    GPA = creditHrs / counter;
    return GPA;
}

//showing slighly incorrect GPA. 
float Course::csGPA(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0.0f;
    }

    std::string target = "C-S";
    std::string cont = "";
    int counter = 0;
    float creditHrs = 0;
    float csCounter = 0.0;
    float GPA = 0.0;

    std::vector<Course *> compSCI;

    for (Course* course : courses)
    {
        counter++;
        if (course->coursePrefix == target)
        {
            compSCI.push_back(course);
        }
    }

    int testCounter = 0;


    for (Course* course : compSCI)
    {
        if (course->getGrade() == "A" || course->getGrade() == "B" || course->getGrade() == "C" || course->getGrade() ==  "F"){
            creditHrs += course->credits;
        }
        csCounter++;
    }

    for (Course* course : compSCI){
        if (course->getGrade() == "W"){
            csCounter--;
        }
    }

    GPA = creditHrs / csCounter;
    return GPA;
}

int Course::courseCount(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0;
    }

    int counter = 0;

    for (Course* course : courses)
    {
        counter++;
    }

    return counter;
}

int Course::coursesIP(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0;
    }

    std::string inProgress = "IP";
    std::string currentGrade = "";
    int counter = 0;

    for (Course* course : courses)
    {
        currentGrade = course->getGrade();
        if (currentGrade == inProgress)
        {
            counter++;
        }
    }

    return counter;
}

int Course::coursesNC(std::vector<Course*> courses) {
    if (courses.empty()) {
        return 0;
    }

    int counter = 0;

    for (Course* course : courses) {
        std::string currentGrade = course->getGrade();
        if (currentGrade == "F" || currentGrade == "NP" || currentGrade == "U" || currentGrade == "W") {
            counter++;
        }
    }

    return counter;
}

int Course::coursesRC(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0;
    }

    int counter = 0;

    // write code that checks if every course has a a, b or c grade.
    for (Course* course : courses)
    {
        std::string gradeRC = course->getGrade();

        if (gradeRC == "A" || gradeRC == "B" || gradeRC == "C")
        {
            counter++;
        }
    }

    return counter;
}

std::string Course::getGrade()
{

    if (grade == "IP")
    {
        return grade;
    }
    else if (grade.length() > 1)
    {
        grade.erase(grade.length() - 1);
    }

    return grade;
}

int Course::creditHE(std::vector<Course *> courses)
{
    if (courses.empty())
    {
        return 0;
    }

    int CHE = 0;

    for (Course* course : courses)
    {
        if (course->getGrade() == "A" || course->getGrade() == "B" || course->getGrade() == "C"){
            CHE += course->credits;
        }
    }
    return CHE;
}

void Course::printAll(std::vector<Course *> courses)
{
    std::cout << "Total number of courses: " << courseCount(courses) << std::endl;
    std::cout << "Courses receiving credit: " << coursesRC(courses) << std::endl;
    std::cout << "Courses in progress: " << coursesIP(courses) << std::endl;
    std::cout << "Courses not receiving credit: " << coursesNC(courses) << std::endl;
    std::cout << "Total GPA credit hours earned: " << std::fixed << std::setprecision(2) << creditHE(courses) << std::endl;
    std::cout << "Overall GPA: " << std::fixed << std::setprecision(2) << overallGPA(courses) << std::endl;
    std::cout << "CS GPA: " << std::fixed << std::setprecision(2) << csGPA(courses) << std::endl;
}