//
// Created by DELL on 2022/1/10.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    //IO1
    /*int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin>>a>>b;
        cout<<a+b<<endl;
    }*/
    //IO3
    /*int a, b;
    while (cin >> a >> b) {
        cout << a + b << endl;
    }*/
    //IO4
    //freopen("in.txt", "r", stdin);  // 重定向输入流
    //freopen("out.txt", "w", stdout);// 重定向输出流
    string s;
    int sum = 0;
    int first;
    /*while (scanf("%[^\n]", s)){
        getchar();
        sum = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48&&s[i]<=57){
                sum+=s[i]-48;
            }
        }
        cout<<sum<<endl;
    }*/
    /*
    while (getline(cin,s)){

        if(s.length()==0){
            break;
        }
        sum = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48&&s[i]<=57){
                sum+=s[i]-48;
            }
        }
        cout<<sum<<endl;
    }*/
    int a;
    /*char d[100];
    while (scanf("%[^\n]%*c",d)){
        s = d;
        sum = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]>=48&&s[i]<=57){
                sum+=s[i]-48;
            }
        }
        cout<<sum<<endl;
    }*/

    while (cin >> a) {
        sum += a;
        if (cin.get() == '\n') {
            cout << sum << endl;
            sum = 0;
        }
    }


    return 0;
}

