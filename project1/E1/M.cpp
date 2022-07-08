//
// Created by DELL on 2022/2/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    while (cin>>n){
        if(n==0){
            break;
        }
        int sum = 0;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin>>tmp;
            sum+=tmp;
        }
        cout<<sum<<endl;
    }
    return 0;
}
