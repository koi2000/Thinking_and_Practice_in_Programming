//
// Created by DELL on 2022/4/24.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

class file {
public:
    bool isDir;
    // 目录配额 后代配额
    ll ld, lr;
    // 目录尺寸 后代尺寸
    ll sd, sr;
    map<string, file> children;

    ll fileSize;

    file() {
        isDir = true;
        ld = 1e18;
        lr = 1e18;
        sd = 0;
        sr = 0;
        fileSize = 0;
    }
};

file root;

// 用于分割路径的函数，以/进行分割
vector<string> split(string &s) {
    char c = '/';
    stringstream stream(s);
    string tmp;
    vector<string> res;
    while (getline(stream, tmp, c)) {
        if (tmp.size() != 0) {

        }
        res.push_back(tmp);
    }
    return res;
};

// 用于寻找文件的函数
vector<file *> find(vector<string> fileNames) {
    vector<file *> res;
    res.push_back(&root);
    for (int i = 1; i < fileNames.size(); ++i) {
        // 如果文件不是目录的话，直接break
        if (!res.back()->isDir) {
            break;
        }
        // 如果找不到该文件，直接break
        if (res.back()->children.count(fileNames[i]) == 0) {
            break;
        }
        // 将该文件加入
        res.push_back(&res.back()->children[fileNames[i]]);
    }
    return res;
};

bool create() {
    string path;
    ll fileSize;
    cin >> path >> fileSize;
    // 首先获取到路径上的所有文件
    vector<string> fileNames = split(path);
    // 通过文件名找到所有的文件
    vector<file *> files = find(fileNames);
    ll inc;
    // 首先判断是否找到了文件
    if (fileNames.size() == files.size()) {
        // 如果文件的最后一个是一个目录，此时直接返回
        if (files.back()->isDir) {
            return false;
        } else {
            inc = fileSize - files.back()->fileSize;
        }
    } else {
        // 判断最后一个文件是否为文件夹，
        if (!files.back()->isDir) {
            return false;
        } else {
            // 否则，增量直接为文件大小
            inc = fileSize;
        }
    }
    for (int i = 0; i < files.size(); ++i) {
        // 判断配额大小是否会超出
        if (files[i]->sr + inc > files[i]->lr) {
            return false;
        }
        if (i == fileNames.size() - 2) {
            // 判断该文件夹配额是否会超出
            if (files[i]->sd + inc > files[i]->ld) {
                return false;
            }
        }
    }

    for (int i = files.size(); i < fileNames.size(); ++i) {
        // 首先在对应的文件夹的children中加入文件
        // 然后在files中加入文件
        files.push_back(&files.back()->children[fileNames[i]]);
    }
    // 让最后一个文件的变为文件
    files.back()->isDir = false;
    files.back()->fileSize = fileSize;
    // 对于路径上的所有文件都加上配额
    for (auto &i:files) {
        i->sr += inc;
    }
    // 对于它所属的文件加上对应配额
    files.end()[-2]->sd += inc;
    return true;
}

bool remove() {
    string path;
    cin >> path;
    // 首先获取到路径上的所有文件
    vector<string> fileNames = split(path);
    // 通过文件名找到所有的文件
    vector<file *> files = find(fileNames);
    // 如果找不到，直接返回true
    if (files.size() != fileNames.size()) {
        return true;
    }
    // 如果是一个文件夹，删除该文件夹当前所用配额数
    if (files.back()->isDir) {
        for (auto &i:files) {
            i->sr -= files.back()->sr;
        }
    } else {
        // 如果是一个文件，删去文件大小
        for (auto &i:files) {
            i->sr -= files.back()->fileSize;
        }
        // 他的直接父文件夹删去该文件大小
        files.end()[-2]->sd -= files.back()->fileSize;
    }
    // 从他的父文件夹中删除
    files.end()[-2]->children.erase(fileNames.back());
    return true;
}

bool quota() {
    string path;
    ll ld, lr;
    cin >> path >> ld >> lr;
    // 特判特殊条件
    if (ld == 0) {
        ld = 1e18;
    }
    if (lr == 0) {
        lr = 1e18;
    }
    // 分割路径
    vector<string> fileNames = split(path);
    // 找到所有文件
    vector<file *> files = find(fileNames);
    // 找不到直接返回false
    if (fileNames.size() != files.size()) {
        return false;
    }
    // 文件夹直接返回false
    if (!files.back()->isDir) {
        return false;
    }
    // 如果配额不满足，直接返回
    if (files.back()->sd > ld || files.back()->sr > lr) {
        return false;
    }
    // 设置配额
    files.back()->ld = ld;
    files.back()->lr = lr;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        char op;
        cin >> op;
        bool res;
        if (op == 'C') {
            res = create();
        }
        if (op == 'R') {
            res = remove();
        }
        if (op == 'Q') {
            res = quota();
        }
        if (res) {
            cout << "Y" << endl;
        } else {
            cout << "N" << endl;
        }
    }
    return 0;
}