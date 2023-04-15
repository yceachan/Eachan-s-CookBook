#include<bits/stdc++.h>
using namespace std;
const int N=100+5;
int w[N];
int n;
int cnt=0;
map<int,bool> vis;
vector<int> vec;
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>w[i];
    
    vec.push_back(0);
    vec.push_back(w[1]);
    vis[w[1]]=1;
    for(int i=2;i<=n;i++)
    {
    	int len=vec.size();
    	for(int j=0;j<len;j++)
    	{
    		int lp=abs(vec[j]-w[i]);
    		int rp=abs(vec[j]+w[i]);
    		if(!vis[lp] && lp)
			{
				vis[lp]=1;
				vec.push_back(lp);
			} 
			if(!vis[rp] && rp) 
			{
				vis[rp]=1;
				vec.push_back(rp);
			}
			
		}
	}
//	for(int i=0;i<vec.size();i++)
//	{
//		cout<<vec[i]<<" ";
//	}
    cout<<vec.size()-1;
	return 0;
}
