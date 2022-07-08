//
// Created by DELL on 2022/2/22.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    stringstream ss;
    while (getline(cin,s)){
        stringstream stringin(s);
        string str;
        vector<int> temp;

        while (stringin >> str) {
            temp.push_back(atoi(str.c_str()));
        }
        int sum = 0;
        for (int j = 0; j < temp.size(); ++j) {
            sum+=temp[j];
        }

        cout<<sum<<endl;
    }
    return 0;
}
