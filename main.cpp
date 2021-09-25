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
using namespace std;
const int INF = 1e9 + 7;
#define int long long
vector<int> massiv;
vector<int> leftToRight;
vector<int> rightToLeft;
vector<int> height;
class Point
{
private:
    double x;
    double y;

    Point(double X, double Y) {
        x = X;
        y = Y;
    }

    Point():Point(0, 0) {

    }

    Point operator+(Point);
    Point operator-(Point);
    Point operator*(int);
    int operator*(Point);
    int operator^(Point);
    int lengthSquared() {
        return x * x + y * y;
    }


};


Point Point::operator+(Point second) {
    return Point(x + second.x, y + second.y);
}

Point Point::operator-(Point second) {
    return Point(x - second.x, y - second.y);
}

Point Point::operator*(int val) {
    return Point(x * val, y * val);
}

int Point::operator*(Point second) {
    return x * second.x + y * second.y;
}


int Point::operator^(Point second) {
    return x * second.y - y * second.x;
}




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);
}