//
// Created by DELL on 2022/1/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>
#include <map>
#define MAX 1000005
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

    bool operator<(const node& a) const {
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

    void dijkstra(int u) {
        //重写了小于号的方法，默认建立大根堆，但由于重载方法，其实建立的是小根堆
        priority_queue<node> q;
        int vis[100005];
        memset(vis,0,sizeof(vis));
        for (int i = 1; i <= n; ++i) {
            //初始的距离均为极大值
            dis[i] = MAX;
        }
        //到自身的距离为0
        dis[u] = 0;
        q.push(node(u, 0));
        while (!q.empty()) {
            //每次从堆中取出一个数，即为当前的位置
            node sign = q.top();
            q.pop();
            int x = sign.pos;
            //避免两次被取到形成环的情况
            if (vis[x]) continue;
            vis[x] = true;
            //遍历这个点所发出的所有的边
            for (auto it = head[x].begin(); it != head[x].end(); it++) {
                int y = (*it).v;
                //这里计算该点到任意一点的最小距离，若发现新的最小距离，则进行更新
                if (dis[y] > dis[x] + (*it).w) {
                    dis[y] = dis[x] + (*it).w;
                    //如果目前这个节点没有被走过，就把这个节点放入堆中
                    if (!vis[y]) {
                        q.push(node(y, dis[y]));
                    }
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int f;
    cin >> f;

    for (int i = 0; i < f; ++i) {
        int n, m, w;
        cin >> n >> m >> w;
        graph g = graph(n);
        int s, e, t;
        for (int j = 0; j <= m; ++j) {
            cin >> s >> e >> t;
            g.addEdge(s, e, t);
            g.addEdge(e, s, t);
        }
        for (int j = m + 1; j < m + w; ++j) {
            cin >> s >> e >> t;
            g.addEdge(s, e, -t);
        }
        g.dijkstra(1);
        int a = 1;
        g.dis;
    }

    return 0;
}




