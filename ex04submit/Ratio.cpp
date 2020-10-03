#include<iostream>
#include"Ratio.h"


Ratio operator+(Ratio& a, Ratio& b){
    // a.setNumerator(a.getNumerator() * b.getDenominator());
    // b.setNumerator(b.getNumerator() * a.getDenominator());
    // a.setDenominator(a.getDenominator() * b.getDenominator());
    // a.setNumerator(a.getNumerator() + b.getNumerator());
    // a.simplify();
    // return a;
    return a += b;
}

Ratio operator-(Ratio& a, Ratio& b){
    a.setNumerator(a.getNumerator() * b.getDenominator());
    b.setNumerator(b.getNumerator() * a.getDenominator());
    a.setDenominator(a.getDenominator() * b.getDenominator());
    a.setNumerator(a.getNumerator() - b.getNumerator());
    a.simplify();
    return a;
}

Ratio operator*(Ratio& a, Ratio& b){
    a.setNumerator(a.getNumerator() * b.getNumerator());
    a.setDenominator(a.getDenominator() * b.getDenominator());
    a.simplify();
    return a;
}


Ratio& Ratio::operator+=(Ratio& b){
    this->setNumerator(this->getNumerator() * b.getDenominator());
    b.setNumerator(b.getNumerator() * this->getDenominator());
    this->setDenominator(this->getDenominator() * b.getDenominator());
    this->setNumerator(this->getNumerator() + b.getNumerator());
    this->simplify();
    return *this;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, (a % b));
}

std::ostream& operator<<(std::ostream &out, Ratio& ratio){
    if(ratio.numerator == 0 || ratio.denominator == 0){
        out << 0;
        return out;
    }
    out << ratio.numerator << "/" << ratio.denominator;
    return out;
};