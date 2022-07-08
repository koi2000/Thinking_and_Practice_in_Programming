//
// Created by DELL on 2022/1/13.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int num = n;
    for (int i = 0; i < n; ++i) {
        a[i] = 1;
    }
    int idx = 0;
    int i = 0;
    while (num > 1) {
        idx += a[i];

        if (idx % k == 0 && a[i] != 0) {
            a[i] = 0;
            num--;
        } else if (idx % 10 == k && a[i] != 0) {
            a[i] = 0;
            num--;
        }
        i = (i + 1) % n;
    }
    for (int j = 0; j < n; ++j) {
        if (a[j] == 1) {
            cout << j + 1 << endl;
        }
    }
    return 0;
}
