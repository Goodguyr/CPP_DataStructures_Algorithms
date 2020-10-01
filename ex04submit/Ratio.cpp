#include"Ratio.h"

Ratio& operator+(Ratio& a, Ratio& b){
    a.setNumerator(a.getNumerator() * b.getDenominator());
    b.setNumerator(b.getNumerator() * a.getDenominator());
    a.setDenominator(a.getDenominator() * b.getDenominator());
    a.setNumerator(a.getNumerator() + b.getNumerator());
    a.simplify();
    return a;
}

Ratio& operator-(Ratio& a, Ratio& b){
    a.setNumerator(a.getNumerator() * b.getDenominator());
    b.setNumerator(b.getNumerator() * a.getDenominator());
    a.setDenominator(a.getDenominator() * b.getDenominator());
    a.setNumerator(a.getNumerator() - b.getNumerator());
    a.simplify();
    return a;
}

Ratio& operator*(Ratio& a, Ratio& b){
    a.setNumerator(a.getNumerator() * b.getNumerator());
    a.setDenominator(a.getDenominator() * b.getDenominator());
    a.simplify();
    return a;
}


void Ratio::operator+=(Ratio& a){
    *this = *this + a;
}

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, (a % b));
}