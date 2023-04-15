	#include<bits/stdc++.h>
	using namespace std;
	const int N = 1e4 + 5;
	int n, m;
	int a[N], b[N];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
	int bound(int x)
	{
		int l=1,r=n;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(a[mid] >= x) r=mid;
			else l=mid+1;
		}
	//	cout<<l<<r<<a[l]<<"\n";
		return l;
	}
	int main()
	{
	//	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
		n=read();
		for (int i = 1; i <= n; i++) a[i]=read();
		m=read();
		for (int j = 0; j < m; j++) b[j]=read();
		bool flag = true;
		for (int i = 0; i < m ; i++)
		{
			int index=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]>=b[i])
				{
					if(!index) index=j;
					else
					index=a[index]<a[j]?index:j;
				}
			}
			if(!index){flag=false;break;}
			a[index]-=b[i];
		}
		sort(a+1, a + n + 1);
		if (!flag) cout << "-1";
		else
			for (int i = 1; i <= n; i++) cout << a[i] << " ";
		return 0;
	}
