//
// Created by DELL on 2022/5/25.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
deque<ll> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll arr[n + 1];
    ll sum[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    q.push_back(0);
    ll ans = INT_MIN;
    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && sum[q.back()] > sum[i]) {
            q.pop_back();
        }
        q.push_back(i);
        while (!q.empty() && i - m > q.front()) {
            q.pop_front();
        }
        ans = max(ans, sum[i] - sum[q.front()]);
    }
    cout << ans << endl;
    return 0;
}

