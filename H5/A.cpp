//
// Created by DELL on 2022/3/23.
//
//
// Created by DELL on 2022/3/22.
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    cin >> n;
    string s;
    cin >> s;
    cin >> m;
    int mat[n + 1][26];
    memset(mat, 0, sizeof(mat));
    for (int i = 1; i <= n; i++) {
        //mat[i] = mat[i-1];
        for (int j = 0; j < 26; j++) {
            mat[i][j] = mat[i - 1][j];
        }
        mat[i][s[i-1] - 'A']++;
    }

    for (int j = 0; j < m; j++) {
        int l, r;
        cin >> l >> r;
        int flag = 0;
        for (int i = 0; i < 26; i++) {
            if (mat[r][i] - mat[l - 1][i] <= 0) {
                cout << "NO" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            cout << "YES" << endl;
        }
    }

    return 0;
}





