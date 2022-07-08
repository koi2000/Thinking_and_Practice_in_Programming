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

#define ll long long
using namespace std;

vector<ll> weight;
vector<ll> value;
vector<ll> number;
ll num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll c;
    cin >> num;
    cin >> c;
    num--;
    for (ll i = 0; i <= num; ++i) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        //ll t4 = t3;
        for (int j = 1; j <= t3; j <<= 1) {
            t3 -= j;
            weight.push_back(t1 * j);
            value.push_back(t2 * j);
        }
        if (t3 > 0) {
            weight.push_back(t1 * t3);//有余数就直接加进去
            value.push_back(t2 * t3);
        }
    }
    ll dp[c + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 0; i < weight.size(); ++i) {
        for (ll j = c; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[c] << endl;
    return 0;
}




