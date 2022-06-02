//
// Created by DELL on 2022/3/30.
//
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

#define ll long long
using namespace std;

const int maxn = 1000005;
ll f[maxn];
int n;
int tot = 0;
int head[maxn];

struct edge {
    ll u, v, w, nxt;

    bool operator>(const edge &ths) {
        return w > ths.w;
    }

    bool operator<(const edge &ths) {
        return w < ths.w;
    }
} edges[maxn];

void inits() {
    //memset(head, -1, sizeof(head));
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
    }
    tot = 0;
}

ll dis[maxn];
int vis[maxn];

struct sign {
    ll pos;
    ll dis;

    sign(long long int pos, long long int dis) : pos(pos), dis(dis) {}

    bool operator<(const sign &rhs) const {
        return dis > rhs.dis;
    }

    bool operator>(const sign &rhs) const {
        return dis < rhs.dis;
    }
};

void initdis() {
    memset(vis, 0, sizeof(vis));
//    memset(dis, 0x3fffffff, sizeof(dis));
    for (int i = 0; i < n+1; ++i) {
        dis[i] = INT32_MAX;
    }
}

ll distance(int s) {
    initdis();
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
        int h = head[sign.pos];
        while (h!= -1) {
            if (dis[edges[h].u] + edges[h].w < dis[edges[h].v]) {
                dis[edges[h].v] = dis[edges[h].u] + edges[h].w;
                if (!vis[edges[h].v]) {
                    q.push({edges[h].v, dis[edges[h].v]});
                }
            }
            h = edges[h].nxt;
        }
    }
    ll maxk = 0;
    ll maxv = -1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] > maxv) {
            maxk = i;
            maxv = dis[i];
        }
    }
    return maxk;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> n;
    inits();
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        edges[tot].u = a;
        edges[tot].v = b;
        edges[tot].w = 1;
        edges[tot].nxt = head[a];
        head[a] = tot;
        tot++;

        edges[tot].u = b;
        edges[tot].v = a;
        edges[tot].w = 1;
        edges[tot].nxt = head[b];
        head[b] = tot;
        tot++;
    }
    ll s1 = distance(1);
    ll s2 = distance(s1);
    vector<ll> res1(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        res1[i] = (dis[i]);
    }
    distance(s2);
    for (int i = 1; i < n + 1; ++i) {
        cout << max(dis[i], res1[i]) << " ";
    }
    return 0;
}





