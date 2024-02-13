
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Course.h"
#include "readFile.h"

std::vector<Course*> readFile::read(std::string& filename) {
    Course* course;
    std::vector<Course*> courses;
    std::ifstream inFile(filename);
    std::string line;

    if (!inFile) {
        std::cerr << "Error: file " << filename << " cannot be opened\n";
        return courses;
    }

    while (std::getline(inFile, line)) {
        if (line.length() < 2)
            continue;
        std::istringstream lineStream(line);
        std::string term, coursePrefix, courseNumber, grade;
        float credits;
        lineStream >> term >> coursePrefix >> courseNumber >> credits >> grade;
        course = new Course(term, coursePrefix, courseNumber, credits, grade);
        courses.push_back(course);
    }

    course->printAll(courses);

    inFile.close();
    return courses;
}