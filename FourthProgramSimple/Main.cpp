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

	//����������, �������� ����� ������������
	/*int inputSetting = 0;
	int actionSetting = 0;
	int outputSetting = 0;
	int exitSetting = 0;*/

	cout << "������� 4 ������� 6 ������� ����������� ����� ������������ �� 423 ������" << endl << endl;
	cout << "����� � ������ ��� ������������� ��������� ������� �������� ������������� ��������" << endl
		<< "(��������, ������� ���� ��������). �������� ��� ��������� ��������� ����� �������" << endl
		<< "����������� ���������� : {������ ������� ������� ������������ ������, ����� �������}." << endl
		<< "����� ������� ���������, ��� � ������ ��� ���������� ��������, ������� ����� ��������" << endl
		<< "�������������� ��� ����������� ���������.������������� ����� �������������� ������������� ������." << endl
		<< "������ : ����� ��������� ������ ������ ���� ������� �� ����� ���������{ 3, 2 }���� ��� �������," << endl
		<< "��� ��������������� ���������, ������� � ������ � ��� �������." << endl;

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
vector<string> str1 = { "�", "���", "�����", "������" };
	vector<string> str2 = { "�", "���", "�����", "������" };

	string tmp1 = "������";
	string tmp2 = "��";

	print(stringReplaceOccurrences(str1, tmp1));
*/