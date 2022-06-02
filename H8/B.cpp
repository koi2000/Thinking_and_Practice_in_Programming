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

}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void kahn() {
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i = 1; i <= n; ++i) {
        if (in[i] == 0){
            q.push(i);
        }
    }
    vector<int>res;
    while (!q.empty()){
        int sign = q.top();
        res.push_back(sign);
        q.pop();
        ll h = head[sign];
        while (h!=-1){
            in[edges[h].v]--;
            if(in[edges[h].v]==0){
                q.push(edges[h].v);
            }
            h = edges[h].nxt;
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout<<res[i]<<" ";
    }
}

int main() {

    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int s, t;
        cin >> s >> t;
        addEdge(s, t, 1);
        //计算入度
        in[t]++;
    }
    kahn();
    return 0;
}
