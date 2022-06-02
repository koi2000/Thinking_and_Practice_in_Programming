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
ll tot1 = 0;
ll tot2 = 0;
ll head1[maxn];
ll head2[maxn];
ll dis[maxn];
ll cnt[maxn];
ll in[maxn];
ll out[maxn];
edge edges1[4 * maxn];
edge edges2[4 * maxn];

int n, m;
// f数组dfs后续数组，c[i] scc编号，
ll dfn[maxn], vis[maxn], re[maxn], dcnt, scnt;
ll c[maxn];
int ine[maxn];

void dfs1(ll x) {
    // 将已经看到的进行标记
    vis[x] = 1;
    // 开始dfs
    for (ll h = head1[x]; h != -1; h = edges1[h].nxt) {
        if (!vis[edges1[h].v]) {
            dfs1(edges1[h].v);
        }
    }
    // 求后序
    dfn[++dcnt] = x;
}

void dfs2(ll x) {
    c[x] = scnt;
    for (ll h = head2[x]; h != -1; h = edges2[h].nxt) {
        if (!c[edges2[h].v]) {
            dfs2(edges2[h].v);
        }
    }
}


void init() {
    tot1 = 0;
    tot2 = 0;
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
}

void addEdge(int u, int v, int w) {
    edges1[tot1].u = u;
    edges1[tot1].v = v;
    edges1[tot1].w = w;
    edges1[tot1].nxt = head1[u];
    head1[u] = tot1;
    tot1++;

    edges2[tot2].u = v;
    edges2[tot2].v = u;
    edges2[tot2].w = w;
    edges2[tot2].nxt = head2[v];
    in[u]++;
    out[v]++;
    head2[v] = tot2;
    tot2++;
}

void kosaraju() {
    scnt = 0;
    dcnt = 0;
    memset(c, 0, sizeof c);
    memset(vis, 0, sizeof vis);

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    for (int i = n; i >= 1; --i) {
        if (!c[dfn[i]]) {
            ++scnt;
            dfs2(dfn[i]);
        }
    }
}

//求连通分量的个数
int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b, 1);
    }
    kosaraju();

    for (int i = 1; i <= n; i++) {
        for (int p = head1[i]; p != -1; p = edges1[p].nxt) {

            if (c[i] != c[edges1[p].v]) {

                ine[c[edges1[p].v]]++;
            }
        }
    }

    int count = 0;
    for (int i = 1; i <= scnt; i++) {
        if (ine[i] == 0) count++;
    }
    printf("%d\n", count);
    return 0;
}
