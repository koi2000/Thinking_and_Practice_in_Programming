//
// Created by DELL on 2022/1/17.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#define maxn 100000
using namespace std;

int n;  //n块巨石
int m;  //m个询问
int l,r;  //每个询问包含两个数字，对于每个询问，回答处于区间[l,r]是否每个字母至少出现一次

int s[5000010][26] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    char c;   //字符
    for (int i = 1; i <= n; i++){
        cin>>c;
        s[i][c-'A'] = 1;
    }
    cin>>m;
    for (int i = 0; i < 26; i++){
        for(int j = 2; j <= n; j++){
            s[j][i] += s[j-1][i];
        }
    }  //求前缀和 O(26n)
    for(int i = 0; i < m; i++){
        bool yn = false;
        cin>>l>>r;
        for(int j = 0; j < 26; j++){
            if (s[r][j] - s[l-1][j] >= 1){
                continue;
            }
            else{
                yn = true;
                printf("NO\n");
                break;
            }
        }
        if(yn == 0)
            printf("YES\n");
    }
    return 0;
}



