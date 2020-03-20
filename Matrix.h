#pragma once

class Matrix
{
	int row;
	int col;
	double **elements;
public:
	Matrix();
	Matrix(int row, int col);
	Matrix(const Matrix& srcMatrix);
	Matrix& operator=(const Matrix& srcMatrix);
	void setNum(double Num, int row,int col);
	Matrix transpose();
	void display();
};



