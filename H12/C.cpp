//
// Created by DELL on 2022/5/15.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

//ll dp[1000][maxn];
int main() {
    int n, v;
    cin >> n >> v;
    ll w[n+1];
    ll c[n+1];
    ll k[n+1];
    int ww, cc, kk;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> c[i] >> k[i];
    }
    ll dp[v + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < ; ++j) {

        }
        for (int j = v; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
        }
    }
    cout << dp[v];
    return 0;
}