#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int n;cin>>n;
	if(n<4 || n==7) cout<<0;
	else
	{
		//3412
		//34512
		//456123
		//将n拆成 k*4+l,l∈[4,5,6];
		
		int k=n/4,l=n%4;
	    if(l)
	    {
	    	k--;l+=4; 
	 	   if(l==7)
	    	{
	    		k--;
	    		l+=4;
			}
		}
		//4k+5  =4k+1 ,4k+6 =4k+2,4k+11=4k+3  就覆盖了所有情况，终点是4k+11
		for(int i=0;i<k;i++)
		{
			int pos=4*i;
			cout<<pos+3<<" "<<pos+4<<" "<<pos+1<<" "<<pos+2<<" ";
		} 
		if(l==5)
		{
			cout<<n-2<<" "<<n-1<<" "<<n<<" "<<n-4<<" "<<n-3;
		}
		else if(l==6)
		{
			cout<<n-2<<" "<<n-1<<" "<<n<<" "<<n-5<<" "<<n-4<<" "<<n-3;
		}
		else if(l==11)
		{
			cout<<n-2-6<<" "<<n-6-1<<" "<<n-6<<" "<<n-6-4<<" "<<n-6-3<<" ";
			cout<<n-2<<" "<<n-1<<" "<<n<<" "<<n-5<<" "<<n-4<<" "<<n-3;
		}
	}
}
