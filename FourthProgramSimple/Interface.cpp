#include "Interface.h"

string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?(con))|((/./)?(con\\.))|((/./)?(con\\.)(.*))");

    while (true) {
        cout << "������� ���� � �����: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "������ ��� �������������� ��������. ����������� ������" << endl;
    }

    return filePath.c_str();
}

void InputFromFile() {

}