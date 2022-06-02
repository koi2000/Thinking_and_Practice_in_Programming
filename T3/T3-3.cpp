//
// Created by DELL on 2022/5/16.
//
#include <bits/stdc++.h>

using namespace std;


// 因为使用vector<string>进行存储，为了方便操作，将所有的坐标映射到0，0
class notebook {
public:
    vector<string> content;
    string copy;
    pair<int, int> his;
    pair<int, int> now;

    notebook() {
        content = vector<string>();
        his = make_pair(0, 0);
        now = make_pair(0, 0);
    }


};

notebook nb;

void handleMove(string comd) {
    if (comd == "Home") {
        nb.now.second = 0;
    }
    if (comd == "End") {
        int size = nb.content[nb.now.first].size();
        nb.now.second = size;
    }
    if (comd == "Up") {
        if (nb.now.first != 0) {
            nb.now.first--;
        }
    }
    if (comd == "Down") {
        if (nb.now.first < nb.content.size() - 1) {
            nb.now.first++;
        }
    }
    if (comd == "Left") {
        // 位于记事本开头
        if (nb.now.second == 0 && nb.now.first == 0) {
        } else if (nb.now.second == 0) {
            // 位于某一行的开始
            nb.now.first--;
            int size = nb.content[nb.now.first].size();
            nb.now.second = size;
        } else {
            nb.now.second--;
        }
    }
    if (comd == "Right") {
        // 获取到最后一行的信息
        int num = nb.content.size() - 1;
        int size = nb.content[num].size() - 1;
        // 获取到当前行的信息
        int sizeNow = nb.content[nb.now.first].size();

        // 如果当前位于最后一行并且位于最后一列
        if(nb.now.first==num&&nb.now.second==size){
        }else if(nb.now.second){

        }
    }
}

void handleInsert(string comd){
    if(comd=="Char"){
        string str;
        cin>>str;

    }
    if(comd=="Enter"){

    }
    if(comd=="Space"){

    }
    if(comd=="Paste"){

    }
}

void handleDel(string comd){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string cmd;

    for (int i = 0; i < n; ++i) {
        cin >> cmd;
        if (cmd == "MOVE") {
            string comd;
            cin >> comd;
            handleMove(comd);
        }
        if (cmd == "INSERT") {
            string comd;
            cin >> comd;
            handleInsert(comd);
        }
        if (cmd == "REMOVE") {

        }
        if (cmd == "PRINT") {

        }
        if (cmd == "FIND") {

        }
        if (cmd == "COPY") {

        }
        if (cmd == "COUNT") {

        }
    }

    return 0;
}
