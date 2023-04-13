#include "Function.h"

void removeCharsFromString(string& str, const char* charsToRemove) {
	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
		str.erase(remove(str.begin(), str.end(), charsToRemove[i]), str.end());
	}
}

vector<string> SubGenerator(const string& str) {
	vector<string> arr;
	for (int subSize = str.size(); subSize > 1; --subSize) {
		for (int subStart = 0; subStart < str.size() - subSize + 1; ++subStart) {
			arr.push_back(str.substr(subStart, subSize));
		}
	}
	return arr;
}

string IndexBuilder(int index, int subLength) {
	int step = 1;
	while (index - step > 0) {
		index -= step;
		++step;
		--subLength;
	}

	return "{" + to_string(index) + "," + to_string(subLength) + "}";
}

string stringReplace(const string& source, const string& toReplace, const string& replaceWith) {
	size_t pos = 0;
	size_t cursor = 0;
	int repLen = toReplace.length();
	stringstream builder;

	do {
		pos = source.find(toReplace, cursor);

		if (string::npos != pos) {
			//copy up to the match, then append the replacement
			builder << source.substr(cursor, pos - cursor);
			builder << replaceWith;

			// skip past the match 
			cursor = pos + repLen;
		}
	} while (string::npos != pos);

	//copy the remainder
	builder << source.substr(cursor);

	return (builder.str());
}

vector<string> stringReplaceOccurrences(vector<string>& str, const string& tmp) {
	size_t pos = 0;
	vector<string> sub;
	if (sub.empty()) sub = SubGenerator(tmp);

	for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < sub.size(); ++j) {
			str[i] = stringReplace(str[i], sub[j], IndexBuilder(j, tmp.size()));
		}
	}

	return str;
}