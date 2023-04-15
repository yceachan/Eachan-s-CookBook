#include<iostream>
#include<vector>
//������
namespace Qpow {
	/*&��λ�룬����Ϊ�棻 | ��λ��������Ϊ�棻 ^ ��λ������ͬ������
	*����if���İ�λ�������ǶԶ����ƽ��а�λ���������ж�����λģʽ�Ƿ�Ϊ�棬����x & 1������ż��
	*��λ��������>>���ƣ�<<����
	*/
	typedef long long ll;
	const int mod = 1e9 + 5;
	ll qpow(ll x, ll y)
	{
		ll ans = 1;
		while (y)
		{
			if (y & 1) ans = ans * x % mod;
			x = x * x % mod;
			y >>=1;	
		}
		return ans;
	}
	
	//��չ������������������
	const int N = 105;
	struct Mat {
		int num[N + 1][N + 1];

		Mat(const char* a = "")
		{
			for (int i = 1; i <= N; i++)
			{
				memset(num[i], 0, sizeof(num[i])); if (a == "e")num[i][i] = 1;
			}
		};
	};
	Mat  operator*(Mat& lhs,Mat& rhs) 
	{
		Mat ans;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				for (int k = 1; k <= N; k++)
					ans.num[i][j] = (ans.num[i][j] + lhs.num[i][k] * rhs.num[k][j]) % mod;
		return ans;
	}
	Mat qpow(Mat x, ll y) {
		Mat ans("e");
		while (y)
		{
			if (y & 1) ans = ans * x;
			x = x * x;
			y >>=1;
		}
		return ans;
	}
}

//ŷ��ɸ������
namespace Prime {
	typedef long long ll;
	const int N = 1e8 + 5;
	int prime[N] = { 0 };
	bool vis[N] = { false };
	int cnt = 0;
	void Getprime()
	{
		//�㷨���ģ�ÿ������ֻ�ᱻ��С������ɸ��
		int n; scanf("%d %d", &n);
		for (int i = 2; i <= n; i++)
		{
			//ö�ٵ�iǰһ����ɸ��i�Ƿ�Ϊ����
			if (!vis[i]) prime[cnt++] = i;
			for (int j = 0; j < cnt && i * prime[j] <= n; j++)//������i��Ϊ����
			{
				vis[i * prime[j]] = 1;
				//����i=bp1,,p1��������С����������b=cp2 ��p2<=p1
				//���ں�������p3,p2<=p1<p3
				// ����n=bp1p2p3�ǲ���ͨ��p3ɸ���ģ���Ϊ���˺�ö�ٵ�ĳ��i=bp1p3ͨ����С������p2ɸȥ��
				if (i % prime[j] == 0)break;
			}
		}
	}
}

namespace Ruler {
	using namespace Prime;
	//ǰ�����Ѵ�����prime����
	int Phi(int x)
	{
		if (x == 1) return 1;
		for (int i = 0; i < cnt; i++)
		{
			if (x == prime[i]) return x - 1;
			int k = x % prime[i];
			if (!k)
			{
				int P = x / prime[i];
				//��,����2������ʽ�У�����һ��p1
				if (P % prime[i] == 0)  return prime[i] * Phi(P);
				//�߻��Էֽ�
				else               return (prime[i] - 1) * Phi(x / prime[i]);
			}
		}
	}
	int phi[N]={0};
	void phis()
	{
		//get_prime();
		phi[1] = 1;
		for (int i = 2; i <= N; i++)
		{
			if (!vis[i])
			{
				prime[cnt++] = i;
				phi[i] = i - 1;
			}
			for (int j = 0; j < cnt && prime[j] * i <= N; j++)
			{
				vis[prime[j] * i] = 1;
				if (i % prime[j] == 0)
				{
					phi[i * prime[j]] = prime[j] * phi[i];
					break;
				}
				else phi[i * prime[j]] = (prime[j] - 1) * phi[i];
			}
		}
		for (int i = 1; i <= 100; i++) printf("%d ", phi[i]);
	}
}