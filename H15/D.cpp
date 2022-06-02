//
// Created by DELL on 2022/6/1.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll p = LONG_LONG_MAX;

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
                    ret.m[i][j] = max(ret.m[i][j], m[i][kk] + rhs.m[kk][j]);
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
//    for (int i = 0; i < res.m.size(); ++i) {
//        res.m[i][i] = 1;
//    }
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

    int n, m;
    cin >> n >> m;
    int h[m][m];
    mat res = mat(m, m);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> res.m[i][j];
            h[i][j] = res.m[i][j];
        }
    }
    res = qpow(res, n - 1);
    ll ret = INT_MIN;
    for (int i = 0; i < m; ++i) {
        ret = max(ret, res.m[0][i]);
    }
    cout << ret << endl;
    return 0;
}
