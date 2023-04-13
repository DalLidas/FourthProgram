#include "pch.h"
#include "Function.h"
#include "Interface.h"

enum inputSettings { inputFromFile = 1, inputFromConsole };

bool i(string str) {
	return str == "std";
}


int main(){
	//setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	//пересенные, хран€щие выбор пользовател€
	/*int inputSetting = 0;
	int actionSetting = 0;
	int outputSetting = 0;
	int exitSetting = 0;*/

	cout << "«адание 4 вариант 6 сделано ћухаметовым ƒанил »льнуровичем из 423 группы" << endl << endl;
	cout << "Ќайти в тексте все повтор€ющиес€ подстроки длиннее заданной пользователем величины" << endl
		<< "(например, длиннее п€ти символов). «аменить все вхождени€ подстроки кроме первого" << endl
		<< "специальной сигнатурой : {индекс первого символа оригинальной строки, длина цепочки}." << endl
		<< "ѕеред заменой убедитьс€, что в тексте нет комбинаций символов, которые могут ошибочно" << endl
		<< "восприниматьс€ как формируема€ сигнатура.ѕредусмотреть режим восстановлени€ оригинального текста." << endl
		<< "ѕример : текст Ђтестова€ строкаї должен быть заменен на текст Ђтестова€{ 3, 2 }рокаї при условии," << endl
		<< "что рассматриваютс€ подстроки, начина€ с длинны в два символа." << endl;

	while (true) {
		int s = Enter(">> ", [](int num){return IsInBetween(num, 0, 2); });
		cout << s << endl;

		double ss = Enter<double>(">> ", [](double num) {return IsInBetween<double>(num, 0, 2); });
		cout << ss << endl;

		string sss = Enter<string>(">> ", i);
		cout << sss << endl;

		string ssss = Enter<string>(">> ", [](string str) {return str == "std"; });
		cout << ssss << endl;

		return 0;
	}
}



/*
vector<string> str1 = { "€", "оба", "куски", "бабаки" };
	vector<string> str2 = { "€", "оба", "куски", "бабаки" };

	string tmp1 = "—обаки";
	string tmp2 = "об";

	print(stringReplaceOccurrences(str1, tmp1));
*/