//
// Created by DELL on 2022/3/21.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<ll> arrx;
    set<ll> arry;
    set<ll> arrz;

    char c;
    ll t;
    vector<char> opts;
    vector<ll> values;
    for (int i = 0; i < m; ++i) {
        cin >> c;
        opts.push_back(c);
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        values.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        c = opts[i];
        t = values[i];
        if (c == 'x') {
            arrx.insert(t);
        }
        if (c == 'y') {
            arry.insert(t);
        }
        if (c == 'z') {
            arrz.insert(t);
        }
        ll last = 0;
        ll xmax = 0;
        ll ymax = 0;
        ll zmax = 0;
        for (auto &item:arrx) {
            ll temp = item - last;
            last = item;
            xmax = max(xmax, temp);
        }
        xmax = max(xmax, n - last);
        last = 0;
        for (auto &item:arry) {
            ll temp = item - last;
            last = item;
            ymax = max(ymax, temp);
        }
        ymax = max(ymax, n - last);
        last = 0;
        for (auto &item:arrz) {
            ll temp = item - last;
            last = item;
            zmax = max(zmax, temp);
        }
        zmax = max(zmax, n - last);
        cout << xmax * ymax * zmax << endl;
    }
    return 0;
};
