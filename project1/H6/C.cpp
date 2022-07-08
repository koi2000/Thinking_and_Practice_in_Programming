//
// Created by DELL on 2022/1/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <map>

using namespace std;
int n;
int f[100000];

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return;
    }
    f[fx] = fy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int j, k;

    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
    int cnt = 1;
    for (int i = 0; i < m; i++) {
        cin >> j >> k;
        int fj = find(j);
        int fk = find(k);
        if (fj != fk) {
            cnt++;
            unite(fj,fk);
        }
        cout<<n-cnt<<endl;
    }

    return 0;
}




