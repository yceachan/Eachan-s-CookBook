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
    //����ұ�����
    while(r-l>er)
    {
        double p=(l+r)/2;
   //     cout<<p<<" ";
        //ap-b�����壺���׷��ӶԱ���p�Ĺ��ף�ap-b>0˵�����׷��ӵı���С��p����֮����p 
		//������ѡȡap-b�͵ķ��ӣ�����ϳ���sum>=0,˵������p���Դ�ɣ�ans<=p 
		//��֮����p�ɴ�ɣ������������вο������p
		//ans��С�ڶ��ִ�p�����ֵ 
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
