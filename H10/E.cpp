//
// Created by DELL on 2022/4/27.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll n;
const ll MAXN = 2e5 + 10;
ll d[MAXN << 2], a[MAXN];
#define ll long long

// 初始化线段树
void build(ll x, ll l, ll r) {
    if (r < 0) {
        r = 0;
    }
    // 根节点直接更新
    if (l == r) {
        d[x] = a[l];
        return;
    }
    ll m = (l + r) / 2;
    // 递归更新左子树和右子树
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    // 节点值位左节点和右节点的最大值
    d[x] = max(d[x * 2], d[x * 2 + 1]);
}

// 更新操作
void upd(ll x, ll l, ll r, ll p, ll v) {
    if (r < 0) {
        r = 0;
    }
    // 找到了更新即可
    if (l == r) {
        d[x] = v;
        return;
    }
    ll m = (l + r) / 2;
    if (p <= m) {
        // 递归更新左子树
        upd(x * 2, l, m, p, v);
    } else {
        // 递归更新右子树
        upd(x * 2 + 1, m + 1, r, p, v);
    }
    // 取两子树最大值
    d[x] = max(d[x * 2], d[x * 2 + 1]);
}

ll ask(ll x, ll l, ll r, ll p1, ll p2) {
    if (r < 0) {
        r = n;
    }
    if (l == p1 && r == p2) {
        return d[x];
    }
    ll m = (l + r) / 2;
    // 查左区间即可
    if (p2 <= m) {
        return ask(x * 2, l, m, p1, p2);
    } else if (p1 > m) {
        // 查右区间即可
        return ask(x * 2 + 1, m + 1, r, p1, p2);
    } else {
        // 查询两个区间
        ll tl = ask(p1, m,x * 2, l, m);
        ll tr = ask(m+1, p2,x * 2 + 1, m + 1, r);
        return max(tl, tr);
    }
}

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    ll p;
    scanf("%d", &n);
    scanf("%d", &p);
    //assert(n<1000);
    //cin >> n >> p;
    ll lst = 0;
    ll idx = 1;
    for (ll i = 0; i < n; ++i) {
        char Q[10];
        ll l;
        //cin >> Q >> l;
        scanf("%s", &Q);
        scanf("%lld", &l);
        if (Q[0] == 'A') {
            l = (l + lst) % p;
            upd(1, 1, n+1, idx, l);
            idx++;
        } else {
            ll p1 = idx - l;
            lst = ask(1, 1, n+1, p1, idx - 1);
            printf("%d\n", lst);
        }
    }
    return 0;
}

