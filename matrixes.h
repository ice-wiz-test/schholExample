#ifndef  MATRIXES
#define MATRIXES

#include <iostream>
#include <vector>

using namespace std;

template<typename T>

class Matrix {
	vector<vector<T>> matrix;
public:
	int X, Y;
	Matrix(vector<vector<T>>);
	Matrix(int XX, int YY);

	int size() const { return X * Y; };

	const Matrix operator+(const Matrix&) const;

	const Matrix operator*(T) const;

	const vector<T>& operator[](int i) { return matrix[i]; }

	const Matrix operator*(const Matrix&) const;

	const Matrix transpose();

	const Matrix raiseToPower(int n);

	template <typename Type> friend istream& operator >>(istream&, Matrix<Type>&);
	template <typename Type> friend ostream& operator <<(ostream&, Matrix<Type>&);
};

template<typename T>
Matrix<T>::Matrix(vector<vector<T>> vect) {
	matrix = vect;
	X = vect.size();
	Y = vect[0].size();
}

template<typename T>
Matrix<T>::Matrix(int XX, int YY) {
	X = XX;
	Y + YY;
	matrix.assign(XX, vector<T>(YY, 0));
}

template<typename T>

const Matrix<T> Matrix<T>::operator+(const Matrix& a) const {
	if (X != a.X || Y != a.Y) throw std::string("Sizes are not equal, try again.");
	vector<vector<T>> res;
	res.assign(X, vector<T>(Y, 0));

	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			res[i][j] = a.matrix[i][j] + matrix[i][j];
		}
	}
	return res;
}

template<typename T>


const Matrix<T> Matrix<T>::raiseToPower(int n) {
	Matrix<T> res = Matrix(matrix);
	return binPower(n, res);
}


template<typename T>

Matrix<T> binPower(int n, Matrix<T>& a ) {
	if (n == 1) return a;
	if (n == 2) return a * a;

	if (n % 2 == 0) {
		Matrix<T> fir = binPower(n / 2, a);
		return fir * fir;
	}

	if (n % 2 == 0) {
		Matrix<T> fir = binPower(n / 2, a);
		Matrix<T> sec = binPower(n / 2, a);
		sec = sec * a;
		return fir * sec;
	}
}
template<typename T>



const Matrix<T> Matrix<T>::transpose() {
	vector<vector<T>> res;
	res.assign(Y, vector<T>(X, 0));

	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			res[i][j] = matrix[j][i];
		}
	}

	return Matrix(res);
}

template<typename T>


const Matrix<T> Matrix<T>::operator*(const Matrix& a) const {
	if (Y != a.Y) throw std::string("When multiplying matrixes A and B, Aj should be equal to Bi");
	vector<vector<T>> res;
	res.assign(X, vector<T>(a.Y, 0));
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < a.Y; ++j) {
			for (int k = 0; k < Y; ++k) {
				res[i][j] = res[i][j] + matrix[i][k] * a.matrix[k][j];
			}
		}
	}

	return Matrix(res);
}


template<typename T>

const Matrix<T> Matrix<T>::operator*(T k) const {
	vector<vector<T>> res;
	res.assign(X, vector<T>(Y, 0));
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			res[i][j] = matrix[i][j] * k;
		}
	}
	return Matrix(res);
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& a) {
	for (int i = 0; i < a.X; ++i) {
		for (int j = 0; j < a.Y; ++j) {
			in >> a.matrix[i][j];
		}
	}
	return in;
}
template <typename T>
ostream& operator>>(ostream& out, Matrix<T>& a) {
	for (int i = 0; i < a.X; ++i) {
		for (int j = 0; j < a.Y; ++j) {
			out >> a.matrix[i][j];
		}
	}
	return out;
}




#endif // ! MATRIXES#pragma once
