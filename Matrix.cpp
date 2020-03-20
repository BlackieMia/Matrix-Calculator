#include "Matrix.h"
#include <iostream>
using namespace std;

//无参构造函数
Matrix::Matrix():elements(0),row(0),col(0){}

//有参构造函数,参数为对象的行数和列数
Matrix::Matrix(int row, int col) :row(row), col(col) {
	this->elements = new double*[row];
	for (int i = 0;i < row;i++) {
		this->elements[i] = new double[col];
	}
}

//拷贝构造函数
Matrix::Matrix(const Matrix& srcMatrix) :row(srcMatrix.row), col(srcMatrix.col) {
	this->elements = new double* [row];
	for (int i = 0;i < row;i++) {
		this->elements[i] = new double[col];
	}
	for (int i = 0;i < row;i++) {
		for(int j = 0;j < col;j++) {
			this->elements[i][j] = srcMatrix.elements[i][j];
		}
	}
}

//重载等号
Matrix& Matrix::operator=(const Matrix& srcMatrix) {
	if (this != &srcMatrix) {
		this->row = srcMatrix.row;
		this->col = srcMatrix.col;
		delete[] this->elements;
		this->elements = new double* [row];
		for (int i = 0;i < row;i++) {
			this->elements[i] = new double[col];
		}
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++) {
				this->elements[i][j] = srcMatrix.elements[i][j];
			}
		}
	}
	return *this;
}

//对矩阵中某行某列的元素进行赋值
void Matrix::setNum(double Num, int row, int col) {
	this->elements[row][col] = Num;
}

//对当前对象求转置并返回一个新矩阵
Matrix Matrix::transpose() {
	Matrix temp(col,row);
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			temp.elements[j][i] = this->elements[i][j];
		}
	}
	return temp;
}

//遍历矩阵
void Matrix::display() {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			cout << this->elements[i][j] << " ";
			if (j == col - 1) {
				cout << endl;
			}
		}
	}
}