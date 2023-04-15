[113.路径总和II](https://leetcode.cn/problems/path-sum-ii)

有两种风格的dfs

~~~C++
 void dfs(TreeNode* pos, int& target)
    {
        if(!pos) return;
        path.push_back(pos->val);
        int sum=sumof(path);
        //if(sum>target) return;
        //叶子节点进入
        if(sum==target &&!pos->left && !pos->right) res.push_back(path);
        else 
        {
            dfs(pos->left,target);
            dfs(pos->right,target);
        }
        path.pop_back();
    }
~~~

~~~C++
 void dfs(TreeNode* pos, int& target)
    {
        if(!pos) return;//这个拿来特判空头结点
        path.push_back(pos->val);
        int sum=sumof(path);
        //if(sum>target) return;
        //叶子节点进入
        if(sum==target &&!pos->left && !pos->right) res.push_back(path);
        else 
        {
          if(pos->left)
          {
                dfs(pos->left,target);
                path.pop_back();
          }
          if(pos->right)
          {
               dfs(pos->right,target);
               path.pop_back();
          }
        }
       
    }
~~~

都是AC的代码

区别在于，1在dfs本层pop，2在上一层pop

而考查[走迷宫](https://www.luogu.com.cn/problem/P1238)

~~~C++
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
~~~

与

~~~C++
void dfs(int x, int y)
{

    vec.push_back(pt(x,y));
    visit[x][y] = true;
    if (x == xe  && y == ye )
    {
        print(vec);
        cnt = 1;
      //  return;  注意想要在本层末pop的话，这里就不能写return，然后
    }
    else
    for (int i = 0; i < 4; i++)
    {
        int xc = x + dx[i];
        int yc = y + dy[i];
        if (map[xc][yc] && !visit[xc][yc] && xc>0 && yc>0 && xc <= m && yc <= n)
        {
            dfs(xc, yc);
            //要用for来枚举dfs因为回溯紧密接于试探,尤其注意回溯visit标记

        }

    }
    visit[x][y] = false;
    vec.pop_back();
}
~~~

当然也可以这么写

（我们当然也可以把if写在递归顶层）

但我认为，我们现在写的是搜索，而不是递归。

~~~C++
void dfs(int x, int y)
{

    vec.push_back(pt(x,y));
    visit[x][y] = true;
    if (x == xe  && y == ye )
    {
        print(vec);
        cnt = 1;
        visit[x][y] = false;
        vec.pop_back();
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

        }

    }
}
~~~

所以我认为比较合理的带vis剪枝的路径dfs写法应该是

~~~C++
1.记录路径
2.终点判断
3.枚举合理的dfs（越界和vis剪枝不开栈）
4.就地回溯路径
~~~

主要在于，用数组和for来压缩枚举的方式比较让人习惯在dfs退出的瞬间开始回溯(因为cur指针的存在)

手写枚举dfs的方式让人习惯在本层原地回溯。

对于枚举下级dfs，当然也可以把剪枝集中在递归头的剪枝集合中——效率低一些，但可读性更好，很优雅。