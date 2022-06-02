//
// Created by DELL on 2022/3/9.
//
#include <bits/stdc++.h>

using namespace std;

bool check(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


void pick(vector<int> &tmp, int k, vector<int> arr, int depth);

int res = 0;

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    vector<int> a = vector<int>();
    pick(a, k, arr, 0);
    cout<<res<<endl;
    return 0;
}

void pick(vector<int> &tmp, int k, vector<int> arr, int depth) {
    if (tmp.size() == k) {
        int sum = 0;
        for (auto it:tmp) {
            sum += it;
        }
        if (check(sum)) {
            res++;
        }
        return;
    } else {
        for (int i = depth; i < arr.size(); ++i) {
            tmp.push_back(arr[i]);
            ++depth;
            pick(tmp, k, arr, depth);
            tmp.pop_back();
        }
    }
}
