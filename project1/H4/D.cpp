#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100000

using namespace std;
int n,m;
double a[maxn],sum[maxn];
double mn[maxn],mx[maxn];

bool check(double mid);
int main() {
    cin >> n >> m;
    sum[0] = 0;
    double l = 2001;
    double r = 0;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        //sum[i] = sum[i - 1] + a[i];
        l = min(a[i],l);
        r = max(a[i],r);
    }

    while (r-l>0.00001){
        double mid = (l+r)/2.0;
        if(check(mid)){
            l = mid;
        }else{
            r=mid;
        }
    }
    printf("%d",(int)(r*1000));
    return 0;
}

bool check(double mid) {
    mn[0]=2000;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i]-mid;
        mn[i]=min(mn[i-1],sum[i]);
    }
    mx[n+1]=-0x7fffffff;
    for(int i=n;i>=1;i--){
        mx[i]=max(mx[i+1],sum[i]);
    }
    double res=-0X7fffffff;
    mn[0]=0;
    for(int i=0;i<=n-m;i++){
        res=max(res,mx[i+m]-mn[i]);
    }
    return res>=0;
}
