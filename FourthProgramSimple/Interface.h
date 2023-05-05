#pragma once

#include "pch.h"
#include "Function.h"

#pragma region DRAW
void DrawBorder(ostream& out = cout);
void DrawSubBorder(ostream& out = cout);
void DrawGeetings();

void DrawStartMenu();
void DrawModMenu();
void DrawInputMenu();
void DrawEndMenu();

void DrawInputConsoleInstruction();

void ErrorMsg();
#pragma endregion DRAW

#pragma region INPUT
string EnterFilePath();

template <typename type = int> 
inline bool IsInBetween(const type& num, const type& start, const type& end) {
    return start < num && num <= end;
}

template <typename type = int, typename func>
type Enter(const string& msg, func Predicat) {
    type item {};

    while (true) {
        while (true) {
            if (cout << msg && !(cin >> item)) {
                cin.clear();
                cin.ignore(INT32_MAX, '\n');
                cout << "Неправильнвый тип ввода. Попытайтесь ещё раз" << endl;
            }
            else{
                break;
            }
        }

        if (Predicat(item)) return item;
        else cout << "Неправильнвый диапозон значения. Попытайтесь ещё раз" << endl;
    }
}

template <typename type = int>
type Enter(const string& msg) {
    type item {};

    while(cout << msg && !(cin >> item)){
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout << endl << "Неправильнвый тип ввода. Попытайтесь ещё раз" << endl;
    }
    
    return item;
}

void InputFromFile(vector<string>& inStr, string& keyWord, int mod);
void InputFromConsole(vector<string>& inStr, string& keyWord, int mod);
#pragma endregion INPUT

#pragma region CODE/DECODE
void Incode(const vector<string>& inStr, vector<string>& outStr, const string& keyWord);
void Decode(const vector<string>& inStr, vector<string>& outStr, const string& keyWord);
#pragma endregion CODE/DECODE

#pragma region WRITE
void Write(ostream& output, const vector<string>& str);
void WriteToConsole(const vector<string>& str, const string& keyWord);
void WriteToFile(const vector<string>& str, const string& keyWord);
#pragma endregion WRITE