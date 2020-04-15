#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>
#include"errorLogger.h"
#include"utils.h"

const int C_STRING_SIZE = 1025;

/**
* Function Added for Cross Compatibility between other core libs.
* Allows for easier porting of my own code. TODO: Implement Function
*/

int makeNewString( char list[][C_STRING_SIZE], int startAt, char ret[] )
{
    if (startAt > C_STRING_SIZE || startAt < 0){
        printError( R"(utils)", 11, -1, R"(Invalid startAt location.)" );
        return -1;
    }
    printError( R"(utils)", 16, 0, R"(Unimplemented Function)" );
    return 0;
}

/**
*   Converts the input to a Long value.
*   @param str The cstring to convert to long
*   @return The long value of the input or null if it is unable to be converted
*/
long convertToLong( char str[] )
{
    return atol( str );
}

/**
*   Converts the input to an Int value.
*   @param str The cstring to convert to long
*   @return The long value of the input or null if it is unable to be converted
*/
int convertToInt( char str[] )
{
    return atoi( str );
}

/**
* Function Added for Cross Compatibility between other core libs.
* Allows for easier porting of my own code. TODO: Implement Function
*/

int makeNewLineString( char list[][C_STRING_SIZE], int startAt, char ret[] )
{
    if (startAt > C_STRING_SIZE || startAt < 0){
        printError( R"(utils)", 53, -1, R"(Invalid startAt location.)" );
        return -1;
    }
    printError( R"(utils)", 56, 0, R"(Unimplemented Function)" );
    return 0;
}