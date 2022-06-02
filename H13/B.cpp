//
// Created by DELL on 2022/5/18.
//
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s.insert(0, "1");
    int size = s.size();
    int dp[size + 1][size + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= size; ++i) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= size; ++j)dp[i][j] = 0x3f3f3f3f;
    }
    for (int i = size; i > 0; --i) {
        for (int j = i + 1; j <= size; ++j) {
            for (int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }
            if (s[i] == '(' && s[j] == ')') {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            } else if (s[i] == '[' && s[j] == ']') {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            } else if (s[i] == '[' || s[i] == '(') {
                dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
            } else if (s[j] == ']' || s[j] == ')') {
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
    }
    cout << dp[1][size]-1 << endl;
    return 0;
}
