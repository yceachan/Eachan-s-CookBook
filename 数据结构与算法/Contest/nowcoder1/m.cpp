#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e2+5;

double ans=0;
vector<int> path,mey;
void print(vector<int>& path){ for(auto it:path) cout<<it<<" ";}
void dfs(double n,int m,double sum)
{
	if(n==0 || m==0) 
	{
//		print();
//		cout<<"\t\tsum:"<<sum<<'\n';
	    if(ans<sum)
	    {
	    	ans=sum;
	        mey.assign(path.begin(),path.end());
		}
	    return;
	}
	for(int i=n;i>=1;i--)
	{
		path.push_back(i);
		dfs(n-i,m-1,sum+i/n);
		path.pop_back();
	}
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
    
    	ans=0;
    	cout<<i<<":\t";
		dfs(n,i,0);
    	print(mey);
    	cout<<"\t\t"<<ans<<'\n';	
	}
    cout<<ans;
    return 0;
}
