//
// Created by DELL on 2022/5/15.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

class obj {
public:
    ll weight;
    ll value;
};

int main() {
    int n, v;
    cin >> n >> v;
    vector<vector<obj>> groups;
    int w, c, k;
    for (int i = 1; i <= n; ++i) {
        cin >> w >> c >> k;
        if (k >= groups.size()) {
            groups.resize(k + 1);
            groups[k] = vector<obj>();
        }
        groups[k].push_back({w, c});
    }
    int num = groups.size();
    ll dp[num][v + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i < groups.size(); ++i) {
        for (int j = v; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            for (int l = 0; l < groups[i].size(); ++l) {
                if (j >= groups[i][l].weight) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - groups[i][l].weight] + groups[i][l].value);
                }
            }
        }
    }
    cout << dp[num - 1][v];
    return 0;
}
