//
// Created by DELL on 2022/5/4.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    assert(n < 1000000);
    ll dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    ll sum[n + 1];
    memset(sum, 0, sizeof dp);
    sum[0] = 1;
    set<ll> unsafe;
    for (ll i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        unsafe.insert(t);
        //dp[t] = 0;
    }
    for (ll i = 1; i <= n; ++i) {
        if (unsafe.find(i) != unsafe.end()) {
            dp[i] = 0;
        } else {
            if (i - k - 1 < 0) {
                dp[i] = sum[i - 1];
            } else {
                dp[i] = (sum[i - 1] % mod - sum[i - k - 1] % mod) % mod;
            }
        }
        sum[i] = (sum[i - 1] + dp[i]);
        sum[i] = (mod + sum[i] % mod) % mod;
        dp[i] = sum[i];
    }
    cout << dp[n] % mod;
    return 0;
}