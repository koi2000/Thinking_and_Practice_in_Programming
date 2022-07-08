#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define maxn 100010
using namespace std;
int n, m;
long long a[maxn];

bool check(long long x) {
    int y = 1;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] > x) {
            sum = a[i];
            y++;
        } else sum += a[i];
    }
    if (y > m)return false;
    else return true;
}

int main() {
    cin >> n >> m;
    long long ans, l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        r += a[i];
        l = max(l, a[i]);
    }
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (check(mid)) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }
    printf("%lld\n", ans);
    return 0;
}