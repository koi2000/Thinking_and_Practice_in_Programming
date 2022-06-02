//
// Created by DELL on 2022/5/18.
//
#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool check(ll i);

ll h, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> h >> w;
    // 共h行，dp[i][S]表明填充到第i行状态为S的方案数量，S的最大
    ll dp[h + 1][1 << w];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for (ll i = 1; i <= h; ++i) {
        for (ll j = 0; j < (1 << w); ++j) {
            for (ll k = 0; k < (1 << w); ++k) {
                if ((j & k) != 0)continue;;
                if (!check(j | k))continue;
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    ll sum = 0;
//    for (ll i = 0; i < (1 << w); ++i) {
//        sum += dp[h][i];
//    }
    cout << dp[h][0] << endl;
    return 0;
}

bool check(ll num) {
    //char s[15];
    vector<ll> split;
    while (num > 0) {
        split.push_back(num % 2);
        num /= 2;
    }
//    for (int i = split.size(); i < w; ++i) {
//        split.push_back(0);
//    }
    while (split.size() < w) {
        split.push_back(0);
    }
    bool isZero = false;
    for (ll i = 0; i < split.size(); ++i) {
        if (split[i] == 0) {
            isZero = !isZero;
        } else {
            if (isZero) {
                return false;
            }
        }
    }
    return !isZero;
}
