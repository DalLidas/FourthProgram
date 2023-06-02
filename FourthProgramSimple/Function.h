#pragma once

#include "pch.h"

void RemoveCharsFromString(string& str, const char* charsToRemove);

vector<string> SubGenerator(const string& str);

string IndexBuilder(int index, int subLength);

string StringReplace(const string& source, const string& toReplace, const string& replaceWith);

vector<string> Incoder(vector<string> str, const string& keyWord);

vector<string> Decoder(vector<string> str, const string& keyWord);

bool IndexIncludesChecker(vector<string> inStr, const string& keyWord);