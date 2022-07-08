#include<bits/stdc++.h>

using namespace std;
const int maxX = 1e6 + 10;

int n,x;
int a[maxX];
int L[maxX],R[maxX];
int preL[maxX],preR[maxX];

int sufL[maxX],sufR[maxX];

void init(){
    for (int i = 0; i <= x; ++i) {
        L[i] = preL[i] = sufL[i] = x+1;
    }
    set<int>s;

    for (int i = 1; i <= n; ++i) {
        int t = a[i];
        auto it = s.upper_bound(t);
        if (it==s.end()){
            s.insert(t);
            continue;
        }else{

        }
    }
}

int main() {
    cin>>n>>x;
    for (int i = 1; i <= n; ++i) {
        cin>>a[i];
    }
    return 0;
}