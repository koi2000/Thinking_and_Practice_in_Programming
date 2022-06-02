//
// Created by DELL on 2022/5/15.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    int w[n + 1];
    int c[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> c[i];
    }
    int dp[n + 1][v + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (w[i] <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + c[i]);
            }
        }
    }
    cout << dp[n][v];
    return 0;
}
