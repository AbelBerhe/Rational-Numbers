//
// Created by abelg on 2022-11-16.
//

#ifndef RATIONALNUM_RNUMBERS_H
#define RATIONALNUM_RNUMBERS_H

#include <string>

using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;
public:
    RationalNumber();//default constructor
    ~RationalNumber();// destructor
    RationalNumber(int p_num); // one argument constructor
    RationalNumber(int numerator, int denominator);// two argument constructor
    RationalNumber(string);

    RationalNumber operator+(const RationalNumber &p_Rn);

    RationalNumber operator-(const RationalNumber &p_Rn);

    RationalNumber operator*(const RationalNumber &p_Rn);

    RationalNumber operator/(const RationalNumber &p_Rn);

    bool operator>(const RationalNumber &p_Rn) const;

    bool operator<(const RationalNumber &p_Rn) const;

    bool operator==(const RationalNumber &p_Rn) const;

    int getNumerator();

    int GCD(int n1, int n2);

    friend ostream &operator<<(ostream &output, RationalNumber &p_Rn);
};

#endif //RATIONALNUM_RNUMBERS_H
