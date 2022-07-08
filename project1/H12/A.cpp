//
// Created by DELL on 2022/1/18.
//
#include <bits/stdc++.h>

using namespace std;
vector<int> weight;
vector<int> value;
int num;

int f(int i, int cap) {
    if (i == num) {
        return cap >= weight[i] ? value[i] : 0;
    }
    if (weight[i] > cap) {
        return f(i + 1, cap);
    }
    return max(f(i + 1, cap), f(i + 1, cap - weight[i]) + value[i]);
}

int main() {
    int c;
    cin >> num;
    cin >> c;
    num--;
    for (int i = 0; i <= num; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        weight.push_back(t1);
        value.push_back(t2);
    }
    int dp[c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= num; ++i) {
        for (int j = c; j >= weight[i]; --j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout<<dp[c]<<endl;
    /*int dp[num+1][c+1];

    memset(dp, 0, sizeof(dp));//一维记得清空

    for (int i = 1; i <= num; i++) {
        for (int j = c; j >= 0; j--) {
            if (j >= weight[i]) {//如果背包装得下当前的物体
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            } else {//如果背包装不下当前物体
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[num][c] << endl;*/
    return 0;
}


