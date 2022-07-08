//
// Created by DELL on 2022/1/11.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> mm;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mm.find(a[i]) != mm.end()) {
            mm[a[i]] = mm[a[i]] + 1;
        } else {
            mm[a[i]] = 1;
        }
    }
    int sum = 0;
    for (auto it = mm.begin(); it != mm.end(); it++) {
        if (mm.find(it->first + 1) != mm.end()) {
            sum += it->second * mm[it->first + 1];
        }
    }
    cout << sum << endl;
    return 0;
}

