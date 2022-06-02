#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll N, V;
ll w[41];
ll c[41];
vector<pair<ll, ll>> res1;
vector<pair<ll, ll>> res2;

void generate() {

}

int main() {
    cin >> N >> V;
    for (int i = 0; i < N; ++i) {
        cin >> w[i] >> c[i];
    }
    ll mid = N / 2;
    ll part1 = 1 << mid;
    // 二进制枚举前一半每一种情况
    for (int i = 0; i < part1; ++i) {
        ll sumw = 0, sumv = 0;
        for (ll j = 0; j < mid; ++j) {
            sumw += ((i >> j) & 1) * w[j];
            sumv += ((i >> j) & 1) * c[j];
        }
        res1.push_back({sumw, sumv});
    }
    ll part2 = 1 << (N - mid);
    // 二进制枚举后一半每一种情况
    for (ll i = 0; i < part2; ++i) {
        ll sumw = 0, sumv = 0;
        for (ll j = 0; j < N - mid; ++j) {
            sumw += ((i >> j) & 1) * w[j + mid];
            sumv += ((i >> j) & 1) * c[j + mid];
        }
        res2.push_back({sumw, sumv});
    }
    // 根据重量排序
    sort(res1.begin(), res1.end());
    vector<pair<ll, ll> > v1;
    vector<pair<ll, ll> > v2;
    v1.push_back(res1[0]);
    v2.push_back(res2[0]);
    // 选取性价比较高的组合，即为重量小，价值高的物品
    // 得到一个质量增加，价格也增加的序列
    for (ll i = 0; i < res1.size(); i++) {
        if (v1.back().second < res1[i].second) {
            v1.push_back(res1[i]);
        }
    }
    for (ll i = 0; i < res2.size(); i++) {
        if (v2.back().second < res2[i].second) {
            v2.push_back(res2[i]);
        }
    }
    ll res = 0;
    // 遍历第二部分
    for (ll i = 0; i < res2.size(); i++) {
        // 在第二部分中找到
        if (res2[i].first <= V) {
            // 查看其剩余的空间
            ll x = V - res2[i].first;
            // 在第一部分中寻找符合条件的pair
            auto it = upper_bound(v1.begin(), v1.end(), make_pair(x, LONG_LONG_MIN)) - 1;
            ll y = it->second;
            // 记录最大值
            res = max(res, y + res2[i].second);
        }
    }
    cout << res << endl;
    return 0;
}