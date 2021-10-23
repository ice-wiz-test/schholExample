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

signed main() {	
	LinkedList<int> ll;
	cout << "Welcome to the program. At the moment, you have an empty linked list. We support the following commands:" << endl;
	cout << "push_front x -  we will make x the front element" << endl;
	cout << "push_back x -  we will make x the last element" << endl;
	cout << "pop_front -  we will delete the front element" << endl;
	cout << "pop_back -  we will delete the last element" << endl;

	cout << "find_val x -  we will find the index of value x, or return -1, if it does not exist" << endl;
	cout << "add_index x y - we will either say to you that you are out of bounds, or insert y to the xth INDEX (numerated from 0)" << endl;
	cout << "delete_val x -  we will delete the first instance of vaue appearing" << endl;
	cout << "delete_index x -  we will delete the value by index" << endl;
	cout << "At the moment, this works only with ints" << endl;
	cout << "type EXIT if you want to exit the program" << endl;
	while (true) {
		string s;
		cin >> s;
		if (s == "pop_front") {
			ll.deleteFront();
			cout << ll << endl;
		}
		if (s == "pop_back") {
			ll.deleteBack();
			cout << ll << endl;
		}
		if (s == "push_front") {
			int temp = 0;
			cin >> temp;
			ll.addFront(temp);
			cout << ll << endl;
		}
		if (s == "push_back") {
			int temp = 0;
			cin >> temp;
			ll.addBack(temp);
			cout << ll << endl;
		}

		if (s == "find_val") {
			int temp = 0;
			cin >> temp;
			cout << ll.findVal(temp) << endl;
		}

		if (s == "delete_val") {
			int temp = 0;
			cin >> temp;
			ll.deleteVal(temp);
			cout << ll << endl;
		}

		if (s == "add_index") {
			int fir = 0,
				sec = 0;
			cin >> fir >> sec;
			ll.addIndex(fir, sec);
			cout << ll << endl;
		}
		if (s == "add_index") {
			int fir = 0;
			cin >> fir;
			ll.deleteIndex(fir);
			cout << ll << endl;
		}
		if (s == "EXIT") break;



	}

}
