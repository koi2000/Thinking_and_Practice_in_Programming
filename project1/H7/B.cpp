//
// Created by DELL on 2022/1/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

#define maxn 100000
using namespace std;

class times {
public:
    int l, r;

    times(int l, int r) : l(l), r(r) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<times> a;
    vector<times> b;
    int maxx = -1;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        times t = times(l, r);
        maxx = max(maxx, r);
        a.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        times t = times(l, r);
        maxx = max(maxx, r);
        b.push_back(t);
    }
    int line[maxx];
    memset(line, 0, sizeof(line));
    for (int i = 0; i < a.size(); ++i) {
        for (int j = a[i].l; j < a[i].r; ++j) {
            line[j]++;
        }
    }
    for (int i = 0; i < b.size(); ++i) {
        for (int j = b[i].l; j < b[i].r; ++j) {
            line[j]++;
        }
    }
    int sum = 0;
    for (int i = 1; i < maxx; ++i) {
        if (line[i] == 2) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}




