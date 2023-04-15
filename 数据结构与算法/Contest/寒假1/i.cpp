#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;

void solve(int x)
{
	int mod=x%7;
	if(x%10-mod >=0 && (x%10-mod)) cout<<x-mod<<'\n';
	else if( x+(7-mod) <= (x/10+1)*10) cout<<x+(7-mod)<<'\n';
	
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
