//
// Created by DELL on 2022/3/23.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

#define ll long long

const ll mod = 1e9 + 7;
using namespace std;

map<ll, ll> maps;

map<ll, ll> split(ll num) {
    //存储本次的结果
    map<ll, ll> res;
    ll n = num;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            n /= i;
            if (res.find(i) != res.end()) {
                res[i]++;
            } else {
                res[i] = 1;
            }
            i--;
        }
    }
    //更新全局maps，里面存储每一项的最小值
    for (auto &item:maps) {
        if (res.find(item.first) != res.end()) {
            maps[item.first] = min(res[item.first], item.second);
        } else {
            maps[item.first] = 0;
        }
    }
    return res;
}

ll pow(ll v, ll u) {
    ll res = 1;
    while (u) {
        if (u & 1) {
            res = res * v % mod;
        }
        v = v * v % mod;
        u = u >> 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    ll a[n + 1];
    vector<ll> arr[n + 1];
    //memset(a, 1, sizeof(a));
    for (int i = 1; i < n + 1; ++i) {
        //a[i] = 1;
        cin>>a[i];
    }
//    for (int i = 0; i < m; ++i) {
//        int l, r, c, d;
//        cin >> l >> r >> c >> d;
//        ll num = pow(c, d);
//        arr[l].push_back(num);
//        if (r + 1 <= n) {
//            arr[r + 1].push_back(-num);
//        }
////        for (int j = l; j <= r; ++j) {
////            //a[j] = (a[j] % mod) * (num % mod) % mod;
////            a[j] = a[j] * num % mod;
////        }
//    }
//    //让第一检查的值直接等于全局值，然后开始更新全局值
//    for (int i = 1; i <= n; i++) {
//        ll num = a[i - 1];
//        for (int j = 0; j < arr[i].size(); ++j) {
//            if (arr[i][j] >= 0) {
//                num = ((num%mod) * (arr[i][j])%mod)%mod;
//            } else {
//                num = (num%mod) / ((-arr[i][j])%mod)%mod;
//            }
//        }
//        a[i] = num;
//    }
    maps = split(a[1]);
    for (int i = 2; i <= n; ++i) {
        split(a[i]);
    }
    ll sum = 1;
    for (auto &item:maps) {
        //cout << item.first << " " << item.second << endl;
        sum = (sum % mod) * (pow(item.first, item.second) % mod) % mod;
    }
    cout << sum << endl;
    return 0;
}





