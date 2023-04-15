# 1.诈骗模型

>一堆石子n个两人轮流每步可以去[1:m]个，先取完的获胜

~~~C++
//对于先取完的人：处理的是1：m的case，
//故对手处理的是m+1的case
//我方处理m+1~m+1 +m的case，处理为m+1的case 
cout<<((n%(m+1)!=0)?"first\n":"second\n");
~~~

> 被迫先取完的lose

~~~C++
//switch（n），轮到op方操作
//1   op方lose ， 
//234 op方均将其处理为case1 ，win 
//5   op方无论将其处理为case234 ,lose
//678 op将均将其处理为case5 
cout<<((n%4==1)?"second":"first");
~~~

# 2.[Minimax 算法模型](https://oi.wiki/search/alpha-beta/)

Alpha-Beta 剪枝呗

# 3.[dp模型](https://labuladong.gitee.io/algo/3/28/93/)

决策状态空间的转移