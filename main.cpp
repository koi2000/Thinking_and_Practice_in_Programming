#include<bits/stdc++.h>

using namespace std;
#define ll long long
const ll maxN = 5009;
int n, m;
vector<int> lines;

int check(double mid) {
    int num = 0;
    for (int i = 0; i < n; ++i) {
        num += lines[i] / mid;
    }
    return num >= m;
}

int main() {
    cin >> n >> m;
    lines.resize(n);
    int rr = INT_MIN;
    for (int i = 0; i < n; ++i) {
        cin >> lines[i];
        rr = max(lines[i], rr);
    }
    double l = 0;
    double r = rr;
    double mid;
    while (r - l > 0.000001) {
        mid = l + (r - l) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << mid << endl;
    return 0;
}