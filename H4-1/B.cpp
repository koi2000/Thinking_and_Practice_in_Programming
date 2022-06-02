#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    //x为大值
    if (x < y) {
        swap(x, y);
    }
    int str = y;
    n--;
    int idx = 0;
    int lastx = 0;
    int lasty = 0;
    while (n > 0) {
        int xx = x + lastx - idx;
        int yy = y + lasty -idx;
        int step = min(xx, yy);
        idx += step;

        if (idx - lastx == x) {
            n--;
            lastx = idx;
        }
        if (n == 0) {
            break;
        }
        if (idx - lasty == y) {
            n--;
            lasty = idx;
        }
        if (n == 0) {
            break;
        }
    }
    cout << str + idx << endl;

    return 0;
}