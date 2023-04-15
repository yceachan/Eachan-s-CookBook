//Õÿ∆À≈≈–Ú
#include<bits/stdc++.h>
using namespace std;

using ll=long long;

const int N=1e5+5;
const int K=1e9;
int n,k;


struct Item
{
	int pos, val;
	bool operator<(const Item& rhs) const { return val<rhs.val;}
}item[N];



int psum[N]={0};
int modsum[N]={0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
  	ll cnt=0;
  	int T;cin>>T;
  	for(int t=1;t<=T;t++)
  	{
  		int n;cin>>n;
  		for(int i=1;i<=n;i++) 
  		{
  			item[i].pos=i;
			  cin>>item[i].val;
		}
  		
  		sort(item+1,item+n+1);
  		
  		for(int i=1;i<=n;i++)
  		{
  			if(item[i].val==0) continue;
  			
  			int minn=max(0,min(item[item[i].pos-1].val +1 ,item[item[i].pos+1].val+1));
  			
  			if(minn>item[i].val) cnt+=item[i].val;
  			else cnt+=item[i].val-minn;
  			item[i].val=minn;
		}
		
		cout<<"Case "<<t<<'\n';
		if(cnt&1)
		{
			cout<<"Alice\n";
		}
		else cout<<"Bob\n";
	}
	
	return 0;
} 
