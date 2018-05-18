#define _CRT_SECURE_NO_WARNINGS
#define forn(i, a, n) for(int i = a; i < n; ++i)
#define pb push_back
#define mp make_pair
#define f first
#define s second

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
#include "classes.h"

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#pragma comment(linker, "/STACK:228228000")
const ll mod = (ll)1e9;

ll prior;
string time, name;
vector<event> timet;

ll gett (ll h1, ll h2, ll m1, ll m2)
{
    return(h1*600 + h2 * 60 + m1 * 10 + m2);
}

int main()
{
    ifstream cin;
    ofstream cout;
    cin.open("input.txt");
    cout.open("output.txt");
    setlocale(0, "");
    bool out = true;
    string trash;
    cin >> trash;
    while(out)
    {
        time.clear();
        name.clear();
        cin >> prior >> time;
        while(name[name.size()-1] != '#')
        {
            string reader;
            if(!(cin >> reader))
            {
                out = false;
                break;
            }
            if (reader == "#") break;
            name += " ";
            name += reader;
        }
        ll t1, t2;
        t1 = gett (time[0] - '0', time[1] - '0', time[3] - '0', time[4] - '0');
        t2 = gett (time[6] - '0', time[7] - '0', time[9] - '0', time[10] - '0');
        event e(prior, t1, t2, name);
        timet.push_back(e);//здесь могла быть ваша реклама
    }
    sort(timet.begin(), timet.end());

    forn(i, 0, timet.size())
        timet[i].show();


    return 0;
}
