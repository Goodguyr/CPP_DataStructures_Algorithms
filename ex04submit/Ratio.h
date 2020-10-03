int gcd(int,int);

class Ratio{
private:
    int numerator;
    int denominator;
public:
    Ratio(int n = 0, int d = 1): numerator(n), denominator(d){
        simplify();
    }
    friend Ratio operator*(Ratio& a, Ratio& b);
    friend Ratio operator+(Ratio& a, Ratio& b);
    friend Ratio operator-(Ratio& a, Ratio& b);
    Ratio& operator+=(Ratio& b);
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
    friend std::ostream& operator<<(std::ostream &out, Ratio& ratio);
};