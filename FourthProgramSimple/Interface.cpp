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
    cout << endl << "Задание 4 вариант 6 сделано Мухаметовым Данил Ильнуровичем из 423 группы" << endl << endl;
    cout << "Найти в тексте все повторяющиеся подстроки длиннее заданной пользователем величины" << endl
        << "(например, длиннее пяти символов). Заменить все вхождения подстроки кроме первого" << endl
        << "специальной сигнатурой : {индекс первого символа оригинальной строки, длина цепочки}." << endl
        << "Перед заменой убедиться, что в тексте нет комбинаций символов, которые могут ошибочно" << endl
        << "восприниматься как формируемая сигнатура.Предусмотреть режим восстановления оригинального текста." << endl
        << "Пример : текст «тестовая строка» должен быть заменен на текст «тестовая{3,2}рока» при условии," << endl
        << "что рассматриваются подстроки, начиная с длинны в два символа." << endl;
}

void DrawStartMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t\tМЕНЮ" << endl;
    DrawSubBorder();
    cout << endl << "1. Запустить программу" << endl
        << "2. Запустить модульные тесты" << endl
        << "3. Закрыть программу" << endl;
}

void DrawModMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tМЕНЮ ФУНКЦИЙ" << endl;
    DrawSubBorder();
    cout << endl << "1. Закодировать " << endl
        << "2. Разкодировать" << endl;
}

void DrawInputMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tМЕНЮ ВВОДА" << endl;
    DrawSubBorder();
    cout << endl << "1. Ввести из файла" << endl
        << "2. Ввести из консоли" << endl;
}

void DrawEndMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tМЕНЮ ВЫХОДА" << endl;
    DrawSubBorder();
    cout << endl << "1. Перезапустить программу" << endl
        << "2. Перезапустить программу со старым значением" << endl
        << "3. Перезапустить программу с результатом" << endl
        << "4. Вернуться в меню" << endl
        << "5. Закрыть программу" << endl;
}

void DrawInputConsoleInstruction() {
    cout << endl << "\t\t\t  ВЫХОД ИЗ КОНСОЛИ" << endl;
    DrawSubBorder();
    cout << endl << "\t\tПервое введённое вами слово воспримится как ключевое";
    cout << endl << "\tЧтобы закончить ввода текста, необходима ввести в новой строчке \"~~~\"" << endl;
    DrawSubBorder();
    cout << endl;
}

void ErrorMsg(){
    cout << "Непредвиденный пункт меню" << endl;
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
            cout << "Файл уже существует. Попытайтесь заного" << endl;
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
                if (Enter("\nВ ведённом тексте уже присутствуют индексы. Ввести новый текст? (Да \"1\" или Нет \"2\")\n>>",
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
            if (Enter("\nВ ведённом тексте уже присутствуют индексы. Ввести новый текст? (Да \"1\" или Нет \"2\")\n>>",
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

    cout << "Ключевое слово: \"" << keyWord << "\"" << endl << endl;
    Write(cout, str);
}

void WriteToFile(const vector<string>& str, const string& keyWord) {
    while (true) {
        string filePath = " ";
        filePath = EnterFilePath();

        ifstream test(filePath.c_str());
        if (test.is_open()) {
            if (Enter("Файл уже существует. Вы действительно хотете перезаписать его? (Да \"1\" или Нет \"2\")\n>>",
                [](int num) {return IsInBetween(num, 0, 2); }) == 2) {
                continue;
            }
        }

        ofstream outputStream(filePath.c_str());
        if (!outputStream.is_open()) {
            cout << "Не удаллось открыть файл. Попытайтесь заного" << endl;
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