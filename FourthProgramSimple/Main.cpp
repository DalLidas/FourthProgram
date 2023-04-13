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
		case(closeProgram): return EXIT_SUCCESS; break;		//полное выход из программы	
		default: cout << "Unexpected behavior" << endl; continue;
		}
	}
}

void Program() {
	//пересенные, хранящие выбор пользователя
	int modSetting = 0;
	int inputSetting = 0;
	int endSetting = 0;

	//флаги
	bool flagWriteIfConsole = false;
	bool flagBackToStart = false;

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

		//ввод
		switch (inputSetting) {
		case(inputFromFile): InputFromFile(inStr, keyWord); break;									 //ввод из файла                        
		case(inputFromConsole): InputFromConsole(inStr, keyWord); flagWriteIfConsole = true; break;  //ввод из консоли	
		default: cout << "Unexpected behavior" << endl; continue;
		}

		if (flagWriteIfConsole) {
			if (Enter("\nDo you want show result to file? (Yes \"1\" or No \"2\")\n>> ", [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToFile(inStr);
			}
			flagWriteIfConsole = false;
		}

		//действие
		switch (modSetting) {
		case(incoding): Incode(inStr, outStr, keyWord); break;							   //ввод из файла                        
		case(decoding): Decode(inStr, outStr, keyWord); flagWriteIfConsole = true; break;  //ввод из консоли	
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
		case(restart): continue; break;					//перезапуск программы                        
		case(back): flagBackToStart = true; break;		//вернуться в ытортовое меню	
		case(close): exit(EXIT_SUCCESS); break;         //полное выход из программы	
		default: cout << "Unexpected behavior" << endl; continue;
		}

		if (flagBackToStart) break;
	}
}

/*
vector<string> str1 = { "я", "оба", "куски", "бабаки" };
	vector<string> str2 = { "я", "оба", "куски", "бабаки" };

	string tmp1 = "Собаки";
	string tmp2 = "об";

	print(stringReplaceOccurrences(str1, tmp1));
*/