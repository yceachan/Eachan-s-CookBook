#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=55;
int n;
int a[2*N];

struct Edge{
	int from,to,val;
}edge[2*N];
int cnt_e=0;
void add(int u,int v,int val)
{
	edge[cnt_e].from=u;
	edge[cnt_e].to=v;
	edge[cnt_e++].val=val;
}
bool cmp(const Edge& lhs,const Edge& rhs) {return lhs.val<rhs.val;}

bool vis[N]={0};

int ans=0x7f7f7f7f;
vector<Edge> vec;
void dfs(int lvl,int sum)
{
	if(lvl>n-1)
	{
		cout<<sum<<'\n';
		for(auto it:vec) cout<<it.from<<" "<<it.to<<" "<<it.val<<'\n'; cout<<'\n';
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<cnt_e;i++)
	{
		if(!vis[edge[i].from] && !vis[edge[i].to])
		{
			vis[edge[i].from]=1;
			vis[edge[i].to]  =1;
			vec.push_back(edge[i]);
			dfs(lvl+1,sum+edge[i].val);
			vis[edge[i].from]=0;
			vis[edge[i].to]  =0;
			vec.pop_back();
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
    
    for(int i=1;i<=2*n-1;i++)
    {
        add(i,i+1,a[i+1]-a[i]);
	}
	sort(edge,edge+cnt_e,cmp);  
    dfs(1,0);
	cout<<ans;
	return 0;
 } 
