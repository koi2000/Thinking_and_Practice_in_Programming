#include <bits/stdc++.h>

using namespace std;
long long curtentTime;
int n, m;
static unsigned int p = 1;

int myrand(void) {
    p = p * 1103515245 + 12345;
    return ((unsigned int) (p / 65536) % 100);
}

struct task {
    string name;
    long long startTime;
    long long duration;
};

struct finishMsg {
    string taskName;
    long long startTime;
    long long finishTime;
    string shopName;

    bool operator<(const finishMsg &f) const {
        if (finishTime != f.finishTime) {
            return finishTime > f.finishTime;
        }
        return startTime > f.startTime;
    }
};

priority_queue<finishMsg> allTask;

struct cmpTF {
    bool operator()(const task &a, const task &b) {
        return a.startTime > b.startTime;
    }
};

struct cmpSF {
    bool operator()(task &a, task &b) {
        if (a.duration != b.duration)
            return a.duration > b.duration;
        return a.name < b.name;
    }
};

struct cmpLF {
    bool operator()(task &a, task &b) {
        if (a.duration != b.duration)
            return a.duration < b.duration;
        return a.name < b.name;
    }
};

struct shop {
    string name;
    priority_queue<task, vector<task>, cmpTF> todoTF;
    priority_queue<task, vector<task>, cmpSF> todoSF;
    priority_queue<task, vector<task>, cmpLF> todoLF;
    string type;
    bool isWorking;

    void finishTask(long long finishTime) {
        isWorking = false;
        curtentTime = finishTime;
        allTask.pop();
        if (!isWorking && type == "TF" && !todoTF.empty()) {
            allTask.push({todoTF.top().name, todoTF.top().startTime, curtentTime + todoTF.top().duration, name});
            todoTF.pop();
            isWorking = true;
        } else if (!isWorking && type == "SF" && !todoSF.empty()) {
            allTask.push({todoSF.top().name, todoSF.top().startTime, curtentTime + todoSF.top().duration, name});
            todoSF.pop();
            isWorking = true;
        } else if (!isWorking && type == "LF" && !todoLF.empty()) {
            allTask.push({todoLF.top().name, todoLF.top().startTime, curtentTime + todoLF.top().duration, name});
            todoLF.pop();
            isWorking = true;
        }
    }

    void addTask(task t) {
        curtentTime = t.startTime;
        if (type == "TF") {
            todoTF.push(t);
        } else if (type == "SF") {
            todoSF.push(t);
        } else if (type == "LF") {
            todoLF.push(t);
        }
        if (!isWorking && type == "TF" && !todoTF.empty()) {
            allTask.push({todoTF.top().name, todoTF.top().startTime, curtentTime + todoTF.top().duration, name});
            todoTF.pop();
            isWorking = true;
        } else if (!isWorking && type == "SF" && !todoSF.empty()) {
            allTask.push({todoSF.top().name, todoSF.top().startTime, curtentTime + todoSF.top().duration, name});
            todoSF.pop();
            isWorking = true;
        } else if (!isWorking && type == "LF" && !todoLF.empty()) {
            allTask.push({todoLF.top().name, todoLF.top().startTime, curtentTime + todoLF.top().duration, name});
            todoLF.pop();
            isWorking = true;
        }
    }
};

map<string, shop> allchejian;

void readchejian() {
    for (long long i = 0; i < n; ++i) {
        string name, type;
        cin >> name >> type;
        allchejian[name].name = name;
        if (type == "TF") {
            allchejian[name].type = "TF";
        } else if (type == "SF") {
            allchejian[name].type = "SF";
        } else if (type == "LF") {
            allchejian[name].type = "LF";
        }
    }
}

void readtask() {
    for (long long i = 0; i < m; ++i) {
        long long t, d, k;
        string s;
        cin >> t >> s >> d >> k;
        vector<string> c;
        for (long long j = 0; j < k; j++) {
            string temp;
            cin >> temp;
            c.push_back(temp);
        }
        while (!allTask.empty() && allTask.top().finishTime <= t) {
            cout << allTask.top().finishTime << " " << allTask.top().taskName << endl;
            string tempname = allTask.top().shopName;
            long long temptime = allTask.top().finishTime;
            allchejian[tempname].finishTask(temptime);
        }
        long long temp = c.size();
        long long tempk = 100 / k;
        for (long long j = 0; j < temp; ++j) {
            string tempfindchejian = c[j];
            task ttt;
            ttt.name = s;
            ttt.startTime = t;
            ttt.duration = d;
            if (j == c.size() - 1) {
                allchejian[tempfindchejian].addTask(ttt);
                break;
            }
            if (tempk > myrand()) {
                allchejian[tempfindchejian].addTask(ttt);
                break;
            }
        }
    }
}

void init() {
    cin >> n >> m;
    readchejian();
    readtask();
}

void output() {
    while (!allTask.empty()) {
        finishMsg temp;
        temp.finishTime = allTask.top().finishTime;
        temp.taskName = allTask.top().taskName;
        temp.shopName = allTask.top().shopName;
        cout << temp.finishTime << " " << temp.taskName << "\n";
        allchejian[temp.shopName].finishTask(temp.finishTime);
    }
}

int main() {
    init();
    output();
}