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

using namespace std;

class bit {
public:
    vector<long long> tree;
    int n;

    bit(int nn) : n(nn), tree(nn + 1) {}


    static int lowbit(int x) {
        return x & (-x);
    }

    long long query(int x) {
        long  long ret = 0;
        while (x) {
            ret += tree[x];
            x -= lowbit(x);
        }
        return ret;
    }

    void update(int x, int y) {
        while (x <= n) {
            tree[x] += y;
            x += lowbit(x);
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    int arr[n + 1];
    arr[0] = 0;
    bit bit(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        bit.update(i,arr[i]);
    }
    for (int i = 0; i < q; i++) {
        int ops;
        cin >> ops;
        int l,r;
        if (ops == 1) {
            cin>>l>>r;
            bit.update(l,r);
        }else{
            cin>>l>>r;
            long long x = bit.query(l-1);
            long long y = bit.query(r);
            cout<<y-x<<endl;
        }
    }
    return 0;
}




