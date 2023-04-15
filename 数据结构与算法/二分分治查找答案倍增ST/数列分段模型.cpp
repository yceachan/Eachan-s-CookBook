#include<bits/stdc++.h>
using namespace std;
int n,m;
int* a;
bool check(int mid)
{
    int cnt=0,app=0;
    for(int i=0;i<n;i++)
    {
        if(app+a[i]>mid)
        {
            app=0;
            cnt++;
        }
        app+=a[i];
    }
    return cnt+1<=m;

}
int main()
{
    cin>>n>>m;
    a=new int[n];
    int rhs=0,lhs=0,ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        rhs+=a[i];
        lhs=max(a[i],lhs);
    }
    //可想而知的是，对于任一ans指针∈[a_Max,a_Sum]，均可顺利的将数组切割为cnt段，我们需要找出令其中cnt==m的最小ans指针
    //最朴素的枚举法就是遍历[a_Max,a_Sum]来check，最优解为最先出现的ans指针
    //二分搜索思想是从区间中点mid开始搜索cnt，重点是搜索到cnt==m后的求精——继续缩小mid指针搜索更优的mid解，若过小就扩大mid,直到lr指针重合
//    while(lhs<=rhs)
//    {
//        int mid=(lhs+rhs)/2;
//        if(check(mid))
//        {
//            ans=mid;//仔细思考二分特性，对于cnt<m的解，当然要缩小mid指针从而获得更多cnt，对于cnt==m的解，继续缩小mid指针搜索更优的mid解，并用ans迭代记录
//            rhs=mid-1;
//        }
//        else lhs=mid+1;//对于mid指针过小，cnt过多的情况，扩大mid指针以搜索
//    }
    //倍增算法
    //自hi向lo倍增pace用k指针搜索cnt,类似一个试探回溯模型————先试探hi-p+1，这个指针，cnt<m则hi前进，=也前进求精,越界则改为倍缩p
    //末状态为对于最优解k指针=(hi-p+1)，倍增p并试图用这个p更新k指针试探求精,此后缩小p直至!p，均是失败的试探，ans迭代着最优k指针退出循环。
    int p=1,hi=rhs;
    while(p)
    {
        int k=hi-p+1;
        if(k>=lhs&&check(k))
        {
            ans=k;
            hi-=p;
            p*=2;
        }
        else p/=2;
    }

    printf("%d",ans);
    return 0;

}