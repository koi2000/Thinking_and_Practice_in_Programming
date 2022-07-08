//
// Created by DELL on 2022/1/10.
//
#include <bits/stdc++.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209
using namespace std;

int g1(int x);

int g2(int x);

int dis(int pos1, int pos2) {
    return ((pos1 - pos2) * (pos1 - pos2));
}


int main() {
    /*double n, m;
    cin >> n >> m;
    printf("%.3f", 100 * (n - m) / n);
    */
    /*string s;
    cin >> s;
    if (s[0] == s[1]) {
        cout << "Won" << endl;
    } else {
        cout << "Lost" << endl;
    }*/
    //M
    /*string s;
    cin >> s;
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if ((i + 1) % 2 == 1) {
            if (s[i] < 'a' || s[i] > 'z') {
                flag = 1;
                cout << "No" << endl;
                break;
            }
        } else {
            if (s[i] < 'A' || s[i] > 'Z') {
                flag = 1;
                cout << "No" << endl;
                break;
            }
        }
    }
    if (flag == 0) {
        cout << "Yes" << endl;
    }*/
    //N
    /*int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]!=m){
            cout<<a[i]<<" ";
        }
    }*/
    //N
    /*int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    double mina = (double)sum / (double)n;
    int min1 = (int)mina;
    int min2 = (int)mina+1;
    //sort(a,a+n);
    int res1 = 0;
    int res2 = 0;
    for (int i = 0; i < n; i++) {
        res1+=dis(min1,a[i]);
    }
    for (int i = 0; i < n; i++) {
        res2+=dis(min2,a[i]);
    }
    cout<<min(res1,res2)<<endl;*/
    //P
    /*int a,b,H,M;
    cin>>a>>b>>H>>M;
    double du1 = (double)H*5/60+(double)((double)M/60*5)/60;
    double du2 = (double)M/60;
    double du = abs(du1-du2);
    double res = sqrt(a*a+b*b-2*a*b*cos(du*2*PI));
    printf("%.10f",res);*/
    int N, K;
    cin>>N>>K;
    int a[K+1];
    a[0] = N;
    for (int i = 1; i <= K; i++) {
        int g11 = g1(a[i - 1]);
        int g22 = g2(a[i - 1]);
        a[i] = g11-g22;
    }
    cout << a[K] << endl;
    return 0;
}

int g1(int x) {
    vector<int> a;
    while (x > 0) {
        a.push_back(x % 10);
        x = x / 10;
    }
    sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += (int)(a[i] * pow(10, i));
    }
    return sum;
}

int g2(int x) {
    vector<int> a;
    while (x > 0) {
        if(x%10!=0){
            a.push_back(x % 10);
        }
        x = x / 10;
    }
    sort(a.begin(), a.end(), [](int a, int b) -> bool {
        return a > b;
    });
    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i] * pow(10, i);
    }
    return sum;
}