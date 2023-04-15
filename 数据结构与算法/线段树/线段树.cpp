#include<iostream>
using namespace std;
const int N = 1e5 + 5;
int n, m;
typedef long long ll;
ll a[N]={0}, d[N << 2] = {0};
ll tag[N << 2] = { 0 };//lazy_tag：声明该节点的子树未更新
inline int 	left(int i) { return i<<1; }
inline int  right(int i) { return i<<1|1; }
inline int  fa(int i) { return i>>1; }

//自顶向下下回溯时push_up建树策略
inline void push_up(int p)
{
	d[p] = d[left(p)] + d[right(p)];
}
//自顶向下递推时传递lazy_tag
inline void push_down(int p,int l,int r)
{
    if (!tag[p]) return;
    int mid = (l + r) >> 1;
    tag[left(p)] += tag[p];
    tag[right(p)] += tag[p];
    d[left(p)]  += tag[p] * (mid   -  l    + 1);
    d[right(p)] += tag[p] * (r - (mid + 1) + 1);
    tag[p] = 0;
}

void build(int p, int l, int r)
{
    //tag[p] = 0;
    if (l == r) { d[p] = a[l]; return; }
    int mid = (l + r) >> 1;
    build(left(p), l, mid);
    build(right(p), mid + 1, r);
    push_up(p);
}

ll query(int lo, int hi, int l, int r, int p)
{
    ll res = 0;
    if (lo <= l && r <= hi) return d[p];//奇异线段：树上区间是目的区间的子区间
    int mid = (l + r) >> 1;
    push_down(p, l, r);//如果是查询到lazy_tag以下的线段，也需要下放tag
    if (lo <= mid)res += query(lo, hi, l, mid, left(p));
    if (hi > mid) res += query(lo, hi, mid + 1, r, right(p));
    return res;
}

void update(int lo, int hi, int l, int r, int p,int k)
{
    //奇异情形：更新线段，打上lazy_tag,暂不更新子线段
    if (lo <= l && r <= hi)
    {
        d[p] += k * (r - l + 1);
        tag[p] += k;
        return;
    }
    push_down(p, l, r);//本区间不是query的奇异线段，需下放（如果有）的lazy_tag
    int mid = (l + r) >> 1;
    if (lo <= mid) update(lo, hi,   l  , mid, left(p), k);
    if (hi > mid ) update(lo, hi, mid+1,  r , right(p), k);
    push_up(p);//回溯基是奇异线段，把它的信息push_up上去
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n>>m; for (int i = 1; i <= n; i++) cin >> a[i]; build(1,1,n);
    
    while (m--)
    {
        int sel; cin >> sel;
        if (sel == 1)
        {
            int l, r, k; cin >> l >> r >> k;
            update(l, r,1,n,1,k);
        }
        if (sel == 2)
        {
            int l, r; cin >> l >> r;
            cout<<query(l, r,1,n,1)<<'\n';
        }
    }
    return 0;
}