//
// Created by DELL on 2022/4/13.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            s[i] = 'a';
        }
    }
    int dp[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = 0;
            }
        }
    }
    ll maxlen = 0;
    for (int r = 1; r < n; ++r) {
        for (int l = 0; l < n; ++l) {
            if(s[r]==s[l]&&(r-l<=2)){
                dp[l][r] = 1;
            }else if(s[r]==s[l]){
                dp[l][r] = dp[l+1][r-1];
            }
            if(dp[l][r]){
                maxlen = max(maxlen,(ll)(r-l+1));
            }
        }
    }
    cout << maxlen << endl;
    return 0;
}
