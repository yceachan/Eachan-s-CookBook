#include<iostream>
#include<stdlib.h>
using namespace std;
const int N=5005,M=100005;
typedef long long ll;
int n,m;
ll ans=0;
int mey;

int* del[N];
ll* a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<=n+1;i++)
    {
        del[i]=(int*)malloc(sizeof(int)*(n+2));
        for(int j=0;j<=n+1;j++) del[i][j]=0;
    }
    while(m--)
    {
        int a,b,c,d,h;
        cin>>a>>b>>c>>d>>h;
        del[a][b]+=h;
        del[c+1][b]-=h;

        del[a][d+1]-=h;
        del[c+1][d+1]+=h;
    }
    //不懂，原地求前缀和吧 
    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            del[i][j]+=del[i-1][j];
            //		cout<<del[i][j]<<" ";
        }
        //	cout<<'\n';
    }
//	cout<<'\n';
    for(int i=1;i<=n;i++)
    {
        a[i]=(ll*)malloc(sizeof(ll)*(n+1));
        a[i][0]=0;
        for(int j=1;j<=n;j++)
        {
            a[i][j]=a[i][j-1]+del[i][j];
            //		cout<<a[i][j]<<" ";
        }
        free(del[i]);
        //	cout<<'\n';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            if(a[i][j]>ans)
            {
                ans=a[i][j];
                mey=0;
            }
            if(a[i][j]==ans) mey++;
        }
        free(a[i]);
    }
    cout<<ans<<" "<<mey;
    return 0;
}
