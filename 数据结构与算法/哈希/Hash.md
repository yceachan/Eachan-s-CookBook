# Hash

散列Hashing：数组查询迭代器是O(1)的，有序二分查找值是O(logn)的

散列表Hash table，又称哈希表，是一种数据集，若关键字为**k**，则其值存放在**f(k)**的存储位置上。由此，不需比较便可直接取得所查记录。称这个对应关系**f**为散列函数，按这个思想建立的表为散列表。存储位置f(k)称“哈希槽”


哈希函数：又称[散列函数](https://so.csdn.net/so/search?q=散列函数&spm=1001.2101.3001.7020)，是把一段有限二进制串（字符串等）变换为自然数的一种函数。

哈希更像是一种思想。**Hash算法没有一个固定的公式，只要符合散列思想的算法都可以被称为是Hash算法。 [2]** 

![img](https://pic4.zhimg.com/80/v2-9e1761d7f1da3d08966f85291eda44cf_1440w.webp)

能为 key 计算索引之后，我们就可以知道每个键值对应的值 value 应该放在哪里了。假设我们用数组 a 存放数据，哈希函数是 f，那键值对 `(key, value)` 就应该放在 `a[f(key)]` 上。不论键值是什么类型，范围有多大，`f(key)` 都是在可接受范围内的整数，可以作为数组的下标。

# 常用字符串hash：

对于仅含已知全集的字符串，例如字母串（多项式哈希

~~~C++
hash[i]=( hash[i-1]*p + idx(s[i]) )%mod;
~~~



~~~cpp
const int M = 1e9 + 7;
const int B = 233;

typedef long long ll;

int get_hash(const string& s) {
  int res = 0;
  for (int i = 0; i < s.size(); ++i) {
    res = (ll)(res * B + s[i]) % M;
  }
  return res;
}

bool cmp(const string& s, const string& t) {
  return get_hash(s) == get_hash(t);
}
~~~

**hash[i]**为s的前缀串s(0,i)的hash值，**idx**为自定义的字符的索引
例如：字母串哈希:idx('a')=1,...idx('z')=26，p为自定义参

基于字符串hash，可以求字符串任何一个子串的hash值

~~~C++
Hash(l,r)=(((hash[r] - hash[l-1]* p^(r-l+1))%mod) + mod )%mod
~~~

p和mod需要有适当的取值，防止hash碰撞

p去一个6到8位的较大素数，mod取大素数

一般的 p=1e9+7,mod=1e9+9 

由此观摩其特点

1. **计算hash值的速度比较快（否则无法应用到实际生产的生产环境中）；**
2. **防碰撞特性（Collisionresistance）（保证上传和下载的数据是一样的）；**
3. **隐藏性（Hiding）或者叫做单向性（one-way）（即哈希函数的计算过程是单向不可逆的）；**
4. **谜题友好（puzzlefriendly）（即无法直观的从输入数据判断出输出数据是什么样子的）；**

# hash与map

hash是散列表，O(1)查询，

map是映射，底层是红黑树，树上O(logn)查询

可将hash封装为hash_map用以查找。

hash不安全的，哈希碰撞问题，需要有很多微妙的构造函数，

hash查找极快

hash构造很慢

