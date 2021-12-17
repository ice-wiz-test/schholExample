#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#include <cstdio>
#include <random>
#include <chrono>
#include <deque>
#include <fstream>
#include <bitset>
#include <map>
#include <algorithm>
#include <stack>
#include <cassert>

using namespace std;

#define int long long
#define ld long double
#define ll long long
const int INF = 1e13 + 5;
const int mod = 1e9 + 7;


class node {
public:
	int value;
	node* left;
	node* right;
	int height;
	node(int val) {
		value = val;
		left = nullptr;
		right = nullptr;
		height = 1;
	}

};
typedef node* pnode;
class Tree{
    public:
    pnode root;
    int pointerHeight(pnode p);
    int fact(pnode p);
    void correctHeight(pnode p);
    pnode turnRight(pnode p);
    pnode turnLeft(pnode p);
    pnode balance(pnode p);
    pnode insertTree(pnode p, int val);
    pnode findMin(pnode p);
    pnode searchAndDestroyMin(pnode p);
    pnode removeKey(pnode p, int val);
    pnode findKey(pnode p, int val);
    void printOUT(pnode p);
    Tree() {
        root = nullptr;
    }
};
int Tree::pointerHeight(pnode p) {
    if(p == nullptr) return 0;
    return p->height;
}

int Tree::fact(pnode p) {
    return pointerHeight(p->right) - pointerHeight(p->left);
}

void Tree::correctHeight(pnode p) {
    p->height = max(pointerHeight(p->left), pointerHeight(p->right)) + 1;
}

pnode Tree::turnRight(pnode p)// правый поворот вокруг p
{
	pnode q = p->left;
	p->left = q->right;
	q->right = p;
	Tree::correctHeight(p);
	Tree::correctHeight(q);
	return q;
}
pnode Tree::turnLeft(pnode q) {
    pnode p = q->right;
	q->right = p->left;
	p->left = q;
	Tree::correctHeight(q);
	Tree::correctHeight(p);
	return p;
}

pnode Tree::balance(pnode p) {
    correctHeight(p);
    if(fact(p) == 2) {
        if(fact(p->right) < 0 ) {
            p->right = turnRight(p->right);
        }
        return turnLeft(p);
    }
    if(fact(p) == -2) {
        if(fact(p->left) > 0) {
            p->left = turnLeft(p->left);
        }
        return turnRight(p);
    }
    return p;
}

pnode Tree::insertTree(pnode p, int value) {
    if(p == nullptr) return new node(value);
    if(value < p->value) p->left = insertTree(p->left, value);
    else p->right = insertTree(p->right, value);
    return balance(p);
}

pnode Tree::findMin(pnode p) {
    if(p->left == nullptr) return p;
    return p->left;
}

pnode Tree::searchAndDestroyMin(pnode p) {
    if(p->left == nullptr) return p->right;
    p->left = Tree::searchAndDestroyMin(p->left);
    return balance(p);
}

pnode Tree::findKey(pnode p, int value) {
    if(p ==  nullptr) return p;
    if(p->value == value) return p;
    if(p->value > value) return findKey(p->left, value);
    else return findKey(p->right, value);
}

pnode Tree::removeKey(pnode p, int value) {
    if(!p) return nullptr;
    if(value < p->value) {
        p->left = removeKey(p->left, value);
    } else {
        if(value > p->value) {
            p->right = removeKey(p->right, value);
        } else {
            pnode q = p->left;
            pnode r = p->right;
            delete p;
            if(r ==  nullptr) return q;
            pnode mn = Tree::findMin(r);
            mn->right = searchAndDestroyMin(r);
            mn->left = q;
            return balance(mn);
        }
    }
}

void Tree::printOUT(pnode p) {
    if(p->right !=  nullptr) {
        cout << p->right->value << " RIGHT VALUE. ";
    }
    if(p->left !=  nullptr) {
        cout << p->left->value << " LEFT VALUE. ";
    }
    cout << p->value << " VALUE." << endl;
    if(p->right != nullptr) Tree::printOUT(p->right);
    if(p->left !=  nullptr) Tree::printOUT(p->left);
}
/*
    if the question arises, the function to delete the minimal element is searchAndDestroyMin, and call iot from the root
*/
void solve() {

    cout << " Welcome to the AVL TREE!!! If you wish to exit, enter -1" << endl;
    cout << "To delete the minimal element, enter 11. To enter a new value, enter 12 followed by your number" << endl;
    cout << "To delete by key, enter 13 followed by your element. To print the tree, enter 14" << endl;
    Tree t = Tree();
    while(true) {
        int input = 0;
        cin >> input;
        if(input == -1) break;
        if(input == 11) {
                if(t.root == nullptr) cout << "Why would you do that." << endl;
                else t.root = t.searchAndDestroyMin(t.root);
        }
        if(input == 12) {
            int tmp = 0;
            cin >> tmp;
            t.root = t.insertTree(t.root, tmp);
        }
        if(input == 13) {
            int tmp = 0;
            cin >> tmp;
            t.root = t.removeKey(t.root, tmp);
        }
        if(input == 14) {
            if(t.root == nullptr) cout << "That is not very nice of you to do." << endl;
            else t.printOUT(t.root);
        }
    }

}

signed main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	solve();
}
