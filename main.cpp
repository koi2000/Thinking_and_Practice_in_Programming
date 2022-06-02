#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxN = 5009;

int main() {
    int m, n;
    cin >> m;
    n = 2 * m - 1;
    int a[n + 1];
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = m + 1; i <= n; ++i) {
        a[i] = a[i - m];
        sum[i] = sum[i - 1] + a[i];
    }
    int mindp[n+1][n+1];
    int maxdp[n+1][n+1];
    for (int i = 0; i < ; ++i) {

    }
    return 0;
}