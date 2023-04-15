#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e2+5;

double dp[N][N]={0};
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    
    //动规基：dp[1][1]=dp[0][0]+1; 
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		for(int k=0;k<=j;k++)
    		{
    			//将j个仙贝分配给i个人，在(第1位)第i个人分配k个下：由其余i-1个人分配j-k个仙贝,加上本位的权值：k/j 
    			dp[i][j]=max(dp[i][j],dp[i-1][j-k] + k/(double)j );
			}
		}
	}
     std::cout << std::fixed << std::setprecision(10) << dp[n][m] << "\n";
    return 0;
}
