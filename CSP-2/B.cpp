//
// Created by csp on 2022/4/12.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
int n = 0;

int main() {
    cin >> n;
    ll app[n + 1];
    ll sum[n + 1];
    //memset(sum, 0, sizeof(sum));
    sum[0] = 0;
    app[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> app[i];
        sum[i] = sum[i - 1] + app[i];
    }

    ll cnt = 0;
    ll summ = sum[n];
    set<int> ff;
    set<int> ee;
    int idx = 0;
    for (int i = 1; i < n; i++) {
        if (sum[i] == summ / 3) {
            ff.insert(i);
        }
    }
    map<int,int>eee;
    for (int i = 1; i < n; ++i) {
        if (sum[i] == summ * 2 / 3) {
            ee.insert(i);
            eee[i] = idx;
            idx++;
        }
    }
    if(summ==0){
        for (auto &it:ff) {
            auto c = ee.lower_bound(it);
            cnt += (idx - 1 - eee[*c]);
        }
        cout<<cnt;
        return 0;
    }
    for (auto &it:ff) {
        auto c = ee.upper_bound(it);
        cnt += (idx - 1 - eee[*c]);
    }
    cout << cnt;
    return 0;
}