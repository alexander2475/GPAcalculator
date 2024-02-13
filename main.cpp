
#include <iostream>
#include <fstream>
#include <sstream>
#include "readFile.h"
#include "Course.h"
#include <string>
#include <vector>

int main(int argc, char* argv[])
{  
    readFile reader;
    if (argc != 2) {
        std::cerr << "Error: a filename argument must be given\n";
        return -1;
    }
    std::string filename = argv[1];
    reader.read(filename);
    return 0;
}