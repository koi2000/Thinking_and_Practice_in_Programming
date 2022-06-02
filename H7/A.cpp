//
// Created by DELL on 2022/4/6.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const ll maxn = 50000;

struct edge {
    ll u, v, w, nxt;
};
ll tot = 0;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
ll cnt[maxn];
edge edges[4 * maxn];
ll n, m, w;

struct sign {
    ll pos;
    ll dis;

    sign(ll pos, ll dis) : pos(pos), dis(dis) {}

    bool operator<(const sign &rhs) const {
        return dis > rhs.dis;
    }

    bool operator>(const sign &rhs) const {
        return dis < rhs.dis;
    }
};

ll lastn = 0;

void init() {
//    memset(head, -1, sizeof(head));
//    memset(vis, 0, sizeof(vis));
    for (ll i = 0; i < n + 1; ++i) {
        dis[i] = INT32_MAX;
    }
    for (ll i = 0; i < n + 1; ++i) {
        head[i] = -1;
    }
    for (ll i = 0; i < n + 1; ++i) {
        vis[i] = 0;
    }
    for (int i = 0; i < n + 1; ++i) {
        cnt[i] = 0;
    }
    for (int i = 0; i <= tot; ++i) {
        edges[i].u = 0;
        edges[i].v = 0;
        edges[i].w = 0;
        edges[i].nxt = 0;
    }
    lastn = n;
    tot = 0;
}


void spfa(int s) {
    for (int i = 1; i <= n; ++i) {
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
                    if (cnt[v] >= n) return;
                    q.push(v);
                    vis[v] = 1;
                }
            }
            h = edges[h].nxt;
        }
    }
}

void addEdge(ll u, ll v, ll w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

int main() {
    ll f;
    cin >> f;
    while (f--) {
        cin >> n >> m >> w;
        init();
        for (ll i = 0; i < m; ++i) {
            ll s, e, t;
            cin >> s >> e >> t;
            addEdge(s, e, t);
            addEdge(e, s, t);
        }
        for (ll i = 0; i < w; ++i) {
            ll s, e, t;
            cin >> s >> e >> t;
            addEdge(s, e, -t);
        }
        ll flag = 0;
        for (int i = 1; i <= n; ++i) {
            // 计算该点到所有点的最小距离
            spfa(i);
            for (ll j = 1; j <= n; ++j) {
                // 再次遍历所有点的所有边，找到v为当前点的点
                if (j == i) {
                    continue;
                }
                ll h = head[j];
                while (h != -1) {
                    if (edges[h].v == i) {
                        if (edges[h].w + dis[j] < 0) {
                            cout << "YES" << endl;
                            flag = 1;
                            break;
                        }
                    }
                    h = edges[h].nxt;
                }
                if (flag == 1) break;
            }
            if (flag == 1) break;
        }
        if (flag == 0) cout << "NO" << endl;
    }

    return 0;
}
