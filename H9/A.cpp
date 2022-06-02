//
// Created by DELL on 2022/4/24.
//
#include <bits/stdc++.h>

using namespace std;

map<string, int> parseFormula(string &s, int &p);
vector<string> split(string &s, char c) {
    stringstream stream(s);
    string tmp;
    vector<string> res;
    while (getline(stream, tmp, c)) {
        res.push_back(tmp);
    }
    return res;
};

int parseInt(string &s, int &p) {
    int idx = p;
    for (int i = p; i < s.size(); ++i) {
        if (isdigit(s[i])) {
            idx = i + 1;
        } else {
            break;
        }
    }
    if (idx == p) {
        return 1;
    } else {
        string dig = s.substr(p, idx - p);
        char *di = const_cast<char *>(dig.c_str());
        int par = atoi(di);
        p = idx;
        return par;
    }
}

string parseEle(string &s, int &p) {
    string res;
    res += s[p];
    p++;
    if (p != s.size() && islower(s[p])) {
        res += s[p];
        p++;
    }
    return res;
}

map<string, int> parseItem(string &item, int &p) {
    // 如果遇到左括号，则进行递归调用
    if (item[p] == '(') {
        p++;
        map<string, int> res = parseFormula(item, p);
        p++;
        return res;
    } else {
        // 否则，直接读取一个元素即可
        string ele = parseEle(item, p);
        map<string, int> res;
        res[ele] = 1;
        return res;
    }
}

void merge(map<string, int> &res, map<string, int> &tmp, int coef) {
    for (auto &item:tmp) {
        res[item.first] += item.second * coef;
    }
}

map<string, int> parseFormula(string &s, int &p) {
    map<string, int> num;
    while (p != s.size() && s[p] != ')') {
        // 首先解析一项
        map<string, int> tmp = parseItem(s, p);
        // 然后开始读取系数
        int coef = parseInt(s, p);
        merge(num, tmp, coef);
    }
    return num;
}

map<string, int> parse(string formula) {
    map<string, int> res;
    // 将一部分以+号进行分割，来处理每一个项
    vector<string> formulas = split(formula, '+');
    for (auto i:formulas) {
        int p = 0;
        // 首先读取系数，默认值为1
        int coef = parseInt(i, p);
        map<string, int> tmp = parseFormula(i, p);
        // 将map合并
        merge(res, tmp, coef);
    }
    return res;
}

[[noreturn]] [[noreturn]] void solve() {
    string equation;
    cin >> equation;
    // 将一个化学方程式的左右两边以=号进行分割，然后对两边进行解析，如果两边最后的结果相同，则说明已经配平
    vector<string> reg = split(equation, '=');
    if (parse(reg[0]) == parse(reg[1])) {
        cout << "Y" << endl;
    } else {
        cout << "N" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

