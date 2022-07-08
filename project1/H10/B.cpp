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


int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    cout << arr[n-1] << " ";
    if (n % 2 == 0) {
        int res = (arr[n / 2] + arr[n / 2 - 1]);
        if (res % 2 == 0) {
            cout << res / 2 << " ";
        } else {
            double rres = (double) res / 2.0;
            printf("%.1f ", rres);
        }
    } else {
        cout << arr[n / 2] << " ";
    }
    cout << *arr.begin() << " ";
    return 0;
}




