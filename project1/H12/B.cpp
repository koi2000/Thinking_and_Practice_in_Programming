//
// Created by DELL on 2022/1/18.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

#define maxn 100000
using namespace std;

vector<int> weight;
vector<int> value;
int num;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> num;
    cin >> c;
    num--;
    vector<vector<int>> f;//f状态矩阵
    for (int i = 0; i <= num; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        weight.push_back(t1);
        value.push_back(t2);
    }
    int dp[c + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= num; ++i) {
        for (int j = weight[i]; j <= c; j++) {
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




