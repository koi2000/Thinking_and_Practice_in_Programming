//
// Created by DELL on 2022/4/27.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define lowbit(x) ( x & -x )
const ll MAXN = 1e6 + 1;
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
    for (ll i = p; i <= n; i += lowbit(i)) {
        s[i] += x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll q;
    cin >> n >> q;
    ll opt, l, r;
    ll arr[n+1];
    arr[0] = 0;

    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
        upd(i,arr[i]);
    }
    for (ll i = 0; i < q; ++i) {
        cin >> opt >> l >> r;
        if (opt == 1) {
            upd(l, r);
        } else {
            cout << ask(r) - ask(l - 1) << endl;
        }
    }
    return 0;
}


