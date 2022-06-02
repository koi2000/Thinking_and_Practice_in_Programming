//
// Created by DELL on 2022/3/22.
//
//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <ctype.h>

#define ll long long
using namespace std;

class date {
public:
    int hour;
    int min;
    int sec;

    date() {}

    date(int hour, int min, int sec) : hour(hour), min(min), sec(sec) {}
};

class stu {
public:
    string name;
    string id;
};

class logs {
public:
    string id;
    date start;
    date end;
    bool isSign;
};

//19:00:00
date convert(string str) {
    date t;
    char* tmp = const_cast<char*>(str.c_str());
    t.hour = atoi(tmp);
    t.min = atoi(tmp + 3);
    t.sec = atoi(tmp + 6);
    return t;
}

class result {
public:
    string id;
    vector<string> type;

    result() {
        type = vector<string>();
    }
};

int flag = 0;

string convertName(string name) {
    int it = name.find('-');
    flag = 0;
    int flagi = 0;
    for (int i = 0; i < name.size(); ++i) {
        if (isdigit(name[i])) {
            flagi = i;
            break;
        }
    }
    if (flagi != 0) {
        return name.substr(flagi);
    }
    else {
        flag = 1;
        return name;
    }
}

date scourse;
date endcourse;

ll computetime(date start, date end) {
    ll cst = scourse.hour * 60 * 60 + scourse.min * 60 + scourse.sec;
    ll ced = endcourse.hour * 60 * 60 + endcourse.min * 60 + endcourse.sec;
    ll st = start.hour * 60 * 60 + start.min * 60 + start.sec;
    ll ed = end.hour * 60 * 60 + end.min * 60 + end.sec;

    ll fins;
    ll fine;
    if (st < cst) {
        fins = cst;
    }
    else {
        fins = st;
    }
    if (ed > ced) {
        fine = ced;
    }
    else {
        fine = ed;
    }
    return fine - fins;
}

vector<result>
check(vector<stu>& stus, unordered_map<string, stu>& id2stu, unordered_map<string, stu>& name2stu,
      unordered_map<string, vector<logs>>& id2log) {
    vector<result> res;
    ll courseTime = computetime(scourse, endcourse);
    for (auto& it : stus) {
        auto item = id2log.find(it.id);
        //cout << it.id << endl;
        result r;
        if (item == id2log.end()) {
            r.id = it.id;
            r.type.emplace_back("A");
            res.push_back(r);
            continue;
        }
        vector<logs> rl = item->second;
        ll sum = 0;
        for (int i = 0; i < rl.size(); ++i) {
            ll t = computetime(rl[i].start, rl[i].end);
            t = max(t, (ll)0);
            sum += t;
        }
        if (sum <= 0) {
            r.id = it.id;
            r.type.emplace_back("A");
        }
        else if (sum <= (courseTime / 2)) {
            r.id = it.id;
            r.type.emplace_back("L");
        }
        bool dd = false;
        for (int i = 0; i < rl.size(); ++i) {
            if (rl[i].isSign) {
                dd = true;
                break;
            }
        }
        if (!dd) {
            r.id = it.id;
            r.type.emplace_back("D");
        }
        if (!r.type.empty()) {
            res.push_back(r);
        }
    }
    return res;
}

/*
需要快速查找，所以需要计算一个学号到信息的快速映射，由于只存在查找问题，所以可以使用unorder,
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    cin >> t;
    int idx = 1;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string start;
        string end;
        cin >> start;
        cin >> end;
        scourse = convert(start);
        endcourse = convert(end);
        vector<stu> stus(n);
        unordered_map<string, stu> id2stu;
        unordered_map<string, stu> name2stu;
        unordered_map<string, vector<logs>> id2log;
        for (int i = 0; i < n; ++i) {
            cin >> stus[i].id >> stus[i].name;
            id2stu[stus[i].id] = stus[i];
            name2stu[stus[i].name] = stus[i];
        }
        vector<logs> rlog(m);
        for (int i = 0; i < m; ++i) {
            string name;
            string st;
            string ed;
            string isSign;
            cin >> name;
            string id = convertName(name);
            //cout << id << endl;
            if (flag == 0) {
                rlog[i].id = id;
            }
            else {
                id = name2stu[id].id;
                rlog[i].id = name2stu[id].id;
            }
            cin >> st;
            rlog[i].start = convert(st);
            cin >> ed;
            rlog[i].end = convert(ed);
            cin >> isSign;

            if (isSign == "Yes") {
                rlog[i].isSign = true;
            }
            else {
                rlog[i].isSign = false;
            }
            id2log[id].push_back(rlog[i]);
        }
        vector<result> res = check(stus, id2stu, name2stu, id2log);

        cout << "Case #" << idx << ":" << endl;
        if (res.empty()) {
            cout << "Well done." << endl;
        }
        else {
            for (int i = 0; i < res.size(); i++) {
                cout << res[i].id << " " << res[i].type[0] << endl;
            }
        }
        idx++;
    }
    return 0;
}




