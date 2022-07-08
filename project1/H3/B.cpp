#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    int sum = 0;
    int last = 0;
    vector<int> a;
    while (cin >> k) {
        a.push_back(k);
        if (k == 0) {
            break;
        }
    }
    int lastScore = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 2) {
            if (lastScore == 1) {
                sum += 2;
                lastScore = 2;
            } else {
                lastScore += 2;
                sum += lastScore;

            }

        } else if (a[i] == 1) {
            sum += 1;
            lastScore = 1;
        }

    }
    cout << sum << endl;
    return 0;
}

