#include "Interface.h"

#pragma region DRAW
void DrawBorder() {
    cout << "===================================================================================";
}
void DrawSubBorder() {
    cout << "-----------------------------------------------------------------------------------";
}
void DrawGeetings() {
    DrawBorder();
    cout << endl << "������� 4 ������� 6 ������� ����������� ����� ������������ �� 423 ������" << endl << endl;
    cout << "����� � ������ ��� ������������� ��������� ������� �������� ������������� ��������" << endl
        << "(��������, ������� ���� ��������). �������� ��� ��������� ��������� ����� �������" << endl
        << "����������� ���������� : {������ ������� ������� ������������ ������, ����� �������}." << endl
        << "����� ������� ���������, ��� � ������ ��� ���������� ��������, ������� ����� ��������" << endl
        << "�������������� ��� ����������� ���������.������������� ����� �������������� ������������� ������." << endl
        << "������ : ����� ��������� ������ ������ ���� ������� �� ����� ���������{ 3, 2 }���� ��� �������," << endl
        << "��� ��������������� ���������, ������� � ������ � ��� �������." << endl;
}
void DrawStartMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t\tMENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Run program" << endl
        << "2. Run module texts" << endl
        << "3. Close program" << endl;
}
void DrawModMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tMOD MENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Incode " << endl
        << "2. Decode" << endl;
}
void DrawInputMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tInput MENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Input from file" << endl
        << "2. Input from console" << endl;
}
#pragma endregion DRAW

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