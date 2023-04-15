



# [1.ST表_RMQ问题](https://www.luogu.com.cn/problem/P3865)



ST 表是用于解决 **可重复贡献问题** 的数据结构。

* **可重复贡献问题**

> 可重复贡献问题指对于预算 x opt x=x ，则对于区间内的询问是可重复贡献的

如，静态区间最大值查询问题（RMQ）。

$eg. max(l,r)=max(\ max(l,m)\ ,\ max(m,r)\ )$

![image-20221108120338392](https://s2.loli.net/2022/11/08/b3Kqrgimvuhc56F.png) 

## 题面

**Q:给定一个长度为 N*的数列，和 M 次询问，求出每一次询问的区间内数字的最大值。**

* ST表基于倍增思想，可以做到$O(nlogn)$预处理下$O(1)$询问

## 代码:

~~~C++
//基于倍增思想，改造f[][21]表示index下长度为2^j步区间的最值
int f[N][22]={0},Log[N]={0};
int n,m,a[N]={0};
void ST()
{
    //与构造向下取整的log2，——对于长度为n的区间，我们期望尽量二分它eglog7=2,二分区间长度为2^2=4
	Log[1]=0;Log[2]=1;
	for(int i=3;i<N;i++) Log[i]=Log[i>>1] +1;  
	for(int i=1;i<=n;i++) f[i][0]=a[i];
	
	for(int j=1;j<22;j++)
	{
		for(int i=1;i+ (1<<j) -1 <=n;i++) //把握好边界 从i开始长度为2^j的区间，其尾索引为i + 2^j -1  
		{
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		} 
	}
} 
void quire(int l,int r)
{
    int q=Log[r-l+1];
    //2^q>=n/2,当且仅当2|n等号成立，故两个区间分别是[l,l+2^q-1],[r-2^q +1,r]
	int ans=max(f[l][q],f[r- (1<<q) + 1][q]);
    return ans;
}
~~~

# [2.最近公共祖先（LCA)](https://www.luogu.com.cn/problem/P3379)

**Q:给定一棵有根多叉树，请求出指定两个点直接最近的公共祖先。**

## 代码：

~~~C++
void Loginit()
{
	Log[1]=0;Log[2]=1;
	for(int i=3;i<N;i++) Log[i]=Log[i>>1] +1;
} 
//dfs树时构造出深度信息与倍增祖先表
void dfs(int u, int pre)
{
	fa[u][0]=pre;depth[u]=depth[pre]+1;//直接祖先与深度的dfs构造
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
        //跳越界到root外的continue掉，在选择好优雅的倍增起点pow(2,x的深度的向下取对)后，不会出现这种情况
		if(!fa[x][i]) continue;
		//跳到>=LCA的位置也continue掉
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];y=fa[y][i];  //可以证明的是，对于跳了2^i步的新xy，其深度小于2^i,所以可以继续用这个i--来迭代
		}
    }
    //上面的for的迭代结果是：
	return fa[x][0]; 
}
~~~

## 图解倍增策略：

###  1.深度同步

<img src="https://s2.loli.net/2022/11/08/yvL2C9uJEpVghAm.png" alt="image-20221108172030505" style="zoom:67%;" />

* 考查结点**6^th^,16^th^**,后者先需要跳到8^th，再进行同步倍增上爬——

  深度为x的结点跳到深度为y处的倍增方案是：

​              **——每次跳2^^xy深度差的向下取对^** ,显然没有越界问题。

* 终点是：`depth[x]==depth[y]`

###  2.同步倍增

<img src="https://s2.loli.net/2022/11/08/vQcnpYbG63Xy5Me.png" alt="image-20221108171049529" style="zoom:67%;" />

* 如图考查结点**6^th^ ， 11^th^**，**这是一个单调上爬过程，depth递减**，其**最优倍增上爬距离**是**2^^其深度的向下取对^**,且此后的最优倍增距离不会超过**2^i**,固有如上LCA方案

终点是`return fa[x][0]; `

## 精简板子

~~~C++
void dfs(int u, int pre)
{
	fa[u][0]=pre;depth[u]=depth[pre]+1;
	for(int i=1; 1<<i < depth[u];i++)	{
		fa[u][i]=fa[fa[u][i-1]][i-1];
	}
    
	for(int j=head[u];j;j=edge[j].nxt)  {
		int to=edge[j].to;
		if(to!=u) dfs(to,u);
	} 
}
void Loginit(){
	Log[1]=0;Log[2]=1;
	for(int i=3;i<N;i++) Log[i]=Log[i>>1] +1;
} 
int LCA(int x, int y){
    if(depth[x] <depth[y]) swap(x,y);//x在y之下，x向上跳至同一深度
	while(depth[x]>depth[y])
	{
		int q=Log[depth[x]-depth[y]];//xy的深度差的向下取对
		x=fa[x][q]; 
	} 
	if(x==y) return x;
	
	
	for(int i=Log[depth[x]];i>=0;i--)//倍增起点pow(2,x深度的向下取对)
	{
		if(fa[x][i]!=fa[y][i])  //倍增可能depth结果：lcs<=res<=root 或， res<lcs
        {
			x=fa[x][i];y=fa[y][i]; 
        }
    }
	return fa[x][0]; //迭代倍增策略结果：lca=fa[x][0]
}
~~~



