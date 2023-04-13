#include "pch.h"
#include "Function.h"
#include "Interface.h"

void ErrorHandler() {
	cout << endl << "tests passed" << endl;
}
void Program(); //главная программа

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//пересенные, хранящие выбор пользователя
	int startSettings = 0;

	DrawGeetings(); //Название проги и имя создателя

	while (true) {
		DrawStartMenu(); 
		startSettings = Enter(">> ", [](int num) {return IsInBetween(num, 0, 3); });
		DrawBorder();

		//начало
		switch (startSettings) {
		case(runProgram): Program(); break;                 //запускает главную программу                        
		case(runTests): ErrorHandler(); break;				//запускает модульный тесты
		case(closeProgram): return EXIT_SUCCESS; break;		//выходит из програмы
		default: cout << "Unexpected behavior" << endl; continue;
		}
	}
}

void Program() {
	//пересенные, хранящие выбор пользователя
	int modSetting = 0;
	int inputSetting = 0;
	//int actionSetting = 0;
	//int outputSetting = 0;
	//int exitSetting = 0;

	//флаги
	bool flagWriteIfConsole = false;

	//контейнеры 
	vector<string> inStr;
	vector<string> outStr;

	//ключевое слово
	string keyWord = "";

	system("cls");

	while (true) {
		DrawModMenu();
		modSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });

		DrawInputMenu();
		inputSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });
		DrawBorder();

		////ввод
		//switch (inputSetting) {
		//case(inputFromFile): InputFromFile(inStr, keyWord); break;									 //ввод из файла                        
		//case(inputFromConsole): InputFromConsole(inStr, keyWord); flagWriteIfConsole = true; break;  //ввод из консоли	
		//default: cout << "Unexpected behavior" << endl; continue;
		//}

		//if (flagWriteIfConsole) {
		//	cout << endl << "write after console input" << endl;
		//	flagWriteIfConsole = false;
		//}



	}
}

/*
vector<string> str1 = { "я", "оба", "куски", "бабаки" };
	vector<string> str2 = { "я", "оба", "куски", "бабаки" };

	string tmp1 = "Собаки";
	string tmp2 = "об";

	print(stringReplaceOccurrences(str1, tmp1));
*/