#include<iostream>
#include<algorithm> 
#include<map>
using namespace std;
#define ll long long
const int N=1e3+5;

int prime[N];
bool vis[N];
int phi[N]; 
int cnt=0;
void phis()
{
    phi[1]=1;
    for(int i=2;i<=N;i++)
    {
    	if(!vis[i])
    	{
    		prime[cnt++]=i;
    		phi[i]=i-1;
		}
		for(int j=0;j<cnt && i*prime[j]<=N;j++)
		{
			vis[prime[j]*i]=1;
			if(i%prime[j]==0)
			{
				phi[i*prime[j]]=prime[j] * phi[i];
				break;
			}
			else phi[i*prime[j]]=(prime[j] -1 ) *phi[i]; 
		}
	}
}

void solve(int n)
{
	ll ans=0;
	for(int i=2;i<=n;i++) ans+=phi[i];
	ans=ans*2+3;
	cout<<ans<<"\n";
}
	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    phis();
	
	int T;cin>>T;
	for(int i=1;i<=T;i++)
	{
		int n;cin>>n;
		cout<<i<<" "<<n<<" ";
		solve(n);
	}
	return 0;
 } 
