//
// Created by DELL on 2022/4/27.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    int maxx = INT_MIN;
    int minn = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        maxx = max(maxx, arr[i]);
        minn = min(minn, arr[i]);
    }

    sort(arr, arr + n);
    printf("%d ",maxx);
    if (n % 2 == 0) {
        int sum = arr[(n-1)/2]+arr[n/2];
        if(sum%2==0){
            printf("%d ",sum/2);
        }else{
            double res = sum/2.0;
            printf("%.1f ",res);
        }
    } else {
        printf("%d ",arr[n/2]);
    }
    printf("%d ",minn);
    return 0;
}







