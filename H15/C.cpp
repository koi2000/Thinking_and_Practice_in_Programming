//
// Created by DELL on 2022/6/1.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int p = 998244353;

class mat {
public:
    vector<vector<ll>> m;

    mat(int ms, int mn) {
        m = vector<vector<ll>>(ms, vector<ll>(mn, 0));
    }

    mat mul(const mat &rhs) {
        // m第一维
        ll ms = m.size();
        // k
        ll ks = rhs.m[0].size();
        // n
        ll ns = rhs.m.size();
        mat ret = mat(ms, ks);
        for (ll i = 0; i < ms; i++) {
            for (ll j = 0; j < ks; j++) {
                for (ll kk = 0; kk < ns; kk++) {
                    ret.m[i][j] += (m[i][kk] * rhs.m[kk][j] % p);
                    ret.m[i][j] %= p;
                }
            }
        }
        return ret;
    }

    mat(const mat &t) {
        for (int i = 0; i < m.size(); ++i) {
            for (int j = 0; j < m[i].size(); ++j) {
                m[i][j] = t.m[i][j];
            }
        }
    }
};


mat qpow(mat &a, ll x) {
    mat res = mat(a.m.size(), a.m.size());
    for (int i = 0; i < res.m.size(); ++i) {
        res.m[i][i] = 1;
    }
    while (x > 0) {
        if (x & 1) res = res.mul(a);
        a = a.mul(a);
        x = x >> 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        mat res = mat(3, 3);
        res.m[0][0] = res.m[1][1] = 1;
        res.m[2][2] = 1;
        res.m[2][1] = res.m[2][0] = 2;
        res.m[0][2] = res.m[1][2] = 1;
        res = qpow(res, n - 1);
        cout << (res.m[0][0] + 2 * res.m[0][2]) % p << endl;
    }
    return 0;
}
