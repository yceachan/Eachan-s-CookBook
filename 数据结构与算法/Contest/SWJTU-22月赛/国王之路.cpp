#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=2e5+5;
int n,m; 
struct Drus{
	int from,to,val;
}edge[M];
int cnt_m=0; 
void add(int u,int v,int w)
{
	edge[++cnt_m].from=u;
	edge[cnt_m].to=v;
	edge[cnt_m].val=w; 
}

struct Edge{
	int to,val,nxt;
}e[M];
int head[N]={0},cnt_e=0;
void Add(int u,int v,int w)
{
	e[++cnt_e].to=v;
	e[cnt_e].val=w;
	e[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}

int fa[N];
int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
void merge(int x,int y) { fa[y]=find(x);}
bool cmp(const Drus& lhs,const Drus& rhs) {return lhs.val<rhs.val;}

void krus()
{
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(edge+1,edge+cnt_m+1,cmp);
	for(int i=1;i<=cnt_m && cnt<n;i++)
	{
		int eu=find(edge[i].from),ev=find(edge[i].to);
		if(find(eu)==find(ev)) continue;
		merge(eu,ev);
		cnt++;
		Add(eu,ev,edge[i].val);
		Add(ev,eu,edge[i].val);
	}
}
int dp[N];
int ans=0;
void dfs(int u,int fa)
{
    for(int j=head[u];j;j=e[j].nxt)
    {
        int to=e[j].to;
        if(to==fa) continue;
        dfs(to,u);
        ans=max(ans,dp[u]+dp[to]+e[j].val);
        dp[u]=max(dp[u],dp[to]+e[j].val);
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v,w;cin>>u>>v>>w;
		add(u,v,w);
	}
	krus();
	memset(dp,0,sizeof(dp));
	dfs(1,0);
	cout<<ans;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<" ";
//		for(int j=head[i];j;j=e[j].nxt)
//		{
//			cout<<e[j].to<<" ";
//		}
//		cout<<"\n";
//	}
	return 0;
}
