//
// Created by DELL on 2022/3/23.
//
#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

#define ll long long
using namespace std;


int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mm;
    int ans = INT32_MAX;
    int l = 0;
    int r = -1;
    while (true) {
        if (r >= n) {
            break;
        }
        if (mm.size() == 26) {
            ans = min(ans, r - l + 1);
            if (mm[s[l]] > 1) {
                mm[s[l]]--;
            } else if (mm.find(s[l]) != mm.end()) {
                mm.erase(s[l]);
            }
            l++;
        } else {
            r++;
            if (r > s.size()) {
                break;
            }
            if (mm.find(s[r]) != mm.end()) {
                mm[s[r]]++;
            } else {
                mm[s[r]] = 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}





