#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=2e5+5;
int a[N],b[N];
int n,m;
const double er = 1e-4;

double c[N];
struct node
{
	double val;
	int id;
	
};
bool cmp(const node& lhs,const node& rhs)
{
  return lhs.val<rhs.val;
}
double suma=0,sumb=0;
void binary (double l,double r)
{
	vector<node> c(n);
    //左闭右闭搜搜
    while(r-l>er)
    {
        double p=(l+r)/2;
   //     cout<<p<<" ";
        //ap-b的意义：这套房子对倍率p的贡献，ap-b>0说明这套房子的倍率小于p，反之大于p 
		//故优先选取ap-b低的房子，若组合出的sum>=0,说明倍率p难以达成，ans<=p 
		//反之倍率p可达成，向右搜索更有参考意义的p
		//ans是小于二分答案p的最大值 
        for(int i=0;i<n;i++)
        {
        	c[i].val=a[i]*p-b[i];
        	c[i].id=i;
  //      	cout<<c[i].val<<" ";
		}
  
		sort(c.begin(),c.end(),cmp);
  
 		double sum=0;
 		for(int i=0;i<m;i++) sum+=c[i].val;
 		
 //		cout<<sum<<" ";
  		if(sum>=0)
  		{
  			suma=0,sumb=0;
  			for(int i=0;i<m;i++) suma+=a[c[i].id],sumb+=b[c[i].id];
  			r=p;
		}
		else
		{
			l=p;
		}
	//	cout<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    binary(1,3+er);
    printf("%.4f",sumb/suma);
    return 0;
}
