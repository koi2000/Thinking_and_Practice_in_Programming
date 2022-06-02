//
// Created by DELL on 2022/3/30.
//
#include <bits/stdc++.h>

using namespace std;
//#define maxn 1e6
//#define maxm 1e5
const int maxn = 1e6;

struct edge {
    int u, v, w, nxt;
} edges[maxn];
int head[maxn];
int tot = 0;


void init() {
    memset(edges, -1, sizeof(edges));
    memset(head, -1, sizeof(head));
    tot = 0;
}

void addEdge() {

}

int f[maxn];

void inits() {
    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    f[x] = find(x);
    return f[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if(x==y)return false;
    f[x] = y;
    return true;
}

int kru(){
    inits();
    sort(edges,edges+tot);
    int ans = 0,cnt=0;
    for (int i = 0; i < tot; ++i) {
        if(unite())
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < n; i++) {
        cin >> w;
        edges[tot].u = 0;
        edges[tot].v = i;
        edges[tot].w = w;
        tot++;
    }

    for (int i = 0; i <= m; ++i) {
        cin >> u >> v >> w;
    }
    return 0;
}
