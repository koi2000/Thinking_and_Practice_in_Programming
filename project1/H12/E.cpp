//
// Created by DELL on 2022/1/18.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> weight;
vector<int> value;
int num;

ll f(int i, ll cap) {
    if (i == num) {
        return cap >= weight[i] ? value[i] : 0;
    }
    if (weight[i] > cap) {
        return f(i + 1, cap);
    }
    return max(f(i + 1, cap), f(i + 1, cap - weight[i]) + value[i]);
}

int main() {
    ll c;
    cin >> num;
    cin >> c;
    for (int i = 0; i < num; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        weight.push_back(t1);
        value.push_back(t2);
    }
    cout<<f(0,c);
    /*int dp[c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= num; ++i) {
        for (int j = c; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout<<dp[c]<<endl;*/
    return 0;
}


