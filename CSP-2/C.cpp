//
// Created by csp on 2022/4/12.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;

int main() {

    cin >> n >> m;
    ll w[n];
    ll d[m];

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> d[i];
    }

    // 该数组记录每个数上一次出现的位置
    vector<ll> pre(n + 1, -1);
    ll res = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 遍历所有的位置，查看是否在每一个的前面
            if (pre[j] > pre[d[i]]) {
                // 将所有压在自己上面的加起来
                res += w[j - 1];
            }
        }
        // 更新每一个前一个位置
        pre[d[i]] = i;
    }
    cout << res;
    return 0;
}