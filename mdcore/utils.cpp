#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include"errorLogger.h"
#include"utils.h"

const int C_STRING_SIZE = 1025;

int makeNewString( char list[][C_STRING_SIZE], int startAt, char ret[] )
{
    if (startAt > C_STRING_SIZE || startAt < 0){
        printError( R"(utils)", 11, -1, R"(Invalid startAt location.)" );
        return -1;
    }
    for (int i = startAt; i < C_STRING_SIZE; i++){
        
    }
}