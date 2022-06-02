#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define maxn 100010
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &it:a) {
        cin >> it.second >> it.first;
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int last = -1e9;
    for (auto &i:a) {
        if (i.second < last) {
            continue;
        }
        ans++;
        last = i.first;
    }
    cout << ans << endl;
    return 0;
}