//
// Created by DELL on 2022/4/12.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 1e6 + 8;
ll dis[maxn];
ll vis[maxn];
struct edge {
    ll u, v, w, nxt;
} edges[4 * maxn];

struct node {
    ll pos, dis;

    bool operator>(const node &rhs) {
        return this->dis < rhs.dis;
    }

    bool operator<(const node &rhs) {
        return this->dis > rhs.dis;
    }

};

ll head[maxn];
int tot = 0;

void init() {
    tot = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(ll u, ll v, ll w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void dijkra(ll s) {
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    priority_queue<node> q;
    q.push({s,0});

}

void spfa(ll s){
    memset(dis,0x3f3f3f3f,sizeof(dis));
    memset(vis,0,sizeof(vis));

    queue<int>q;
    q.push(s);
    vis[s] = 1;
    while(!q.empty()){
        int sign = q.front();
        q.pop();
        vis[sign] = 0;
        ll h = head[sign];
        while (h!=-1){
            ll u = edges[h].u;
            ll v = edges[h].v;
            ll w = edges[h].w;
            if(dis[u]+w<dis[v]){
                dis[v] = dis[u]+w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void singleStack(int n){
    deque<pair<int,int>>q;

}

int main() {

//    int l,r;
//    while(l<=r){
//        int mid=(l+r)/2;
//        if(judge(mid)){
//            ans=mid;
//
//        }else{
//
//        }
//    }
    return 0;
}
