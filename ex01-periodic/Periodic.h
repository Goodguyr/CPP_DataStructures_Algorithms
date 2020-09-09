#include <string>
using namespace std;

namespace ds_course
{
    class Periodic
    {
    public:
    Periodic(); 
    std::string output;
    int isPeriodic(std::string &word, std::string &mode);
    };
}

string operator* (string, int);
bool allSame(string&);
bool isPrime(int&);
int longestPeriod(string&);
