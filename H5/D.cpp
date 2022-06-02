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
using namespace std;


ll res = 0;
ll a[100006];
int n;

map<int, int> ml;
map<int, int> mr;

void check(int now) {
    int l = now;
    int r = now;
    deque<int> m;
    if (a[now] == 1) {
        return;
    }
    if (a[now] * n <= res) {
        return;
    }
    for (int j = now; j >= 0; j--) {
        if (a[j] < a[now]) {
            l = j + 1;
            break;
        }
    }
    for (int j = now; j < n; ++j) {
        if (a[j] < a[now]) {
            r = j - 1;
            break;
        }
    }
    res = max((r - l + 1) * a[now], res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
        while (!q.empty() && q.back().first >= a[i]) {
            q.pop_back();
        }
        if (q.empty()) {
            ml[i] = -1;
        } else {
            ml[i] = q.back().second;
        }
        q.emplace_back(a[i], i);
    }
    q.clear();
    for (int i = n - 1; i >= 0; --i) {
        while (!q.empty() && q.back().first >= a[i]) {
            q.pop_back();
        }
        if (q.empty()) {
            mr[i] = n;
        } else {
            mr[i] = q.back().second;
        }
        q.emplace_back(a[i], i);
    }

    for (int i = 0; i < n; ++i) {
        //check(i);
        int l = i;
        int r = i;
        l = ml[i] + 1;
        r = mr[i] - 1;
        res = max((r - l + 1) * a[i], res);
    }
    cout << res << endl;
    return 0;
}





