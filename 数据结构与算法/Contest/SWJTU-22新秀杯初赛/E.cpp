#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
//开始dp优化
 
const int N=1e6+5,M=1e4+5;
long long a[N];
int n;
long long ans=0;
long long by[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	by[0]=a[0];
    for(int i=1;i<n;i++)
    {
    	//cout<<by[i-1]<<"\n";
    	by[i]=__gcd(by[i-1],a[i]);
	}
	for(int i=0;i<n;i++) ans+=a[i]/by[n-1];
	cout<<ans;
	return 0;
}
