//
// Created by DELL on 2022/1/18.
//
//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//    int a[n + 1];
//    for (int i = 1; i <= n; i++) {
//        cin >> a[i];
//    }
//    int dp[n + 1];
//    memset(dp,1,sizeof(dp));
//    /*for (int i = 0; i < n + 1; ++i) {
//        dp[i] = 1;
//    }*/
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j < i; j++) {
//            if (a[i] > a[j]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//    }
//    cout << *max_element(dp + 1, dp + n + 1) << endl;
//    return 0;
//}
#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;

ll w[10001];
ll f[10001];

int main() {
    ll n;
    cin >> n;
    for (ll i = 1; i <= n; i++){
        scanf("%d", &w[i]);
    }
    f[1] = w[1];
    ll len = 1;
    for (ll i = 2; i <= n; i++) {
        if (w[i] > f[len])
            f[++len] = w[i];
        else {
            ll l = 1, r = len, mid, t = len;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if (w[i] <= f[mid]) {
                    t = mid;
                    r = mid - 1;
                } else
                    l = mid + 1;
            }
            f[t] = w[i];
        }
    }
    cout << len;
    return 0;
}
