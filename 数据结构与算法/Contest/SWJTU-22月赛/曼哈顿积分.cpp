#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int x[N],y[N];
int n;
int col,row;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	int row=0,cow=0;
	sort(x+1,x+1+n);
	sort(y+1,y+1+n);
	if(n%2) row=1,col=1;
	else row=x[n/2+1]-x[n/2]+1,col=y[n/2+1]-y[n/2]+1;
	cout<<col*row;
	return 0;
}
