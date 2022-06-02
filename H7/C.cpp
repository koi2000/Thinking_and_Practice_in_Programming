//
// Created by DELL on 2022/4/6.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int maxn = 1e6 + 6;

struct edge {
    ll u, v, c, d, nxt;
};
ll tot = 0;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
ll cnt[maxn];
edge edges[4 * maxn];
ll n, m, t;

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

}

void addEdge(int u, int v, int c, int d) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].c = c;
    edges[tot].d = d;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

ll distance(ll s) {

}

bool check(ll c) {
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<sign> q;
    q.push({1, 0});
    dis[1] = 0;
    while (!q.empty()) {
        sign sign = q.top();
        q.pop();

        if (vis[sign.pos]) {
            continue;
        }
        vis[sign.pos] = 1;
        ll h = head[sign.pos];
        while (h != -1) {
            if (dis[edges[h].u] + edges[h].d < dis[edges[h].v]) {
                if (edges[h].c >= c) {
                    dis[edges[h].v] = dis[edges[h].u] + edges[h].d;
                    if (!vis[edges[h].v]) {
                        q.push({edges[h].v, dis[edges[h].v]});
                    }
                }
            }
            h = edges[h].nxt;
        }
    }
    if (dis[n] <= t) {
        return true;
    }else{
        return false;
    }
}

int main() {
    int X;
    cin >> X;
    // 二分答案，枚举所有可能的c，然后进行check
    while (X--) {
        cin >> n >> m >> t;
        ll cs[m];
        ll minn = INT32_MAX;
        ll maxx = -1;
        init();
        for (int i = 0; i < m; ++i) {
            ll a, b, c, d;
            cin >> a >> b >> c >> d;
            cs[i] = c;
            minn = min(minn, c);
            maxx = max(maxx, c);
            addEdge(a, b, c, d);
            addEdge(b, a, c, d);
        }
        sort(cs, cs + m);
        ll l = minn;
        ll r = maxx;
        while (r - l > 1) {
            ll mid = l + (r - l) / 2;
            // 如果满足了，就
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << endl;
        //cout << r << endl;
    }
    return 0;
}