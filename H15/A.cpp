//
// Created by DELL on 2022/6/1.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
ll n, p;

class mat {
public:
    ll m[2][2];

    mat() {
        memset(m, 0, sizeof m);
    }

    mat mul(const mat rhs, ll mod) {
        mat ret;
        for (ll i = 0; i < 2; i++) {
            for (ll j = 0; j < 2; j++) {
                for (ll k = 0; k < 2; k++) {
                    ret.m[i][j] += (m[i][k] * rhs.m[k][j] % p);
                    ret.m[i][j] %= mod;
                }
            }
        }
        return ret;
    }

    mat(const mat &t) { memcpy(m, t.m, sizeof m); };
};


mat qpow(mat &a, ll x) {
    mat res;
    res.m[0][0] = res.m[1][1] = 1;
    while (x > 0) {
        if (x & 1) res = res.mul(a, p);
        a = a.mul(a, p);
        x = x >> 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        cin >> n >> p;
        mat res;
        res.m[0][0] = res.m[0][1] = res.m[1][0] = 1;
        res = qpow(res, n-2);
        cout << (res.m[0][1]+res.m[0][0])%p << endl;
    }

    return 0;
}
