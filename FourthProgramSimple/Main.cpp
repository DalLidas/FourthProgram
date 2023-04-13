#include "pch.h"
#include "Function.h"
#include "Interface.h"

void ErrorHandler() {
	cout << endl << "tests passed" << endl;
}
void Program(); //������� ���������

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//����������, �������� ����� ������������
	int startSettings = 0;

	DrawGeetings(); //�������� ����� � ��� ���������

	while (true) {
		DrawStartMenu(); 
		startSettings = Enter(">> ", [](int num) {return IsInBetween(num, 0, 3); });
		DrawBorder();

		//������
		switch (startSettings) {
		case(runProgram): Program(); break;                 //��������� ������� ���������                        
		case(runTests): ErrorHandler(); break;				//��������� ��������� �����
		case(closeProgram): return EXIT_SUCCESS; break;		//������� �� ��������
		default: cout << "Unexpected behavior" << endl; continue;
		}
	}
}

void Program() {
	//����������, �������� ����� ������������
	int modSetting = 0;
	int inputSetting = 0;
	//int actionSetting = 0;
	//int outputSetting = 0;
	//int exitSetting = 0;

	//�����
	bool flagWriteIfConsole = false;

	//���������� 
	vector<string> inStr;
	vector<string> outStr;

	//�������� �����
	string keyWord = "";

	system("cls");

	while (true) {
		DrawModMenu();
		modSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });

		DrawInputMenu();
		inputSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });
		DrawBorder();

		////����
		//switch (inputSetting) {
		//case(inputFromFile): InputFromFile(inStr, keyWord); break;									 //���� �� �����                        
		//case(inputFromConsole): InputFromConsole(inStr, keyWord); flagWriteIfConsole = true; break;  //���� �� �������	
		//default: cout << "Unexpected behavior" << endl; continue;
		//}

		//if (flagWriteIfConsole) {
		//	cout << endl << "write after console input" << endl;
		//	flagWriteIfConsole = false;
		//}



	}
}

/*
vector<string> str1 = { "�", "���", "�����", "������" };
	vector<string> str2 = { "�", "���", "�����", "������" };

	string tmp1 = "������";
	string tmp2 = "��";

	print(stringReplaceOccurrences(str1, tmp1));
*/