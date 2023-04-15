#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int x[N];

void solve()
{
	int n;
	cin>>n;
	int ixor=0;
	//统计每一bit，有多少个元素在此位为1 
	vector<int> vec(21);
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
		ixor^=x[i];
		int t=x[i];
		for(int j=0;t;j++,t>>=1)
		{
			vec[j]+=t&1;
		}
	}
	if(!ixor) 
	{
		cout<<0<<'\n';
		return;
	}
	//如何评价偶数个高位不影响结果？
	//对偶数个高位的博弈没什么意义，双方最终在此为积分相同，但这些的元素的选取是否破坏了低位的奇偶性质呢
	//显然只有当所影响的位为奇时才有讨论意义。
	//分两种情况，本来为奇的，为分配偶个
	//下面这套分析多少有点乱搞的感觉 
	for(int i=vec.size()-1;i>=0;i--)
	{
		//如果本位是偶数，在本位的情况是平局
		if(! (vec[i]&1) ) continue;
		
	   	//如果本位是奇数
	   	if(vec[i]==1) 	{  cout<<1<<'\n';   return;}
		if(vec[i]&1)
		{
			//有奇数个x元素，选到奇个x元素得玩家可以在本位得1，只有1个玩家能选到奇个x元素，对x元素得博弈可分胜负，，特别的，若vec[i]==1,先手必胜
			
			//对偶数个n-x元素或偶数个x元素的博弈是无意义的，双方轮流选取偶数次这些元素，情势没有发生任何变化。
			
			//先手先选1次x元素后，在本位积1，余偶个x元素，若只有x元素先手必胜。
			
			//后手必要选1次x元素，在本位积1，余奇个x元素，奇x情势的博弈结果是先手胜。
			 
			//然后开始对n-x元素的博弈，偶n-x的博弈是无意义的，情势并没有变化
			
			//若n-x为奇  情况是先手取走最后一个n-x，后手获得先取奇x堆的机会，暨，n-x元素的意义是交换先后手
			//在x为奇下，若n-x为奇，后手胜，反之，先手胜 
			
			//3目巨坑hah 
			cout<< ((n&1)?1:-1)<<'\n';
			return;
			
		} 
	}
	//全偶平局
	cout<<0<<'\n'; 
	
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}
