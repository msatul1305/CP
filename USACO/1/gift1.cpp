/*
ID: <hidden>
PROG: gift1
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

class person
{
public:
    string name;
    int money;
    int di;
    person() : money(0),di(0){}
}p[10];

int serch(int np,string x)
{
    for(int i=0;i<np;i++)
    {
        if(x==p[i].name)
            return i;
    }
}
int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);
    int np;
    cin >> np;
    for(int i=0;i<np;i++)
        cin >> p[i].name;
    for(int i=0;i<np;i++)
    {
        string temp;
        int no;
        cin >> temp;
        int found = serch(np,temp);
        cin >> p[found].di;
        cin >> no;
        if(no==0)
            continue;
        int dis=p[found].di/no;
        p[found].money -= (dis*no);
        for(int j=0;j<no;j++)
        {
            cin >> temp;
            int t=serch(np,temp);
            p[t].money=p[t].money+dis;
        }
    }
    for(int i=0;i<np;i++)
    {
        cout << p[i].name << " " << p[i].money << "\n";
    }
    return 0;
}
