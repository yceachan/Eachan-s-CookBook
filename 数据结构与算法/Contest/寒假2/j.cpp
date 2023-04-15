#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+5;

int vis[N]={0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    
    int cnt=0; 
    for(int i=1;i<=m;i++)
    {
    	int x,y;cin>>x>>y;
    	if(vis[x] && vis[y])
    	{
    		cout<<i<<' ';
    	    	cnt++;
		}
		vis[x]=1;vis[y]=1;
	}
	cout<<cnt;
	return 0;
 } 
