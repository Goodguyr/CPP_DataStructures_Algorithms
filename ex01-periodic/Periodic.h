#include <string>

namespace ds_course
{
    class Periodic
    {
    public:
    Periodic(); 
    std::string output;
    int isPeriodic(int number);
    int isPeriodic(std::string word, bool hex);
    };
}
