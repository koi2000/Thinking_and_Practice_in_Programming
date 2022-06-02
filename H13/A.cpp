//
// Created by DELL on 2022/5/18.
//
#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int m = n;
    n = 2 * n - 1;
    int a[n + 1];
    // 前缀和数组，方便o1的获得区间和
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
    int mindp[n + 1][n + 1];
    int maxdp[n + 1][n + 1];
    // 将值进行初始化
    memset(mindp, 0x3f, sizeof mindp);
    memset(maxdp, -0x3f, sizeof maxdp);
    for (int i = 0; i <= n; ++i) {
        mindp[i][i] = 0;
        maxdp[i][i] = 0;
    }
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            // 想要获得l,r之间石子合并的最小值，枚举每一种情况
            int l = i;
            int r = i + len - 1;
            for (int j = l; j < r; ++j) {
                mindp[l][r] = min(mindp[l][r], sum[r] - sum[l - 1] + mindp[l][j] + mindp[j + 1][r]);
                maxdp[l][r] = max(maxdp[l][r], sum[r] - sum[l - 1] + maxdp[l][j] + maxdp[j + 1][r]);
            }
        }
    }
    int Max = -INT_MIN;
    int Min = INT32_MAX;
    // 然后枚举每个隔板，找到长度为m时的最大值和最小值
    for(int i = 1; i <= m; i++){
        Max = max(Max, maxdp[i][i + m - 1]);
        Min = min(Min, mindp[i][i + m - 1]);
    }
    cout << Min << endl;
    cout << Max << endl;
    return 0;
}
