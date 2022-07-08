#include<bits/stdc++.h>
using namespace std;

int nums = 0;
int vis[9] = {0};
bool a[9][9];
char c;
void permutation(int x, int y, int n, int k){
    if( y == k){
        nums++;
        return;
    }
    for(int i = x; i < n; i++)
        for(int j = 0; j < n; j++){
            if(vis[j] == 0 && a[i][j]) {
                vis[j] = 1;
                permutation(i+1,y+1,n,k);
                vis[j] = 0;
            }
        }
}

int main(){
    int n,k;
    while(cin>>n>>k){
        if(n==-1&&k==-1){
            break;
        }
        for (int j = 0; j < n; j++){
            for (int i = 0; i < n; i++){
                cin >> c;
                if (c == '#')
                    a[i][j] = 1;
                else
                    a[i][j] = 0;
            }
        }
        for(int i = 0; i <= n; i++){
            nums = 0;
            permutation(0,0,n,k);
        }
        cout<<nums<<endl;
    }
    return 0;
}