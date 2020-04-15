#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include"errorLogger.h"

void printError( char errorLocation[], int lineNum, int errorCode,
                 char errorMessage[] )
{
    std::cout << "Internal Error in mdcore: " << std::endl;
    std::cout << "\t at " << errorLocation << " line # " << lineNum 
              << std::endl;
    std::cout << "\t" << errorMessage;
}
