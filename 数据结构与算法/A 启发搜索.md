# A* 启发搜索

在结点图中，快速搜索最优路径的算法。

需要设计：

起点终点。

启发函数$F(x)=g(x)+h(x)$：搜索依据

代价函数$g(x)$:起点到此点的代价  。作用:保证最短路的可行性

预估函数$h(x)$:此点到终点(目标状态)的预估代价 。作用：优化搜索方向，加快搜索

**1、h(x) >= 0 ； 2、h(x)越小表示 x 越接近目标状态； 3、如果 h(x) ==0 ，说明达到目标状态。4、h(x)<=h\*(x),h\*(x)为实际代价**（你预想的距离一定是比实际距离短，或者刚好等于实际距离的值。这样我们称你的 h(x) **是可纳的，是乐观的。**）

A*常用在游戏寻路中，常见的预估函数可取：曼哈顿距离，欧几里得距离。



当 **F(x) = g(x)** 的时候就是一个等代价搜索，完全是按照花了多少代价去搜索。比如 bfs，我们每次都是从离得近的层开始搜索，一层一层搜 ；以及dijkstra算法，也是依据每条边的代价开始选择搜索方向。 当h=0时，退化为dijk算法

当**F(x) = h(x)** 的时候就相当于一个贪婪优先搜索。每次都是向最靠近目标的状态靠近。(h不可纳时不一定有解)



算法流程：（dijk）

​    维护一个键为F的优先队列open表

​       pop出队首，遍历邻点 ，vis剪枝

​       relax，push



此过程中若搜索到终点，搜索完成。

反之，队列为空后，无解。

# 样例程序：迷宫寻路

初始化一个N*N的有若干障碍的迷宫，打印出从起点到终点的最短路径。

路径存储方法：递归path。

~~~cpp
#include<queue>
#include<string.h>
#include<iostream>


const int inf=0x3f3f3f3f;
const int N=6;
int map[N][N];
bool vis[N][N];//close_set
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};


struct node{
    int x,y,f,g,h;//u节点从起点的距离，作g
    node(int x,int y,int f,int g=inf,int h=0) :x(x),y(y),f(f),g(g),h(h) {}
    bool operator< (const node& rhs) const { return f<rhs.f;}
};

std::pair<int,int> path[N][N];

void init()
{
    srand(time(NULL));
    memset(map,0,sizeof(map));

    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)  path[i][j]= std::pair<int,int>(-1,-1);

    memset(vis,0,sizeof(vis));
    for(int i=1;i<=7;i++)
    {
        int x=rand()%N,y=rand()%N;
        if((x==0 && y==0) || (x==N-1 && y==N-1) ) continue;
        map[x][y]=1;
    }
}

//递归路径
void print(int i,int j)
{
    if(i==0 && j==0) {printf("(%d,%d)->",i,j);return;}
    print(path[i][j].first,path[i][j].second);
    printf("(%d,%d)->",i,j);
}


void asearch()
{
    std:: priority_queue<node> pq;
    pq.push(node(0,0,0+N-1+N-1,0,N-1+N-1));

    while(!pq.empty())
    {
        node u=pq.top(); pq.pop();

        for(int i=1;i<=4;i++)
        {
            int x=u.x+dx[i],y=u.y+dy[i];
            if(x < 0 || x >= N  || y < 0 || y >= N) continue;
            if(vis[x][y])  continue;
            if(map[x][y]==1) continue;
            vis[x][y]=1;

            path[x][y]=std::pair<int,int>(u.x,u.y);

            if(x==N-1 && y==N-1)
            {
                std::cout<<"scuessed\n";
                print(N-1,N-1);
                return;
            }
            
            //无需relax比较：dijk优化的relax是以g为搜索凭据，向外bfs，最初遇到的dis就是最优的dis。
            pq.push(node(x,y,(u.g+1)+N-1+N-1-x-y,u.g+1,N-1+N-1-x-y));
        }

    }
    std::cout<<"failed";
}
int main()
{
    init();
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(map[i][j]==0)    std::cout<<'_';
            else if(map[i][j]==1) std::cout<<'#';
            else std::cout<<'*';
        }
        std::cout<<'\n';
    }
    std::cout<<"\n\n";
    asearch();

    return 0;
}
~~~



# 样例程序：八数码

> 给定3*3地图，中间填零，外围填1-8，零可与四方数字交换位置，给定初始局面，问需要多少步可以达成目标局面。

可证一定有解，需寻找最优方法

## 1.仅考虑代价函数：bfs

遍历当前步可行动作，将新局面存入队列。

## 2.DFS

遍历当前步可行动作，dfs直至达到目标局面，必须对vised局面去重

## 3.A*

以$\sum当前局面每个位置的数字与目标局面对应位置的数字的差值$为评估函数h

以步数为代价函数g

正确性证明：有且仅有h=0是目标局面，h越小越近似目标局面。







你可以[将所有可能的棋局盘面（游戏状态）表示成节点](https://en.wikipedia.org/wiki/Game_tree)，所有可能的走棋策略（游戏操作）表示为边，然后通过搜索它的一部分，来决定如何移动棋子。你可以[把 NPC 的状态表示成节点](http://gameprogrammingpatterns.com/state.html)，把他们的行为表示成边。你可以（通过图来）构建 NPC 对话数据库，以表示谈话主题。在[地图生成器](http://www-cs-students.stanford.edu/~amitp/game-programming/polygon-map-generation/)中，你可以利用图来生成河流与道路。你可以用图来表示游戏中的经济系统，用节点表示小麦与面包，用边来表示烘培工艺。3D 多边形网格也能视为一种图。图是一种简洁的抽象。如果数据结构采用类似图的形式，你就能够复用各种各样的图算法。
