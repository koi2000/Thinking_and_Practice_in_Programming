//
// Created by DELL on 2022/1/12.
//
#include <bits/stdc++.h>

using namespace std;


class card {
public:
    int number;
    int color;

    card() {}

    card(int number, int color) : number(number), color(color) {}

    bool operator>(card c) const {
        return this->number > c.number;
    }

    bool operator<(card c) const {
        return this->number < c.number;
    }

    bool operator==(card c) const {
        return this->number == c.number && this->color == c.color;
    }
};

int check(int pInt[3], int l);

int check2(int pInt[3]);

int check4(int pInt[3]);

int check5(int pInt[3]);

map<int, int> mm;
vector<card> arr;
card ai;
card bi;

vector<card> getVector(int pInt[3]) {
    vector<card> cards;
    for (int i = 0; i < 3; ++i) {
        cards.push_back(arr[pInt[i]]);
    }
    cards.push_back(ai);
    cards.push_back(bi);
    return cards;
}

int check1(int pInt[3]) {
    return check4(pInt) * check5(pInt);
}

int check2(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    map<int, int> map;
    for (int i = 0; i < cards.size(); ++i) {
        if (map.find(cards[i].number) != map.end()) {
            map[cards[i].number] = map[cards[i].number] + 1;
        } else {
            map[cards[i].number] = 1;
        }
    }
    for (auto it = map.begin(); it != map.end(); it++) {
        if ((*it).second == 4) {
            return 1;
        }
    }
    return 0;
}

int check3(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    map<int, int> map;
    for (int i = 0; i < cards.size(); ++i) {
        if (map.find(cards[i].number) != map.end()) {
            map[cards[i].number] = map[cards[i].number] + 1;
        } else {
            map[cards[i].number] = 1;
        }
    }
    auto it1 = map.begin();
    auto it2 = ++map.begin();
    if ((*it1).second == 3 && (*it2).second == 2) {
        return 1;
    } else if ((*it1).second == 2 && (*it2).second == 3) {
        return 1;
    }
    return 0;
}

int check4(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    for (int i = 1; i < cards.size(); ++i) {
        if (cards[i].color != cards[0].color) {
            return 0;
        }
    }
    return 1;
}

int check5(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    sort(cards.begin(), cards.end());
    for (int i = 1; i < cards.size(); ++i) {
        if (cards[i].number - cards[i - 1].number != 1) {
            return 0;
        }
    }
    return 1;
}

int check6(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    map<int, int> map;
    for (int i = 0; i < cards.size(); ++i) {
        if (map.find(cards[i].number) != map.end()) {
            map[cards[i].number] = map[cards[i].number] + 1;
        } else {
            map[cards[i].number] = 1;
        }
    }

    for (auto it = map.begin(); it != map.end(); it++) {
        if ((*it).second == 3) {
            return 1;
        }
    }
    return 0;
}

int check7(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    map<int, int> map;
    for (int i = 0; i < cards.size(); ++i) {
        if (map.find(cards[i].number) != map.end()) {
            map[cards[i].number] = map[cards[i].number] + 1;
        } else {
            map[cards[i].number] = 1;
        }
    }
    int cnt = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        if ((*it).second == 2) {
            cnt++;
        }
    }
    if (cnt == 2) {
        return 1;
    } else {
        return 0;
    }
}

int check8(int pInt[3]) {
    vector<card> cards = getVector(pInt);
    map<int, int> map;
    for (int i = 0; i < cards.size(); ++i) {
        if (map.find(cards[i].number) != map.end()) {
            map[cards[i].number] = map[cards[i].number] + 1;
        } else {
            map[cards[i].number] = 1;
        }
    }
    int cnt = 0;
    for (auto it = map.begin(); it != map.end(); it++) {
        if ((*it).second == 2) {
            cnt++;
        }
        if ((*it).second == 3) {
            return 0;
        }
    }
    if (cnt == 1) {
        return 1;
    }
    return 0;
}

int check9(int pInt[3]) {
    int cnt = 0;
    for (int i = 1; i < 9; ++i) {
        if (check(pInt, i) == 1) {
            return 0;
        }
    }
    return 1;
}

int check(int pInt[3], int l) {
    if (l == 1) {
        return check1(pInt);
    }
    if (l == 2) {
        return check2(pInt);
    }
    if (l == 3) {
        return check3(pInt);
    }
    if (l == 4) {
        return check4(pInt);
    }
    if (l == 5) {
        return check5(pInt);
    }
    if (l == 6) {
        return check6(pInt);
    }
    if (l == 7) {
        return check7(pInt);
    }
    if (l == 8) {
        return check8(pInt);
    }
    if (l == 9) {
        return check9(pInt);
    }

}

int main() {
    int A, B;
    cin >> A >> B;

    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    ai = card(a1, b1);
    bi = card(a2, b2);

    for (int i = 1; i <= 9; ++i) {
        mm[i] = 0;
    }

    for (int i = 0; i < A; ++i) {
        for (int j = 0; j < B; ++j) {
            card c = card(i, j);
            if (c == ai || c == bi) {
                continue;
            } else {
                arr.push_back(c);
            }
        }
    }
    vector<int[3]> perm;
    for (int i = 0; i < arr.size() - 2; ++i) {
        for (int j = i + 1; j < arr.size() - 1; ++j) {
            for (int k = j + 1; k < arr.size(); ++k) {
                int temp[3] = {i, j, k};
                //perm.push_back(temp);
                for (int l = 1; l <= 9; ++l) {
                    if(check(temp, l)==1){
                        mm[l] += check(temp, l);
                        break;
                    }

                }
            }
        }
    }
    for (int i = 1; i <= 9; ++i) {
        /*if (i == 6) {
            cout << mm[6] - mm[3] << " ";
            continue;
        }*/
        cout << mm[i] << " ";
    }
    return 0;
}


