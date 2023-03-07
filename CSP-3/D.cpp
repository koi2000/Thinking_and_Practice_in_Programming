//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
using namespace std;

const ll N = 8020010;
struct edge {
    ll u, v, w, nxt;
};
edge edges[2 * N];
ll head[N];
ll tot = 0;
ll vis[N];
ll n, m;
ll dis[N];

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
}

void addEdge(ll u, ll v, ll w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

void dij(ll u) {
    priority_queue<pii, vector<pii >, greater<pii>> q;
    q.push({0, u});
    dis[u] = 0;

    while (!q.empty()) {
        pii nd = q.top();
        q.pop();
        if (vis[nd.second])continue;
        vis[nd.second] = 1;
        ll h = head[nd.second];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                q.push({dis[e.v], e.v});
            }
            h = edges[h].nxt;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    for (ll i = 0; i < m; ++i) {
        ll u, v, t1, t2;
        cin >> u >> v >> t1 >> t2;
        if (t1 != -1) {
            if (t1 % 2 == 1) {
                addEdge(u, v + n, t1);
                addEdge(v, u + n, t1);
            } else {
                addEdge(u, v, t1);
                addEdge(v, u, t1);
            }
        }
        if (t2 != -1) {
            if (t2 % 2 == 1) {
                addEdge(u + n, v, t2);
                addEdge(v + n, u, t2);
            } else {
                addEdge(u + n, v + n, t2);
                addEdge(v + n, u + n, t2);
            }
        }
    }
    for (ll i = 1; i <= n; ++i) {
        addEdge(i, i + n, 1);
        addEdge(i + n, i, 1);
    }
    dij(1);
    cout << min(dis[n], dis[2 * n]);
    return 0;
}
