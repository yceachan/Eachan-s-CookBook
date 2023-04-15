#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+5;

ll a[N];
ll  d[N<<2]={0};
ll  tag[N<<2]={0};

inline int 	left(int i) { return i<<1; }
inline int  right(int i) { return i<<1|1; }
inline int  fa(int i) { return i>>1; }

inline void push_up(int p)
{
	d[p] = max(d[left(p)] , d[right(p)] );
}
inline void push_down(int l,int r,int p)
{
    if (!tag[p]) return;
    int mid = (l + r) >> 1;
    tag[left(p)] = tag[p];
    tag[right(p)] = tag[p];
    d[left(p)]  = tag[p];
    d[right(p)] = tag[p];
    tag[p] = 0;
}

void build(int l,int r,int p)
{
	if(l==r) 
	{
	    d[p]=a[l];
		return; 
	}
	int mid=(l+r)>>1;
	build(l,mid,left(p));
	build(mid+1,r,right(p));
	push_up(p);
}
ll query(int lo,int hi,int l,int r,int p)
{
	ll res=0;
	if(lo<=l && r<=hi) return d[p];
	int mid=(l+r)>>1;
	push_down(l,r,p);
	if(lo<=mid) res=max(res,query(lo,hi,l,mid,left(p)));
	if(hi>mid)  res=max(res,query(lo,hi,mid+1,r,right(p)));
	return res;
}
void update(int lo,int hi,int l,int r,int p,ll elm)
{
	if(lo<=l && r<=hi)
	{
		d[p]=elm;
		tag[p]=elm;
		return;
	}
	push_down(l,r,p);
	int mid = (l + r) >> 1;
    if (lo <= mid) update(lo, hi,   l  , mid, left(p),elm);
    if (hi > mid ) update(lo, hi, mid+1,  r , right(p),elm);
    push_up(p);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		 cin>>a[i];
	}
	build(1,n,1);
//	for(int i=1,lvl=0;i<=4*n;lvl++) {for(int j=1;j<=1<<lvl;j++) cout<<d[i++]<<" "; cout<<'\n';}
	int m;cin>>m;
	while(m--)
	{
		int w,h;cin>>w>>h;
		ll maxn=query(1,w,1,n,1);
		cout<<maxn<<'\n';
		update(1,w,1,n,1,maxn+h);
	}
	
	return 0;
 } 
