//
// Created by DELL on 2022/1/10.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int sum = 0;
    int n5 = n / 50;
    n = n % 50;
    int n3 = n / 30;
    n = n % 30;
    int n1 = n / 10;
    sum = sum + n5 * 7 + n3 * 4 + n1;
    cout << sum << endl;
    return 0;
}

