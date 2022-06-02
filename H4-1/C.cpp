#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

#define ll long long
using namespace std;

//ll a[100005];
/*
1
10
6 8 10 10 10 10 10 12 14 10

1
7
6 8 10 10 10 10 10
*/

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int t;
    cin >> t;
    for (int q = 0; q < t; q++) {
        int n;
        cin >> n;
        ll a[n];
        ll num = 0;
        ll profit = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }
        ll pro[n];
        pro[0] = 0;
        ll minn = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) {
                minn = a[i];
                pro[i] = a[i] - minn;
                continue;
            }
            pro[i] = a[i] - minn;
            minn = min(minn, a[i]);
        }

        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (pro[i] > 0) {
                num++;
                profit += pro[i];
                if (flag == 1 && pro[i] >= pro[i - 1]) {
                    num--;
                    profit -= pro[i - 1];
                }
                flag = 1;
            } else {
                flag = 0;
            }
        }
        cout << profit << " " << num * 2 << endl;
    }

    return 0;
}