//
// Created by DELL on 2022/1/11.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    map<int, int> mm;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (mm.find(a[i]) != mm.end()) {
            mm[a[i]] = mm[a[i]] + 1;
        } else {
            mm[a[i]] = 1;
        }
        b[i] = mm[a[i]];
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}

