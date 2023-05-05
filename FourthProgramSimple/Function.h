#pragma once

#include "pch.h"

void removeCharsFromString(string& str, const char* charsToRemove);

vector<string> SubGenerator(const string& str);

template <typename T = string>
void print(const vector<T>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << endl;
	}
}

string IndexBuilder(int index, int subLength);

string stringReplace(const string& source, const string& toReplace, const string& replaceWith);

vector<string> Incoder(vector<string> str, const string& keyWord);

vector<string> Decoder(vector<string> str, const string& keyWord);

bool IndexIncludesChecker(vector<string> inStr, const string& keyWord);