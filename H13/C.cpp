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
    s.insert(0, " ");
    int num = s.size();
    int dp[num][num];
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < num; ++i) {
        dp[i][i] = 1;
    }
    for (int i = s.size(); i > 0; --i) {
        for (int j = i + 1; j < s.size(); ++j) {
            if (i == j)continue;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[1][num-1] << endl;
    return 0;
}
