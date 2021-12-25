#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>
#include <queue>
#include <map>
#include <cstdio>
#include <random>
#include <chrono>
#include <deque>
#include <fstream>
#include <set>
#include <bitset>
#define ll long long
#define ld long double
#define int long long
using namespace std;
const int INF = 1e13 + 5;

struct Node {
    int value = 0,
        minOnTree = 0,
        Priority = 0,
        cnt = 0;
    Node* l = nullptr;
    Node* r = nullptr;
    Node() {};
    Node(int val) {
        value = val;
        Priority = rand() << 16 + rand();
        minOnTree = val;
        l = nullptr;
        r = nullptr;

    }
};
typedef Node* pnode;

int cnt(pnode p) {
    if (p != nullptr) return p->cnt;
    return 0;
}

int getMin(pnode p) {
    if (p != nullptr) return p->minOnTree;
    return INF;
}

void recalc(pnode p) {
    if (p != nullptr) {
        p->cnt = 1 + cnt(p->l) + cnt(p->r);
        p->minOnTree = min({ p->value, getMin(p->l), getMin(p->r )});
    }
}

void Merge(pnode L, pnode R, pnode& t) {
    if (L == nullptr || R == nullptr) {
        if (L != nullptr) t = L;
        else t = R;
    }
    else {
        if (L->Priority > R->Priority) {
            Merge(L->r, R, L->r), t = L;
        }
        else {
            Merge(L, R->l, R->l), t = R;
        }
    }
    recalc(t);
}

void Split(pnode t, pnode &l, pnode &r, int pos) {
    if (!t) return void(l = r = 0);
    if (pos <= cnt(t->l)) {
        Split(t->l, l, t->l, pos), r = t;
    }
    else {
        Split(t->r, t->r, r, pos - 1 - cnt(t->l)), l = t;
    }
    recalc(t);
}

pnode root = nullptr,
t1 = nullptr,
t2 = nullptr;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int M = 0;
    cin >> M;
    char c;
    while (M--) {
        t1 = nullptr;
        t2 = nullptr;
        cin >> c;
        if (c == '+') {
            int pos = 0,
                tmp = 0;
            cin >> pos >> tmp;
            Split(root, t1, t2, pos);
            Merge(t1, new Node(tmp), t1);
            Merge(t1, t2, root);
        }
        else {
            int lll = 0,
                rrr = 0;
            cin >> lll >> rrr;
            Split(root, root, t1, lll - 1);
            Split(t1, t1, t2, rrr - lll + 1);
            cout << t1->minOnTree << endl;
            Merge(root, t1, root);
            Merge(root, t2, root);
        }
    }
    return 0;
}
