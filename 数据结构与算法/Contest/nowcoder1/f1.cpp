#include<bits/stdc++.h>

using namespace std;
using ll=long long;
const int N=1e5+5,M=4e5+5;
int n,m;
int dsu[N];

int find(int x) { return x==dsu[x] ? x: dsu[x]=find(dsu[x]);}
void merge(int u,int v) {  dsu[find(u)]=find(v);}
void init() { for ( int i= 1;i<=n;i++) dsu[i]=i;}

int x[N]={0};
int c[N];
int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	init();
	
	for(int i=1;i<=m;i++)
	{
		int u,v;cin>>u>>v; 
		merge(u,v);
	}
	for(int i=1;i<=n;i++)  cin>>c[i];
	
    vector<int> vec;   //子图dsu节点 
    map<int,ll> cnt;  //子图点数 
    map<int,bool> bom; //bom标记 
	for(int i=1; i<=n; i++)
	{
		int u= find( i );
		
		//维护集合元素 
		if(u == i)
		{
			vec.push_back(u);
		}
		cnt[u]++;
		//找炸蛋 
		if(c[i])	bom[u]=1;
	}
	
    if(bom.empty())
    {
    	ll sum=0;
    	for(auto it:vec)
    	{
    		sum+=cnt[it]*cnt[it];
		}
		cout<<sum;
	}
	else if(bom.size() == 1 )
	{
		for(auto it:vec)
		{
			if(bom[it])
			{
				cout<<1ll*cnt[it]*cnt[it];
				return 0;
			}
		}
	}
	else cout<<0;
	return 0;
}
