#include <iostream>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <regex>
#include "RNumbers.h"

//using namespace  std;
//bool strSplitAndValidate(char* strRn);
bool isStrNum(string &str);

int main() {

    cout
            << "This program demonstrates adding two rational numbers which in this case are objects. It performs all arithmetic and comparison operations and displays the result"
            << endl;

    cout
            << "=========================================one argument constructor===================================================="
            << endl;

    //one argument constructor

    string wholeNum1;
    string wholeNum2;
    int num1;
    int num2;
    while (true) {

        cout << "Please enter whole number 1" << endl;
        getline(cin, wholeNum1);
        cout << "Please enter whole number 2" << endl;
        getline(cin, wholeNum2);


        if (isStrNum(wholeNum1) && isStrNum(wholeNum2)) {
            stringstream ss1;
            stringstream ss2;
            ss1 << wholeNum1;
            ss1 >> num1;

            ss2 << wholeNum2;
            ss2 >> num2;

            break;
        } else {
            cerr << "Please enter a valid number!" << endl;
        }

    }


    RationalNumber Rn1(num1);
    RationalNumber Rn2(num2);
    RationalNumber Rn3;
    bool result;

    Rn3 = Rn1 + Rn2;
    cout << "Add :" << Rn3 << endl;
    Rn3 = Rn1 - Rn2;
    cout << "Sub :" << Rn3 << endl;
    Rn3 = Rn1 * Rn2;
    cout << "Multi :" << Rn3 << endl;
    Rn3 = Rn1 / Rn2;
    cout << "Div : " << Rn3 << endl;
    result = Rn1 > Rn2;
    cout << "Greater than : " << result << endl;
    result = Rn1 < Rn2;
    cout << "Less than : " << result << endl;
    result = Rn1 == Rn2;
    cout << "Equals : " << result << endl;


    cout
            << "=========================================two argument constructor===================================================="
            << endl;
    string numerator1;
    string denominator1;
    string numerator2;
    string denominator2;
    int n1;
    int d1;
    int n2;
    int d2;

    while (true) {
        cout << "Enter first numerator" << endl;
        getline(cin, numerator1);
        cout << "Enter first denominator" << endl;
        getline(cin, denominator1);
        cout << "Enter second numerator" << endl;
        getline(cin, numerator2);
        cout << "Enter second denominator" << endl;
        getline(cin, denominator2);

        if (isStrNum(numerator1) && isStrNum(denominator1) && isStrNum(numerator2) && isStrNum(denominator2)) {
            stringstream ss1;
            stringstream ss2;
            stringstream ss3;
            stringstream ss4;

            ss1 << numerator1;
            ss1 >> n1;

            ss2 << denominator1;
            ss2 >> d1;

            ss3 << numerator2;
            ss3 >> n2;

            ss4 << denominator2;
            ss4 >> d2;

            break;
        } else {
            cerr << "Please enter a valid number!" << endl;
        }
    }


    RationalNumber Rn4(n1, d1);
    RationalNumber Rn5(n2, d2);
    RationalNumber Rn6;


    bool result2;

    Rn6 = Rn4 + Rn5;
    cout << "Add :" << Rn6 << endl;
    Rn6 = Rn4 - Rn5;
    cout << "Sub :" << Rn6 << endl;
    Rn6 = Rn4 * Rn5;
    cout << "Multi :" << Rn6 << endl;
    Rn6 = Rn4 / Rn5;
    cout << "Div : " << Rn6 << endl;
    result2 = Rn4 > Rn5;
    cout << "Greater than : " << result2 << endl;
    result2 = Rn4 < Rn5;
    cout << "Less than : " << result2 << endl;
    result2 = Rn4 == Rn5;
    cout << "Equals : " << result2 << endl;


    cout
            << "=========================================string constructor===================================================="
            << endl;


    string strRn1;
    string strRn2;
    regex var_rex("[-]?\\d+[/][-]?\\d+");


    while (true) {
        cout << "Enter first rational number(eg. 1/2): " << endl;
        getline(cin, strRn1);
        cout << "Enter second rational number(eg. 1/2): " << endl;
        getline(cin, strRn2);

        if (regex_match(strRn1, var_rex) && regex_match(strRn2, var_rex)) {
            break;
        } else {
            cerr << "Please enter a valid number!" << endl;
        }
    }

    RationalNumber Rn7(strRn1);
    RationalNumber Rn8(strRn2);
    RationalNumber Rn9;

    bool result3;

    Rn9 = Rn7 + Rn8;
    cout << "Add :" << Rn9 << endl;
    Rn9 = Rn7 - Rn8;
    cout << "Sub :" << Rn9 << endl;
    Rn9 = Rn7 * Rn8;
    cout << "Multi :" << Rn9 << endl;
    Rn9 = Rn7 / Rn8;
    cout << "Div : " << Rn9 << endl;
    result3 = Rn7 > Rn8;
    cout << "Greater than : " << result3 << endl;
    result3 = Rn7 < Rn8;
    cout << "Less than : " << result3 << endl;
    result3 = Rn7 == Rn8;
    cout << "Equals : " << result3 << endl;

    return 0;
}


bool isStrNum(string &str) {

    for (char ch: str) {
        if (isdigit(ch) == 0) {
            return false;
        }
    }
    return true;
}