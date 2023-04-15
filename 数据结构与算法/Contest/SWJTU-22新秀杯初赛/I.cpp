#include<bits/stdc++.h>
using namespace std;

int au1,ag1,cu1,au2,ag2,cu2; 
string xat,swt;
char Upper[26];
int len=0;
int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>au1>>ag1>>cu1>>au2>>ag2>>cu2;
    cin>>xat>>swt;
    
    
    int cnt=0,nau=0,nag=0,ncu=0;
    int au=0,ag=0,cu=0;
    int oau=0,oag=0,ocu=0;
    for(int i=0;i<xat.size();i++)
    {
    	//仙交摸到稀胶 
        if(xat[i]>='a' && xat[i]<='z')
        {
        	 cnt++;
        	 //稀胶自己打，o 
        	 if(xat[i]-'a'<=au2) oau++;
			 else if(xat[i]-'a'+1>au2 && xat[i]-'a'+1<=au2+ag2) oag++;
		         else if(cnt<=au2+ag2+cu2)ocu++; 
		         
		    //仙交代打 ，n 
            if(cnt<=au1) nau++;
		    else if(cnt>au1 && cnt<=au1+ag1) nag++;
		         else if(cnt<=au1+ag1+cu1) ncu++; 
		}
		
	}
//	for(int i=0;i<swt.size();i++)
//	{
//		if(swt[i]>='a' && swt[i]<='z')
//		{
//			//稀胶自己打， 
//			if(swt[i]-'A'<=au2) au++;
//			else if(swt[i]-'A'>au2 && swt[i]-'A'<=au2+ag2) ag++;
//		         else cu++; 
//		}
//	}
//	cout<<nau<<" "<< nag<<" "<< ncu<<" "<<oau<<" "<<oag<<" "<<ocu<<'\n';
	if(nau>oau || nag>oag || ncu>ocu) cout<<"Yeah!";
	else cout<<"No!";
	
	
	return 0;
}
