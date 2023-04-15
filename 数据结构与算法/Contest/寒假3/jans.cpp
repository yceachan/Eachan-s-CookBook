#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int M=100005;
ll n,k;
ll a[M],b[M];
bool ok(ll t){
	ll cnt=0;
	for (int i=1;i<=n;i++) 
		if (b[i]<a[i]*t) cnt+=a[i]*t-b[i];
		
		cout<<cnt<<" ";
	return cnt<=k;
}
int main(){
	cin>>n>>k;ll l=1<<30,r=-1;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) cin>>b[i],l=min(l,b[i]/a[i]),r=max(l,(b[i]+k)/a[i]);
	while (l<=r){
		ll mid=(l+r)/2;
		if (ok(mid)) l=mid+1;
		else r=mid-1;
	}
//	cout<<r<<endl;
	return 0;
}
