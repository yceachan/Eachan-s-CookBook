//��������
#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=1e5+5;
struct Edge{
	int to,nxt;
}edge[2*N];
int head[N]={0};
int cnt_e=0;
void add(int u,int v)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}
int n,m;

void print(vector<int>& path )  {  for( auto it : path) cout<<it<<" ";}

bool vis[N]={0};

//��ͨ��ͼ�ڣ�û����һ���㣬�������push�����ȶ��У�ÿ�������ȶ�����ѡ��С�ĵ�����߷ã����ȶ�����ȫ�ֵ� 
vector<int> path;
priority_queue<int> pq;
void topo(int u)
{
	path.push_back(u);
	vis[u]=1;
	
	for(int j=head[u];j;j=edge[j].nxt)
	{
		if(!vis[edge[j].to]) 
		    pq.push(-1*edge[j].to);
	}
	while( ! pq.empty() )
	{
		int to=pq.top()*-1;
		pq.pop();
	if(!vis[to])	topo(to);
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
   
   topo(1);
   print(path);
	return 0;
} 
