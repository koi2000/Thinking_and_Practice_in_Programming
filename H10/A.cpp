//
// Created by DELL on 2022/4/27.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int r, y, g;
    cin >> r >> y >> g;
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int k, t;
        cin >> k >> t;
        if (k == 1) {
            sum += (t);
        }
        if (k == 2) {
            sum += (r + t);
        }
        if (k == 3) {

        }
        if (k == 0) {
            sum += t;
        }
    }
    cout << sum << endl;
    return 0;
}


