//
// Created by DELL on 2022/3/23.
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

deque<pair<int, int>> q;

vector<int> windows(int n, int k, int a[]) {
    vector<int> res;
    q.clear();
    for (int i = 0; i < k -1; ++i) {
        while (!q.empty() && q.back().first >= a[i]) {
            q.pop_back();
        }
        q.emplace_back(a[i],i);
    }
    for (int i = k-1; i < n; ++i) {
        while (!q.empty() && q.back().first >= a[i]) {
            q.pop_back();
        }
        if (!q.empty() && q.front().second < i - k + 1) {
            q.pop_front();
        }
        q.emplace_back(a[i], i);
        res.push_back(q.front().first);

    }
    return res;
}

vector<int> windowmax(int n, int k, int a[]) {
    vector<int> res;
    q.clear();
    for (int i = 0; i < k -1; ++i) {

        while (!q.empty() && q.back().first <= a[i]) {
            q.pop_back();
        }
        q.emplace_back(a[i],i);
    }
    for (int i = k-1; i < n; ++i) {
        while (!q.empty() && q.back().first <= a[i]) {
            q.pop_back();
        }
        if (!q.empty() && q.front().second < i - k + 1) {
            q.pop_front();
        }
        q.emplace_back(a[i], i);
        res.push_back(q.front().first);

    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, k;
    cin >> n >> k;
    queue<pair<int, int>> qq;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> res1 = windows(n, k, a);
//    for (int i = 0; i < n; ++i) {
//        a[i] = -a[i];
//    }
    vector<int> res2 = windowmax(n, k, a);
    for (int i = 0; i < res1.size(); ++i) {
        cout << res1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    cout << endl;
    return 0;
}





