#pragma once

#include "pch.h"

#pragma region DRAW
void DrawBorder();
void DrawSubBorder();
void DrawGeetings();

void DrawStartMenu();
void DrawModMenu();
void DrawInputMenu();
#pragma endregion DRAW

string EnterFilePath();

template <typename type = int> 
inline bool IsInBetween(const type& num, const type& start, const type& end) {
    return start < num && num <= end;
}

template <typename type = int, typename func>
type Enter(string msg, func Predicat) {
    type item;

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
type Enter(string msg) {
    type item;

    while(cout << msg && !(cin >> item)){
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cout << "Неправильнвый тип ввода. Попытайтесь ещё раз" << endl;
    }
    
    return item;
}