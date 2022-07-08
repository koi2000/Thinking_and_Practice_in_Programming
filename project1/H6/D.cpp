//
// Created by DELL on 2022/1/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <list>
#include <vector>
#include <queue>
#include <map>

using namespace std;


class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class graph {
public:
    int n;
    vector<vector<edge>> head;

    int dis[100005];

    graph(int n) : n(n) {
        head.resize(n + 1);
        for (int i = 0; i < n + 1; ++i) {
            head[i] = vector<edge>();
        }
    }

    void addEdge(int u, int v) {
        edge e = edge(u, v, 1);
        head[u].push_back(e);
    }

    int getMax(int u) {
        dis[u] = 0;
        int vis[n + 1];
        memset(vis, 0, sizeof(vis));
        vis[u] = 1;
        queue<int> node;
        node.push(u);
        while (!node.empty()) {
            int sign = node.front();
            node.pop();
            for (auto it = head[sign].begin(); it != head[sign].end(); it++) {
                if (vis[it->v] == 0) {
                    dis[it->v] = dis[sign] + it->w;
                    node.push(it->v);
                    vis[it->v] = 1;
                }
            }
        }

        int mm = *max_element(dis + 1, dis + n + 1);
        memset(dis, 0, n + 1);
        return mm;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    graph g = graph(m);
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
        g.addEdge(v, u);
    }
    for (int i = 1; i <= m; ++i) {
        cout << g.getMax(i) << " ";
    }
    return 0;
}




