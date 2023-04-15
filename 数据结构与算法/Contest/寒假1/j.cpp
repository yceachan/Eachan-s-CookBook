#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;

void solve(int x)
{
    if(x==2) {cout<<"0 1\n";return;}
    int m=1;
    while(m<=(x-1))
    {
    	m<<=1;
	}
	m>>=1;
//	cout<<m;
    for(int i=1;i<x;i++)
    {
      if(i==m) cout<<0<<" ";
      cout<<i<<" ";
    }
    cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
   int T;cin>>T;
   while(T--)
   {
   	int x;cin>>x;
   	solve(x);
   }
    return 0;
}
