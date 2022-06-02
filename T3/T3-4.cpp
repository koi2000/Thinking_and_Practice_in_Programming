#include <bits/stdc++.h>

#define rep(i, s, t) for(int i=s;i<=t;i++)
using namespace std;

/* 全局变量 */
int n;                   // 猪的数量
queue<char> allCards;    // 牌堆

struct Pig {
/* 属性 */
    int index;            // 当前猪下标
    int hp = 4;           // 血量
    char type;            // 猪的类型: M, Z, F
    char jumpType = 0;    // 跳的类型: Z(忠), F(反), f(MP视角的类反), 0(空), 注意对MP来说针对F更优先于f
    bool arming = false;  // 有无装备
    list<char> cards;     // 手中的牌
/* 方法定义, 这里是完成本题必须的方法, 可以不必多定义了 */
    void jump() { jumpType = type == 'F' ? 'F' : 'Z'; } // 跳阵营
    bool isJumpItsFriend(Pig *pig) { return pig->type == 'F' ? jumpType == 'F' : jumpType == 'Z'; } // 我跳它朋友了吗?
    Pig *getNextPig();    // 获取存活的下家
    void addCards(int num);// 从牌堆拿牌放到自己手右
    bool del(char c);     // 删掉手里一张牌, 删成功则返回true
    void hurt(Pig *attacker);// 被攻击掉一点血
    bool cost(Pig *attacker, char c);// 被迫消耗手中一张牌, 消耗成功返回true并不减血, 否则减血, 减血到0尝试用桃, 无则死亡, 根据身份对杀者做后续处理
    bool useP();          // 主动使用桃, 满足使用条件就使用, 使用后返回true
    bool useK();          // 主动使用杀, 满足使用条件就使用, 使用后返回true
    bool useF();          // 主动使用决斗, 满足使用条件就使用, 使用后返回true
    bool useN();          // 主动使用南猪入侵, 满足使用条件就使用, 使用后返回true
    bool useW();          // 主动使用万箭齐发, 满足使用条件就使用, 使用后返回true
    bool findJ(Pig *attacker); // 被迫去求无懈可击, 求到则返回true
    bool useJ(Pig *pig);  // 帮某个猪用无懈可击, 用成功返回true
} ps[15];

/* 全局方法 */
bool isGameEnd() {
    // 主猪的血量小于0，游戏结束
    if (ps[0].hp <= 0) return true;
    // 遍历所有反猪
    rep(i, 1, n - 1)
        if (ps[i].type == 'F' && ps[i].hp > 0)
            return false;
    return true;
}

int cnt = 0;

// 判断哪一方胜利
void judgeGameEnd() {
    if (isGameEnd()) {
        printf(ps[0].hp > 0 ? "MP\n" : "FP\n");
        rep(i, 0, n - 1) {
            if (ps[i].hp <= 0) {
                printf("DEAD\n");
            } else {
                for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++)
                    printf(it == ps[i].cards.end() ? "%c" : "%c ", *it);
                printf("\n");
            }
        }
        exit(0);
    }
}

void solve() {
    ps[0].jump();
    while (true) {
        // 遍历每一只猪
        rep(i, 0, n - 1) {
            // 当前猪死了，跳过他
            if (ps[i].hp <= 0) continue;
            // 摸两张牌
            ps[i].addCards(2);
            // 记录是否使用了杀
            bool usedK = false;
            // 遍历所有手牌
            for (list<char>::iterator it = ps[i].cards.begin(); it != ps[i].cards.end(); it++) {
                // 判断该牌是否被使用
                bool used = false;
                char c = *it;
                it = ps[i].cards.erase(it);
                switch (c) {
                    // 桃
                    case 'P':
                        used = ps[i].useP();
                        break;
                        // 杀，这里已经实现了判断是否装备了诸葛连弩
                    case 'K':
                        if (!usedK || ps[i].arming) used = usedK = ps[i].useK();
                        break;
                        // 决斗
                    case 'F':
                        used = ps[i].useF();
                        break;
                        // 南蛮入侵
                    case 'N':
                        used = ps[i].useN();
                        break;
                        // 万箭齐发
                    case 'W':
                        used = ps[i].useW();
                        break;
                        // 诸葛连弩
                    case 'Z':
                        ps[i].arming = used = true;
                        break;
                }
                // 如果该牌已经被使用
                if (used) it = --ps[i].cards.begin();
                    // 该牌没有被使用
                else it = ps[i].cards.insert(it, c);
                if (ps[i].hp <= 0) break;
            }
        }
    }
}

/* 主控方法 */
int main() {
    // Input
    int m;
    scanf("%d%d", &n, &m);
    char s[5];
    rep(i, 0, n - 1) {
        ps[i].index = i;
        scanf("%s", s), ps[i].type = s[0];
        rep(j, 1, 4) scanf("%s", s), ps[i].cards.push_back(s[0]);
    }
    while (m--) scanf("%s", s), allCards.push(s[0]);
    // To solve
    solve();
}

Pig *Pig::getNextPig() {
    int nxt = (index + 1) % n;
    while (ps[nxt].hp <= 0) {
        nxt = (nxt + 1) % n;
    }
    return &ps[nxt];
}

void Pig::addCards(int num) {
    rep(i, 1, num) {
        cards.push_back(allCards.front());
        allCards.pop();
    }
}

bool Pig::useP() {
    if (hp < 4) {
        hp++;
        return true;
    }
    return false;
}

// 根据伤害来源来判断死亡情况
void Pig::hurt(Pig *attacker) {
    if (--hp == 0) {
        if (this->del('P')) {
            this->useP();
        } else {
            judgeGameEnd();
            switch (type) {
                case 'F':
                    attacker->addCards(3);
                    break;
                case 'Z':
                    if (attacker->type == 'M') attacker->cards.clear(), attacker->arming = false;
                    break;
            }
        }
    }
}

bool Pig::cost(Pig *attacker, char c) {
    if (this->del(c)) {
        return true;
    }
    hurt(attacker);
    return false;
}

bool Pig::findJ(Pig *attacker) {
    Pig *nxt = attacker;
    do {
        // "找个好心的猪猪帮我挡刀"
        if (this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !nxt->useJ(this);
        }
        nxt = nxt->getNextPig();
    } while (nxt != attacker);
    return false;
}

//
bool Pig::useJ(Pig *pig) {
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // "套娃指找找有没有猪猪会阻止我帮别人挡刀"
        if (!this->isJumpItsFriend(nxt) && nxt->del('J')) {
            nxt->jump();
            return !pig->findJ(nxt);
        }
    }
    return false;
}

bool Pig::useK() {
    // TODO: 补全代码
    // 一个猪的攻击距离最多有两个猪
    // 逆时针的第一个猪
    Pig *pg1 = getNextPig();
    // 找顺时针的第一个猪
    int nxt = (index - 1 + n) % n;
    while (ps[nxt].hp <= 0) {
        nxt = (nxt - 1 + n) % n;
    }
    Pig *pg2 = &ps[nxt];
    vector<Pig *> pgs;
    // 不相同才能放入其中
    if (pg1->index != this->index) {
        pgs.push_back(pg1);
    }
    bool find = false;
    // 对于主猪来说
    if (this->type == 'M') {
        // 首先找到表反的猪
        for (auto &pg:pgs) {
            // 找到反猪，攻击他，并找他要闪
            if (pg->jumpType == 'F') {
                pg->cost(this, 'D');
                find = true;
                break;
            }
        }
        if (find)return find;
        // 找到表类反的猪
        for (auto &pg:pgs) {
            // 找到反猪，攻击他，并找他要闪
            if (pg->jumpType == 'f') {
                pg->cost(this, 'D');
                find = true;
                break;
            }
        }
        if (find)return find;
    } else if (type == 'Z') {
        // 对于忠猪来说
        // 首先找到表反的猪
        for (auto &pg:pgs) {
            // 找到反猪，攻击他，并找他要闪，这时忠猪已经表忠
            if (pg->jumpType == 'F') {
                pg->cost(this, 'D');
                find = true;
                // 跳忠
                this->jump();
                break;
            }
        }
        if (find)return find;
    } else if (type == 'F') {
        // 对于反猪来说
        // 首先找主猪
        for (auto &pg:pgs) {
            // 找到主猪
            if (pg->type == 'M') {
                pg->cost(this, 'D');
                find = true;
                // 跳反
                this->jump();
                break;
            }
        }
        if (find)return find;

        // 找不到主族，找忠猪，攻击他，并找他要闪
        for (auto &pg:pgs) {
            if (pg->jumpType == 'Z') {
                pg->cost(this, 'D');
                find = true;
                // 跳反
                this->jump();
                break;
            }
        }
        if (find)return find;
    }
    return false;
}

bool Pig::useF() {
    //assert(false);
    // TODO: 补全代码
    bool find = false;
    if (this->type == 'M') {
        // 首先找到表反的猪
        for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            // 如果能找到，则双方开始厮杀
            if (nxt->jumpType == 'F') {
                // 来找找是否有人使用无懈可击
                if (nxt->findJ(this)) {
                    return true;
                }
                find = true;
                while (true) {
                    if (!nxt->cost(this, 'K'))break;
                    if (!this->cost(nxt, 'K'))break;
                }
                break;
            }
        }
        if (find)return find;
        // 找到表类反的猪
        for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            if (nxt->jumpType == 'f') {
                // 如果类反猪是真的反猪，则开始厮杀
                // 来找找是否有人使用无懈可击
                if (nxt->findJ(this)) {
                    return true;
                }
                find = true;
                if (nxt->type == 'F') {
                    while (true) {
                        if (!nxt->cost(this, 'K'))break;
                        if (!this->cost(nxt, 'K'))break;
                    }
                    break;
                } else {
                    // 来找找是否有人使用无懈可击
                    if (findJ(nxt)) {
                        return true;
                    }
                    // 如果类反猪是忠猪，则不出杀，直接受伤
                    nxt->hurt(this);
                }
            }
        }
        if (find)return find;
    } else if (type == 'Z') {
        // 对于忠猪来说
        // 首先找到表反的猪，此时他也已经表忠
        for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            // 如果能找到，则双方开始厮杀
            if (nxt->jumpType == 'F') {
                this->jump();
                find = true;
                // 来找找是否有人使用无懈可击
                if (nxt->findJ(this)) {
                    return true;
                }
                while (true) {
                    if (!nxt->cost(this, 'K'))break;
                    if (!this->cost(nxt, 'K'))break;
                }
                break;
            }
        }
        if (find)return find;
    } else {
        // 对于反猪来说
        // 首先找到主猪
        for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            // 如果能找到，则双方开始厮杀
            if (nxt->type == 'M') {
                find = true;
                this->jump();
                // 来找找是否有人使用无懈可击
                if (nxt->findJ(this)) {
                    return true;
                }
                while (true) {
                    if (!nxt->cost(this, 'K'))break;
                    if (!this->cost(nxt, 'K'))break;
                }
                break;
            }
        }
        if (find)return find;
        // 找到表类反的猪
        for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
            if (nxt->jumpType == 'Z') {
                // 如果类反猪是真的反猪，则开始厮杀
                find = true;
                this->jump();
                // 来找找是否有人使用无懈可击
                if (nxt->findJ(this)) {
                    return true;
                }
                while (true) {
                    if (!nxt->cost(this, 'K'))break;
                    if (!this->cost(nxt, 'K'))break;
                }
                break;
            }
        }
        if (find)return find;
    }
    return false;
}

bool Pig::useN() {
    //assert(false);
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        // 来找找是否有人使用无懈可击
        if (nxt->findJ(this)) continue;
        // 无人使用无懈可击
        bool res = nxt->cost(this, 'K');
        if (nxt->type == 'M' && !res) {
            if (this->jumpType == 0) {
                this->jumpType = 'f';
            }
        }
    }
    return true;
}

bool Pig::useW() {
    //assert(false);
    for (Pig *nxt = getNextPig(); nxt != this; nxt = nxt->getNextPig()) {
        // TODO: 补全代码
        // 来找找是否有人使用无懈可击
        if (nxt->findJ(this)) continue;
        // 无人使用无懈可击
        bool res = nxt->cost(this, 'D');
        if (nxt->type == 'M' && !res) {
            if (this->jumpType == 0) {
                this->jumpType = 'f';
            }
        }
    }
    return true;
}

bool Pig::del(char c) {
    // TODO: 补全代码
    bool used = false;
    for (auto it = this->cards.begin(); it != this->cards.end(); it++) {
        if (*it == c) {
            this->cards.erase(it);
            used = true;
            break;
        }
    }
    return used;
}