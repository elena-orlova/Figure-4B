#include "My2DPoint.h"


CMy2DPoint::CMy2DPoint(void) : m_x(0), m_y(0) { std::cout << "Point was created!" << std::endl; }


CMy2DPoint::CMy2DPoint(double x, double y) : m_x(x), m_y(y) {}


CMy2DPoint::CMy2DPoint(const CMy2DPoint &p) : m_x(p.m_x), m_y(p.m_y) {}



CMy2DPoint::~CMy2DPoint(void)

{

	std::cout << "Point was destructed!" << std::endl;

}


CMy2DPoint& CMy2DPoint::operator=(const CMy2DPoint& a) {

	m_x = a.m_x;

	m_y = a.m_y;

	return *this;

}

const CMy2DPoint CMy2DPoint::operator+(const CMy2DPoint & b) {

	return CMy2DPoint((*this).m_x + b.m_x, (*this).m_y + b.m_y);

}

CMy2DPoint& CMy2DPoint::operator+=(const CMy2DPoint & b) {

	m_x = m_x + b.m_x;

	m_y = m_y + b.m_y;

	return *this;

}

const CMy2DPoint CMy2DPoint::operator-(const CMy2DPoint & b) {


	return CMy2DPoint((*this).m_x - b.m_x, (*this).m_y - b.m_y);

}

const CMy2DPoint operator*(const CMy2DPoint & a, const CMy2DPoint & b) {

	return CMy2DPoint(a.m_x * b.m_x, a.m_y * b.m_y);

}

const CMy2DPoint operator*(const double & a, const CMy2DPoint & b) {

	return CMy2DPoint(a * b.m_x, a * b.m_y);

}

const CMy2DPoint operator*(const CMy2DPoint & a, const double & b) {

	return CMy2DPoint(a.m_x * b, a.m_y * b);

}

const CMy2DPoint operator/(const CMy2DPoint & a, const double & b) {

	return CMy2DPoint(a.m_x / b, a.m_y / b);

}

const CMy2DPoint operator/(const CMy2DPoint & a, const CMy2DPoint & b) {

	return CMy2DPoint(a.m_x / b.m_x, a.m_y / b.m_y);

}

const bool operator==(const CMy2DPoint & a, const CMy2DPoint & b) {

	return (a.m_x == b.m_x && a.m_y == b.m_y);

}

const bool operator!=(const CMy2DPoint & a, const CMy2DPoint & b) {

	return !operator==(a, b);

}

ostream &operator<<(ostream &output, const CMy2DPoint& a) {

	output << "(" << a.m_x << "; " << a.m_y << ")";

	return output;

}


istream &operator >> (istream &input, CMy2DPoint& D) {

	input >> D.m_x >> D.m_y;

	return input;

}