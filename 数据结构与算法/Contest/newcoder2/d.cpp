#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll ans=0;

//����û��ż������
//�������õ�ż������Զѡ���1�������������ִ�������ֻ�ܼ���ż�����վ�������2-1�����ִ���1 
//��֮�����ִ���������ֻҪ���� 
//��������������Զ��������ż��
//����ż��������Զѡ��-1 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	
   	long long n; cin >> n;
    if(!(n&1)) cout<<"kou";
    else cout<<"yukari";
	return 0;
}

