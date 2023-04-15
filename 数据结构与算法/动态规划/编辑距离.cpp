#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int dp[N][N]={0};
string s1,s2;
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s1>>s2;
	memset(dp,0,sizeof(dp));	
	for(int i=1;i<=s1.size();i++) dp[i][0]=i;
	for(int i=1;i<=s2.size();i++) dp[0][i]=i;
	//��i����Ϊj��--ɾһ���ַ�[i-1]ƥ��[j]���Ĵ����ϣ�[i]βɾһ���ַ�   ��һ���ַ�����[i]��ƥ��[j-1]���Ĵ����ϣ���i��β��s2[j]  �޸ġ�����[i-1]ƥ��[j-1]�� 
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
    		else
    		{
    			dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) +1;
			}
		}
	}
	cout<<dp[n][m];
	return 0;

}
