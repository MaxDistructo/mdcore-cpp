#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>

void printError( const char errorLocation[], int lineNum, int errorCode,
                 const char errorMessage[] );

#endif


