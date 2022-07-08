//
// Created by DELL on 2022/1/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>

#define maxn 100000
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long num = n;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = a[i];
        if (a[i] == 1) {
            continue;
        }
        if (a[i] * n <= num) {
            continue;
        }
        for (int j = 1; j + i < n; ++j) {
            if (a[j + i] >= a[i]) {
                sum += a[i];
            } else {
                break;
            }
        }
        for (int j = 1; i - j >= 0; ++j) {
            if (a[i - j] >= a[i]) {
                sum += a[i];
            } else {
                break;
            }
        }
        num = max(sum, num);
    }
    cout << num << endl;
    return 0;
}
