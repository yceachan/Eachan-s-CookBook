#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll cnt=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    int x,y;cin>>x>>y;
	
	while(y>x)
	{
		if(y&1) cnt++;
		y+=y&1;
		
		y>>=1;
	//	cout<<y<<" ";
	    cnt++;
	}
	cout<<cnt+x-y;
	return 0;
}
