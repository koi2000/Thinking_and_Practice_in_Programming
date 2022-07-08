#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;
int father[1000001];

int find(int x) {
    if (x == father[x]) {
        return x;
    }
    father[x] = find(father[x]);
    return father[x];
}

//y为被merge的数
void merge(int x, int y) {
    int f1 = find(x);
    int f2 = find(y);
    if (f1 != f2) {
        father[f2] = f1;
    }
}

void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    } else {
        father[y] = x;
    }
}

class node {
public:
    int pos;
    int dis;

    node(int pos, int dis) : pos(pos), dis(dis) {}

    bool operator<(const node &a) const {
        return this->dis > a.dis;
    }
};

class edge {
public:
    int u, v, w;

    edge() {}

    edge(int u, int v, int w) : u(u), v(v), w(w) {}

    bool operator-(edge e) const {
        return this->w - e.w;
    }
};

bool operator<(edge a, edge b) {
    return a.w >= b.w;
}

int p;

template<class T>
class graph {
private:
    int nodeSize;
    list<T> *head;
public:
    graph(int size);

    void addEdge(int u, int v, int w);

    void delEdge(int u, int v);

    void prim(int x);
};

template<class T>
graph<T>::graph(int size) {
    nodeSize = size;
    head = new list<T>[size + 1];
    for (int i = 1; i < size + 1; i++) {
        head[i].resize(0);
    }
}

template<class T>
void graph<T>::addEdge(int u, int v, int w) {
    edge e = edge(u, v, w);
    head[u].push_back(e);
}

template<class T>
void graph<T>::delEdge(int u, int v) {
    for (auto it = head[u].begin(); it != head[u].end(); it++) {
        if (((*it).u) == u && ((*it).v == v)) {
            head[u].erase(it);
            break;
        }
    }
}

template<class T>
void graph<T>::prim(int u) {
    set<int> nodes;

    nodes.insert(u);
    queue<int> queue;
    queue.push(u);
    int k = 0;
    int n = this->nodeSize;
    long long sum = p;
    /*for (int i = 1; i <= n; ++i) {
        if (head[i].size() == 0) {
            sum += p;
            nodes.insert(i);
            k++;
        }
    }*/
    priority_queue<node> qq;
    while (nodes.size() != n) {
        //得到了所有的点集
        int x = queue.front();
        queue.pop();
        for (auto it = head[x].begin(); it != head[x].end(); it++) {
            if (nodes.find((*it).v) != nodes.end()) {
                continue;
            }
            qq.push(node((*it).v, (*it).w));
        }

        while (!qq.empty()) {
            node tt = qq.top();
            int a = find(u);
            int b = find(tt.pos);
            if (a == b) {
                qq.pop();
                continue;
            } else {
                nodes.insert(tt.pos);
                if (qq.top().dis > p) {
                    qq.pop();
                    sum += p;
                    k++;
                    continue;
                }
                merge(1, qq.top().pos);
                sum += qq.top().dis;
                k++;
                queue.push(qq.top().pos);
                qq.pop();
                break;
            }
        }
    }
    cout << sum << endl;
}


int main() {
    int n, m;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    graph<edge> g = graph<edge>(n);

    int u, v, w;
    int minn = INT32_MAX;
    int idx = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge e = edge(u, v, w);
        //g.addEdge(v, u, w);
        g.addEdge(u, v, w);
        if (w < minn) {
            minn = w;
            idx = u;
        }
    }
    g.prim(idx);
    return 0;
}