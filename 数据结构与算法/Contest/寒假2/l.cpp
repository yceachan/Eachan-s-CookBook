#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// 连通分量问题:将玩具建模为点，将child建模为两点之间的边：每入一条边，其两端的点被vis。
//在一张n个点(玩具)m条边(child)的连通图中，通过适当的（拓扑序）读边，可以满足N-1个child。（生成树） 
//考查本题所建模的图，可以是不连通而有若干连通分量的，用并查集来维护连通分量数。  
const int N=1e5+5,M=2*N;
struct Edge{
	int to, nxt;
}edge[M];
int cnt_e=0;
int head[N]={0};
void add(int u,int v)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}
int n,m;
bool vis[N]={0};
int cnt=0;
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=1;
	for(int j=head[u];j;j=edge[j].nxt)
	{
		int to=edge[j].to;
		if(!vis[to]) dfs(to);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    	int u,v;cin>>u>>v;
    	add(u,v);add(v,u);
	}
    
    for(int i=1;i<=n;i++)
    {
    	if(!vis[i])
    	{
    		cnt++;
    		dfs(i);
		}
	}
    cout<<max(0,m-(n-cnt));
	return 0;
 } 
