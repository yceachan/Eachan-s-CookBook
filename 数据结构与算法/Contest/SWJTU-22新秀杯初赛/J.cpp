#include<bits/stdc++.h>
using namespace std;
map<string,char> F;
int T; 
string rct[3]={"Swirl","Electro-Charged","hehe"};
void solve(string op)
{
	bool flag=1;
	char state='0';
	if(op[0]!='2') state=op[0];
	for(int i=1;i<op.size();i++)
	{
	//	cout<<"ops:"<<state<<' '<<op[i]<<"\n";
	    
	    if(state!='0') 
	    {
	       	//扩散后没有元素 
	       if(op[i]=='2' && (state=='1' || state=='3')) 
		    {
		    	cout<<rct[0]<<' ';
			    flag=0;
			    state='0';
	    	}
		    //感电还有元素 
		    if((op[i]=='3' && state=='1') || (op[i]=='1' && state=='3'))  
		    {
				cout<<rct[1]<<" ";flag=0;
				//state='0';
		    }
			if(op[i]!='2' && state!='0') state=op[i];
			//cout<<"newstate:"<<state<<"\n";	
		}
		else if(op[i]!='2') state=op[i];
	
	}
	if(flag) cout<<rct[2];
}
int main()
{
    
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	F["Bongo-Head"]='1';
	F["Twirly-Whirly"]='2';
	F["Blitzara"]='3';
	cin>>T;
	while(T--)
	{
		string a[4],op;cin>>a[1]>>a[2]>>a[3]>>op;
		for(int i=0;i<op.size();i++)
		{
			op[i]=F[a[op[i]-'0']];
		}
	//	cout<<"op："<<op<<'\n';
		solve(op);cout<<'\n';
	}
    
	return 0;
}
