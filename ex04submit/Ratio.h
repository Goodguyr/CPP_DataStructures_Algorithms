class Ratio{
private:
    int numerator;
    int denominator;
public:
    Ratio(int n = 0, int d = 1): numerator(n), denominator(d){
        simplify();
    }
    void operator+=(Ratio&);
    int getNumerator(){return numerator;}
    int getDenominator(){return denominator;}
    void setNumerator(int n){
        numerator = n;
    }
    void setDenominator(int n){
        denominator = n;
        }
    void simplify(){
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }
    friend int gcd(int,int);
};

int gcd(int,int);