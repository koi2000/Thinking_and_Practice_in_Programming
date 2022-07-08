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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int sum = a[i];
        int idx = 1;
        if (i - 1 >= 0) {
            sum += a[i - 1];
            idx++;
        }
        if (i + 1 < n) {
            sum += a[i + 1];
            idx++;
        }
        cout << sum / idx << " ";
    }
    return 0;
}




