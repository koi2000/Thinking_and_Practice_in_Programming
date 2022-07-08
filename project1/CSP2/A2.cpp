//
// Created by DELL on 2022/3/22.
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, k;
    cin >> n >> k;
    map<int, int> kv;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        if (kv.find(m) != kv.end()) {
            kv[m]++;
        } else {
            kv[m] = 1;
        }
    }
    int num = 0;
    for (auto &item:kv) {
        if (item.second >= 2) {
            num += item.second / 2;
        }
    }
    cout << num << endl;
    return 0;
}




