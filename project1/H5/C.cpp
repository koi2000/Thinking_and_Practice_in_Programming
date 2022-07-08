//
// Created by DELL on 2022/1/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#define maxn 100000
using namespace std;

bool check(double mid);

struct cmp
{
    bool operator()(pair<int, int>a, pair<int, int>b)
    {
        return a.first > b.first;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    priority_queue<pair<int, int>>maxx;
    priority_queue<pair<int, int>, vector<pair<int, int>>,cmp>minn;
    vector<int>big;
    vector<int>small;
    for (int i = 0; i < k; ++i) {
        maxx.push(pair<int, int>(a[i], i));
        minn.push(pair<int, int>(a[i], i));
    }
    big.push_back(maxx.top().first);
    small.push_back(minn.top().first);
    for (int i = k; i < n; ++i) {
        maxx.push(pair<int, int>(a[i], i));
        minn.push(pair<int, int>(a[i], i));
        while (maxx.top().second <= i - k) {
            maxx.pop();
        }
        while (minn.top().second <= i - k) {
            minn.pop();
        }
        big.push_back(maxx.top().first);
        small.push_back(minn.top().first);
    }


    for (int i = 0; i < small.size(); ++i) {
        cout << small[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < big.size(); ++i) {
        cout << big[i] << " ";
    }
    return 0;
}
