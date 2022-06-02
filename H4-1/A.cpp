#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

using namespace std;

int n, k;

bool check(double mid, double arr[]) {
    int t = 0;


    for (int i = 0; i < n; i++) {
        double temp = arr[i];
        //arr[i] = temp % mid;
        t += int(temp / mid);
    }

    return t >= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double a[100001];
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    double l = 0;
    double r = a[n - 1];
    while (r - l > 0.000001) {
        double mid = l + (r - l) / 2;
        if (check(mid, a)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << r << endl;
    return 0;
}