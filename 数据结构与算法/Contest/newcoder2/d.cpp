#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans=0;

//奇数没有偶数因子
//若先手拿到偶数，永远选择减1，把奇数给对手处理，对手只能减成偶数，终局是先手2-1，后手处理1 
//反之若先手处理奇数，只要不是 
//处理奇数的人永远会把它变成偶数
//处理偶数的人永远选择-1 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	
   	long long n; cin >> n;
    if(!(n&1)) cout<<"kou";
    else cout<<"yukari";
	return 0;
}

