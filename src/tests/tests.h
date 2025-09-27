#pragma once

#include "../soup/soup-strings.h"

#define SUCCESS true
#define FAILURE false

void LogTestFailure(char* test_name, char* expect, char* actual);
bool Test_RemoveSubString();
