#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=45;
int n,m;
int a[N];
int sum[N];
ll dfs(ll hp,ll it)
{
	if(hp==0 || a[it]-hp==0)  return 1;
	
	if(sum[it]<hp || !it)  return 0;
	
	if(it>n ) return 0;
	return dfs(hp-a[it],it-1) + dfs(hp,it-1);
    
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n-1;i++) 
	{
		sum[i]+=a[i];
		sum[i+1]+=sum[i];
	}
	sum[n]+=a[n];
	
    for(int i=0;i<m;i++)
    {
    	ll hp;cin>>hp;
    	
    	cout<<dfs(hp,n)<<'\n';
    	
        
	}
	return 0;
}
