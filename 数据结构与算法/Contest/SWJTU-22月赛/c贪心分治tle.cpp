#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,a[N];

int solve_m(int l,int r)
{
	int ans=0;
	int top=min(a[l],a[r]);
    for(int i=l;i<=r;i++)  if(top-a[i] >0 )ans+=top-a[i];
    return ans;
}
int solve_l(int r)
{ 
    if(r==0) return 0;
    int l=0;
    for(int i=1;i<r;i++) { l=a[l]>a[i]?l:i;	}
    
    return solve_l(l) + solve_m(l,r);
}
int solve_r(int l)
{
	if(l==n-1) return 0;
	int r=l+1;
	for(int i=r+1;i<n;i++)  r=a[r]>a[i] ? r:i;
	return solve_r(r)+solve_m(l,r);
} 
int main()
{
	int ans=0;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	
	int l=0,r=0;
	for(int i=1;i<n;i++) l=a[l]>a[i]?l:i;
	
	for(int i=1;i<n;i++) {if(i==l) continue; r=a[r]>a[i]?r:i;}
	if(l>r) swap(l,r);
	
	ans=solve_l(l)+solve_m(l,r)+solve_r(r);
	
	cout<<ans;
}
