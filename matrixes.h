#ifndef  MATRIXES
#define MATRIXES

#include <iostream>
#include <vector>
 
using namespace std;

template<typename T>

class Matrix {
	int X, Y;
	vector<vector<T>> matrix;
public:
	Matrix(vector<vector<T>>);
	Matrix(int XX, int YY);

	int size() const { return X * Y; };

	const Matrix operator+(const Matrix&) const;

	const Matrix operator*(T) const;

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
	if(X != a.X || Y != a.Y) throw std::string "Sizes are not equal, try again".
	vector<vector<T>> res;
	res.assign(XX, vector<T>(YY, 0));

	for (int i = 0; i < XX; ++i) {
		for (int j = 0; j < YY; ++j) {
			res[i][j] = a.matrix[i][j] + matrix[i][j];
		}
	}
	return res;
}


const Matrix<T> Matrix<T>::operator*(T k) const {
	vector<vector<T>> res;
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			res[i][j] = matrix[i][j] * k;
		}
	}
	return Matrix(res);
}

template <typename T>
istream& operator>>(istream& in, Matrix<T>& a) {
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			in >> a.matrix[i][j];
		}
	}
	return in;
}
template <typename T>
ostream& operator>>(ostream& out, Matrix<T>& a) {
	for (int i = 0; i < X; ++i) {
		for (int j = 0; j < Y; ++j) {
			out >> a.matrix[i][j];
		}
	}
	return out;
}
#endif // ! MATRIXES

