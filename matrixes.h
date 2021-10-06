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

	const int getDeterminant();

	const int getDeterminantGauss();

	template <typename Type> friend istream& operator >>(istream&, Matrix<Type>&);
	template <typename Type> friend ostream& operator <<(ostream&, Matrix<Type>&);
};

template<typename T> 

vector<T> getAnswersTo(vector<vector<T>>& matr, int size) {
	cout << size << " SOZE " << endl;
	double coeff;
	for (int k = 0; k < size; ++k) {
		for (int j = k + 1; j < size; ++j) {
			if (matr[k][k] == 0) {
				bool b = false;
				for (int i = k + 1; i < size; ++i) {
					if (matr[i][k] != 0) {
						b = true;
						for (int m = k; m < size + 1;  ++m) {
							swap(matr[k][m], matr[i][m]);
						}
					}
				}

				if (!b) {
					throw std::string("This system does not have a solution");
				}
			}
			coeff = matr[j][k] / matr[k][k];

			for (int i = k; i < size + 1; ++i) {
				matr[j][i] = matr[j][i] - matr[k][i] * coeff;
			}

		}
	}

	double res = 1;

	for (int k = 0; k < size; ++k) {
		res = res * matr[k][k];
	}

	for (auto x : matr) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	vector<T> answers;
	for (int k = size - 1; k >= 0; --k) {
		if (answers.size() == 0) {
			answers.push_back(matr[k][k + 1] / matr[k][k]);
		}
		else {
			for (int j = size - 1; j > k; j--) {
				matr[k][size] -= matr[k][j] * answers[size - j - 1];
			}
			answers.push_back(matr[k][size] / matr[k][k]);
		}
	}
	return answers;
}


template<typename T>

T getDetGauss(vector<vector<T>>& matr, int size) {
	double coeff;
	for (int k = 0; k < size; ++k) {
		for (int j = k + 1; j < size; ++j) {
			if (matr[k][k] == 0) {
				bool b = false;
				for (int i = k + 1; i < size; ++i) {
					if (matr[i][k] != 0) {
						b = true;
						for (int m = k; m < size; ++m) {
							swap(matr[k][m], matr[i][m]);
						}
					}
				}

				if (!b) {
					throw std::string("This system does not have a solution");
					return 0;
				}
			}
			coeff = matr[j][k] / matr[k][k];

			for (int i = k; i < size; ++i) {
				matr[j][i] = matr[j][i] - matr[k][i] * coeff;
			}

		}
	}

	double res = 1;

	for (int k = 0; k < size; ++k) {
		res = res * matr[k][k];
	}
	return res;
}
template<typename T> 

vector<T> solveSystem() {
	vector<vector<T>> helpMe;
	int counter = 0;
	cout << "Please output the amount of equations you wish to input" << endl;
	cin >> counter;

	helpMe.resize(counter);

	for (int i = 0; i < counter; ++i) {
		cout << "Please enter the amount of letters you wish to solve for" << endl;
		int temp = 0;
		cin >> temp;
		T coeff;
		for (int k = 0; k < temp; ++k) {
			cin >> coeff;
			helpMe[i].push_back(coeff);
		}
		cout << "Please enter the result" << endl;
		T result;
		cin >> result;
		helpMe[i].push_back(result);
	}
	for (auto x : helpMe) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	try {
		return getAnswersTo(helpMe, helpMe.size());
	}
	catch (string s) {
		cout << s << endl;
	}
}

template<typename T>

vector<T> solveSystemProm() {
	try {
		vector<T> answers = solveSystem<T>();
		return answers;
	}
	catch (string s) {
		cout << s << endl;
	}
}
template<typename T>

int getDet(vector<vector<T>>& matrix, int size) {
	int deter = 0;
	vector<vector<T>> submatrix;
	submatrix.assign(size - 1, vector<T>(size - 1, 0));

	if (size == 2) {
		return matrix[1][1] * matrix[0][0] - matrix[1][0] * matrix[0][1];
	}
	else {
		for (int x = 0; x < size; ++x) {
			int subI = 0;
			for (int i = 1; i < size; ++i) {
				int subJ = 0;
				for (int j = 0; j < size; ++j) {
					if (j == x) continue;
					submatrix[subI][subJ] = matrix[i][j];
					subJ++;
				}
				subI++;
			}
			deter = deter + (pow(-1, x) * matrix[0][x] * getDet(submatrix, size - 1));
		}
	}
	return deter;
}

template<typename T>

const int Matrix<T>::getDeterminant() {
	vector<vector<T>> vect = matrix;
	return getDet(vect, X);
}

template<typename T> 

const int Matrix<T>::getDeterminantGauss() {
	vector<vector<T>> vect = matrix;
	try {
		return getDetGauss(vect, X);
	}
	catch (string s) {
		cout << s << endl;
	}
}

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

Matrix<T> binPower(int n, Matrix<T>& a) {
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