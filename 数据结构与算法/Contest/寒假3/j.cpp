#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=1e5+5;
const int K=1e9;
ll n,k;
ll a[N],b[N];


//二分答案极性：若sume<=k可能可以尝试更好的cur ,-->l=mid,反之需要缩小cur-->r=mid-1.这与左闭右闭的二分极性相反，需要处理一下 
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
	
  	
  	//二分答案 
  	cin>>n>>k;
  	ll l=1,r=2e9;
  	for(int i=1;i<=n;i++) cin>>a[i];
  	for(int i=1;i<=n;i++) cin>>b[i],l=min(l,b[i]/a[i]),r=max(l,(b[i]+k)/a[i]);
    while(l<r)
    {
     
	    //二分答案需要如上极性：传r+1(右开) .  
    	ll mid=(l + r + 1)>>1;
    	
    	if(check(mid)) l=mid;  //awesome bound 
    	else r=mid-1 ;
    //		cout<<l<<" "<<r<<"\n"; 
	}
	cout<<l;
	return 0;
} 
