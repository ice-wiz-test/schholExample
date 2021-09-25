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
class Point
{
private:
    int x;
    int y;
public:
    Point(int X, int Y) {
        x = X;
        y = Y;
    }

    Point():Point(0, 0) {

    }

    int get_X() { return x; }
    int get_Y() { return y; }

    Point operator+(Point);
    Point operator-(Point);
    Point operator*(int);
    int operator*(Point);
    int operator^(Point);
    int lengthSquared() {
        return x * x + y * y;
    }
    bool operator==(Point);
    bool operator!=(Point);

    double angle(Point);

    friend ostream& operator<<(ostream&, const Point&);
};


ostream& operator<<(ostream& out, const Point& a) {
    return out << a.x << " - X. " << a.y << " - Y.";
}

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

double Point::angle(Point second) {
    double len1 = 0,
            len2 = 0,
            Area = 0;
    Area = Point(x, y) ^ second;
    len1 = sqrt(lengthSquared());
    len2 = sqrt(second.lengthSquared());

    double sin;
    sin = Area / (len1 * len2);

    return asin(sin);
}


int Point::operator^(Point second) {
    return x * second.y - y * second.x;
}

bool Point::operator==(Point second) {
    if(second.x == x && second.y == y) {
        return true;
    }
    return false;
}

bool Point::operator!=(Point second) {
    if (second.x != x || second.y != y) {
        return true;
    }
    return false;
}

double angle(Point x, Point y) {
    double len1 = 0,
            len2 = 0,
            Area = 0;
    Area = x ^ y;
    len1 = sqrt(x.lengthSquared());
    len2 = sqrt(y.lengthSquared());

    double sin;
    sin = Area / (len1 * len2);

    return asin(sin);
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(12);

    Point a(2, 2);

    cout << a.get_X() << " - X, not in function." << a.get_Y() << " - Y, not in function." << endl;

    Point b(3, 3);

    Point C = a + b;
    cout << C << endl;

    Point D = a - b;
    cout << D << endl;
    int scalar = 0;
    cout << a * 10 << " Multiplication." << endl;

    cout << a * b << " - Scalar Multiplication" << endl;
    int temp = a ^ b;
    cout << temp << " - Non-scalar multiplication" << endl;

    cout << a.angle(b) << " - Angle between them " << endl;

    cout << sqrt(a.lengthSquared()) << " - Length, in double format" << endl;
}