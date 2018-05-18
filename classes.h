    #include <iostream>
    #include <fstream>
    #include <string>
    #include <vector>

    using namespace std;

    class event
    {
        public:
            event(long long in_prior, int in_time1, int in_time2, string in_name)
            {
                prior = in_prior;
                t1 = in_time1;
                t2 = in_time2;
                name = in_name;
            }

            long long prior;
            int t1, t2, elder;
            string name;
            operator > (event sec)
            {
                if(t1 == sec.t1)
                    return t2 > sec.t2;
                return t1 > sec.t1;
            }

            operator < (event sec)
            {
                if(t1 == sec.t1)
                    return t2 < sec.t2;
                return t1 < sec.t1;
            }
            void show(bool cinput = true)
            {
                ofstream out;
                out.open("output.txt", ios_base::app);
                if (cinput)
                    cout << "Event " << name
                         << ":\nPriority - " << prior
                         << ";\nTime - " << t1/60/10 << t1/60%10 << ":" << t1%60/10 << t1%60%10 << "-"
                         << t2/60/10 << t2/60%10 << ":" << t2%60/10 << t2%60%10 << "\n\n";
                else
                    out << "Event " << name
                        << ":\nPriority - " << prior
                        << ";\nTime - " << t1/60/10 << t1/60%10 << ":" << t1%60/10 << t1%60%10 << "-"
                        << t2/60/10 << t2/60%10 << ":" << t2%60/10 << t2%60%10 << "\n\n";

            }
    };
