#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5,M=5e5+5;
struct Edge{
	int to,nxt;
}edge[M]; 
int head[N]={0},in[N]={0},out[N]={0},n,m;
int cnt_e=0;
//�ߵĹ�ϵu��v��ʳ 
void add(int u,int v)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
	in[v]++;
	out[u]++; 
}
int dp[N]={0},mod=80112002,ans=0;
queue<int> que;
//ע�����ǿ��Դ������������--���δ������Ϊ������� 
void topo(){
	for(int i=1;i<=n;i++) if(!in[i]) {que.push(i);dp[i]=1;}//���Ϊ�㣬��ʾ�����ߣ���topo���
	
	while(!que.empty())
	{
		int u=que.front();que.pop();
		for(int j=head[u];j;j=edge[j].nxt)
		{
			int to=edge[j].to;
			dp[to]=(dp[u]+dp[to])%mod;;
			in[to]--;
		//	cout<<u<<" "<<to<<" "<<in[to]<<" "<<dp[to]<<"\n"; 
			if(!in[to]) que.push(to);
		}
	} 
	for(int i=1;i<=n;i++) if(!out[i]) ans=(ans+dp[i])%mod;
}
//ifstream fin("P4017_5.in");
int main()
{
	ios::sync_with_stdio(false); 
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int u,v;cin>>u>>v;
		add(u,v);
	}
	topo();
//	fin.close();
    cout<<ans;
}
