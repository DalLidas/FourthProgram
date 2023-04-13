#include "Interface.h"

string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?(con))|((/./)?(con\\.))|((/./)?(con\\.)(.*))");

    while (true) {
        cout << "Введите путь к файлу: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "Данное имя зарезерировано системой. Попытайтесь заново" << endl;
    }

    return filePath.c_str();
}

void InputFromFile() {

}