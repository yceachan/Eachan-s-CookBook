#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=1e5+5;
const int K=1e9;
ll n,k;
ll a[N],b[N];


//���ִ𰸼��ԣ���sume<=k���ܿ��Գ��Ը��õ�cur ,-->l=mid,��֮��Ҫ��Сcur-->r=mid-1.��������ұյĶ��ּ����෴����Ҫ����һ�� 
bool check(ll cur)
{
	ll sume=0;
	for(int i=1;i<=n;i++)
	{
		if(1ll * b[i] < 1ll * a[i] * cur)  sume+= a[i] * cur -b[i];
	}
	return sume<=k;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
  	
  	//���ִ� 
  	cin>>n>>k;
  	ll l=1,r=2e9;
  	for(int i=1;i<=n;i++) cin>>a[i];
  	for(int i=1;i<=n;i++) cin>>b[i],l=min(l,b[i]/a[i]),r=max(l,(b[i]+k)/a[i]);
    while(l<r)
    {
     
	    //���ִ���Ҫ���ϼ��ԣ���r+1(�ҿ�) .  
    	ll mid=(l + r + 1)>>1;
    	
    	if(check(mid)) l=mid;  //awesome bound 
    	else r=mid-1 ;
    //		cout<<l<<" "<<r<<"\n"; 
	}
	cout<<l;
	return 0;
} 
