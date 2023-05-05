#include "Test.h"


bool ErrorHandler() {
    try {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
    }
    catch (const int& numOfFailedTest) {
        switch (numOfFailedTest) {
        case(1):
            cout << "Test 1 is Failed" << endl;
            break;
        case(2):
            cout << "Test 2 is Failed" << endl;
            break;
        case(3):
            cout << "Test 3 is Failed" << endl;
            break;
        case(4):
            cout << "Test 4 is Failed" << endl;
            break;
        case(5):
            cout << "Test 5 is Failed" << endl;
            break;
        default:
            cout << "Undefined error" << endl;
            break;
        }

        return true;
    }
    return false;
}

bool Test1() {
    vector<string> str1{ "прив", "етт", "права", "рири" };
    vector<string> str2{};
    vector<string> str3{};
    string keyWord = "Привет";

    str2 = Incoder(str1, keyWord);
    str3 = Decoder(str2, keyWord);

    if (str3 == str1) {
        return true;
    }
    else {
        throw (1);
    }
}

bool Test2(){
    vector<string> str1{ "мирмир", "мивыми", "права", "римрри" };
    vector<string> str2{};
    vector<string> str3{};
    string keyWord = "мир";

    str2 = Incoder(str1, keyWord);
    str3 = Decoder(str2, keyWord);

    if (str3 == str1) {
        return true;
    }
    else {
        throw (1);
    }
}
bool Test3() {
    vector<string> str1{ "Пиво", "ПивоПивоПиво", "Пиввово", "пипивовиво" };
    vector<string> str2{};
    vector<string> str3{};
    string keyWord = "Пиво";

    str2 = Incoder(str1, keyWord);
    str3 = Decoder(str2, keyWord);

    if (str3 == str1) {
        return true;
    }
    else {
        throw (1);
    }
}
bool Test4() {
    vector<string> str1{ "салив", "вало", "крапива", "жужило" };
    vector<string> str2{};
    vector<string> str3{};
    string keyWord = "Сало";

    str2 = Incoder(str1, keyWord);
    str3 = Decoder(str2, keyWord);

    if (str3 == str1) {
        return true;
    }
    else {
        throw (1);
    }
}
bool Test5() {
    vector<string> str1{ "боба", "борва", "вавамоявфбобор", "орор" };
    vector<string> str2{};
    vector<string> str3{};
    string keyWord = "Борщ";

    str2 = Incoder(str1, keyWord);
    str3 = Decoder(str2, keyWord);

    if (str3 == str1) {
        return true;
    }
    else {
        throw (1);
    }
}