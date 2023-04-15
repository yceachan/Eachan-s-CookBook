#include<bits/stdc++.h>
using namespace std;
string s;
int ans=0;

int main()
{
	cin>>s;
	
    for(int i=0;i<s.size();i++)
    {
    	if(s[i]=='(')
    	{
    	   int ls=0,rs=0;
    	    for(int j=i;j<s.size();j++)
    	    {
    	    	if(s[j]=='(') ls++;
    	    	else rs++;
				if(ls==rs)
    	    	{
    	    	    ans=max(ans,j-i+1);
				}
				if(rs>ls) 
				{
					i=j-1;
					break;
				}
			}
		}
	}
	cout<<ans;
    
	return 0;
}
