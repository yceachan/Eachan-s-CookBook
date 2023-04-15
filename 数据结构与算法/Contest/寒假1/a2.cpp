#include<bits/stdc++.h>
using namespace std;
using ll=unsigned long long;
int n,m;
const int N=1e5+5;
class Pair
{
	public:
	Pair(int x,int y) : x(x),y(y){} 
	int x,y;
};
map<int,vector<Pair>> mey;
ll X=0;
int cnt[N];
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
			maxn=max(a[i][j],maxn);
			cnt[a[i][j]]++;
		} 
	}
	for(int i=1;i<=maxn;i++) mey[i].reserve(cnt[i]);
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			
			for(auto it:mey[a[i][j]])
			{
				X+=abs(i-it.x)+abs(j-it.y);
			}
			mey[a[i][j]].push_back(Pair(i,j));
		}
	}
	cout<<X;
	
    return 0;
}
