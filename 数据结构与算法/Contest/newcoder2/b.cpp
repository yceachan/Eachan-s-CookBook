#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool check(ll ans,ll n)
{
	return n>= ans + (ans - (n/2 + (n&1))) + (ans - (n/2 + ( n&1))); //&& n<= ans + (ans - (n/2 + (n&1))) + (ans - (n/2 + (n&1)))*(ans - (n/2 + (n&1)));Ϊʲô�����ж��ҽ��أ���Ϊ���Դ������ط��ۣ�����n����ô��������и��Ž� 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    int T;cin>>T;
    while ( T-- )
    {
    	ll n; cin>>n;
    	if(n==2) 
    	{
    		cout<<-1<<'\n';
    		continue;
		}
    	//��ȡ�� 
    	ll l=n/2 + (n&1),r=n;
    	
    	while(l < r)
    	{
    		ll mid=(l+r + 1)>>1;
    		if(check(mid,n)) l=mid;
    		else r=mid-1;
		}
	    
	     cout<<l<<'\n';
	}
	return 0;
}
