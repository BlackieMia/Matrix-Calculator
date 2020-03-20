#include "Matrix.h"
#include <iostream>
using namespace std;

//�޲ι��캯��
Matrix::Matrix():elements(0),row(0),col(0){}

//�вι��캯��,����Ϊ���������������
Matrix::Matrix(int row, int col) :row(row), col(col) {
	this->elements = new double*[row];
	for (int i = 0;i < row;i++) {
		this->elements[i] = new double[col];
	}
}

//�������캯��
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

//���صȺ�
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

//�Ծ�����ĳ��ĳ�е�Ԫ�ؽ��и�ֵ
void Matrix::setNum(double Num, int row, int col) {
	this->elements[row][col] = Num;
}

//�Ե�ǰ������ת�ò�����һ���¾���
Matrix Matrix::transpose() {
	Matrix temp(col,row);
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			temp.elements[j][i] = this->elements[i][j];
		}
	}
	return temp;
}

//��������
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