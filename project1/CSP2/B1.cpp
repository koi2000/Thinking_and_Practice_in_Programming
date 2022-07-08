//
// Created by DELL on 2022/3/22.
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
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    cin>>n;
    int idx = 0;
    int a[n];
    map<int,int>usr;
    for (int i = 0; i < n; ++i) {
        int num;
        cin>>num;
        for (int j = 0; j < num; ++j) {
            int t;
            cin>>t;
            if(usr.find(t)!=usr.end()){
                //user小于当前，更新user
                if(usr[t]<a[i-1]){
                    usr[t] = a[i-1];
                    a[i] = max(a[i-1],a[i]);
                }
            }else{
                usr[t] = idx;
            }
        }

    }
    return 0;
}




