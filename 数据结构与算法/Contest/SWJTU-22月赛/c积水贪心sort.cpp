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
		t[i]=p[i].val;//���ӵ�ԭ���� 
	}
	
	p[0].id=0,p[n+1].id=n+1;//������0���� 
	sort(p,p+1+n+1);
	int l,r;
	//lr������غ� 
	l=r=p[0].id;
	
	//ÿ��askһ���ϴ������Ȼ���ж��������id���Ǹ����䣬Ȼ�������������Ȩ 
	//0.lrά�������Ѿ�ask�������� 
	//��֤��Ƕfor�ܹ�ֻ�����һ�����飬����ʱ�临�Ӷ���O(2n) 
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
