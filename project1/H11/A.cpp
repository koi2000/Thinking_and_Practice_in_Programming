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

#define maxn 1000009
#define ll long long
using namespace std;

ll f[maxn];
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    set<int> unsafe;

    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        unsafe.insert(t);
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    for (int i = 0; i <= n; ++i) {
        if (unsafe.find(i) != unsafe.end()) {
            f[i] = 0;
        } else {
            for (int j = i - 1; j >= 0 && (i - j) <= k; j--) {
                f[i] = (f[i] + f[j]) % mod;
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}




