#include <bits/stdc++.h>
using namespace std;
#define ri register int 
#define M 2000005

int n,m;
struct dian{
	int val,id;
	bool operator <(const dian &t)const
	{
		return val>t.val;
	}
}p[M];
int t[M];
long long ans=0;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(ri i=1;i<=n;i++) 
	{
		cin>>p[i].val;
		p[i].id=i;
		t[i]=p[i].val;//柱子的原排列 
	}
	
	p[0].id=0,p[n+1].id=n+1;//两侧用0包裹 
	sort(p,p+1+n+1);
	int l,r;
	//lr最高柱重合 
	l=r=p[0].id;
	
	//每次ask一个较大的数，然后判断这个数的id在那个区间，然后这段区间易求权 
	//0.lr维护的是已经ask过的区间 
	//易证内嵌for总共只会遍历一边数组，所以时间复杂度是O(2n) 
	for(ri i=1;i<=n+1;i++)
	{
	    if(p[i].id>r)
	    {
	    	int top=min(p[i].val,t[r]);
	    	for(int j=r+1;j<p[i].id;j++) ans+=top-t[j];
	    	r=p[i].id;
		}
		if(p[i].id<l)
	    {
	    	int top=min(p[i].val,t[l]);
	    	for(int j=p[i].id+1;j<l;j++) ans+=top-t[j];
	    	l=p[i].id;
		}
	    
	}
	cout<<ans;
	return 0;
	
	
} 
