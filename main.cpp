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
void BAD_gauss(vector<vector<double>>& mtr, vector<double>& consta) {
	int sz1 = mtr.size();
	int sz2 = mtr[0].size();
	double temp;

	for (int i = 0; i < sz1; ++i) {
		if (i >= sz2) break;
		for (int j = 0; j < sz1; ++j) {
			temp = mtr[j][i];

			for (int k = 0; k < sz2; ++k) {
				if (mtr[i][i] != 0 && j != i) {
					mtr[j][k] = mtr[j][k] - (mtr[j][i] / mtr[i][i]) * mtr[i][k];
				}
			}
			if (j - i != 0) {
				consta[j] = consta[j] - mtr[j][i] / mtr[i][i] * consta[i];
			}
		}
	}

	for (int i = 0; i < sz1; ++i) {
		for (int j = 0; j < sz2; ++j) {
			if (mtr[i][j] != 0) break;

			if (j == sz2 - 1 && mtr[i][j] == 0 && consta[i] != 0) {
				cout << "This system does not have solutions." << endl;
				return;
			}

		}
	}

	cout << "The list of free variables is as follows:" << endl;

	for (int it = sz1; it < sz2; ++it) {
		cout << "X" << it << endl;
	}

	// this is bad

	for (int iter = sz1 - 1; iter >= 0; iter--) {
		cout << "x" << iter + 1 << " ";
	}
	cout << endl;

	for (int i = sz1 - 1; i >= 0; --i) {
		cout << "x" << i + 1 << " = " << consta[i] / mtr[i][i] << " - ";
		for (int k = i + 1; k < sz2; ++k) {
			double x = mtr[i][k] / mtr[i][i];

			if (k + 1 != sz2) {
				if (x != 0 && x != 1) {
					cout << "x" << k + 1 << " - ";
				}
				if (x == 1) cout << "x" << k + 1 << " - ";
			}

			else {
				if (x != 0 && x != 1) cout << x << "x" << k + 1;
				if (x == 1) cout << "x" << k + 1;
			}
		}

	}

	cout << endl;
}
void solve() {
	int T = 0;
	cin >> T;
	while (T--) {
		int N = 0,
			M = 0;
		cin >> N >> M;
		vector<vector<double>> matr;
		vector<double> ans;
		ans.assign(N, 0);
		matr.assign(N, vector<double>(M , 0));
		if (N != M) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					cin >> matr[i][j];
				}
				cin >> ans[i];
			}

			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M - 1; ++j) {
					cout << matr[i][j] << " ";
				}
				cout << endl;
			}


			BAD_gauss(matr, ans);
		}

		else {
			cout << "Please refer to the square function inside of the Matrix function" << endl;
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}