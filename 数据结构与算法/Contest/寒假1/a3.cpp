#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;
ll X=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	map<int,map<int,pair<int,int>>> mey;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];  
			mey[a[i][j]][i].first++;
			mey[a[i][j]][j].second++;
		} 
	}
	
	//O(nnmlognn)
    for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
		//	cout<<a[i][j]<<" "<<row[a[i][j]][i]<<'\n';
			for(int k=0;k<i;k++) X+=(i-k)*mey[a[i][j]][k].first;
		} 
	}
	
    for(int j=1;j<m;j++)
    {
    	for(int i=0;i<n;i++)
    	{
    	//	cout<<a[i][j]<<" "<<col[a[i][j]][j]<<'\n';
    		for(int k=0;k<j;k++) X+=(j-k)*mey[a[i][j]][k].second;
		}
	}
    cout<<X;
    
    return 0;
}
