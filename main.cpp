    #define _CRT_SECURE_NO_WARNINGS
    #define forn(i, a, n) for(int i = a; i < n; ++i)
    #define pb push_back
    #define mp make_pair
    #define f first
    #define s second

    #include <iostream>
    #include <fstream>
    #include <stdlib.h>
    #include <vector>
    #include <algorithm>
    #include <string>
    #include <stack>
    #include <set>
    #include <ostream>
    #include <queue>
    #include <functional>
    #include <sstream>
    #include <map>
    #include <math.h>
    #include <time.h>
    #include "classes.h"

    using namespace std;
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pll;
    #pragma comment(linker, "/STACK:228228000")
    const ll mod = (ll)1e9;

    ll prior;
    string tim, name;
    vector<event> timet;
    vector<ll> a;
    ll glhap = 0;
    ll glft = 0;
    vector<ll> gla;

    void toMasOfChar(string s, char* c)
    {
        unsigned int i;
        for (i = 0; i < s.length(); i ++)
        {
            c[i]=s[i];
        }
        for (i = s.length(); i < s.length()*2; i ++)
        c[i]=' ';
    }


    void fun(ll v, ll hap, ll ft)
    {
        if(timet[v].elder == -1)
        {
            if((hap == glhap && ft > glft)||(hap > glhap))
            {
                gla = a;
                glhap = hap;
                glft = ft;
            }
            return;
        }
        forn(i, timet[v].elder, timet.size())
        {
            a.push_back(i);
            fun(i, hap + timet[i].prior, ft +  timet[i].t1 - timet[v].t2);
            a.pop_back();
        }
    }

    ll gett (ll h1, ll h2, ll m1, ll m2)
    {
        return(h1*600 + h2 * 60 + m1 * 10 + m2);
    }

    int main()
    {
        ifstream in;
        ofstream out;
        //srand(time(NULL));
        //char nm[5];
        //nm[0]='c'; nm[1]='o'; nm[2]='l'; nm[3]='o'; nm[4]='r'; nm[5]=' '; nm[6]='0'; nm[7]=rand()%6+'a';
        //system(nm);
        in.open("input.txt");
        out.open("output.txt");
        setlocale(0, "");
        bool aut = true, put;
        string trash;
        cout << "Вывод в консоль: 0\nВывод в файл:1\n";
        cin >> put;
        in >> trash;
        while(aut)
        {
            tim.clear();
            name.clear();
            in >> prior >> tim;
            while(name[name.size()-1] != '#')
            {
                string reader;
                if(!(in >> reader))
                {
                    aut = false;
                    break;
                }
                if (reader == "#") break;
                name += " ";
                name += reader;
            }
            ll t1, t2;
            t1 = gett (tim[0] - '0', tim[1] - '0', tim[3] - '0', tim[4] - '0');
            t2 = gett (tim[6] - '0', tim[7] - '0', tim[9] - '0', tim[10] - '0');
            event e(prior, t1, t2, name);
            timet.push_back(e);//здесь могла бы быть ваша реклама
        }
        event sleep(0, 1380, 1380, "Сон");
        sleep.elder = -1;
        timet.push_back(sleep);
        sort(timet.begin(), timet.end());

        forn(i, 0, timet.size()-1)
        {
            ll le = 0;
            while(timet[le].t1 < timet[i].t2)
                le++;
            timet[i].elder = le;
        }

        fun(0, timet[0].prior, 0);
        forn(i, 0, gla.size()-1)
        {
            timet[gla[i]].show(0);
            if (!put)
                timet[gla[i]].show();
        }
        out.close();
        out.open("output.txt", ios_base::app);
        if (!put)
            cout << "Free time:" << glft - timet[gla[gla.size()-1]].t1 + timet[gla[gla.size()-2]].t2 << "\nКоличество мероприятий - " << gla.size()-1 << endl;
        out << "Free time:" << glft - timet[gla[gla.size()-1]].t1 + timet[gla[gla.size()-2]].t2 << "\nКоличество мероприятий - " << gla.size()-1 << endl;
        return 0;
    }
