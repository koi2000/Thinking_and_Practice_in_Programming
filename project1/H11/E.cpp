//
// Created by DELL on 2022/1/18.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    int b[m+1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; ++j) {
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}
