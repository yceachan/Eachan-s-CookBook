#include <bits/stdc++.h>
 
using i64 = long long;
 
void solve( int a,int b,int c) {
   
     
    int ans;
    if (a == 0) {
        ans = 1;
    } else if ((a & c) != c) {
        ans = 1;
    } else if (b == 0) {
        ans = 2;
    } else if (b != c && c != 0) {
        ans = 2;
    } else if (b == c) {
        ans = 2;
    } else {
        ans = -1;
    }
     
    std::cout << ans << "\n";
}
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
     
    int t;
    for(int a=0;a<=6;a++) for(int b=0;b<=6;b++) for(int c=0;c<=6;c++)
    {
    	if(((a&b)==c )|| ((a|b)==c) || ( (a^b)==c))
        {
        		std::cout<<a<<b<<c<<'\t';
    	solve(a,b,c);
		}
	}
    return 0;
}
