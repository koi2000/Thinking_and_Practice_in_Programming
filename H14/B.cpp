//
// Created by DELL on 2022/5/25.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
vector<ll> ks;
const int maxn = 2e5 + 6;
const int maxk = 101;
struct edge {
    ll u, v, w, nxt;
} edges[maxn];
ll tot = 0;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
ll N, M, K;
ll dp[maxn][maxk];
ll ans = LONG_LONG_MAX;
ll numk[maxn];

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void dfs(ll u, ll f) {
    dp[u][0] = 0;
    // 如果当前节点为重要节点，则记录numk为1
    if (ks[u]) {
        // 以u为根的子树选择一个节点时值为0
        dp[u][1] = 0;
        numk[u]++;
    }
    ll h = head[u];
    while (h != -1) {
        // 遍历到根节点直接返回
        if (edges[h].v == f){
            h = edges[h].nxt;
            continue;
        }
        dfs(edges[h].v, u);
        // 加上v所得的节点数量
        numk[u] += numk[edges[h].v];
        for (int j = min(K, numk[u]); j >= 0; j--) {
            for (int l = 0; l <= j && l <= min(K, numk[edges[h].v]); ++l) {
                dp[u][j] = min(dp[u][j], dp[edges[h].v][l] + dp[u][j - l] + l * (K - l) * edges[h].w);
            }
        }
        h = edges[h].nxt;
    }
    ans = min(ans, dp[u][K]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    ks.resize(N+1);
    init();
    for (int i = 0; i < M; ++i) {
        int tmp;
        cin >> tmp;
        ks[tmp] = 1;
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    memset(dp,0x3f,sizeof dp);
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}

