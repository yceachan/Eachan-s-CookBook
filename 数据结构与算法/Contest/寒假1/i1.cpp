#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;

map<int,int> tle;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    for(int i=1;i<=999;i++)
    {
    //	cout<<i<<" "<<i%10<<" "<<i%7<<" ";
    	if(i%10>=i%7) tle[i]=i-i%7;  //cout<<i-i%7;
    	else tle[i]=i+7-i%7;  //cout<<i+7-i%7;
    //	cout<<'\n';
	}
    
    int T;cin>>T;
    while(T--)
    {
    	int x;cin>>x;
        cout<<tle[x]<<'\n';
	}
    return 0;
}
