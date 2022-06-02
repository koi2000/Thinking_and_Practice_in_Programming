//
// Created by DELL on 2022/5/25.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll mod = 1e9 + 7;
const ll maxk = 5010;
ll dp[maxk];
ll sum[maxk];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    dp[a] = 1;
    if (a > b) {
        for (int i = b + 1; i <= min(n, a + abs(a - b) - 1); ++i) {
            dp[i] = 1;
        }
    } else {
        for (int i = max(1, a - abs(a - b) + 1); i <= b - 1; ++i) {
            dp[i] = 1;
        }
    }

    dp[a] = 0;
    dp[b] = 0;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + dp[i];
    }
    for (int i = 1; i < k; ++i) {
        memset(dp, 0, sizeof dp);
        for (int j = 1; j <= n; ++j) {
            if (j > b) {
                dp[j] = sum[n] - sum[((j + b) >> 1)] - sum[j] + sum[j - 1];
                if (dp[j] > mod)dp[j] %= mod;
                if (dp[j] < 0) dp[j] = mod + dp[j];
            } else if (j < b) {
                dp[j] = sum[((j - 1 + b) >> 1)] - sum[j] + sum[j - 1];
                if (dp[j] > mod)dp[j] %= mod;
                if (dp[j] < 0) dp[j] = mod + dp[j];
            }
        }
        for (int j = 1; j <= n; ++j) {
            sum[j] = (sum[j - 1] % mod + dp[j] % mod) % mod;
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans = (ans + dp[i]) % mod;
    }
    cout << ans << endl;
    return 0;
}

