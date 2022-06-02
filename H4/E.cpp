#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define maxn 100010
using namespace std;

int n, m;

double arr[maxn];
double amax[maxn];
double amin[maxn];
double sum[maxn];

bool check(double mid) {
    sum[0] = 0;
    amin[0] = INT32_MAX;
    for (int i = 1; i <= n; ++i) {
        sum[i] = sum[i - 1] + arr[i] - mid;
        amin[i] = min(sum[i], amin[i - 1]);
    }

    amax[n + 1] = INT_MIN;
    for (int i = n; i > 0; i--) {
        amax[i] = max(sum[i], amax[i + 1]);
    }
    double res = INT_MIN;
    amin[0] = 0;
    for (int i = 0; i <= n - m; i++) {
        res = max(amax[i + m] - amin[i], res);
    }
    return res >= 0;
}

int main() {
    cin >> n >> m;
    double maxx = INT_MIN;
    double minn = INT32_MAX;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        maxx = max(maxx, arr[i]);
        minn = min(minn, arr[i]);
    }
    double l = minn;
    double r = maxx;
    while (r - l > 0.00001) {
        double middle = l + (r - l) / 2.0;
        if (check(middle)) {
            l = middle;
        } else {
            r = middle;
        }
    }
    int w = r * 1000;
    cout << w << endl;
    return 0;
}