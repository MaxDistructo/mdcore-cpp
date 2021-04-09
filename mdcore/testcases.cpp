#include "../lib/catch.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"

#ifdef _WIN32
#include <stdlib.h>
#include <stdio.h>
#endif

using namespace std;

TEST_CASE("utils")
{
    SECTION("openFile")
    {
        std::ofstream file;
        std::string filePath;
        std::ifstream file2;
        std::string contents;

        #ifdef _WIN32
            filePath = getenv( "TEMP" );
            filePath += "\\test.json";
        #else
            filePath = "/dev/shm/test.json";
        #endif
        contents = "test";

        file.open(filePath);
               
        if(file.is_open())
        {
            file << contents << endl;
            file.close();
        }
        
        ostringstream stream;
        openFile(filePath, file2);
        //file2 >> stream;
        REQUIRE(stream.str() == contents);

    };
}