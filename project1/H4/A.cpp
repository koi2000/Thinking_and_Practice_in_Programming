#include <bits/stdc++.h>

using namespace std;

class rule {
public:
    int l;
    int r;
    int k;

    rule(int l, int r, int k) : l(l), r(r), k(k) {}

    bool operator<(const rule &rhs) const {
        return r < rhs.r;
    }

    bool operator>(const rule &rhs) const {
        return r > rhs.r;
    }
};

int v[30010] = {0};


int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    vector<rule> rules;
    int l, r, k;
    for (int i = 0; i < m; i++) {
        cin >> l >> r >> k;
        rule rr = rule(l, r, k);
        rules.push_back(rr);
    }
    sort(rules.begin(), rules.end());

    for (int i = 0; i < m; i++) {
        int l1 = rules[i].l, r1 = rules[i].r, cnt1 = 0;
        for (int j = l1; j <= r1; j++) {
            if (v[j] == 1) cnt1++;
        }
        while (cnt1 < rules[i].k) {
            if (v[r1] == 0) {
                v[r1] = 1;
                cnt1++;
                cnt++;
            }
            r1--;
        }
    }
    cout << cnt;
    return 0;
}