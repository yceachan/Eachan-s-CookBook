#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e4+5;
string tex,cold;
int n,m;
int mark[N]={0};
int vec[N]={0};
bool cmp(const int& lhs,const int& rhs) {return lhs>rhs;}
long long ans=0;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	cin>>tex;
	cin>>cold;
	for(int i=0;i<n;i++) cin>>mark[i];
	int len=0;
	for(int i=0;i<n;i++) if(tex[i]!=cold[i]) vec[len++]=mark[i]; else ans+=mark[i];
	sort(vec,vec+len,cmp);
	for(int i=0;i<m;i++) ans+=vec[i];
	cout<<ans;
	return 0;
}
