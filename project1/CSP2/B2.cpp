//
// Created by DELL on 2022/3/22.
//
#include <bits/stdc++.h>
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
using namespace std;

int a[1000002];
int maxn = 1000000;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    for (int i = 1; i <= maxn; ++i) {
        a[i] = a[i] + a[i - 1];
    }
    int maxk = -1;
    int maxv = -1;
    for (int i = 1; i <= maxn; ++i) {
        if (a[i] >= maxv) {
            maxk = i;
            maxv = a[i];
        }
    }
    cout << maxk <<" "<< maxv << endl;
    return 0;
}




