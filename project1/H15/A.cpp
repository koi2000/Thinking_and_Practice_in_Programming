#include <iostream>
#include <cstddef>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;
int mod = 10000;
typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &a, mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

mat pow(mat a, ll n) {
    mat res(a.size(), vec(a.size()));
    for (int i = 0; i < a.size(); i++)
        res[i][i] = 1;//单位矩阵；
    while (n) {
        if (n & 1) res = mul(res, a);
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

ll solve(ll n) {
    mat a(2, vec(2));
    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;
    a = pow(a, n);
    return a[0][1];//也可以是a[1][0];
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        int m;
        cin >> m;
        cin >> mod;
        cout << solve(m) << endl;
    }
    return 0;
}