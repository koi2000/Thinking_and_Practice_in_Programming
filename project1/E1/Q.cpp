//
// Created by DELL on 2022/2/22.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        stringstream sstream(input);

        string t;
        vector<int> temp;
        while (sstream >> t) {
            temp.push_back(stoi(t, nullptr, 16));
        }
        int sum = 0;
        for (int j = 0; j < temp.size(); ++j) {
            sum += temp[j];
        }

        cout << sum << endl;
    }
    return 0;
}
