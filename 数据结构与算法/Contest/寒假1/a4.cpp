#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int N=1e5+5;
vector<int> x[N];
vector<int> y[N];
ll X=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int a;cin>>a;
		    x[a].push_back(i);
		    y[a].push_back(j); 
		}
		
	}	
	for(int i=1;i<=1e5;i++)
	{
		if(x[i].empty()) continue;
		
		sort(x[i].begin(),x[i].end());		
		ll xsum=0,cnt=0;
		for(auto it:x[i])
		{
		
			X+=1ll*cnt*it-xsum;
			cnt++;
			xsum+=it;
		}
	}
	for(int i=1;i<=1e5;i++)
	{
		if(y[i].empty()) continue;
		
		sort(y[i].begin(),y[i].end());		
		ll ysum=0,cnt=0;
		for(auto it:y[i])
		{
			X+=1ll*cnt*it-ysum;
			cnt++;
			ysum+=it;
		}
	}
	
    cout<<X;
    return 0;
}
