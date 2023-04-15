#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e2+5;
int a[N][N];
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	
    int T;cin>>T;
    while(T--)
    {
    	int n;cin>>n;
    	ll ans=0;
    	for(int i=1;i<=n;i++)
    	{
    		int a;cin>>a;if(a) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
