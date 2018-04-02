/*
ID: <hidden>
TASK: beads
LANG: C++11
*/
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
	freopen("beads.in","r",stdin);
	freopen("beads.out","w",stdout);
	int n,ans=0,flag=0;string x;
	cin >> n;
	cin >> x;
	string z = x;//to retain the original string
	for(int i=1;i<x.size();i++)
	{
		string :: iterator it = z.begin()+i;
		string a(z.begin(),it);
		string b(it,z.begin()+z.size());
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		x = a+b;
		int left=0,right=0;
		char l=x[0],r=x[x.size()-1];
		if(l==r && flag==0)
		{
			for(int j=0;j<x.size()-1;j++)
			{
				if(x[j]!=x[j+1])
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				cout << x.size() << endl;
				return 0;
			}
		}
		if(l==r) continue;
		if(l=='w' && r=='r') l='b';
		if(l=='w' && r=='b') l='r';
		if(l=='r' && r=='w') r='b';
		if(l=='b' && r=='w') r='r';
		for(int j=0;x[j]==l||x[j]=='w';j++)
		{
			left++;
		}
		for(int j=x.size()-1;x[j]==r||x[j]=='w';j--)
		{
			right++;
		}
		ans=max(ans,left+right);
	}
	cout << ans << "\n";
	return 0;
}
