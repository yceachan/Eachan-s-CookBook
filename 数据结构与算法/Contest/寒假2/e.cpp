#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//ll query(ll k)
//{	 	
//    ll bin=0;
//    while( ( 1<<bin ) <= k) bin++; bin--;
//    
//    if(k==1<<bin) return bin+1;
//    else return query(k-(1<<bin));    
//}
//map<ll,ll> mey;
//ll lg(ll k)
//{
//	if(mey[k] || k==1) return mey[k];
//	mey[k]=1+lg(k>>1);
//	return mey[k];
//}
//ll quert(ll k)
//{
//	while(1)
//	{
//		 ll bin=lg(k);
//   		 if(k==1<<bin) return bin+1;
//   		 k&=~(1ll*1<<bin);
//	}
//}
ll querr(ll n,ll k)
{
	for(ll i=1;i<=n+1;i++)
	{
		ll tmp=k-(1ll*1<<(i-1));
		if(tmp%(1ll*1<<(i))==0) 
		{
			return i;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    ll n,k;cin>>n>>k;
    //for(ll i=1;i<=1<<n;i++) cout<<querr(n,i)<<" ";
    cout<<querr(n,k);
	return 0;
 } 
