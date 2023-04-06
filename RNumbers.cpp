//
// Created by abelg on 2022-11-16.
//

#include "RNumbers.h"
#include <iostream>
#include <sstream>
#include <cstring>

//default constructor
RationalNumber::RationalNumber() {
    cout << "Default constructor was invoked" << endl;
    this->numerator = 0;
    this->denominator = 1;
}

RationalNumber::~RationalNumber() {
    cout << "Destructor was invoked" << endl;
}

RationalNumber::RationalNumber(int p_num) {
    cout << "One arguments -  constructor was invoked" << endl;
    this->numerator = p_num;
    this->denominator = 1;
}

RationalNumber::RationalNumber(int numerator, int denominator) {
    cout << "Two argument - constructor was invoked" << endl;
    this->numerator = numerator;
    this->denominator = denominator;
    if (this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }

}

RationalNumber::RationalNumber(string s) {
    cout << "string argument - constructor was invoked" << endl;
//    char *ptr;
//    ptr = strtok(rn, "/");
//    string nums[10];
//    int counter =0;
//    while (ptr != nullptr)
//    {
//        nums[counter] = ptr;
//        ptr = strtok (nullptr, "/");
//        counter++;
//    }
//
    string nums[3];
    size_t pos = 0;
    string token;

    string delimiter = "/";

    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        //std::cout << token << std::endl;
        nums[0] = token;
        s.erase(0, pos + delimiter.length());
    }

    nums[1] = s;

    stringstream ss1;
    stringstream ss2;
    int num1;
    int num2;

    ss1 << nums[0];
    ss1 >> num1;

    ss2 << nums[1];
    ss2 >> num2;

    this->numerator = num1;
    this->denominator = num2;


}


int RationalNumber::getNumerator() {
    return this->numerator;
}

//Addition operator overload
RationalNumber RationalNumber::operator+(const RationalNumber &p_Rn) {

    RationalNumber rn;

    rn.numerator = (this->numerator * p_Rn.denominator) + (p_Rn.numerator * this->denominator);
    rn.denominator = this->denominator * p_Rn.denominator;
    if (rn.numerator != 0 && rn.denominator != 0) {
        int reducer = GCD(rn.numerator, rn.denominator);

        rn.numerator /= reducer;
        rn.denominator /= reducer;

    }
    return rn;
}


//Subtraction operator overload
RationalNumber RationalNumber::operator-(const RationalNumber &p_Rn) {

    RationalNumber rn;

    rn.numerator = (this->numerator * p_Rn.denominator) - (p_Rn.numerator * this->denominator);
    rn.denominator = this->denominator * p_Rn.denominator;

    if (rn.numerator != 0 && rn.denominator != 0) {
        int reducer = GCD(rn.numerator, rn.denominator);

        rn.numerator /= reducer;
        rn.denominator /= reducer;


    }
    return rn;
}


//Multiplication operator overload
RationalNumber RationalNumber::operator*(const RationalNumber &p_Rn) {

    RationalNumber rn;

    rn.numerator = this->numerator * p_Rn.numerator;
    rn.denominator = this->denominator * p_Rn.denominator;

    if (rn.numerator != 0 && rn.denominator != 0) {
        int reducer = GCD(rn.numerator, rn.denominator);

        rn.numerator /= reducer;
        rn.denominator /= reducer;
    }


    return rn;
}


//Division operator overload
RationalNumber RationalNumber::operator/(const RationalNumber &p_Rn) {

    RationalNumber rn;


    rn.numerator = this->numerator * p_Rn.denominator;
    rn.denominator = this->denominator * p_Rn.numerator;

    if (rn.denominator == 0) {
        rn.numerator = 0;
        rn.denominator = 0;
    }
    if (rn.numerator != 0 && rn.denominator != 0) {
        int reducer = GCD(rn.numerator, rn.denominator);

        rn.numerator /= reducer;
        rn.denominator /= reducer;


    }
    return rn;
}

//Grater than operator overload
bool RationalNumber::operator>(const RationalNumber &p_Rn) const {

    return (this->numerator * p_Rn.denominator) > (p_Rn.numerator * this->denominator);
}


//Less than operator overloaded
bool RationalNumber::operator<(const RationalNumber &p_Rn) const {
    return (this->numerator * p_Rn.denominator) < (p_Rn.numerator * this->denominator);
}


//equal operator overloaded
bool RationalNumber::operator==(const RationalNumber &p_Rn) const {

    return (this->numerator * p_Rn.denominator) == (p_Rn.numerator * this->denominator);
}


int RationalNumber::GCD(int n1, int n2) {
    int hcf;
    if (n1 < 0) {
        n1 *= -1;
    }
    if (n2 < 0) {
        n2 *= -1;
    }


    if (n2 > n1) {
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    for (int i = 1; i <= n2; ++i) {
        if (n1 % i == 0 && n2 % i == 0) {
            hcf = i;
        }
    }

    return hcf;
}


ostream &operator<<(ostream &output, RationalNumber &p_Rn) {
    if (p_Rn.denominator == 0) {
        output << "Undefined" << endl;
    } else {
        output << p_Rn.numerator << "/" << p_Rn.denominator << endl;
    }
    return output;
}
















