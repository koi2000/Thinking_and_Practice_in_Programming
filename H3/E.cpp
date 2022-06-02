//
// Created by DELL on 2022/3/9.
//
#include <bits/stdc++.h>

using namespace std;

int vis[8];
int res = 0;
int board[8][8];

void dfs(int n, int k, int len, int size) {
    if (size == k) {
        res++;
        return;
    }

    if (len >= n) {
        return;
    }

    for (int j = 0; j < n; ++j) {
        if (board[len][j] == 1) {
            if (vis[j] == 0) {
                vis[j] = 1;
                size++;
                dfs(n, k, len + 1, size);
                size--;
                vis[j] = 0;
            }
        }
    }
    dfs(n, k, len + 1, size);
}

int main() {
    int n, k;
    char tt;
    while (cin >> n >> k) {
        if (n == -1 && k == -1) {
            break;
        }
        for (int j = 0; j < n; j++) {
            for (int q = 0; q < n; q++) {
                cin >> tt;
                if (tt == '#') {
                    board[j][q] = 1;
                } else {
                    board[j][q] = 0;
                }
            }
        }
        memset(vis, 0, sizeof(vis));
        res = 0;
        dfs(n, k, 0, 0);
        cout << res << endl;
    }

    return 0;
}