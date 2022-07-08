//
// Created by DELL on 2022/2/22.
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum+=(a[i]*b[i]);
    }
    if(sum==0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}

