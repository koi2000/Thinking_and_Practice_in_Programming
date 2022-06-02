//
// Created by DELL on 2022/4/13.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 1e6 + 6;

struct edge {
    ll u, v, w, nxt;
};
ll tot = 0;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
ll cnt[maxn];
ll in[maxn];
edge edges[4 * maxn];
int n, m;

void init() {
    tot = 0;
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
    memset(cnt,0,sizeof (cnt));
}

int flag = 0;

void spfa(int s) {
    for (int i = 0; i <= n; ++i) {
        vis[i] = 0;//节点i是否在队列中
        dis[i] = INT32_MAX;
    }
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int sign = q.front();

        q.pop();
        vis[sign] = 0;
        ll h = head[sign];

        while (h != -1) {
            ll u = edges[h].u;
            ll v = edges[h].v;
            ll ww = edges[h].w;
            if (dis[u] + ww < dis[v]) {
                dis[v] = dis[u] + ww;
                if (!vis[v]) {
                    cnt[v] = cnt[u] + 1;
                    if (cnt[v] >= n) {
                        flag = 1;
                        return;
                    }
                    q.push(v);
                    vis[v] = 1;
                }
            }
            h = edges[h].nxt;
        }
    }
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int k, a, b, c;
        cin >> k >> a >> b >> c;
        if (k == 1) {
            addEdge(a - 1, b, c);
        } else if (k == 2) {
            addEdge(b, a - 1, -c);
        } else if (k == 3) {
            addEdge(a - 1, b, c - 1);
        } else if (k == 4) {
            addEdge(b, a - 1, -(c + 1));
        } else if (k == 5) {
            addEdge(a - 1, b, c);
            addEdge(b, a - 1, -c);
        }
    }
    for (int i = 0; i < n; ++i) {
        addEdge(i, i+1, 1);
        addEdge(i + 1, i, 0);
    }
    spfa(0);
    //cout << "impossible";
    if (flag) {
        cout << "impossible";
    } else {
        cout << dis[n];
    }
    return 0;
}