/*
ID: <hidden>
TASK: friday
LANG: C++11
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    freopen("friday.in","r",stdin);
    freopen("friday.out","w",stdout);
    int n;
    cin >> n;
    int day = 6;//first 13 = saturday so day->6
    int f[7]={0};
    int ex[12]={3,0,3,2,3,2,3,3,2,3,2,3};
    for(int i=1900;i<1900+n;i++)//through the years
    {
        if((i%4==0 && i%100!=0)||(i%400==0))//leap
            ex[1]=1;
        else
            ex[1]=0;
        for(int j=0;j<12;j++)
        {
            f[day]++;
            day+=ex[j];
            day=day%7;
        }
    }
    cout << f[6] << " " << f[0] << " " << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << " " << f[5] << "\n";
}
