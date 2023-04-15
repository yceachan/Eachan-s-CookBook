#include<bits/stdc++.h>
//P1238 走迷宫
int n, m;
int map[16][16];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
bool visit[16][16] = { false };
class pt {
public:
    int x, y;
    pt(int xx = 0, int yy = 0) :x(xx), y(yy) {}
};
int xb, yb, xe, ye;
std::vector<pt> vec;
int cnt = 0;
void print(std::vector<pt>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("(%d,%d)", vec[i].x, vec[i].y);
        if (i != vec.size() - 1) printf("->");
    }
    printf("\n");
}

void dfs(int x, int y)
{
    
    vec.push_back(pt(x,y));
    visit[x][y] = true;
    if (x == xe  && y == ye )
    {
        print(vec);
        cnt = 1;     
        return;
    }
   
    for (int i = 0; i < 4; i++)
    {
        int xc = x + dx[i];
        int yc = y + dy[i];
        if (map[xc][yc] && !visit[xc][yc] && xc>0 && yc>0 && xc <= m && yc <= n)
        {
            dfs(xc, yc);
            //要用for来枚举dfs因为回溯紧密接于试探,尤其注意回溯visit标记
            visit[xc][yc] = false;
            vec.pop_back();
        }
   
    }
    
    
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &(map[i][j]));
    scanf("%d%d%d%d", &xb, &yb, &xe, &ye);
    dfs(xb,yb);
    if (!cnt) printf("-1");
    return 0;
}