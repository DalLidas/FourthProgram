#include "Interface.h"

#pragma region DRAW
void DrawBorder() {
    cout << "===================================================================================";
}
void DrawSubBorder() {
    cout << "-----------------------------------------------------------------------------------";
}
void DrawGeetings() {
    DrawBorder();
    cout << endl << "Задание 4 вариант 6 сделано Мухаметовым Данил Ильнуровичем из 423 группы" << endl << endl;
    cout << "Найти в тексте все повторяющиеся подстроки длиннее заданной пользователем величины" << endl
        << "(например, длиннее пяти символов). Заменить все вхождения подстроки кроме первого" << endl
        << "специальной сигнатурой : {индекс первого символа оригинальной строки, длина цепочки}." << endl
        << "Перед заменой убедиться, что в тексте нет комбинаций символов, которые могут ошибочно" << endl
        << "восприниматься как формируемая сигнатура.Предусмотреть режим восстановления оригинального текста." << endl
        << "Пример : текст «тестовая строка» должен быть заменен на текст «тестовая{ 3, 2 }рока» при условии," << endl
        << "что рассматриваются подстроки, начиная с длинны в два символа." << endl;
}
void DrawStartMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\t\tMENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Run program" << endl
        << "2. Run module texts" << endl
        << "3. Close program" << endl;
}
void DrawModMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tMOD MENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Incode " << endl
        << "2. Decode" << endl;
}
void DrawInputMenu() {
    DrawBorder();
    cout << endl << "\t\t\t\tInput MENU" << endl;
    DrawSubBorder();
    cout << endl << "1. Input from file" << endl
        << "2. Input from console" << endl;
}
#pragma endregion DRAW

string EnterFilePath() {
    string filePath = " ";
    static const regex reg("((/./)?(con))|((/./)?(con\\.))|((/./)?(con\\.)(.*))");

    while (true) {
        cout << "Введите путь к файлу: ";
        cin >> filePath;

        if (!regex_match(filePath.c_str(), reg)) {
            break;
        }
        cout << "Данное имя зарезерировано системой. Попытайтесь заново" << endl;
    }

    return filePath.c_str();
}

void InputFromFile() {

}