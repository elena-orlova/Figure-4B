#pragma once

#include <iostream>

#include <math.h>

#include <assert.h>

#include <cstdlib>

#include <cmath>

#define eps 10e-4


using namespace std;


//описание класса CMy2DPoint для точки

class CMy2DPoint

{

public:

	CMy2DPoint(void);

	CMy2DPoint(double x, double y);

	CMy2DPoint(const CMy2DPoint &p);

	~CMy2DPoint(void);


	double m_x;

	double m_y;


	//перегрузка операторов

	CMy2DPoint& operator=(const CMy2DPoint& a);

	const CMy2DPoint operator+(const CMy2DPoint & b);

	CMy2DPoint& operator+=(const CMy2DPoint & b);

	const CMy2DPoint operator-(const CMy2DPoint & b);

	friend const CMy2DPoint operator*(const CMy2DPoint & a, const CMy2DPoint & b);

	friend const CMy2DPoint operator*(const double & a, const CMy2DPoint & b);

	friend const CMy2DPoint operator*(const CMy2DPoint & a, const double & b);

	friend const CMy2DPoint operator/(const CMy2DPoint & a, const double & b);

	friend const CMy2DPoint operator/(const CMy2DPoint & a, const CMy2DPoint & b);

	friend const bool operator==(const CMy2DPoint & a, const CMy2DPoint & b);

	friend const bool operator!=(const CMy2DPoint & a, const CMy2DPoint & b);

	friend ostream& operator<<(ostream &output, const CMy2DPoint& D);

	friend istream& operator >> (istream &input, CMy2DPoint& D);



};


CMy2DPoint operator*(double k, const CMy2DPoint& rp);