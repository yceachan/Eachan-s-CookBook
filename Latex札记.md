参考博客[LaTeX公式手册(全网最全) - 樱花赞 - 博客园 (cnblogs.com)](https://www.cnblogs.com/1024th/p/11623258.html)

Latex elegant

组合{}

# 修饰

上标^

下标_

向量\vec

上划线\overline

下滑线\underline

# 多行公式排版

> 通常，一个格式化后的表格比单纯的文字或排版后的文字更具有可读性。数组和表格均以 `\begin{array}` 开头，并在其后定义列数及每一列的文本对齐属性，`c` `l` `r` 分别代表居中、左对齐及右对齐。若需要插入垂直分割线，在定义式中插入 `|` ，若要插入水平分割线，在下一行输入前插入 `\hline` 。与矩阵相似，每行元素间均须要插入 `&` ，每行元素以 `\\` 结尾，最后以 `\end{array}` 结束数组。

e.g
$$
\begin{array}{ll}
S = a1 · a2 &+ a1 · a3 + · · ·&+a1 · an \\
&+a2 · a3 + · · · &+a2·an\\
&&+an-1 · an.
\end{array}
$$
