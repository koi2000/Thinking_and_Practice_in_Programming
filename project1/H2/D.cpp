//
// Created by DELL on 2022/1/11.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> note;
    for (int i = 0; i < n; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            string word;
            cin >> word;
            if (note.find(word) != note.end()) {
                cout << "found" << endl;
            } else {
                note.insert(word);
                cout << "write" << endl;
            }
        }
        if (op == 2) {
            string word;
            cin >> word;
            if (note.find(word) != note.end()) {
                note.erase(word);
                cout << "erased" << endl;
            } else {
                cout << "not found" << endl;
            }
        }
        if (op == 3) {
            for (const string& word:note) {
                cout << word << " ";
            }
            cout<<endl;
        }
    }
    return 0;
}


