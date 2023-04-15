#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
bool cmp(const int& lhs,const int& rhs) {return lhs>rhs;}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=i;
	
	while(m--)
	{
		int op, th;
		cin>>op>>th;
		if(op==0) sort(a+1,a+th+1,cmp);
		else sort(a+th,a+n+1);
		
		//	for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<'\n';
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" "; 
}
    
