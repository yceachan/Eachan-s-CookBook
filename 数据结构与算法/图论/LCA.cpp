//LCA
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m, s, cnt_e = 0;
struct Edge {
	int to, nxt;
}edge[2 * N];
int head[N] = { 0 };
void add(int u, int v)
{
	edge[++cnt_e].to = v;
	edge[cnt_e].nxt =head[u];
	head[u] = cnt_e;
}

int fa[N][22] = { 0 }, depth[N] = { 0 },Log[N]={0};//u结点的2^i级祖先 

void Loginit()
{
	Log[1]=0;Log[2]=1;
	for(int i=3;i<N;i++) Log[i]=Log[i>>1] +1;
} 
void dfs(int u, int pre)
{
	fa[u][0]=pre;depth[u]=depth[pre]+1;//直接祖先与深度的dfs链接
	//维护树上u结点的2^i级祖先 
	for(int i=1; 1<<i < depth[u];i++)
	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
	
	for(int j=head[u];j;j=edge[j].nxt)
	{
		int to=edge[j].to;
		if(to==pre) continue;
		dfs(to,u);
	} 
}

int LCA(int x, int y)
{
    if(depth[x] <depth[y]) swap(x,y);//x在y之下，x向上跳至同一深度
	
	while(depth[x]>depth[y])
	{
		//x=fa[x][0];蜗牛说，我要一步一步往上爬！
		//它要倍增爬，每跳一步，depth减少2^q吧 
		int q=Log[depth[x]-depth[y]];//xy的深度差的向下取对
		x=fa[x][q]; 
	} 
	if(x==y) return x;
	
	//同层下的LCA算法：一起倍增上爬 
	
	for(int i=Log[depth[x]];i>=0;i--)
	{
		if(!fa[x][i]) continue;
		//对于pace太大的，已跳到>=LCA的位置 
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];  //可以证明的是，对于跳了2^i步的新xy，其深度小于2^i,所以可以继续用这个i--来迭代
		}
    }
    //上面的for的迭代结果是：
	return fa[x][0]; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> s;
	for (int i = 1; i < n; i++)
	{
		int u,v; cin >> u>>v;
		add(u, v); add(v, u);
	}
    Loginit();
	dfs(s, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y; cin >> x >> y;
		cout << LCA(x, y) << "\n";
	}
	return 0;
}
