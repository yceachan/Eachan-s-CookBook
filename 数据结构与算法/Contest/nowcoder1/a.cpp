#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int T;cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		
		int lhs=0,rhs=0;
		int i=0;
		int lnt=0,rnt=0;
		for(;i<s.length();i++)
		{
			if(s[i]=='1')
			{
	            if(i%2==1) lhs++;
	            else rhs++;
			}
			if(i%2) lnt++;
			else rnt++;
			if(rhs-lhs>5-lnt) break;
			if(lhs-rhs>5-rnt) break;
		}
		
		if(i==s.length()) cout<<"-1\n";
		else cout<<i+1<<'\n';
	}
}
