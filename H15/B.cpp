//
// Created by DELL on 2022/6/1.
//
#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 2;
int n, k;
int p = 1e9 + 7;

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

ll c(int m, int np) {
    ll mm = 1;
    ll nn = 1;
    for (int i = np; i >= np - m + 1; --i) {
        nn = (i * nn) % p;
    }
    for (int i = 1; i <= m; ++i) {
        mm = (mm * i) % p;
    }
    return nn / mm;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        cin >> n >> k;
        mat res = mat(k + 2, k + 2);
        res.m[0][0] = 1;
        for (int j = 1; j < k + 2; ++j) {
            res.m[0][j] = c(j - 1, k);
        }
        for (int j = 1; j < k + 2; ++j) {
            for (int l = j; l < k + 2; ++l) {
                res.m[j][l] = c(l - j, k - j + 1);
            }
        }
        res.m[k + 1][k + 1] = 1;
        res = qpow(res, n - 1);
        ll ret = 0;
        for (int j = 0; j < res.m[0].size(); ++j) {
            ret = (ret + res.m[0][j]) % p;
        }
        cout << ret << endl;
    }
    return 0;
}
