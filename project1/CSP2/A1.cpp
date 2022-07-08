//
// Created by DELL on 2022/3/22.
//
//#include <bits/stdc++.h>
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin >> n;
    int flag = 0;
    int idx = 0;
    int minn = INT32_MAX;
    for (int j = 0; j < n; ++j) {
        int p;
        cin>>p;
        string s;
        cin >> s;
        map<char, int> bub;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                if (bub.find(s[i]) != bub.end()) {
                    bub[s[i]]++;
                } else {
                    bub[s[i]] = 1;
                }
            }
            if (s[i] == '1') {
                if (bub.find(s[i]) != bub.end()) {
                    bub[s[i]]++;
                } else {
                    bub[s[i]] = 1;
                }
            }
            if (s[i] == '5') {
                if (bub.find(s[i]) != bub.end()) {
                    bub[s[i]]++;
                } else {
                    bub[s[i]] = 1;
                }
            }
        }
        if (bub.size() == 3 && bub['0'] >= 2) {
            flag = 1;

            if(p<minn){
                minn = p;
                idx = j;
            }

        }
    }
    if (flag == 0) {
        cout << 0 << endl;
    }else{
        cout << ++idx << endl;
    }
    return 0;
}




