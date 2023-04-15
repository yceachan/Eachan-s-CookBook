#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e2+5;


void dfs(int x,int y,int a,int b)
{
	double iou=0;
	//рт(a,b)н╙сроб╫г
	for(int i=0;b+i<=y && a-i>=0;i++)
	{
		//(0,0,x,y),(a-i,b,a,b+i)
		int w=min(a,x)-max(a-i,0);
		int h=min(b+i,y)-max(b,0);
	    double area=w*h;
	    iou=area/()
		
	} 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
    int T;w=cin>>T;
    while(T--)
    {
    	int x,y,a,b;
		cin>>x>>y>>a>>b;
		dfs(x,y,a,b); 
	}
}
