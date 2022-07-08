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
    set<char> yuan;
    yuan.insert('a');
    yuan.insert('e');
    yuan.insert('i');
    yuan.insert('o');
    yuan.insert('u');
    int dp[n];
    for (int i = 0; i < n; ++i) {
        if (yuan.find(s[i]) != yuan.end()) {
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




