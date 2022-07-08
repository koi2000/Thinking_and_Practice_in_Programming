//
// Created by DELL on 2022/1/11.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>bucket[n];
    int s,t;
    for (int i = 0; i < m; i++) {
        cin>>s>>t;
        bucket[t-1].push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        sort(bucket[i].begin(),bucket[i].end());
    }
    for (int i = 0; i < n; ++i) {
        for (int j : bucket[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}


