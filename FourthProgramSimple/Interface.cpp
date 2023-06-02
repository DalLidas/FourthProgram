#include "Interface.h"

#pragma region DRAW
void DrawBorder(ostream& out) {
    out << "===================================================================================";
}

void DrawSubBorder(ostream& out) {
    out << "-----------------------------------------------------------------------------------";
}

void DrawGeetings() {
    DrawBorder();
    cout << endl << "������� 4 ������� 6 ������� ����������� ����� ������������ �� 423 ������" << endl << endl;
    cout << "����� � ������ ��� ������������� ��������� ������� �������� ������������� ��������" << endl
        << "(��������, ������� ���� ��������). �������� ��� ��������� ��������� ����� �������" << endl
        << "����������� ���������� : {������ ������� ������� ������������ ������, ����� �������}." << endl
        << "����� ������� ���������, ��� � ������ ��� ���������� ��������, ������� ����� ��������" << endl
        << "�������������� ��� ����������� ���������.������������� ����� �������������� ������������� ������." << endl
        << "������ : ����� ��������� ������ ������ ���� ������� �� ����� ���������{3,2}���� ��� �������," << endl
        << "��� ��������������� ���������, ������� � ������ � ��� �������." << endl;
}

void DrawStartMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t\t����" << endl;
    DrawSubBorder();
    cout << endl << "1. ��������� ���������" << endl
        << "2. ��������� ��������� �����" << endl
        << "3. ������� ���������" << endl;
}

void DrawModMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t���� �������" << endl;
    DrawSubBorder();
    cout << endl << "1. ������������ " << endl
        << "2. �������������" << endl;
}

void DrawInputMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t���� �����" << endl;
    DrawSubBorder();
    cout << endl << "1. ������ �� �����" << endl
        << "2. ������ �� �������" << endl;
}

void DrawEndMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t���� ������" << endl;
    DrawSubBorder();
    cout << endl << "1. ������������� ���������" << endl
        << "2. ������������� ��������� �� ������ ���������" << endl
        << "3. ������������� ��������� � �����������" << endl
        << "4. ��������� � ����" << endl
        << "5. ������� ���������" << endl;
}

void DrawInputConsoleInstruction() {
    cout << endl << "\t\t\t  ����� �� �������" << endl;
    DrawSubBorder();
    cout << endl << "\t\t������ �������� ���� ����� ����������� ��� ��������";
    cout << endl << "\t����� ��������� ����� ������, ���������� ������ � ����� ������� \"~~~\"" << endl;
    DrawSubBorder();
    cout << endl;
}

void ErrorMsg(){
    cout << "�������������� ����� ����" << endl;
}
#pragma endregion DRAW

#pragma region INPUT
string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?([cC][oO][nN]))|((/./)?([cC][oO][nN]\\.))|((/./)?([cC][oO][nN]\\.)(.*))");

    while (true) {
        cout << "Enter file path: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "You enter reserved by system file name. Try again" << endl;
    }

    return filePath.c_str();
}

void InputFromFile(vector<string>& inStr, string& keyWord, int mod) {
    string str{};
    string word{};

    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();
        ifstream inputStream(filePath.c_str());
        if (!inputStream.is_open()) {
            cout << "���� ��� ����������. ����������� ������" << endl;
            continue;
        }
        else {
            while (getline(inputStream, str)) {
                for (auto i = str.begin(); i != str.end(); ++i) {
                    if (*i == ' ') {
                        if(!word.empty()) inStr.push_back(word.c_str());

                        word.clear();
                    }
                    else {
                        word += *i;
                    }
                }

                if (!word.empty()) inStr.push_back(word);
                word.clear();

                inStr.push_back("\n");
            }

            keyWord = *inStr.cbegin();
            RemoveCharsFromString(keyWord, characterIgnorList);
            inStr.erase(inStr.cbegin());

            if (mod == 1 && IndexIncludesChecker(inStr, keyWord)) {
                DrawSubBorder();
                if (Enter("\n� ������� ������ ��� ������������ �������. ������ ����� �����? (�� \"1\" ��� ��� \"2\")\n>>",
                    [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
                    inStr.clear();
                    DrawSubBorder();
                    cout << endl;
                    continue;
                }
            }

            inputStream.close();
            break;
        }
    }
}

void InputFromConsole(vector<string>& inStr, string& keyWord, int mod) {
    string str{};
    string word{};
    string exitChar{ "~~~" };

    DrawInputConsoleInstruction();
    while (true) {
        while (getline(cin, str)) {
            if (str == exitChar) break;
            for (auto i = str.begin(); i != str.end(); ++i) {
                if (*i == ' ') {
                    if (!word.empty()) inStr.push_back(word.c_str());

                    word.clear();
                }
                else {
                    word += *i;
                }
            }

            if (!word.empty()) inStr.push_back(word);
            word.clear();

            if (!word.empty())inStr.push_back("\n");
        }

        keyWord = *inStr.cbegin();
        RemoveCharsFromString(keyWord, characterIgnorList);
        inStr.erase(inStr.cbegin());

        if (mod == 1 && IndexIncludesChecker(inStr, keyWord)) {
            DrawSubBorder();
            if (Enter("\n� ������� ������ ��� ������������ �������. ������ ����� �����? (�� \"1\" ��� ��� \"2\")\n>>",
                [](int num) {return IsInBetween(num, 0, 2); }) == 1) {
                inStr.clear();
                DrawSubBorder();
                cout << endl;
                continue;
            }
        }
        break;
    }

    DrawBorder();
    cout << endl;
}

#pragma endregion INPUT

#pragma region CODE/DECODE
void Incode(const vector<string>& inStr, vector<string>& outStr, const string& keyWord) {
    outStr = Incoder(inStr, keyWord);
}

void Decode(const vector<string>& inStr, vector<string>& outStr, const string& keyWord) {
    outStr = Decoder(inStr, keyWord);
}
#pragma endregion CODE/DECODE

#pragma region WRITE
void Write(ostream& output, const vector<string>& str) {
    for (auto word = str.begin(); word != str.end(); ++word) {
        output << " " << *word;
    }
}

void WriteToConsole(const vector<string>& str, const string& keyWord) {
    DrawBorder();
    cout << endl;

    cout << "�������� �����: \"" << keyWord << "\"" << endl << endl;
    Write(cout, str);
}

void WriteToFile(const vector<string>& str, const string& keyWord) {
    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();

        ifstream test(filePath.c_str());
        if (test.is_open()) {
            if (Enter("���� ��� ����������. �� ������������� ������ ������������ ���? (�� \"1\" ��� ��� \"2\")\n>>",
                [](int num) {return IsInBetween(num, 0, 2); }) == 2) {
                continue;
            }
        }

        ofstream outputStream(filePath.c_str());
        if (!outputStream.is_open()) {
            cout << "�� �������� ������� ����. ����������� ������" << endl;
            continue;
        }
        else {
            outputStream << keyWord << " ";
            Write(outputStream, str);
            break;
        }
    }
}
#pragma endregion WRITE