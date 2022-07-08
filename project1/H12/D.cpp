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
vector<ll> group;
ll num;

struct good{
    ll w;
    ll v;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<good>>groups;

    ll c;
    cin >> num;
    cin >> c;
    num--;
    for (ll i = 0; i <= num; ++i) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t3>=groups.size()){
            groups.resize(t3+1);
            groups[t3] = vector<good>();
        }
        groups[t3].push_back({t1,t2});
    }
    ll dp[c + 1];
    memset(dp, 0, sizeof(dp));
    for (ll i = 1; i < groups.size(); ++i) {
        for (ll j = c; j >= 1; --j) {
            for (ll k = 0; k < groups[i].size(); ++k) {
                if (j >= groups[i][k].w) {
                    dp[j] = max(dp[j], dp[j - groups[i][k].w] + groups[i][k].v);
                }
            }
        }
    }
    cout << dp[c] << endl;
    return 0;
}