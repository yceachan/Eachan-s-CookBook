#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans=0;


vector<int> op;
vector<int> num;
 string s;
void solve()
{
	
	
}
void dfs(int lvl)
{
	if(lvl>=op.size())
	{
		solve();
	}
	s[op[lvl]]='+';
	dfs(lvl);
	s[op[lvl]]='-';
	dfs(lvl);
	s[op[lvl]]='#';
	dfs(lvl);
}
int main()
{
   
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
    	if(s[i] == '?') op.push_back(i);
    	num.push_back(stoi(s.substr(i))); 
	}
	int ans=stoi(s.substr(s.find('=') +1));
	cout<< ans;
}

