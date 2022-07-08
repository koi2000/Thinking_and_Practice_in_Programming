//
// Created by DELL on 2022/1/10.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int b[n - 1];
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i + 1] - a[i]);
    }
    sort(b, b + n - 1);
    cout << b[0] << endl;
    return 0;
}

