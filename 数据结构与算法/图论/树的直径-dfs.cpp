#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge
{
    int to, val,nxt;
}edge[2*N];
int cnt_e=0;
int head[N]={0};
void add(int u,int v,int w)
{
    edge[++cnt_e].to=v;
    edge[cnt_e].val=w;
    edge[cnt_e].nxt=head[u];
    head[u]=cnt_e;
}
int n;
int dis[N];
void dfs(int u,int fa)
{
    for(int j=head[u];j;j=edge[j].nxt)
    {
        int to=edge[j].to;
        if(to==fa) continue;
        dis[to]=dis[u]+edge[j].val;
        dfs(to,u);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);
        add(v,u,w);
    }
    memset(dis,0,sizeof(dis));
    dfs(1,0);
    int beg=1;
    for(int i=2;i<=n;i++)
    {
        beg=dis[i]>dis[beg]?i:beg;
    }
    memset(dis,0,sizeof(dis));
    dfs(beg,0);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dis[i]);
    }
    printf("%d",ans);

}

