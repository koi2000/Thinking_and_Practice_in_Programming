#include <bits/stdc++.h>
#include<iostream>
#include<string>
#include<set>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class node {
public:
    int timeA;
    int timeB;

    node() {}

    node(int timeA, int timeB) : timeA(timeA), timeB(timeB) {}
};

int main() {
    int n;
    cin >> n;
    node nodes[n];
    vector<node> parta;
    vector<node> partb;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        nodes[i] = node(a, b);
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        int a = nodes[i].timeA;
        nodes[i].timeB = b;
        if (a < b) {
            parta.push_back(nodes[i]);
        } else {
            partb.push_back(nodes[i]);
        }
    }
    sort(parta.begin(), parta.end(), [](node a, node b) -> bool {
        return a.timeA < b.timeA;
    });

    sort(partb.begin(), partb.end(), [](node a, node b) -> bool {
        return a.timeB > b.timeB;
    });

    vector<node> fin;
    for (int i = 0; i < parta.size(); ++i) {
        fin.push_back(parta[i]);
    }

    for (int i = 0; i < partb.size(); ++i) {
        fin.push_back(partb[i]);
    }


    int time1[n + 1];
    int time2[n + 1];

    time1[0] = 0;
    time2[0] = 0;

    for (int i = 1; i <= n; i++) {
        time1[i] = time1[i - 1] + fin[i - 1].timeA;
    }
    time2[0] = fin[0].timeA;
    for (int i = 1; i <= n; i++) {
        time2[i] = max(time2[i - 1], time1[i]) + fin[i - 1].timeB;
    }
    cout << time2[n] << endl;
    return 0;
}