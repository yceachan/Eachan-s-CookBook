#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int w[N];
int n;
int cnt=0;
//背包解法：答案空间已定。背包：从前i个砝码组合出重量j。状态:j是否能达成。 
bool dp[N][100005]; 
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	int sum=0; 
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
	}
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=sum;j++)
    	{
    		int lp=abs(w[i]-j);
    		int rp=abs(w[i]+j);
    		dp[i][j]=dp[i-1][j] || dp[i-1][lp] || dp[i-1][rp];
		}
	//	for(int j=0;j<=sum;j++) if(dp[i][j])cout<<j<<" "; cout<<'\n';
	}
    
	for(int j=1;j<=sum;j++) if(dp[n][j]) cnt++;
	
	cout<<cnt;
  
	return 0;
}
