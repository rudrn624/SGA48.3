#include "Matrix.h"

Matrix::Matrix()
{
	m[0] = m[3] = 1.f;
	m[1] = m[2] = 0.f;
}
Matrix::Matrix(const float& _0, const float& _1, const float& _2, const float& _3)
{
	m[0] = _0;
	m[1] = _1;
	m[2] = _2;
	m[3] = _3;
}
Matrix::~Matrix()
{
}

Matrix Matrix::operator + (const Matrix& o) const
{
	Matrix tmp(*this);

	for (int i = 0; i < 4; i++)
	{
		tmp.m[i] += o.m[i];
	}

	return tmp;
}
Matrix Matrix::operator - (const Matrix& o) const
{
	Matrix tmp(*this);

	for (int i = 0; i < 4; i++)
	{
		tmp.m[i] -= o.m[i];
	}

	return tmp;
}
Matrix& Matrix::operator = (const Matrix& o)
{
	for (int i = 0; i < 4; i++)
	{
		m[i] = o.m[i];
	}

	return *this;
}
Matrix& Matrix::operator = (const float& v)
{
	for (int i = 0; i < 4; i++)
	{
		m[i] = v;
	}

	return *this;
}
Matrix& Matrix::operator = (const int& v)
{
	for (int i = 0; i < 4; i++)
	{
		m[i] = float(v);
	}

	return *this;
}
Matrix& Matrix::operator ++ ()
{
	for (int i = 0; i < 4; i++)
	{
		m[i] += 1.f;
	}
	
	return *this;
}
Matrix Matrix::operator ++ (int)
{
	Matrix tmp(*this);

	++*this;

	return tmp;
}
Matrix Matrix::operator * (const Matrix& o) const
{
	Matrix tmp;

	tmp.m[0] = m[0]*o.m[0] + m[1]*o.m[2];
	tmp.m[1] = m[0]*o.m[1] + m[1]*o.m[3];
	tmp.m[2] = m[2]*o.m[0] + m[3]*o.m[2];
	tmp.m[3] = m[2]*o.m[1] + m[3]*o.m[3];

	return tmp;
}
float& Matrix::operator [] (const char* name)
{
	static float error = 0;

	if (strcmp(name, "one") == 0)
	{
		return m[0];
	}
	else if (strcmp(name, "two") == 0)
	{
		return m[1];
	}
	else if (strcmp(name, "three") == 0)
	{
		return m[2];
	}
	else if (strcmp(name, "four") == 0)
	{
		return m[3];
	}

	return error;
}


Matrix operator * (const Matrix& lhs, const float& rhs)
{
	Matrix tmp(lhs);

	for (int i = 0; i < 4; i++)
	{
		tmp.m[i] *= rhs;
	}

	return tmp;
}

Matrix operator * (const float& lhs, const Matrix& rhs)
{
	Matrix tmp(rhs);

	for (int i = 0; i < 4; i++)
	{
		tmp.m[i] *= lhs;
	}

	return tmp;
}

ostream& operator << (ostream& os, const Matrix& obj)
{
	os << obj.m[0] << ' ' << obj.m[1] << endl;
	os << obj.m[2] << ' ' << obj.m[3] << endl;

	return os;
}
