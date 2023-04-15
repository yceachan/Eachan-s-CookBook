#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 45;
int n, m;
int a[N];
ll lhs[ (1 << 20) + 5], rhs[(1 << 20) + 5];
map<ll, ll> mapl, mapr;
int lenl = 0, lenr = 0;
void dfsl(ll atk, int lo, int hi)
{

	if (lo == hi)
	{
		return;
	}

	for (int i = lo + 1; i <= hi; i++)
	{
		lhs[lenl++] = atk + a[i];
		mapl[atk + a[i]]++;
		dfsl(atk + a[i], i, hi);
	}
}
void dfsr(ll atk, int lo, int hi)
{

	if (lo == hi)
	{
		return;
	}

	for (int i = lo + 1; i <= hi; i++)
	{
		rhs[lenr++] = atk + a[i];
		mapr[atk + a[i]]++;
		dfsr(atk + a[i], i, hi);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n / 2; i++)
	{
		lhs[lenl++] = a[i];
		mapl[a[i]]++;
		dfsl(a[i], i, n / 2);
	}
	for (int i = n / 2 + 1; i <= n; i++)
	{
		rhs[lenr++] = a[i];
		mapr[a[i]]++;
		dfsr(a[i], i, n);
	}

	for (int k = 0; k < m; k++)
	{
		ll hp;
		cin >> hp;
		ll ans = 0;
		for (int i = 0; i < lenl; i++)
		{
			if (lhs[i] == hp) ans++;
			else
				ans += mapr[hp - lhs[i]];
		}
		for (int j = 0; j < lenr; j++)
		{
			if (rhs[j] == hp) ans++;
		}
		if (hp == 0) ans++;
		cout << ans << '\n';
	}
	return 0;
}
