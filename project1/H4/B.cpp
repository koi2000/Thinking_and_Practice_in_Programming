#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <algorithm>
#include<list>

using namespace std;
struct node {
    int idx;
    int timeA;
    int timeB;
    /*bool operator >(const node& rhs)const{
        return time>rhs.time;
    }*/
};
bool cmp1(node n1, node n2) {
    return n1.timeA < n2.timeA;
}
bool cmp2(node n1, node n2) {
    return n1.timeB > n2.timeB;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    vector<node>n1;
    vector<node>n2;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        node nn;
        if (a[i] < b[i]) {
            nn.idx = i;
            nn.timeA = a[i];
            nn.timeB = b[i];
            n1.push_back(nn);
        }
        else {
            nn.idx = i;
            nn.timeA = a[i];
            nn.timeB = b[i];
            n2.push_back(nn);
        }
    }
    sort(n1.begin(), n1.end(), cmp1);
    sort(n2.begin(), n2.end(), cmp2);
    vector<node>tt;
    for (int i = 0; i < n1.size(); ++i) {
        tt.push_back(n1[i]);
    }
    for (int i = 0; i < n2.size(); ++i) {
        tt.push_back(n2[i]);
    }
    int time1[n + 1];
    int time2[n + 1];
    //time1[0] = n1[0].timeA;
    time1[0] = 0;

    for (int i = 1; i <= n; ++i) {
        time1[i] = tt[i-1].timeA + time1[i - 1];
    }
    time2[0] = time1[1];
    for (int i = 1; i < n; ++i) {
        time2[i] = time2[i - 1] + tt[i-1].timeB;
        if (time2[i] < time1[i + 1]) {
            time2[i] = time1[i + 1];
        }
    }
    int time = max(time1[n], time2[n - 1]) + tt[n-1].timeB;
    cout << time << endl;
    return 0;
}