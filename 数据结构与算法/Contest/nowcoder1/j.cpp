#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e2+5;

vector<int> Sand;
vector<int> Sor;
void print(vector<int>& vec) { for(auto it:vec) cout<<it<<" "; cout<<'\n'; }

void check(int a,int c)
{

    bool en=true;
    vector<int> vea,vec;

    for(int i=0;(1<<i)<=a;i++)
    {
        int bit=a&(1<<i);
        vea.push_back(bit?1:0);
    }
    for(int i=0;(1<<i)<=c;i++)
    {

        int bit=c&(1<<i);
        vec.push_back(bit?1:0);
    }
    int len=max(vea.size(),vec.size());
    vector<int> veband;
    std::function<void(int)>  adddfs;
    adddfs= [&](int i)
    {

        if(!en) return;
        if(i>=len)
        {
            int ans=0;
            for(int j=0;j<veband.size();j++) ans+=veband[j]<<j;
            Sand.push_back(ans);
            return;
        }

        int abit=i>=vea.size()?0:vea[i];
        int cbit=i>=vec.size()?0:vec[i];
        if(abit==0 && cbit==1) { en=false;return; }
        else if(abit==0 && cbit==0)
        {
        	
        	
            veband.push_back(1);
            adddfs(i+1);
            veband.pop_back();

            veband.push_back(0);
            adddfs(i+1);
            veband.pop_back();
        }
        else if(abit && cbit)
        {
            veband.push_back(1);
            adddfs(i+1);
            veband.pop_back();
        }
        else
        {
            veband.push_back(0);
            adddfs(i+1);
            veband.pop_back();
        }
    };
    adddfs(0);

    en=true;
    vector<int> vebor;
    std::function<void(int)> ordfs=[&](int i)
    {
        if(!en) return;
        if(i>=len)
        {
            int ans=0;
            for(int j=0;j<vebor.size();j++) ans+=vebor[j]<<j;
            Sor.push_back(ans);
            return;
        }
        int abit=i>=vea.size()?0:vea[i];
        int cbit=i>=vec.size()?0:vec[i];
        if(abit==1 && cbit==0) { en=false;return; }
        else if(abit==1 && cbit==1)
        {
            vebor.push_back(1);
            ordfs(i+1);
            vebor.pop_back();

            vebor.push_back(0);
            ordfs(i+1);
            vebor.pop_back();
        }
        else if(abit==0 && cbit==1)
        {
            vebor.push_back(1);
            ordfs(i+1);
            vebor.pop_back();
        }
        else
        {
            vebor.push_back(0);
            ordfs(i+1);
            vebor.pop_back();
        }
    };
    ordfs(0);
}
void solve(int a,int b,int c)
{
	Sand.resize(0,0);
    Sor.resize(0,0);
    check(a,c);
    cout<<"ac\n";
    cout<<"Sand:\t";
    print(Sand);
    cout<<"Sor:\t";
    print(Sor);
    cout<<"Sxor:\t"<<(a^c)<<"\n";
    
    bool orflag=1;
    bool addflag=1;
    int xorflag=0;
    
    if(!Sand.empty()) Sand.push_back(Sand[0]+(1<<30));
    
   		 for(auto it:Sor) if(find(Sand.begin(),Sand.end(),it)==Sand.end()) addflag=0;
   		 if(find(Sand.begin(),Sand.end(),a^c)==Sand.end()) addflag=0;
    
    	 
    	for(auto it:Sand) if(find(Sor.begin(),Sor.end(),it)==Sor.end()) orflag=0;
    	if(find(Sor.begin(),Sor.end(),a^c)==Sor.end()) orflag=0;  
    	
		if((Sand.empty() || ( Sand.size()==1 &&Sand[0]==a^c ) )  &&  (Sor.empty() || (Sor.size()==1 && Sor[0]==a^c))) xorflag=1;
    cout<<addflag;
	if(addflag ||(  orflag) || (xorflag)) cout<<1<<'\n';
	else
	{
	Sand.resize(0,0);
    Sor.resize(0,0);
	check(b,c);
	cout<<"\nbc\n";
    cout<<"Sand:\t";
    print(Sand);
    cout<<"Sor:\t";
    print(Sor);
    cout<<"Sxor:\t"<<(a^c)<<"\n";
    if(!Sand.empty()) Sand.push_back(Sand[0]+(1<<30));
		bool addflag=1;
   		for(auto it:Sor) if(find(Sand.begin(),Sand.end(),it)==Sand.end()) addflag=0;
   		if(find(Sand.begin(),Sand.end(),b^c)==Sand.end()) addflag=0;
    
    	bool orflag=1;
    	for(auto it:Sand) if(find(Sor.begin(),Sor.end(),it)==Sor.end()) orflag=0;
    	if(find(Sor.begin(),Sor.end(),b^c)==Sor.end()) orflag=0;
    
    	bool xorflag=0;
    	if((Sand.empty() || ( Sand.size()==1 &&Sand[0]==b^c ) )  &&  (Sor.empty() || (Sor.size()==1 && Sor[0]==b^c))) xorflag=1;
    	
    
    
		if(addflag || (orflag ) || (xorflag)) cout<<2<<'\n'; 
		else cout<<-1<<'\n'; 
	}
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

//    int T;cin>>T;
//    while(T--)
//    {	
//        int a,b,c;
//        cin>>a>>b>>c;      
//        solve(a,b,c);
//    }
	for(int a=0;a<=5;a++) for(int b=0;b<=5;b++) for(int c=0;c<=5;c++)
    {
    	if(a&b==c || a|b==c || a^b==c)
        {
        		std::cout<<a<<b<<c<<'\t';
    	solve(a,b,c);
		}
	}
   
    return 0;
}
