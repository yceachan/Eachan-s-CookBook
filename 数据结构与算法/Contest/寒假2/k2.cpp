#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int n;
const int N=55;
int a[2*N];
int b[2*N];
bool vis[2*N]={0};
int ans=0x7f7f7f7f;

void solve()
{
	int sum=0;
	for(int i=1;i<=2*n;)
	{
		if(vis[i]) i++;
		if(vis[i]) i++;
		sum+=a[i+1]-a[i];
		i+=2;
	}
	ans=min(ans,sum);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+2*n+1);
   
    for(int i=1;i<=2*n;i+=2)
    {
    	vis[i]=1;
    	for(int j=i+1;j<=2*n;j+=2)
    	{
    		vis[j]=1;
    		solve();
    		vis[j]=0;
		}
		vis[i]=0;
	}
	cout<<ans;
	return 0;
 } 
