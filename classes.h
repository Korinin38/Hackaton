#include <iostream>
#include <string>

class event
{
    public:
        event(long long in_prior, int in_time1, int in_time2, std::string in_name)
        {
            prior = in_prior;
            t1 = in_time1;
            t2 = in_time2;
            name = in_name;
        }

        long long prior;
        int t1, t2;
        std::string name;
        operator > (event sec)
        {
            return t1 > sec.t1;
        }

        operator < (event sec)
        {
            return t1 < sec.t1;
        }
        void show()
        {
            std::cout << "Event " << name
                      << ": Priority - " << prior
                      << "; Time - " << t1/60/10 << t1/60%10 << ":" << t1%60/10 << t1%60%10 << "-"
                       << t2/60/10 << t2/60%10 << ":" << t2%60/10 << t2%60%10 << " (min)" << endl;
        }
};
