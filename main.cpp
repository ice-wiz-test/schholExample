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
	LinkedList<int> lll;

	lll.addFront(3);
	lll.addBack(4);

	lll.debugPutOut();
	lll.deleteFront();
	lll.deleteFront();

	lll.debugPutOut();

	lll.addBack(9);
	lll.debugPutOut();
	lll.addFront(3);
	lll.debugPutOut();
	lll.addIndex(1, 2);
	lll.debugPutOut();

	lll.deleteIndex(1);
	lll.debugPutOut();
	lll.addBack(16);
	lll.deleteVal(16);
	lll.debugPutOut();
	cout << lll.findVal(9) << endl;

	cout << lll << endl;

	lll.addFront(99);

	LinkedList<int>* hh;
	LinkedList<int>* temp;
	temp = &lll;
	cout << (*temp) << endl;

	temp = mergeSortNew<int>(temp);
	cout << (*temp) << endl;
}
