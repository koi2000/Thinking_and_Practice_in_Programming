//
// Created by DELL on 2022/3/23.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

#define ll long long

const ll mod = 1000000007;
using namespace std;

map<ll, ll> maps;

map<ll, ll> split(ll num) {
    //存储本次的结果
    map<ll, ll> res;
    ll n = num;
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            n /= i;
            if (res.find(i) != res.end()) {
                res[i]++;
            } else {
                res[i] = 1;
            }
            i--;
        }
    }
    //更新全局maps，里面存储每一项的最小值
    for (auto &item:maps) {
        if (res.find(item.first) != res.end()) {
            maps[item.first] = min(res[item.first], item.second);
        } else {
            maps[item.first] = 0;
        }
    }
    return res;
}

ll qpow(ll v, ll u) {
    ll res = 1;
    while (u) {
        if (u & 1) {
            res = res * v % mod;
        }
        v = v * v % mod;
        u = u >> 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    ll a[n + 1];
    vector<ll> arr[n + 2];
    //memset(a, 1, sizeof(a));
    for (int i = 0; i < n + 1; ++i) {
        a[i] = 1;
    }
    //存储每一个数前n位
    vector<map<ll,ll>>res(n+2);
    for (int i = 0; i < m; ++i) {
        ll l, r, c, d;
        cin >> l >> r >> c >> d;
        map<ll,ll>tmpl = res[l];
        map<ll,ll>tmpr = res[r+1];
        for (int j= 2; j<= c; j++) {
            if (c % j == 0) {
                c /= j;
                if (tmpl.find(j) != tmpl.end()) {
                    tmpl[j]+=d;
                } else {
                    tmpl[j] = d;
                }
                if(tmpr.find(j)!=tmpr.end()){
                    tmpr[j]-=d;
                }else{
                    tmpr[j] = -d;
                }
                j--;
            }
        }
        res[l] = tmpl;
        res[r+1] = tmpr;
    }
    for(int i=1;i<=n;i++){
        for(auto &item:res[i-1]){
            if(res[i].find(item.first)!=res[i].end()){
                res[i][item.first] = res[i][item.first] + res[i-1][item.first];
            }else{
                res[i][item.first] = item.second;
            }
        }
    }
    map<ll,ll>ret;
    map<ll,ll>re = res[n];
    ll sum = 1;

    for(auto &item:re){
        ll maxx = item.second;

        for (int i = 1; i < n; i++) {
            if(res[i].find(item.first)!=res[i].end()){
                maxx = min(maxx,res[i][item.first]);
            }else{
                maxx = 0;
            }
        }
        ret[item.first] = maxx;
    }
    for(auto &item:ret){
        sum *= qpow(item.first,item.second);
    }
    cout << sum << endl;
    return 0;
}





