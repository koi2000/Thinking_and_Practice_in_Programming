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
int n, m, p;

struct edge {
    ll u, v, w, nxt;

    bool operator>(const edge &ths) {
        return w > ths.w;
    }

    bool operator<(const edge &ths) {
        return w < ths.w;
    }
} edges[maxn];

int head[maxn];

void init() {
    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
}

ll find(ll x) {
    if (x == f[x]) {
        return x;
    }
    f[x] = find(f[x]);
    return f[x];
}

void unite(ll x, ll y) {
    ll fx = find(x);
    ll fy = find(y);
    f[fx] = fy;
}

int tot = 0;

void inits() {
    //memset(head, -1, sizeof(head));
    for (int i = 0; i <= n; ++i) {
        head[i] = -1;
    }
    tot = 0;
}

void kurl() {

    init();
    sort(edges, edges + tot);
    ll sum = 0;
    ll size = 0;
    for (int i = 0; i < tot; ++i) {
        if (find(edges[i].v) == find(edges[i].u)) {
            continue;
        }
        sum += edges[i].w;
        size++;
        unite(edges[i].u, edges[i].v);
        if (size == n + 1) {
            break;
        }
    }
    cout << sum << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    cin >> n >> m >> p;
    inits();
    for (int i = 1; i <= n; ++i) {
        edges[tot].u = 0;
        edges[tot].v = i;
        edges[tot].w = p;
        edges[tot].nxt = head[0];
        head[0] = tot;
        tot++;

        edges[tot].v = 0;
        edges[tot].u = i;
        edges[tot].w = p;
        edges[tot].nxt = head[i];
        head[i] = tot;
        tot++;
    }
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges[tot].u = a;
        edges[tot].v = b;
        edges[tot].w = c;
        edges[tot].nxt = head[a];
        head[a] = tot;
        tot++;
        edges[tot].v = a;
        edges[tot].u = b;
        edges[tot].w = c;
        edges[tot].nxt = head[b];
        head[b] = tot;
        tot++;
    }
    kurl();
    return 0;
}





