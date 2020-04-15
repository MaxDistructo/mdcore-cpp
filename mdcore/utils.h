#pragma once

#ifndef MDCORE_UTILS_H
#define MDCORE_UTILS_H

const int C_STRING_SIZE = 1025;

int makeNewString( char list[][C_STRING_SIZE], int startAt, char ret[] );
long convertToLong( char str[] );
int convertToInt( char str[] );
int makeNewLineString( char list[][C_STRING_SIZE], int startAt, char ret[] );

#endif
