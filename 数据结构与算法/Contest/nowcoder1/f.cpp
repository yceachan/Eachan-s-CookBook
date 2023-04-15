#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
const int N=1e5 + 5 ,M=2e5 + 5;
struct Edge {
	int to,nxt;
	
}edge[M];
int head[N]={0};
int cnt_e = 0;
void add(int u,int v)
{
	edge[++cnt_e].to=v;
	edge[cnt_e].nxt=head[u];
	head[u]=cnt_e;
}

int dsu[N];
int find(int x ) { return dsu[x] == x? x :find(dsu[x]);}
void merge(int x,int y) { dsu[find(x)]=dsu[find(y)];}

int c[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n , m ; cin >> n>> m;
	
	for(int i= 1; i<= n; i++) dsu[i]=i;
	for (int i = 1 ; i <= m ; i++) 
	{
		int u,v;
		cin>> u >>v;
		add(u , v);
		add(v , u);
		merge(u,v);
	}
	for(int i=1;i<=n;i++ )cin>>c[i];
    //统计并查集个数和元素数
    int cnt=0;
    map<int,bool> vis;
    map<int,int> size;
	for(int i=1;i<=n;i++) 
	{
		int u=find(i);
		if(!vis[u]  && c[u] )
		{
			cnt++;
			vis[u]=1;
		}
		size[u]++;
	}
	
	if(cnt==0)
	{
		int sum=0;
		for(auto it:size)
		{
			sum+=it.second*it.second;
		}
		cout<<sum;
	}
	else if(cnt == 1)
	{
		for(int i=1;i<=n;i++)
		{
			if(c[i])
			{
				cout<<size[i]*size[i];
			}
		}
	}
    else cout<<0;
	return 0;
}
