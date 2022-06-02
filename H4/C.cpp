#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define ll long long
using namespace std;
ll n, m;
ll arr[100010];
ll check(ll num) {
    ll sum = 0;
    ll t = 1;
    for (ll i = 0; i < n; i++) {
        if (sum + arr[i] > num) {
            t++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }
    if (t > m) {
        return 0;
    } else if (t < m) {
        return 1;
    } else {
        return 2;
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    cin >> n >> m;

    ll maxx = 0;
    ll minn = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
        minn = max(minn, arr[i]);
        maxx += arr[i];
    }
    ll l = minn;
    ll r = maxx;
    ll res = 0;
    while (l <= r) {
        ll middle =  (r + l) / 2;
        ll tmp = check(middle);
        if (tmp == 0) {
            l = middle + 1;
        } else if (tmp == 1) {
            res = middle;
            r = middle - 1;
        } else {
            res = middle;
            r = middle - 1;
        }
    }
    cout << res << endl;
    return 0;
}