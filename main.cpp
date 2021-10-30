#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <deque>
#include <string>
#include <ctime>
#include "linkedlist.h"

#define int long long
using namespace std;
const int INF = 1e13 + 8;
const int mod = 998244353;
vector<int> helper;
int score = 0;
LinkedList<int> ll;

void playGame() {
	cout << " !!!! WELCOME TO THE GAME !!!!" << endl;
	cout << ll << endl;

	cout << " !!!! IF YOU GET 3 CONSECUTIVE SAME COLORS, THEY WILL DELETE THEMSELVES !!!! " << endl;

	cout << " !!!! AT THE BEGINNING, YOU ARE POSITIONED AT THE START !!!!" << endl;

	cout << "The rules are simple - you get the number of the next number" << endl;
	cout << "Then you output one number from -5 to 5 - whcih signifies the distance from the current moment to where you wish to insert it" << endl;
	cout << "Notice that it will be inserted before the specified reference, so you cannot insert to the end. This is done for balance reasons" << endl;
	ll.setCur();
	int pos = 11;
	while (true) {
		int dist = 0;
		cout << ll << endl;

		cout << " NEW ELEMENT IS " << helper[pos] << endl;
		pos++;
		cin >> dist;
		cout << dist << endl;
		if (dist < 0) {
			while (dist < 0) {
				ll.pushCurLeft();
				dist++;
			}
		}
		else {
			while (dist > 0) {
				ll.pushCurRight();
				dist--;
			}
		}

		//ll.addCurrent(helper[pos]); //the problem with the loop lies here
		cout << "HERE" << endl;
		score = score + ll.recalc();

		cout << " !!!! THE CURRENT SCORE IS !!!!" << score << endl;


	}
}

signed main() {	
	helper.assign(1e6, 0);

	for (int i = 0; i < 1e6; ++i) {
		helper[i] = rand();
		helper[i] = helper[i] % 4;
	}

	for (int i = 0; i < 10; ++i) {
		ll.addFront(helper[i]);
	}

		playGame();
	
}
