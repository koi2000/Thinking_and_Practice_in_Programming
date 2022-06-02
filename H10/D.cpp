//
// Created by DELL on 2022/4/27.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll MAXN = 1e6 + 1;

class cpp {
public:
    int t;
    int m;

    cpp() {}

    cpp(int t, int m) : t(t), m(m) {}

    bool operator<(const cpp &rhs) const {
        if (t == rhs.t) {
            return m < rhs.m;
        }
        return t < rhs.t;
    }

    bool operator>(const cpp &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const cpp &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const cpp &rhs) const {
        return !(*this < rhs);
    }
};

#define lowbit(x) ( x & -x )
cpp ps[MAXN];
ll s[MAXN];
ll n;

ll ask(ll p) {
    ll res = 0;
    for (ll i = p; i >= 1; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}

void upd(ll p, ll x) {
    for (ll i = p; i <= MAXN; i += lowbit(i)) {
        s[i] += x;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d",&n);
    // 存大于等于该程序的
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&ps[i].t,&ps[i].m);
        ps[i].t++;
        ps[i].m++;
    }
    sort(ps, ps + n);
    int res[n];
    memset(res, 0, n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        res[ask(ps[i].m)]++;
        upd(ps[i].m, 1);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n",res[i]);
    }
    return 0;
}


