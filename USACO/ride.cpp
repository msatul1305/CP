/*
ID: <HIDDEN>
PROG: ride
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;
int num(char *);
int main()
{
    char comet[50],group[50];
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    cin >> comet >> group;
    if(num(comet)==num(group))
        cout << "GO\n";
    else
        cout << "STAY\n";
    return 0;
}

int num(char *x)
{
    int sum=1,c;
    while(*x!='\0')
    {
        c=(*x)-64;
        sum*=c;
        x++;
    }
    return (sum%47);
}
