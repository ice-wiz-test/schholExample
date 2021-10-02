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
#include "helper.h"
#define int long long
using namespace std;
const int INF = 1e13 + 8;
const int mod = 998244353;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<vector<int>> example(5, vector<int> (5, 0));
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			example[i][j] = i * 5 + j;
		}
	}
	Matrix<int> m(example);

	cout << m[0][0] << endl;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}

	Matrix<int> Multi = m * m;

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << Multi[i][j] << " ";
		}

		cout << endl;
	}
	

	Multi = m + m;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << Multi[i][j] << " ";
		}
		cout << endl;
	}
	Multi = m.transpose();
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << Multi[i][j] << " ";
		}
		cout << endl;
	}

	Multi = m.raiseToPower(4);

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << Multi[i][j] << " ";
		}
		cout << endl;
	}

	Multi = m * 5;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << Multi[i][j] << " ";
		}
		cout << endl;
	}
	vector<vector<int>> toUse(3, vector<int>(3, 0));
	toUse[0][0] = 1;
	toUse[0][1] = 2;
	toUse[1][0] = 3;
	toUse[1][1] = 4;
	toUse[2][0] = 5;
	toUse[1][2] = 17;
	toUse[0][2] = 19;
	toUse[2][2] = 213;
	toUse[2][1] = 4;

	Multi = Matrix<int>(toUse);

	cout << Multi.getDeterminant() << endl;
}