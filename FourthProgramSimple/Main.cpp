#include "pch.h"
#include "Interface.h"

void ErrorHandler() {
	cout << endl << "tests passed" << endl;
}
void Program(); //главная программа

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//переменные, хранящие выбор пользователя
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
		default: ErrorMsg(); break;
		}
	}
	
}

void Program() {
	//переменные, хранящие выбор пользователя
	int modSetting = 0;
	int inputSetting = 0;
	int endSetting = 0;

	//флаги
	bool flagBackToStart = false;
	//bool flagTextIncludeIndex = false;

	//контейнеры 
	vector<string> inStr;
	vector<string> outStr;

	//ключевое слово
	string keyWord = "";

	while (true) {
		system("cls");
		if (flagBackToStart) break;

		DrawModMenu();
		modSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });

		DrawInputMenu();
		inputSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 2); });
		DrawBorder();

		//ввод
		switch (inputSetting) {
		case(inputFromFile): InputFromFile(inStr, keyWord, modSetting); break;		  //ввод из файла                        
		case(inputFromConsole): InputFromConsole(inStr, keyWord, modSetting); break;  //ввод из консоли	
		default: ErrorMsg(); continue;
		}
		
		if (inputSetting == inputFromConsole) {
			if (Enter("\nЗаписать записанный текс в файл? (Да \"1\" или Нет \"2\")\n>> ", 
				[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToFile(outStr, keyWord);
			}
		}
		else if (inputSetting == inputFromConsole) {
			DrawBorder();
			if (Enter("\nПоказать текст? (Да \"1\" или Нет \"2\")\n>> ",
				[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
				WriteToConsole(outStr, keyWord);
			}
		}

		//действие
		switch (modSetting) {
		case(incoding): Incode(inStr, outStr, keyWord); break;  //ввод из файла                        
		case(decoding): Decode(inStr, outStr, keyWord); break;  //ввод из консоли	
		default: ErrorMsg(); continue;
		}

		DrawBorder();
		if (Enter("\nПоказать результат? (Да \"1\" или Нет \"2\")\n>> ", 
			[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToConsole(outStr, keyWord);
			cout << endl;
		}

		DrawBorder();
		if (Enter("\nЗаписать результат в файл? (Да \"1\" или Нет \"2\")\n>> ", 
			[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
			WriteToFile(outStr, keyWord);
		}

		DrawEndMenu();
		endSetting = Enter(">> ", [](int num) {return IsInBetween(num, 0, 5); });
		DrawBorder();

		//выход
		switch (endSetting) {
		case(restart): outStr.clear(); inStr.clear(); continue; break;					//перезапуск программы                        
		case(back): outStr.clear(); inStr.clear(); flagBackToStart = true; break;		//вернуться в стартовое меню	
		case(close): exit(EXIT_SUCCESS); break;         //полное выход из программы	
		default: ErrorMsg(); continue;
		}
	}
}