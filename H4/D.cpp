#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define maxn 100010
#define ll long long

using namespace std;
int n, m;
double arr[100010];

double a[maxn], sum[maxn];
double mn[maxn], mx[maxn];

bool check(double mid) {
    mn[0] = 2000;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + a[i] - mid;
        mn[i] = min(mn[i - 1], sum[i]);
    }
    mx[n + 1] = -0x7fffffff;
    for (int i = n; i >= 1; i--) {
        mx[i] = max(mx[i + 1], sum[i]);
    }
    double res = -0X7fffffff;
    mn[0] = 0;
    for (int i = 0; i <= n - m; i++) {
        res = max(res, mx[i + m] - mn[i]);
    }
    return res >= 0;
}
/*
12 6
1
2
1
2
1
1
1
1
1
1
1
1
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    double minn = 2000;
    double maxx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        minn = min(arr[i], minn);
        maxx = max(arr[i], maxx);
    }
    double l = minn;
    double r = maxx;
    while (r - l > 0.00001) {
        double mid = (l + r) / 2.0;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int w = r * 1000;
    cout << w << endl;
    return 0;
}
