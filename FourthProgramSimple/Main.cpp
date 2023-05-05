#include "pch.h"
#include "Interface.h"
#include "Test.h"

void Program(); //главная программа

int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//переменные, хранящие выбор пользователя
	int startSettings = 0;

	//флаги
	bool ErrorExist = true;

	DrawGeetings(); //Название проги и имя создателя

	while (true) {
		DrawStartMenu(); 
		startSettings = Enter(">> ", [](int num) {return IsInBetween(num, 0, 3); });
		DrawBorder();
		cout << endl;

		//начало
		switch (startSettings) {
		case(runProgram): Program(); break;                  //запускает главную программу                        
		case(runTests): ErrorExist = ErrorHandler(); break;	 //запускает модульный тесты
		case(closeProgram): return EXIT_SUCCESS; break;		 //полное выход из программы	
		default: ErrorMsg(); break;
		}

		if (!ErrorExist) {
			cout << "Все тесты пройдены успешно" << endl;
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
	bool flagInput = true;

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

		if (flagInput) {
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
					WriteToFile(inStr, keyWord);
				}
			}
			else if (inputSetting == inputFromFile) {
				DrawBorder();
				if (Enter("\nПоказать текст? (Да \"1\" или Нет \"2\")\n>> ",
					[](int num) {return IsInBetween(num, 0, 2); }) == 1) {
					WriteToConsole(inStr, keyWord);
				}
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
		case(restart): outStr.clear(); inStr.clear(); flagInput = true; continue; break;       //перезапуск программы                        
		case(useIn): outStr.clear(); flagInput = false; continue; break;					   //перезапуск программы со старым значение                       
		case(useOut): inStr = outStr;  outStr.clear(); flagInput = false; continue; break;     //перезапуск программы с результатом                       
		case(back): outStr.clear(); inStr.clear(); flagBackToStart = true; break;		       //вернуться в стартовое меню	
		case(close): exit(EXIT_SUCCESS); break;                                                //полное выход из программы	
		default: ErrorMsg(); continue;
		}
	}
}