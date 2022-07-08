//
// Created by DELL on 2022/1/17.
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

bool check(double mid);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> all;

    int l = 0;
    int r = -1;
    int minl = 0;
    int minr = 0;
    int len = INT32_MAX;

    while (true) {
        if (all.size() < 26) {
            r++;
            if (r >= s.size()) {
                break;
            }
            if (all.find(s[r]) != all.end()) {
                all[s[r]]++;
            } else {
                all[s[r]] = 1;
            }
        }
        if (all.size() >= 26) {
            if (all[s[l]] > 1) {
                all[s[l]]--;
            } else {
                all.erase(s[l]);
            }

            if (r - l + 1 < len) {
                minl = l;
                minr = r;
                len = r - l + 1;
            }
            l++;
        }
    }
    cout << len << endl;
    return 0;
}




