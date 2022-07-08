//
// Created by DELL on 2022/1/13.
//
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>
#include <algorithm>
#include<list>

int check(int num);

using namespace std;


template<typename T>
void combine_inner(T &data, int start, int n, int m, int depth, T temp, vector<T> &result) {
    if (depth == m - 1) {
        //最内层循环 将temp加入result
        for (int i = start; i < n - (m - depth - 1); ++i) {
            temp[depth] = data[i];
            result.push_back(temp);
        }
    } else
        for (int i = start; i < n - (m - depth - 1); ++i) {
            temp[depth] = data[i];//每层输出一个元素
            combine_inner(data, i + 1, n, m, depth + 1, temp, result);
        }
}

//T可以调入vector<int>, string等，需要支持下标[]操作及size()函数
template<typename T>
vector<T> combine(T &data, int m) {
    if (m <= 0)
        return {};
    int depth = 0;
    vector<T> result;
    T temp(m, 0);
    combine_inner(data, 0, data.size(), m, depth, temp, result);
    return result;
}

void combine_inner(vector<int>arr,int start,int end,int num,int depth,vector<int>temp,vector<vector<int>>&result){
    if(depth==num-1){
        for (int i = start; i < end - (num - depth - 1); ++i) {

        }
    }else{
        for (int i = start; i < end; ++i) {

        }
    }
}

vector<vector<int>> combine(vector<int> data,int m){
    vector<int>temp(m,0);
    vector<vector<int>>result;
    combine_inner(data,0,data.size(),m,0,temp,result);
    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<vector<int>> res = combine(arr, k);
    int cnt = 0;
    for (int i = 0; i < res.size(); ++i) {
        int num = 0;
        for (int j = 0; j < res[i].size(); ++j) {
            num += res[i][j];
        }
        if (check(num) == 1) {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

int check(int num) {
    if (num == 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
