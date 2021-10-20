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

	ll.addFront(3);
	ll.addBack(4);

	ll.debugPutOut();
	ll.deleteFront();
	ll.deleteFront();

	ll.debugPutOut();

	ll.addBack(9);
	ll.debugPutOut();
	ll.addFront(3);
	ll.debugPutOut();
	ll.addIndex(1, 2);
	ll.debugPutOut();

	ll.deleteIndex(1);
	ll.debugPutOut();
	ll.addBack(16);
	ll.deleteVal(16);
	ll.debugPutOut();
	cout << ll.findVal(9) << endl;
}
