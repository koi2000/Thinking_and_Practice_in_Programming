//
// Created by DELL on 2022/4/6.
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
edge edges[4 * maxn];
ll n, m;

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

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
    memset(dis,0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;

    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

ll distance(ll s) {
    priority_queue<sign> q;
    q.push({s, 0});
    dis[s] = 0;
    while (!q.empty()) {
        sign sign = q.top();
        q.pop();

        if (vis[sign.pos]) {
            continue;
        }
        vis[sign.pos] = 1;
        ll h = head[sign.pos];
        while (h != -1) {
            if (dis[edges[h].u] + edges[h].w < dis[edges[h].v]) {
                dis[edges[h].v] = dis[edges[h].u] + edges[h].w;
                if (!vis[edges[h].v]) {
                    q.push({edges[h].v, dis[edges[h].v]});
                }
            }
            h = edges[h].nxt;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int s[m];
        int e[m];
        int c[m];
        init();
        for (int i = 0; i < m; ++i) {
            //int s, e, c;
            cin >> s[i] >> e[i] >> c[i];
        }
        for (int i = 0; i < m; ++i) {
            addEdge(s[i], e[i], c[i]);
        }
        distance(1);
        ll sum = 0;
        for (int i = 1; i < n + 1; ++i) {
            sum += dis[i];
        }
        init();
        for (int i = 0; i < m; ++i) {
            addEdge(e[i], s[i], c[i]);
        }
        distance(1);
        for (int i = 1; i < n + 1; ++i) {
            sum += dis[i];
        }
        cout << sum << endl;
    }
    return 0;
}
