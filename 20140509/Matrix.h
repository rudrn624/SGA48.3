#pragma once

#include <iostream>
using namespace std;

class Matrix
{
public :
	Matrix();
	Matrix(const float& _0, const float& _1, const float& _2, const float& _3);
	virtual ~Matrix();

public :
	Matrix operator + (const Matrix& o) const;
	Matrix operator - (const Matrix& o) const;
	Matrix& operator = (const Matrix& o);
	Matrix& operator = (const float& v);
	Matrix& operator = (const int& v);
	Matrix operator * (const Matrix& o) const;
	float& operator [] (const char* name);

	// 전위 증가 연산자
	Matrix& operator ++ ();
	// 후위 증가 연산자.
	Matrix operator ++ (int);

	friend Matrix operator * (const Matrix& lhs, const float& rhs);
	friend Matrix operator * (const float& lhs, const Matrix& rhs);

	friend ostream& operator << (ostream& os, const Matrix& obj);

private :
	float m[4];
};

