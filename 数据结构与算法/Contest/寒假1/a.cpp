#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;

map<int,vector<int>> col;
map<int,vector<int>> row;
ll X=0;
int cnt=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	int maxn=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		    maxn=max(maxn,a[i][j]); 
		} 
	}

	for(int i=0;i<n;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(row.find(a[i][j])==row.end()) row[a[i][j]]=vector<int>(n,0);
    		if(col.find(a[i][j])==col.end()) col[a[i][j]]=vector<int>(m,0);
    		auto &ver=row[a[i][j]];
		    ver[i]++; 
		    auto &vec=col[a[i][j]];
		    vec[j]++;	   
		}
		a[i].clear();
		a[i].shrink_to_fit();
	}
	//xy轴离散化。复杂度：（O(count*(n^2+m^2))）  其中 
	for(int i=1;i<=maxn;i++)
	{
		if(row.find(i)==row.end() || col.find(i)==col.end()) continue;
		auto &ver=row[i];
		auto &vec=col[i];
	    
	    
	    for(int j=0;j<ver.size()-1;j++)  //到这里是O 
	    {
	    	for(int k=j+1;k<ver.size();k++) 
	    	{
	    		X+=ver[j]*ver[k]*(k-j);
			}
		}
		row[i].clear();
		row[i].shrink_to_fit();
		for(int j=0;j<vec.size()-1;j++)
	    {
	    	for(int k=j+1;k<vec.size();k++) 
	    	{
	    		X+=vec[j]*vec[k]*(k-j);
	    	//	cnt++;
			}
		}
		
		col[i].clear();
		col[i].shrink_to_fit();
//	    cout<<i<<'\n';
//	    for(auto it:ver) cout<<it<<" ";  cout<<'\n';
//	    for(auto jt:vec) cout<<jt<<" ";  cout<<'\n';
//	    cout<<'\n';
	}
	cout<<X;//<<cnt;
	
    return 0;
}
