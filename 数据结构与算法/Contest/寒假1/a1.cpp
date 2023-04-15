#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;
class Pair
{
	public:
	Pair(int x,int y) : x(x),y(y){} 
	int x,y;
};
map<int,vector<Pair>> mey;
map<int,int> cnt;
ll X=0;
int maxn=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vector<vector<int>> a(n,vector<int>(m,0));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			maxn=max(a[i][j],maxn);
			cnt[a[i][j]]++;
		} 
	}
	for(int i=1;i<=maxn;i++) mey[i].reserve(cnt[i]);
	
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			mey[a[i][j]].push_back(Pair(i,j));
		} 
	}	
	//O(count*per^2),O() 这个策略在元素种类较多时高效,在元=元素种类较重复时低效 
    for(int i=1;i<=maxn;i++)
	{
		auto &vec=mey[i];
		for(int i=0;i<vec.size()-1;i++) //到这里是o1e5 
		{
			for(int j=i+1;j<vec.size();j++)
			{
				X+=abs(vec[j].x-vec[i].x) +abs(vec[j].y-vec[i].y);
			}
		}
	}
	cout<<X;
    return 0;
}
