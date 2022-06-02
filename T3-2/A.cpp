#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll st, ed;
int flag = 0;

class data {
public:
    ll type;
    ll maxlen;
    ll maxother;
    ll v;
    ll p1other;
    ll v1;
    ll p2other;
    ll v2;

    data() {}

    data(long long int maxlen, long long int maxother, long long int v, long long int p1Other, long long int v1,
         long long int p2Other, long long int v2, long long int type) : maxlen(maxlen), maxother(maxother), v(v),
                                                                        p1other(p1Other), v1(v1),
                                                                        p2other(p2Other), v2(v2), type(type) {}
};

class ans {
public:
    ll st, ed;
    ll bew;
    ll abss;
    data par;
    vector<vector<ll>> mat;

    ans(long long int st, long long int ed, const data &par) : st(st), ed(ed), par(par) {
        ll sz = par.maxlen;
        abss = abs((ed - st) - (sz * sz));
        bew = ed - st;
    }

    ans() {}


    bool operator<(const ans &oth) const {
        if (abss != oth.abss) {
            return abss < oth.abss;
        }
        if (bew != oth.bew) {
            return bew < oth.bew;
        }
        return st < oth.st;
    }

    bool operator>(const ans &oth) const {
        if (abss != oth.abss) {
            return abss > oth.abss;
        }
        if (bew != oth.bew) {
            return bew > oth.bew;
        }
        return st > oth.st;
    }
};

ans fin;

data res;

class date {
public:
    ll h, m, s;

    date(long long int h, long long int m, long long int s) : h(h), m(m), s(s) {}
};

string outputDate(date d);

void output(const ans &s);

ll date2ll(date d) {
    ll sum = d.h * 60 * 60 + d.m * 60 + d.s;
    return sum;
}

date ll2date(ll time) {
    ll hh = time / 3600L;
    time -= (hh * 60 * 60);
    ll mm = time / 60L;
    time -= (mm * 60);
    ll ss = time;
    date now = date(hh, mm, ss);
    return now;
}

vector<vector<ll>> mat;

bool cmp(pair<ll, ll> a1, pair<ll, ll> a2) {
    return max(a1.first, a1.second) < max(a2.first, a2.second);
}


void draw(ll i, ll j, ll maxlen, ll maxother, ll v, ll p1other, ll v1, ll p2other, ll v2, ll type) {

    res = data(maxlen, maxother, v, p1other, v1, p2other, v2, type);
    ans aa = ans(i, j, res);
    if (flag == 0) {
        fin = aa;
        flag = 1;
        return;
    }
    if (aa < fin) {
//        if (type != 1) {
//            output(aa);
//        }
        fin = aa;
    }
}

void draws(ll maxlen, ll maxother, ll v, ll p1other, ll v1, ll p2other, ll v2, ll type) {
//    int maxlen = 0;
//    int maxother = 0;

    mat.resize(maxlen);
    for (ll i = 0; i < maxlen; ++i) {
        mat[i] = vector<ll>(maxlen, 0);
    }

    for (ll i = 0; i < maxother; ++i) {
        mat[i] = vector<ll>(maxlen, v);
    }

    if (type == 1) {
        for (ll i = maxother; i < maxlen; ++i) {
            for (int j = 0; j < maxlen; ++j) {
                if (j < p1other) {
                    mat[i][j] = v1;
                } else {
                    mat[i][j] = v2;
                }
            }

        }
    } else {
        for (ll i = maxother; i < maxother + p1other; ++i) {
            mat[i] = vector<ll>(maxlen, v1);
        }
        for (ll i = maxother + p1other; i < maxlen; ++i) {
            mat[i] = vector<ll>(maxlen, v2);
        }
    }

}

class rect {
public:
    int id;
    ll first, second;

    rect() {}

    rect(int id, ll xx, ll yy) : id(id) {
        if (xx >= yy) {
            first = xx;
            second = yy;
        } else {
            first = yy;
            second = xx;
        }
    }

    bool operator>(const rect &rhs) const {
        return first > rhs.first;
    }

    bool operator<(const rect &rhs) const {
        return rhs > *this;
    }
};

int check(ll start, ll end) {
    date std = ll2date(start);
    date edd = ll2date(end);
    rect re1 = rect(0, std.h, std.m);
    rect re2 = rect(1, std.s, edd.h);
    rect re3 = rect(2, edd.s, edd.m);

    rect value[3] = {re1, re2, re3};
    sort(value, value + 3);
    ll maxlen = value[2].first;
    ll maxother = value[2].second;
//    if (start + (maxlen * maxlen) > ed) {
//        return 0;
//    }
    //||(value[0].first==value[1].first==value[2].first)
    if (value[0].second == 0
        || value[1].second == 0 || value[2].second == 0
        || value[0].first == 0 || value[1].first == 0 || value[2].first == 0) {
        return 0;
    }

    int flags = 0;
    if (value[1].first == value[2].first &&value[1].first == value[0].first) {
        if (value[1].second + value[0].second + value[2].second == value[1].first) {
            draw(start, end, maxlen, maxother, value[2].id, value[0].second, value[0].id, value[1].second, value[1].id,
                 2);
        }
    }
    if (value[0].first == value[1].first) {
        if (value[0].first + maxother == maxlen && value[0].second + value[1].second == maxlen) {
            draw(start, end, maxlen, maxother, value[2].id, value[0].second, value[0].id, value[1].second, value[1].id,
                 1);
        }
    }
    if (value[0].first == value[1].second) {
        if (value[0].first + maxother == maxlen && value[0].second + value[1].first == maxlen) {
            draw(start, end, maxlen, maxother, value[2].id, value[0].second, value[0].id, value[1].first, value[1].id,
                 1);
        }
    }

    if (value[0].second == value[1].first) {
        if (value[0].second + maxother == maxlen && value[0].first + value[1].second == maxlen) {
            draw(start, end, maxlen, maxother, value[2].id, value[0].first, value[0].id, value[1].second, value[1].id,
                 1);
        }
    }
    if (value[0].second == value[1].second) {
        if (value[0].second + maxother == maxlen && value[0].first + value[1].first == maxlen) {
            draw(start, end, maxlen, maxother, value[2].id, value[0].first, value[0].id, value[1].first, value[1].id,
                 1);
            flags = 1;
        }
    }
    return flags;
}

string outputDate(date d) {
    string time;
    if (d.h < 10) {
        time += ("0" + to_string(d.h));
    } else {
        time += to_string(d.h);
    }
    time += ":";
    if (d.m < 10) {
        time += ("0" + to_string(d.m));
    } else {
        time += to_string(d.m);
    }
    time += ":";
    if (d.s < 10) {
        time += ("0" + to_string(d.s));
    } else {
        time += to_string(d.s);
    }
    return time;
}

void output(const ans &s) {
    draws(s.par.maxlen, s.par.maxother, s.par.v, s.par.p1other, s.par.v1, s.par.p2other, s.par.v2, s.par.type);
    vector<vector<ll>> matt = mat;
    ll i = s.st;
    ll j = s.ed;
    int maxlen = matt.size();
    cout << maxlen << endl;
    cout << outputDate(ll2date(i)) << " ";
    cout << outputDate(ll2date(j)) << endl;
    cout << (j - i) << " ";
    cout << s.abss << endl;
    for (int k = 0; k < matt.size(); ++k) {
        for (int l = 0; l < matt.size(); ++l) {
            cout << matt[k][l];
        }
        cout << "\n";
    }
    //cout << "\n";
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    ll a, b, c, d, e, f;
    int idx = 1;
    while (T--) {
        cin >> a >> b >> c >> d >> e >> f;
        date start = date(a, b, c);
        date end = date(d, e, f);
        st = date2ll(start);
        ed = date2ll(end);

        flag = 0;
        for (ll i = st; i <= ed; ++i) {
            for (ll j = i; j <= ed; ++j) {
                check(i, j);
            }
        }
        cout << "Case #" << idx << ":" << endl;
        idx++;
        if (flag == 0) {
            cout << -1 << endl;
            cout << "\n";
        } else {
            //ans an = res.top();
            output(fin);
            cout << "\n";
        }
    }
    return 0;
}