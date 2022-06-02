//
// Created by DELL on 2022/5/25.
//
#include <bits/stdc++.h>

#define ll long long
#define MAXN 100010

using namespace std;

class edge {
public:
    int u, v;

    edge() {}

    edge(int u, int v) : u(u), v(v) {}

};

vector<int> edges[MAXN];

int d[MAXN];
int far[MAXN];
int cntd[MAXN];
int cntf[MAXN];

void dfs(int x, int f) {
    cntf[x] = 1;
    //cntd[x] = 0;
    // 遍历每个点所有出边
    for (int i = 0; i < edges[x].size(); i++) {
        if (edges[x][i] == f)continue;
        // 继续dfs
        dfs(edges[x][i], x);
        // 更新最大值
        if (far[edges[x][i]] + 1 > far[x]) {
            far[x] = far[edges[x][i]] + 1;
            cntf[x] = cntf[edges[x][i]];
        } else if (far[edges[x][i]] + 1 == far[x]) {
            // 如果该节点到尾的值等于far[x]，则可以更新
            cntf[x] += cntf[edges[x][i]];
        }
    }

    d[x] = far[x];
    cntd[x] = cntf[x];

    for (int i = 0; i < edges[x].size(); ++i) {
        if (edges[x][i] == f)continue;
        if (d[edges[x][i]] > d[x]) {
            d[x] = d[edges[x][i]];
            cntd[x] = cntd[edges[x][i]];
        } else if (d[edges[x][i]] == d[x]) {
            cntd[x] += cntd[edges[x][i]];
        }
    }

    if (edges[x].size() < 2 && f == 0)return;
    if (f != 0 && edges[x].size() < 3)return;

    int maxx1 = 0;
    int maxx2 = 0;
    for (int i = 0; i < edges[x].size(); ++i) {
        if (edges[x][i] == f)continue;
        if (far[edges[x][i]] + 1 > maxx2) {
            maxx2 = far[edges[x][i]] + 1;
        }
        if (maxx2 > maxx1) {
            swap(maxx1, maxx2);
        }
    }
    ll sum = 0;
    if (maxx1 == maxx2) {
        ll cnt = 0;
        for (int i = 0; i < edges[x].size(); ++i) {
            if (edges[x][i] == f)continue;
            if (far[edges[x][i]] + 1 == maxx1) {
                sum += cntf[edges[x][i]] * cnt;
                cnt += cntf[edges[x][i]];
            }
        }
    } else {
        ll cnt1 = 0;
        ll cnt2 = 0;
        for (int i = 0; i < edges[x].size(); ++i) {
            if (edges[x][i] == f)continue;
            if (far[edges[x][i]] + 1 == maxx1) {
                cnt1 += cntf[edges[x][i]];
            }
            if (far[edges[x][i]] + 1 == maxx2) {
                cnt2 += cntf[edges[x][i]];
            }
        }
        sum = cnt1 * cnt2;
    }
    if (maxx1 + maxx2 > d[x]) {
        d[x] = maxx1 + maxx2;
        cntd[x] = sum;
    } else if (maxx1 + maxx2 == d[x]) {
        cntd[x] += sum;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 0);
    cout << d[1] << " " << cntd[1] << endl;
    return 0;
}

