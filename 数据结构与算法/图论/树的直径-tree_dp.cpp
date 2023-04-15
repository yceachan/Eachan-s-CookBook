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
int dp[N];
int ans=0;
void dfs(int u,int fa)
{
    for(int j=head[u];j;j=edge[j].nxt)
    {
        int to=edge[j].to;
        if(to==fa) continue;
        dfs(to,u);
        ans=max(ans,dp[u]+dp[to]+edge[j].val);
        dp[u]=max(dp[u],dp[to]+edge[j].val);
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
    dfs(1,0);
    printf("%d",ans);

}

