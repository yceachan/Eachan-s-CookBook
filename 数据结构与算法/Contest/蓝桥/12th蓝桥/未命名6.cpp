#include<bits/stdc++.h>
using namespace std;
const int M=21;
int T,n,cnt[M];
int main()
{
	scanf("%d",&T);
	while(T--)
	{		
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			sum^=x;
			for(int j=0;j<M;j++)	cnt[j]+=(x>>j)&1;
		}
		if(!sum)	puts("0");
		else
		{
			for(int i=20;i>=0;i--)
			{
				if(!(cnt[i]&1))	continue;
				else if(cnt[i]==1)	puts("1");
				else if((n-cnt[i])&1)	puts("-1");
				else puts("1");
				break;
			}
		}
	}
	return 0;
}
