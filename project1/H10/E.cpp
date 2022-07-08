#include<iostream>

using namespace std;
#define maxn 200005
int N, Q;

int M(int a, int b) {

    return a >= b ? a : b;
}

struct node {
    int left;
    int right;
    int max;
};
struct node tree[maxn * 4];

void buildtree(int index, int left, int right) {
    tree[index].left = left;
    tree[index].right = right;
    tree[index].max = 0;
    if (left == right) {
        return;
    }
    int mid = (left + right) >> 1;
    buildtree((index << 1) + 1, left, mid);
    buildtree((index << 1) + 2, mid + 1, right);
    return;
}

void insert(int index, int left, int right, int k) {
    int mid = (tree[index].left + tree[index].right) >> 1;
    if (tree[index].left == tree[index].right) {
        tree[index].max = k;
        return;
    }
    if (right <= mid) {
        if (tree[index].max <= k)
            tree[index].max = k;
        insert((index << 1) + 1, left, right, k);
        return;
    } else if (left > mid) {
        if (tree[index].max <= k)
            tree[index].max = k;
        insert((index << 1) + 2, left, right, k);
        return;
    }
}

int query(int index, int left, int right) {
    int mid = (tree[index].left + tree[index].right) >> 1;
    if (tree[index].left == tree[index].right) {
        return tree[index].max;
    }
    if (right <= mid) {
        return query((index << 1) + 1, left, right);
    } else if (left > mid) {
        return query((index << 1) + 2, left, right);
    } else {
        return M(query((index << 1) + 1, left, mid), query((index << 1) + 2, mid + 1, right));
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    int a = 0;
    int num = 0;
    buildtree(0,1,n);
    for (int i = 0; i < n; i++) {
        char ops;
        cin >> ops;
        int t;
        if (ops == 'A') {
            cin >> t;
            num++;
            t = (t + a) % p;
            insert(0, num, num, t);
        } else {
            cin>>t;
            int rr = num - t;
            if (rr < 1) {
                rr = 1;
            }
            a = query(0, rr, num);
            cout << a << endl;
        }
    }
    return 0;
}