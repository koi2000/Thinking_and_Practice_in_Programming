#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define maxn 100010
#define ll long long

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        a[i] = t;
        arr.push_back(t);
    }
    sort(arr.begin(), arr.end());

    int vis[n];
    int ret = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[i - 1] <= k) {
            vis[i] = 1;
            vis[i - 1] = 1;
            ret++;
        }
    }

    cout << ret << endl;
    return 0;
}
