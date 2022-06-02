#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define maxn 100010
#define ll long long
using namespace std;


int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> works;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (auto &i:a) {
        if (i.first > works.size()) {
            ans += i.second;
            works.push(i.second);
        } else {
            if(works.top()<i.second){
                ans -= works.top();
                works.pop();
                works.push(i.second);
                ans+=i.second;
            }

        }
    }
    cout << ans << endl;
    return 0;
}