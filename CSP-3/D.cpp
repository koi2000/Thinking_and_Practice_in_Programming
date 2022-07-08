//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

vector< pair<int, int> > edge[800009];
int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, t1, t2;
        cin >> u >> v >> t1 >> t2;
        if (t1 != -1) {
            if(t1%2==1){
                edge[u].emplace_back(v+n,t1);
                edge[v].emplace_back(u+n,t1);
            }else{
                edge[u].emplace_back(v,t1);
                edge[]
            }

        }
    }
    return 0;
}
