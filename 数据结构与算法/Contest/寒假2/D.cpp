#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int N=1e5+5;
int n;
double a[N];
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	double sum=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	sum+=a[i];
	}
	double k=sum/(n+1);
    printf("%f ",2*k);
    for(int i=2;i<=n;i++) printf("%f ",k);
//    puts("");
//    double last=-1;
//    while(1)
//    {
//    
//    	for(int i=1;i<n;i++)
//    	{
//    		a[i]/=2;
//    		a[i+1]+=a[i];
//		}
//		a[n]/=2;
//		a[1]+=a[n];
//		if(last==a[1]) 
//		{
//			for(int i=1;i<=n;i++)printf("%f ",a[i]);
//			return 0;
//		}
//		last=a[1];
//		
//	}
	return 0;
 } 
