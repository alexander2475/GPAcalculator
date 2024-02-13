#ifndef READFILE_H
#define READFILE_H
#include "Course.h"
#include <string>
#include <vector>

class readFile
{
public:
	std::vector<class Course*> read(std::string& filename);
};
#endif