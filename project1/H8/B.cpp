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
#include <queue>

#define maxn 100000
using namespace std;

class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class node {
public:
    int pos;
    int dis;

    node(int pos, int dis) : pos(pos), dis(dis) {}

    bool operator<(const node &a) const {
        return this->dis > a.dis;
    }
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

    void addEdge(int u, int v, int w) {
        edge e = edge(u, v, w);
        head[u].push_back(e);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    graph g = graph(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g.addEdge(y, x, 1);
    }
    set<int> nodes;
    priority_queue<int, vector<int>, greater<int>> qq;

    for (int i = 0; i < g.head.size(); ++i) {
        if (g.head[i].size() == 0) {
            qq.push(i);
        }
    }
    vector<int> res;
    while (nodes.size() < n) {
        int sign = qq.top();
        nodes.insert(sign);
        res.push_back(sign);
        qq.pop();
        for (int i = 0; i < g.head.size(); ++i) {
            int flag = 0;
            for (int j = 0; j < g.head[i].size(); ++j) {
                if (nodes.find(g.head[i][j].v) == nodes.end()) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                nodes.insert(i);
                qq.push(i);
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    return 0;
}




