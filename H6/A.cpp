//
// Created by DELL on 2022/3/30.
//
#include <bits/stdc++.h>

#define maxn 100000
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> origin;
    origin.insert('a');
    origin.insert('e');
    origin.insert('i');
    origin.insert('o');
    origin.insert('u');
    int dp[n];
    for (int i = 0; i < n; ++i) {
        if (origin.find(s[i]) != origin.end()) {
            if (i == 0) {
                dp[i] = 1;
            }
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 0;
        }
    }
    cout<<*max_element(dp,dp+n);
    return 0;
}




