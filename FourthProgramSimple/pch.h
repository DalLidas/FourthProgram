#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>

#include <windows.h>
#include <regex>


#define characterIgnorList "/.,<>(){}?'-_=+:;"

enum startSettings { runProgram = 1, runTests, closeProgram };
enum inputSettings { inputFromFile = 1, inputFromConsole };

using namespace std;

