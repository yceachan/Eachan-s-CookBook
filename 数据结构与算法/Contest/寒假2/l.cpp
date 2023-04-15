#include<bits/stdc++.h>
using namespace std;
using ll=long long;

// ��ͨ��������:����߽�ģΪ�㣬��child��ģΪ����֮��ıߣ�ÿ��һ���ߣ������˵ĵ㱻vis��
//��һ��n����(���)m����(child)����ͨͼ�У�ͨ���ʵ��ģ������򣩶��ߣ���������N-1��child������������ 
//���鱾������ģ��ͼ�������ǲ���ͨ����������ͨ�����ģ��ò��鼯��ά����ͨ��������  
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
