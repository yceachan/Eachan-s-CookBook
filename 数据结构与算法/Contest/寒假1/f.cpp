#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;
ll ans=1;
map<int,int> tle;

const int N=1e6+5;
bool cp[N]={0}; 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    for(int i=2;i*i<=N;i++)
    {
    	for(int j=2;i*j<=N;j++) cp[i*j]=1;
	}
    for(int i=1;i<=100;i++) if(!cp[i]) cout<<i<<" ";
    for(int i=2;i<=n;i++)
    {
    	
	}
    return 0;
}
