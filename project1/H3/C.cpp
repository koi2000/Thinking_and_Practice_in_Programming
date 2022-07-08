//
// Created by DELL on 2022/1/13.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include<list>

using namespace std;

class node {
public:
    int dis;
    int pos;

    node(int dis, int pos) : dis(dis), pos(pos) {}

    bool operator<(node other) const {
        return this->dis > other.dis;
    }

    bool operator>(node other) const {
        return this->dis < other.dis;
    }
};

class edge {
public:
    int u, v, w;

    edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

class graph {
public:

    int n;
    vector<list<edge>> head;
    vector<int> vis;
    vector<int> dis;

    graph(int n) : n(n) {
        //head.resize(n);
        for (int i = 0; i <= n; ++i) {
            list<edge> temp;
            head.push_back(temp);
        }
        vis.resize(n + 1);
        for (int i = 0; i < vis.size(); ++i) {
            vis[i] = 0;
        }
        dis.resize(n + 1);
        for (int i = 0; i < dis.size(); ++i) {
            dis[i] = 1256484400;
        }
    }

    void addEdge(int u, int w) {
        if (u + w <= n) {
            int v1 = u + w;
            edge nn = edge(u, v1, 1);
            head[u].push_back(nn);
        }
        if (u - w > 0) {
            int v2 = u - w;
            edge nn = edge(u, v2, 1);
            head[u].push_back(nn);
        }
    }

    void dijkstra(int u) {
        node sign = node(0, u);
        priority_queue<node> qq;
        dis[u] = 0;
        qq.push(sign);

        while (!qq.empty()) {
            node s = qq.top();
            qq.pop();

            if (vis[s.pos] == 1) {
                continue;
            }
            vis[s.pos] = 1;
            for (auto it = head[s.pos].begin(); it != head[s.pos].end(); it++) {
                if (dis[(*it).v] > dis[(*it).u] + (*it).w) {
                    dis[(*it).v] = dis[(*it).u] + (*it).w;
                }
                if (vis[(*it).v] == 0) {
                    //vis[(*it).v] = 1;
                    node nn = node(dis[(*it).v], (*it).v);
                    qq.push(nn);
                }
            }
        }
    }

};

int main() {

    int n, A, B;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        cin >> A >> B;
        graph g = graph(n);
        for (int i = 1; i <= n; ++i) {
            int temp;
            cin >> temp;
            g.addEdge(i, temp);
        }
        if (B > n) {
            cout << -1 << endl;
            return 0;
        }
        g.dijkstra(A);
        if (g.vis[B] == 0) {
            cout << -1 << endl;
        } else {
            cout << g.dis[B] << endl;
        }

    }
    return 0;
}

