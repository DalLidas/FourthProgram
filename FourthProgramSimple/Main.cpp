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
		case(closeProgram): return EXIT_SUCCESS; break;		//������ ����� �� ���������	
		default: cout << "Unexpected behavior" << endl; continue;
		}
	}
}

void Program() {
	//����������, �������� ����� ������������
	int modSetting = 0;
	int inputSetting = 0;
	int endSetting = 0;

	//�����
	bool flagWriteIfConsole = false;
	bool flagBackToStart = false;

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

		//����
		switch (inputSetting) {
		case(inputFromFile): InputFromFile(inStr, keyWord); break;									 //���� �� �����                        
		case(inputFromConsole): InputFromConsole(inStr, keyWord); flagWriteIfConsole = true; break;  //���� �� �������	
		default: cout << "Unexpected behavior" << endl; continue;
		}

		if (flagWriteIfConsole) {
			if (Enter("\nDo you want show result to file? (Yes \"1\" or No \"2\")\n>> ", [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToFile(inStr);
			}
			flagWriteIfConsole = false;
		}

		//��������
		switch (modSetting) {
		case(incoding): Incode(inStr, outStr, keyWord); break;							   //���� �� �����                        
		case(decoding): Decode(inStr, outStr, keyWord); flagWriteIfConsole = true; break;  //���� �� �������	
		default: cout << "Unexpected behavior" << endl; continue;
		}

		if (Enter("\nDo you want show result to console? (Yes \"1\" or No \"2\")\n>> ", [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToConsole(outStr);
		}

		if (Enter("\nDo you want show result to file? (Yes \"1\" or No \"2\")\n>> ", [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToFile(outStr);
		}
		

		DrawEndMenu();
		endSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 3); });
		DrawBorder();

		switch (inputSetting) {
		case(restart): continue; break;					//���������� ���������                        
		case(back): flagBackToStart = true; break;		//��������� � ��������� ����	
		case(close): exit(EXIT_SUCCESS); break;         //������ ����� �� ���������	
		default: cout << "Unexpected behavior" << endl; continue;
		}

		if (flagBackToStart) break;
	}
}

/*
vector<string> str1 = { "�", "���", "�����", "������" };
	vector<string> str2 = { "�", "���", "�����", "������" };

	string tmp1 = "������";
	string tmp2 = "��";

	print(stringReplaceOccurrences(str1, tmp1));
*/