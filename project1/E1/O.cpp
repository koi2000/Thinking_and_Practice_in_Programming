//
// Created by DELL on 2022/2/22.
//
//
// Created by DELL on 2022/2/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int n;
    while (cin>>n){
        int sum = 0;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin>>tmp;
            sum+=tmp;
        }
        cout<<sum<<endl;
    }

    /*
    getline(cin,s);
        int sum = 0;
        for (int j = 0; j < s.size(); ++j) {
            if(s[j]!=' '){
                sum+=(s[j]-'0');
            }
        }
        cout<<sum<<endl;*/
    return 0;
}

