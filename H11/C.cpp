//
// Created by DELL on 2022/5/4.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    ll mat[3][n + 1];
    memset(mat, 0, sizeof mat);
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mat[i][j];
        }
    }
    ll dp[n + 1][3];
    memset(dp, 0x3f3f3f3f, sizeof dp);
    dp[1][0] = 0;
    dp[1][1] = 0;
    dp[1][2] = 0;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 2; i <= n; ++i) {

        dp[i][0] = min(
                        dp[i - 1][0] + abs(mat[0][i] - mat[0][i - 1]),
                min(
                        dp[i - 1][1] + abs(mat[0][i] - mat[1][i - 1]),
                        dp[i - 1][2] + abs(mat[0][i] - mat[2][i - 1]))
        );

        dp[i][1] = min(
                        dp[i - 1][0] + abs(mat[1][i] - mat[0][i - 1]),
                min(
                        dp[i - 1][1] + abs(mat[1][i] - mat[1][i - 1]),
                        dp[i - 1][2] + abs(mat[1][i] - mat[2][i - 1]))
        );
        dp[i][2] = min(
                        dp[i - 1][0] + abs(mat[2][i] - mat[0][i - 1]),
                min(
                        dp[i - 1][1] + abs(mat[2][i] - mat[1][i - 1]),
                        dp[i - 1][2] + abs(mat[2][i] - mat[2][i - 1]))
                        );
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
    return 0;
}

