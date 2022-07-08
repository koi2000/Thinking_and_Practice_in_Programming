//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<list>
using namespace std;

class window {
public:
    int love;
    long long num;

    window(int love) : love(love) {
        num = 0;
    }

    window(int love, long long num) : love(love), num(num) {}

    window() {}
};

class qq {
public:
    qq() {
        top = -1;
        findMap = map<int, window>();
        element = vector<window>();
    }

    int top;
    map<int, window> findMap;
    vector<window> element;
};

int main() {
    int n;
    cin >> n;
    //freopen("in.txt", "r", stdin);  // 重定向输入流
    //freopen("out.txt", "w", stdout);// 重定向输出流

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<string> log;
        qq q = qq();
        for (int j = 0; j < m; j++) {
            string ops;
            cin >> ops;
            if (ops == "Add") {
                int val = 0;
                cin >> val;
                if (q.findMap.find(val) != q.findMap.end()) {
                    log.emplace_back("same likeness");
                }
                else {
                    window w = window(val);
                    q.findMap[val] = w;
                    q.element.push_back(w);
                    log.emplace_back("success");
                }
            }
            if (ops == "Close") {
                int val = 0;
                cin >> val;
                if (q.findMap.find(val) != q.findMap.end()) {
                    auto it1 = q.findMap.find(val);
                    if (val == q.top) {
                        q.top = -1;
                    }
                    string s = "close " + to_string((*it1).first) + " with " + to_string((*it1).second.num);
                    log.emplace_back(s);
                    q.findMap.erase(it1);
                    for (auto it = q.element.begin(); it != q.element.end(); it++) {
                        if ((*it).love == val) {
                            q.element.erase(it);
                            break;
                        }
                    }
                }
                else {
                    log.emplace_back("invalid likeness");
                    //cout << "invalid likeness" << endl;
                }
            }
            if (ops == "Chat") {
                int val = 0;
                cin >> val;
                if (q.top != -1) {
                    auto it1 = q.findMap.find(q.top);
                    it1->second.num = it1->second.num + val;
                    for (auto it = q.element.begin(); it != q.element.end(); it++) {
                        if ((*it).love == q.top) {
                            (*it).num += val;
                            break;
                        }
                    }
                    log.emplace_back("success");
                }
                else {
                    if (q.element.empty()) {
                        log.emplace_back("empty");
                    }
                    else {
                        auto it = q.findMap.find(q.element.begin()->love);
                        it->second.num = it->second.num + val;

                        q.element.begin()->num = q.element.begin()->num + val;
                        log.emplace_back("success");
                    }
                }
            }
            if (ops == "Rotate") {
                int val = 0;
                cin >> val;
                if (val < 1 || val > q.element.size()) {
                    log.emplace_back("out of range");
                    continue;
                }
                else {
                    auto it = q.element.begin();
                    for (int k = 0; k < val - 1; ++k) {
                        it++;
                    }
                    window w = window((*it).love, (*it).num);
                    q.element.erase(it);
                    q.element.insert(q.element.begin(), w);
                    log.emplace_back("success");
                }
            }
            if (ops == "Prior") {
                if (q.element.empty()) {
                    log.emplace_back("empty");
                }
                else {
                    auto maxx = q.element.begin();
                    for (auto it = q.element.begin(); it != q.element.end(); it++) {
                        if ((*it).love > maxx->love) {
                            maxx = it;
                        }
                    }
                    window w = window((*maxx).love, (*maxx).num);
                    q.element.erase(maxx);
                    q.element.insert(q.element.begin(), w);
                    log.emplace_back("success");
                }
            }
            if (ops == "Choose") {
                int val = 0;
                cin >> val;
                if (q.findMap.find(val) != q.findMap.end()) {
                    for (auto it = q.element.begin(); it != q.element.end(); it++) {
                        if ((*it).love == val) {
                            window w = window((*it).love, (*it).num);
                            q.element.erase(it);
                            q.element.insert(q.element.begin(), w);
                            break;
                        }
                    }
                    log.emplace_back("success");
                }
                else {
                    log.emplace_back("invalid likeness");
                }
            }
            if (ops == "Top") {
                int val = 0;
                cin >> val;
                if (q.findMap.find(val) != q.findMap.end()) {
                    q.top = val;
                    log.emplace_back("success");
                }
                else {
                    log.emplace_back("invalid likeness");
                }
            }
            if (ops == "Untop") {
                if (q.top != -1) {
                    q.top = -1;
                    log.emplace_back("success");
                }
                else {
                    log.emplace_back("no such person");
                }
            }
        }

        if (q.top != -1) {
            for (auto it = q.element.begin(); it != q.element.end(); it++) {
                if ((*it).love == q.top) {
                    if ((*it).num != 0) {
                        string s = "Bye " + to_string((*it).love) + ": " + to_string((*it).num);
                        log.push_back(s);
                        q.element.erase(it);
                    }
                }
            }
        }
        for (auto it = q.element.begin(); it != q.element.end(); it++) {
            if ((*it).num != 0) {
                string s = "Bye " + to_string((*it).love) + ": " + to_string((*it).num);
                log.push_back(s);
            }
        }
        for (int k = 0; k < log.size(); k++) {
            cout << "OpId #" << k + 1 << ": " << log[k] << "." << endl;
        }
    }

    return 0;
}
