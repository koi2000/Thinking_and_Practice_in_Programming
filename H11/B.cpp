//
// Created by DELL on 2022/1/18.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

#define maxn 1000009
#define ll long long
using namespace std;

ll cnt[maxn] = {0};
const ll mod = 998244353;
ll dp[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;

    memset(dp, 0, sizeof dp);
    ll t;
    ll maxx = INT32_MIN;
    for (ll i = 0; i < n; ++i) {
        cin >> t;
        cnt[t]++;
        maxx = max(t,maxx);
    }
    dp[1] = cnt[1];
    for (ll i = 2; i <= maxx; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout << dp[maxx] << endl;
    return 0;
}



