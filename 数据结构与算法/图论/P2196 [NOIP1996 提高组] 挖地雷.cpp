#include<bits/stdc++.h>
using namespace std;
const int N=21,M=N*N;
struct Edge{
	int to,nxt;
}edge[M]; 
int head[N]={0},d,n,m,in[N],out[N];
int cnt_e=0;
//边的关系u被v捕食 
void add(int u,int v)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
	in[v]++;
	out[u]++; 
}
int dp[N]={0},a[N]={0},mod=80112002,ans=0,last[N]={0};
queue<int> que;
int print(int u)
{
	if(!u) return 0;
	print(last[u]);
	cout<<u<<" ";
}
void topo(){
	for(int i=1;i<=n;i++) if(!in[i]) {que.push(i);}
	
	while(!que.empty())
	{
		int u=que.front();que.pop();
		for(int j=head[u];j;j=edge[j].nxt)
		{
			int to=edge[j].to;
			if(dp[to]<dp[u]+a[to]) last[to]=u; //路径记录 
			dp[to]=max(dp[to],dp[u]+a[to]);
			in[to]--;
		//	cout<<u<<" "<<to<<" "<<in[to]<<" "<<dp[to]<<"\n"; 
			if(!in[to]) que.push(to);
			
		}
	} 
	int index=0;
	for(int i=1;i<=n;i++) if(!out[i])
	{
	  	 index=ans>dp[i] ?index:i;
		 ans=max(ans,dp[i]);		 
	}
    
    print(index);
	cout<<"\n"<<ans;
}
//ifstream fin("P4017_5.in");
int main()
{
	ios::sync_with_stdio(false); 
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		dp[i]=a[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int k;cin>>k;if(k) add(i,j);
		}
	}
	topo();
   
}
