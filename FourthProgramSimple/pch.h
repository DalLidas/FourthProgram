#pragma once

#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <string>

#include <windows.h>
#include <regex>

//знаки которые отсекаются от ключевого слова
#define characterIgnorList "/.,<>(){}?'-_=+:;" 

enum startSettings { runProgram = 1, runTests, closeProgram };
enum inputSettings { inputFromFile = 1, inputFromConsole };
enum modSettings { incoding = 1, decoding };
enum endSettings { restart = 1, back, closeProgram};


using namespace std;

