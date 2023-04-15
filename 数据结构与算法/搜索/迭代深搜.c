    /*
     * 迭代加深搜索
     * OI-wiki
    定义
    迭代加深是一种 每次限制搜索深度的 深度优先搜索。
    解释
    迭代加深搜索的本质还是深度优先搜索，只不过在搜索的同时带上了一个深度 ，当  达到设定的深度时就返回，一般用于找最优解。如果一次搜索没有找到合法的解，就让设定的深度加一，重新从根开始。
    实上，迭代加深就类似于用 DFS 方式实现的 BFS，它的空间复杂度相对较小。

    过程
    首先设定一个较小的深度作为全局变量，进行 DFS。每进入一次 DFS，将当前深度加一，当发现  大于设定的深度  就返回。如果在搜索的途中发现了答案就可以回溯，同时在回溯的过程中可以记录路径。如果没有发现答案，就返回到函数入口，增加设定深度，继续搜索。*/
    #include<stdio.h>
    #define INF 2147483647
    int gcd(int a,int b){return !b?a:gcd(b,a%b);}
    int x, y,depth=1;
    int path[5000]={0};
    int flag=1;
    //层级level，搜索余项x/y
    //对于搜索终点，表现为余项有y%X==0，正好可以用一个埃及分数来表示.
    //层级而非点状的搜索,我们的一层dfs的对象是x/y ----遍历最能逼近它的埃及分数，且特判余项已是埃及分数的情况

    //考查数据8/11不难发现贪心法——每步取最逼近分数的埃及分数法，是该迭代深搜的一个子解，且是第一个出现的子解

    //考察数据624/625，会有重根，所以我们可以对lo界再进行严格判断,lo=max(path[level-1],Y/X);/
    //1/2 + 1/3 + 1/8 + 1/25 + 1/15000
    //1/2 + 1/8 + 1/3 + 1/25 + 1/15000  废根，后项不应小于前项（前项记录在path尾项）
    //1/3 + 1/2 + 1/8 + 1/25 + 1/15000

    //考查数据127/128（取消最优解flag) 我翻了5分钟输出框，终于找到优美的 1/2 +1/4+ ……+1/128
    void dfs(int level, int X, int Y)
    {
         if(level>depth) return;
         if(X==1)
         {
             path[level]= Y;
             for(int i=0;i<=level;i++)
             {
                 printf("1/%d",path[i]);
                 if(i!=level) printf(" + ");
             }
             puts("");
             flag=0;
             return;

         }

         int lo= Y / X;//我们可以贪心地证明最逼近x/y的埃及分数是 1(y/x+1),但如果用这个lo，就丢失了1/（y/x）==x/y的搜索情况
         int hi= Y * (depth - level + 1) / X;  //l层搜索在下方，故l层到d层相差l-d+1次搜索，这i次搜索至少要用i个float才可能匹配x/Y ，故上界表达式入左
         for(int i=lo;i<=hi;i++)
         {
             //本层用i迭代逼近x/Y,余项为x/Y - 1/i;
             int nx= X * i - Y,ny= Y * i;
             if(nx<0) continue;//用余项为负，i过大
             path[level]=i;
             int g=gcd(ny,nx);
             ny/=g;nx/=g;

             dfs(level+1,nx,ny);
         }
    }

    int main()
    {

         scanf("%d/%d",&x,&y);
         int g=gcd(y,x);

         if(x==g){printf("%d/%d=1/%d",x,y,y/g);return 0;}
         while(flag)
         {
             dfs(0,x,y);
             depth++;
         }

    }