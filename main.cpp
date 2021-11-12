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
	int t;
	t = ll.getCurVal();
	cout << t << endl;
	int pos = 11;
	int curroffset = 0;
	while (true) {
		int dist = 0;
		cout << ll << endl;
		for (int i = 0; i < curroffset; ++i) {
			cout << "      ";
		}
		cout << "O" << endl;
		cout << " NEW ELEMENT IS " << helper[pos] << endl;
		cin >> dist;
		curroffset = curroffset + dist;
		curroffset = max(0ll, curroffset);
		curroffset = min(curroffset, 10ll);
		cout << " CURRENT OFFSET " << curroffset << endl;
		bool right = true;
		if (dist < 0) {
			while (dist < 0) {
				ll.pushCurLeft();
				dist++;
			}
			right = false;
		}
		else {
			while (dist > 0) {
				ll.pushCurRight();
				dist--;
				
			}
		}
		cout << helper[pos] << " ELEM" << endl;
		ll.addCurrent(helper[pos]); //the problem with the loop lies here
		int add = ll.recalc();
		score = score + add;

		cout << " !!!! THE CURRENT SCORE IS " << score << " !!!! " << endl;
		pos++;

		while (ll.size() < 10) {
			pos++;
			ll.addCurrent(helper[pos]);
		}

		ll.TrimDown();

		if (add > 0) {
			curroffset = 0;
			cout << " WE RESET YOUR POSITION DUE TO YOU GETTING 3 COLORS IN A ROW" << endl;
		}
		if (score >= 30) break;
	}

	cout << "YOU WON !!!!" << endl;
}


void playGameBot() {
	cout << "Use this function to test the bot" << endl;
	int pos = 12;
	ll.setCur();
	ll.pushCurRight();
	ll.pushCurRight();
	ll.pushCurRight();
	ll.pushCurRight();

	int score = 0;
	int iter = 0;
	while (true) {
		iter++;
		if (iter % 10 == 0) {
			int brk;
			cin >> brk;
		}
		cout << ll << endl;
		int temp = helper[pos];		
		pos++;

		if (ll.isEqual()) {
			ll.pushCurRight();
			ll.pushCurRight();
		}

		cout << " CURRENT ELEMENT IS -  " << temp << endl;

		ll.addCurrent(temp);

		score = score + ll.recalc();
		ll.TrimDown();
		while (ll.size() < 10) {
			ll.addCurrent(helper[pos]);
			pos++;
		}
		if (score > 30) break;
		if (pos > 1e2) break;
		cout << score << " SCORE " << endl;
	}
}

signed main() {	
	helper.assign(1e6, 0);

	for (int i = 0; i < 1e6; ++i) {
		helper[i] = rand();
		helper[i] = helper[i] % 4;
		if (i < 20) cout << helper[i] << endl;
	}

	for (int i = 0; i < 10; ++i) {
		ll.addFront(helper[i]);
	}
	cout << ll;
	ll.addCurrent(1);
	cout << ll;
		playGame();
		//playGameBot(); // bot pryamo 100% rabotaet, zub dayu
}
