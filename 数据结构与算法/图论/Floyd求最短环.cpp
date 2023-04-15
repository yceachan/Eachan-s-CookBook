#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5,M=5e3+5;
const int inf=0x3f3f3f3f;
long long f[N][N]={0};
long long dis[N][N]={0};
int n,m;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) dis[i][j]=f[i][j]=inf;
    for(int i=1;i<=n;i++)     dis[i][i]=f[i][i]=0;

    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = dis[v][u] = f[u][v] = f[v][u] = f[u][v]
                  = min(f[u][v],w);
    }
    long long ans=inf;

    for(int k=1;k<=n;k++)
    {
        /*在构造floyd的过程中求环：在构造过程中，f[i][j]是讨论不途径k结点时的ij最短路
        * 故可讨论[1:k-1]区域两点的最短路，组合dis[j][k] +dis[k][i]成环。
        */
        for(int i=1;i<k;i++)
            for(int j=i+1;j<k;j++){

                ans=min(ans , f[i][j] +dis[j][k] +dis[k][i] );

            }

        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++){

                f[j][i]=f[i][j]=min(f[i][j],f[i][k] +f[k][j]);

            }
    }

//    for(int i=1;i<=n;i++)
//    {
//
//        for(int j=1;j<=n;j++) cout<<f[i][j]<<" ";
//        cout<<'\n';
//    }

    if(ans >=inf) std::cout<<"No solution.";
    else std::cout<<ans;
    return 0;
}