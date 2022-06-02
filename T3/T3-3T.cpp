#include <bits/stdc++.h>

#define ll long long
using namespace std;

static unsigned int p = 1;

const string TF = "TF";
const string SF = "SF";
const string LF = "LF";
ll timeline = 0;

class result {
public:
    ll startTime;
    ll endTime;
    string taskName;
    string workerName;

    result(long long int startTime, long long int endTime, const string &taskName, const string &workerName)
            : startTime(startTime), endTime(endTime), taskName(taskName), workerName(workerName) {}

    result() {}

    bool operator<(const result &rhs) const {
        if (endTime != rhs.endTime) {
            return endTime > rhs.endTime;
        }
        return startTime > rhs.startTime;
    }
};

priority_queue<result> res;

int myrand() {
    p = p * 1103515245 + 12345;
    return ((unsigned ll) (p / 65536) % 100);
}

class task {
public:
    ll origin;
    ll t, d, k;
    string s;
    vector<string> opt;

    task() {}

    task(ll t, ll d, const string &s) : t(t), d(d), s(s) {
        origin = d;
    }

    // 重载小于号
    bool operator<(const task &rhs) const {

        if (d == rhs.d)return s < rhs.s;
        return d < rhs.d;
    }

    bool operator>(const task &rhs) const {
        return rhs < *this;
    }
};

struct cmpTF {
    bool operator()(const task &x, const task &y) const {
        return x.t > y.t;
    }
};

struct cmpSF {
    bool operator()(const task &x, const task &y) const {
        if (x.d == y.d)return x.s < y.s;
        return x.d > y.d;
    }
};

struct cmpLF {
    bool operator()(const task &x, const task &y) const {
        if (x.d == y.d)return x.s < y.s;
        return x.d < y.d;
    }
};

class consumer {
public:
    string name;
    string type;
    priority_queue<task, vector<task>, cmpTF> tfq;
    task now;
    bool isWorking = false;
    // 返回执行时间最长，字典序最大
    priority_queue<task, vector<task>, cmpLF> lfq;
    // 返回执行时间最短 字典序最大
    priority_queue<task, vector<task>, cmpSF> sfq;
    // 上一个任务被调度到的时间
    ll lastTime = 0;

    consumer() {}

    consumer(const string &name, const string &type) : name(name), type(type) {
        now.s = "";
    }

    void add(task tsk) {
        // 更新历史时间为当前任务传入的时间
        lastTime = tsk.t;
        // 首先将所有的任务都加进去
        if (type == TF) {
            tfq.push(tsk);
        }
        if (type == SF) {
            sfq.push(tsk);
        }
        if (type == LF) {
            lfq.push(tsk);
        }
        // 尝试能否执行任务
        if (isWorking) {
            return;
        }
        // 将任务加入到执行队列中，只有当队列未处于执行状态时才可以加入
        if (type == TF && !tfq.empty()) {
            res.push({tfq.top().t, lastTime + tfq.top().d, tfq.top().s, name});
            tfq.pop();
            isWorking = true;
        } else if (type == SF && !sfq.empty()) {
            res.push({sfq.top().t, lastTime + sfq.top().d, sfq.top().s, name});
            sfq.pop();
            isWorking = true;
        } else if (type == LF && !lfq.empty()) {
            res.push({lfq.top().t, lastTime + lfq.top().d, lfq.top().s, name});
            lfq.pop();
            isWorking = true;
        }
    }


    void finishTask(ll timeNow) {
        // 根据不同车间的类型，以不同的方式执行任务
        lastTime = timeNow;
        isWorking = false;
        res.pop();
        if (isWorking) {
            return;
        }
        if (type == TF) {
            if (!tfq.empty()) {
                res.push({tfq.top().t, lastTime + tfq.top().d, tfq.top().s, name});
                tfq.pop();
                isWorking = true;
            }
        }
        if (type == SF) {
            // 每次改变以下流程，记录被调度到的时间，然后加上执行时间即可直接得到结束的时间
            if (!sfq.empty()) {
                res.push({sfq.top().t, lastTime + sfq.top().d, sfq.top().s, name});
                sfq.pop();
                isWorking = true;
            }
        }
        if (type == LF) {
            if (!lfq.empty()) {
                res.push({lfq.top().t, lastTime + lfq.top().d, lfq.top().s, name});
                lfq.pop();
                isWorking = true;
            }
        }
    }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    // 创建n个车间，每个车间是不同的类型，然后每次在其中进行调度
    vector<consumer> consumers;
    map<string, ll> name2idx;
    cin >> n >> m;
    string name, type;
    for (ll i = 0; i < n; ++i) {
        cin >> name >> type;
        consumers.emplace_back(name, type);
        name2idx[name] = i;
    }

    ll t, d, k;
    string s;

    for (ll i = 0; i < m; ++i) {
        cin >> t >> s >> d >> k;
        ll P = 100 / k;
        // 创建一个新的任务
        task tas = task(t, d, s);
        // 记录每个人任务可能会选择的区间
        vector<string> need = vector<string>(k);
        // 遍历所有的区间，让其执行
        while (!res.empty() && res.top().endTime <= t) {
            cout << res.top().endTime << " " << res.top().taskName << endl;
            string workerName = res.top().workerName;
            ll endTime = res.top().endTime;
            consumers[name2idx[workerName]].finishTask(endTime);
        }

        for (ll j = 0; j < k; ++j) {
            cin >> need[j];
        }
        // 为任务找到一个合适的车间
        for (ll j = 0; j < k; ++j) {
            string c = need[j];
            if (j == k - 1) {
                ll idx = name2idx[c];
                consumers[idx].add(tas);
                break;
            }
            if (P > myrand()) {
                ll idx = name2idx[c];
                consumers[idx].add(tas);
                break;
            }
        }

    }
    while (!res.empty() && res.top().endTime <= LONG_LONG_MAX) {
        cout << res.top().endTime << " " << res.top().taskName << endl;
        string workerName = res.top().workerName;
        ll endTime = res.top().endTime;
        consumers[name2idx[workerName]].finishTask(endTime);
    }
    return 0;
}