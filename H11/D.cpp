//
// Created by DELL on 2022/5/4.
//
#include <bits/stdc++.h>

#define ll long long

#define lowbit(x) ( x & -x )
const int maxn = 1e6 + 10;
ll a[maxn];
ll d[maxn];
ll f[maxn];


using namespace std;

void upd(ll x, ll val) {
    for (ll i = x; i <= maxn; i += lowbit(i)) {
        d[i] = max(d[i], val);
    }
}

ll query(int x) {
    ll res = 0;
    for (ll i = x; i >= 1; i -= lowbit(i)) {
        res = max(res, d[i]);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        f[i] = query(a[i] - 1) + 1;
        upd(a[i], f[i]);
        ans = max(f[i], ans);
    }
    cout << ans;
    return 0;
}

