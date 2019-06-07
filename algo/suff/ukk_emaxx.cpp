//
// Created by imd on 18/05/2019.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <map>
#include <fstream>

using namespace std;
string s;
int n;
int c = 0;

struct node {
    int l, r, par, link;
    map<char, int> next;

    node(int l = 0, int r = 0, int par = -1)
            : l(l), r(r), par(par), link(-1) {}

    int len() { return r - l; }

    int &get(char c) {
        if (!next.count(c)) next[c] = -1;
        return next[c];
    }
};

struct state {
    int v, pos;

    state(int v, int pos) : v(v), pos(pos) {}
};

state ptr(0, 0);
node t[100000];
int sz;

state go(state st, int l, int r) {
    while (l < r)
        if (st.pos == t[st.v].len()) {
            st = state(t[st.v].get(s[l]), 0);
            if (st.v == -1) return st;
        } else {
            if (s[t[st.v].l + st.pos] != s[l])
                return {-1, -1};
            if (r - l < t[st.v].len() - st.pos)
                return {st.v, st.pos + r - l};
            l += t[st.v].len() - st.pos;
            st.pos = t[st.v].len();
        }
    return st;
}

int split(state st) {
    if (st.pos == t[st.v].len())
        return st.v;
    if (st.pos == 0)
        return t[st.v].par;
    node v = t[st.v];
    int id = sz++;
    t[id] = node(v.l, v.l + st.pos, v.par);
    t[v.par].get(s[v.l]) = id;
    t[id].get(s[v.l + st.pos]) = st.v;
    t[st.v].par = id;
    t[st.v].l += st.pos;
    return id;
}

int get_link(int v) {
    if (t[v].link != -1) return t[v].link;
    if (t[v].par == -1) return 0;
    int to = get_link(t[v].par);
    return t[v].link = split(go(state(to, t[to].len()), t[v].l + (t[v].par == 0), t[v].r));
}

void tree_extend(int pos) {
    for (;;) {
        state nptr = go(ptr, pos, pos + 1);
        if (nptr.v != -1) {
            ptr = nptr;
            return;
        }

        int mid = split(ptr);
        int leaf = sz++;
        t[leaf] = node(pos, n, mid);
        t[mid].get(s[pos]) = leaf;

        ptr.v = get_link(mid);
        ptr.pos = t[ptr.v].len();
        if (!mid) break;
    }
}

void build_tree() {
    sz = 1;
    for (int i = 0; i < n; ++i)
        tree_extend(i);
}

void dfs(node *v, node *p, int p_index, ostream &fout) {
    int index = ++c;
    if (v != &t[0]) fout << p_index << ' ' << index << ' ' << v->l + 1 << ' ' << v->r << '\n';
    for (auto pr : v->next) {
        dfs(&t[v->get(pr.first)], v, index, fout);
    }
//    for (int i = 0; i < 26; i++){
//        if ((v->get('a' + i)) != -1) {
//            dfs(&t[v->get('a' + i)], v, index, fout);
//        }
//    }
}

int main(int argc, char *argv[]) {
//    for (int testN = 0; testN < 100; testN++) {
    ifstream fin("test" + string(argv[1]) + ".in");
    ofstream fout("test" + string(argv[1]) + "_ukk.out");
    fill_n(t, 100000, node());
    getline(fin, s);
    n = s.length();
//        ptr = state(0,0);
    build_tree();
//    for (int i = 0; i < n; i++) {
//        cout << t[i].l << ' ' << t[i].r << '\n';
//    }
    dfs(&t[0], nullptr, 0, fout);
//        cout.flush();
//    cout << "OK";
//    }
}