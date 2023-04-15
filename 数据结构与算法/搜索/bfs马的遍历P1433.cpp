//bfs
#include<queue>
#include<iostream>
using namespace std;
int pace[401][401]={0};
bool vis[401][401]={false};
const int dx[8] = {2,2,1,1,-2,-2,-1,-1};
const int dy[8] = {1,-1,2,-2,1,-1,2,-2};
int main()
{
	int n, m, _x, _y;
	std::cin >> n >> m >> _x >> _y;
	queue<pair<int, int>> que;
	que.push(pair<int, int>(_x,_y));
	vis[_x][_y] = true;
	//一圈while是一步，pace通过数组逐级构造
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			pace[i][j] = -1;
	pace[_x][_y] = 0;
	while (!que.empty())
	{
		pair<int, int> xy = que.front();
		que.pop();
		for (int i = 0; i < 8; i++)
		{
			int x = xy.first + dx[i];
			int y = xy.second + dy[i];
			if (vis[x][y] || x<1 || x>n || y<1 || y>m) continue;
			pace[x][y] = pace[x - dx[i]][y - dy[i]]+1;
			//visit剪枝，且先访问的pace一定小
			vis[x][y] = true;
			que.push(pair<int, int>(x, y));
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << pace[i][j] << " ";
		}
		cout << endl;
	}
}