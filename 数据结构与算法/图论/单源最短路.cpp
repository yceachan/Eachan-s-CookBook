#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2*N;
int n,m,cnt_e=0;
struct Edge{
	int to,val,nxt;
}edge[M];
int head[N]={0};
void add(int u,int v,int w)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].val=w;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}

struct node{
	int id,l;
	node(int id,int l) : id(id),l(l){	}
    bool operator< (const node& rhs) const{return l>rhs.l;}
};
int beg;
int dis[N];
priority_queue<node> pq;
bool vis[N]={0};
#define INF 0x3f3f3f3f
void dijk()
{

	for(int i=1;i<=n;i++) dis[i]=INF;
	dis[beg]=0;
	pq.push(node(beg,0));
	
	while(!pq.empty())
	{
		int u=pq.top().id;pq.pop();
		
		if(vis[u]) continue;
		vis[u]=true;
		for(int j=head[u];j;j=edge[j].nxt)
		{
			int to=edge[j].to;
			if(dis[to]>dis[u]+edge[j].val)
			{
				dis[to]=dis[u]+edge[j].val;
				pq.push(node(to,dis[to]));
			}
		}
	}
}
int main()
{
    ios::sync_with_stdio(false);
	cin>>n>>m>>beg;
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);
	}
	dijk();
	for(int i=1;i<=n;i++) cout<<dis[i]<<" ";
	return 0;
}
