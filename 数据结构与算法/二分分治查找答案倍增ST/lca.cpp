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

int fa[N][22] = { 0 }, depth[N] = { 0 },Log[N]={0};//u����2^i������ 

void Loginit()
{
	Log[1]=0;Log[2]=1;
	for(int i=3;i<N;i++) Log[i]=Log[i>>1] +1;
} 
void dfs(int u, int pre)
{
	fa[u][0]=pre;depth[u]=depth[pre]+1;//ֱ����������ȵ�dfs����
	//ά������u����2^i������ 
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
    if(depth[x] <depth[y]) swap(x,y);//x��y֮�£�x��������ͬһ���
	
	while(depth[x]>depth[y])
	{
		//x=fa[x][0];��ţ˵����Ҫһ��һ����������
		//��Ҫ��������ÿ��һ����depth����2^q�� 
		int q=Log[depth[x]-depth[y]];//xy����Ȳ������ȡ��
		x=fa[x][q]; 
	} 
	if(x==y) return x;
	
	//ͬ���µ�LCA�㷨��һ�������� 
	
	for(int i=Log[depth[x]];i>=0;i--)
	{
		if(!fa[x][i]) continue;
		//����pace̫��ģ�������>=LCA��λ�� 
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];  //����֤�����ǣ���������2^i������xy�������С��2^i,���Կ��Լ��������i--������
		}
    }
    //�����for�ĵ�������ǣ�
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
