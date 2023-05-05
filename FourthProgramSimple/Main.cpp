#include "pch.h"
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
		default: ErrorMsg(); break;
		}
	}
	
}

void Program() {
	//����������, �������� ����� ������������
	int modSetting = 0;
	int inputSetting = 0;
	int endSetting = 0;

	//�����
	bool flagBackToStart = false;
	//bool flagTextIncludeIndex = false;

	//���������� 
	vector<string> inStr;
	vector<string> outStr;

	//�������� �����
	string keyWord = "";

	while (true) {
		system("cls");
		if (flagBackToStart) break;

		DrawModMenu();
		modSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });

		DrawInputMenu();
		inputSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });
		DrawBorder();

		//����
		switch (inputSetting) {
		case(inputFromFile): InputFromFile(inStr, keyWord, modSetting); break;		  //���� �� �����                        
		case(inputFromConsole): InputFromConsole(inStr, keyWord, modSetting); break;  //���� �� �������	
		default: ErrorMsg(); continue;
		}
		
		if (inputSetting == inputFromConsole) {
			if (Enter("\n�������� ���������� ���� � ����? (�� \"1\" ��� ��� \"2\")\n>> ", 
				[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToFile(outStr, keyWord);
			}
		}
		else if (inputSetting == inputFromConsole) {
			DrawBorder();
			if (Enter("\n�������� �����? (�� \"1\" ��� ��� \"2\")\n>> ",
				[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToConsole(outStr, keyWord);
			}
		}

		//��������
		switch (modSetting) {
		case(incoding): Incode(inStr, outStr, keyWord); break;  //���� �� �����                        
		case(decoding): Decode(inStr, outStr, keyWord); break;  //���� �� �������	
		default: ErrorMsg(); continue;
		}

		DrawBorder();
		if (Enter("\n�������� ���������? (�� \"1\" ��� ��� \"2\")\n>> ", 
			[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToConsole(outStr, keyWord);
			cout << endl;
		}

		DrawBorder();
		if (Enter("\n�������� ��������� � ����? (�� \"1\" ��� ��� \"2\")\n>> ", 
			[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToFile(outStr, keyWord);
		}

		DrawEndMenu();
		endSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 5); });
		DrawBorder();

		//�����
		switch (endSetting) {
		case(restart): outStr.clear(); inStr.clear(); continue; break;					//���������� ���������                        
		case(back): outStr.clear(); inStr.clear(); flagBackToStart = true; break;		//��������� � ��������� ����	
		case(close): exit(EXIT_SUCCESS); break;         //������ ����� �� ���������	
		default: ErrorMsg(); continue;
		}
	}
}