#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans=0;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	
   	ll xa,ya,xb,yb;
	cin>>xa>>ya>>xb>>yb;
    
    //特判平行坐标轴 
    if(ya == yb)
    {
    	double xd=(xa+xb)/2;
    	if(xd - int(xd) <1e-7)  //整点判定 
    	{
    	    cout<<int(xd)   << " " << ya + abs( xb- int(xd) );
		}
		else cout<<"No Answer!";
	}
	else if(xb == xa)
	{
		double yd=(ya+yb)/2;
    	if(yd - int(yd) <1e-7)  //整点判定 
    	{
    	    cout<<int(yd)   << " " << xa + abs( yb- int(yd) );
		}
		else cout<<"No Answer!";
	}
	else
	{
		double kd  = -1 / ((yb-ya)/double(xb-xa)); 
		double len = (xb-xa)*(xb-xa) + (yb-ya)*(yb-ya);
		double xd=(xa+xb)/2.0,yd=(ya+yb)/2.0;
		
		double pace=sqrt((len/4)/(1+kd*kd));
		
		double xc=xd+pace;
		double yc=yd + kd*pace; 
	//	cout<<kd<<" "<<len<<" "<<pace<<" "<<xc<<" "<<yc<<" ";
		if(xc - int(xc) <1e-7  &&  yc - int(yc) < 1e-7 )
		{
			cout<<int(xc)<<" "<<int(yc);
		}  
		else cout<<"No Answer!";
	}
	return 0;
}

