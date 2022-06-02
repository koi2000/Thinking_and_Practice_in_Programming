//
// Created by DELL on 2022/3/9.
//
#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

using namespace std;

int vis[1000];
int dis[1000];

class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class node {
public:
    int dis;
    int pos;

    node(int dis, int pos) : dis(dis), pos(pos) {}

    bool operator>(const node& oth) const {
        return dis < oth.dis;
    }

    bool operator<(const node& oth) const {
        return dis > oth.dis;
    }
};

class graph {
public:
    int n;

    vector<list<edge>> nodes;

    graph(int n) {
        this->n = n;
        for (int i = 0; i <= n; ++i) {
            list<edge> temp;
            nodes.emplace_back(temp);
        }
    }

    void addEdge(int u, int v, int w) {
        edge e = edge(u, v, w);
        nodes[u].push_back(e);
    }

    void dijkstra(int s) {

        node sign = node(0, s);
        priority_queue<node> q;
        q.push(sign);
        memset(vis, 0, sizeof(vis));
        memset(dis, 125648440, sizeof(dis));
        dis[s] = 0;
        while (!q.empty()) {
            node ss = q.top();
            q.pop();
            if (vis[ss.pos] == 1) {
                continue;
            }
            vis[ss.pos] = 1;
            for (auto it = nodes[ss.pos].begin(); it != nodes[ss.pos].end(); it++) {
                if (dis[it->v] > dis[it->u] + it->w) {
                    dis[it->v] = dis[it->u] + it->w;
                }
                if (vis[it->v] == 0) {
                    q.push(node(dis[it->v], it->v));
                    //vis[it->v] = 1;
                }
            }
        }
    }
};


int main() {
    int n, a, b;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin >> a >> b;
        graph g = graph(n);
        for (int i = 1; i <= n; ++i) {
            int step;
            cin >> step;
            if (i - step > 0) {
                g.addEdge(i, i - step, 1);
            }
            if (i + step <= n) {
                g.addEdge(i, i + step, 1);
            }
        }
        if (b > n) {
            cout << -1 << endl;
            return 0;
        }
        g.dijkstra(a);
        if (vis[b] == 0) {
            cout << -1 << endl;
        }
        else {
            cout << dis[b] << endl;
        }
    }

    return 0;
}