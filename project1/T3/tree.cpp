//
// Created by DELL on 2022/1/12.
//
#include <bits/stdc++.h>

using namespace std;

struct number {
    int num;
    int time;

    bool operator>(const number &rhs) const {
        if (num == rhs.num) {
            return time > rhs.time;
        }
        return num > rhs.num;
    }
};

class LFUCache {
private:
    int time = 0;
    int capacity;
    unordered_map<int, int> kv;
    unordered_map<int, number> cnt;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        time++;
        /*if (kv.find(key) == kv.end()) {
            return -1;
        }*/
        if (kv[key] == 0) {
            return -1;
        }
        cnt[key].num++;
        cnt[key].time = time;
        return kv[key];
    }

    void put(int key, int value) {
        if(capacity<=0){
            return;
        }
        time++;
        if(kv[key] != 0){
            kv[key] = value;
            cnt[key].num++;
            cnt[key].time=time;
            return;
        }
        if (kv.size() == capacity) {
            /*number minn;
            minn.num = INT_MAX;
            minn.time = 0;
            int kk = -1;
            for (auto it = cnt.begin(); it != cnt.end(); it++) {
                if (minn > (*it).second) {
                    minn = (*it).second;
                    kk = (*it).first;
                }
            }*/
            auto it = cnt.begin();
            cnt.erase((*it).first);
            kv.erase((*it).first);
        }

        kv[key] = value;
        number s;
        s.num = 1;
        s.time = time;
        cnt[key] = s;
    }
};
int main() {
    map<int, number> mm;
    cout << mm[1].num << endl;
    return 0;
}