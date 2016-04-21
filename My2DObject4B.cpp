#include "My2DObject4B.h"
using namespace std;


bool fl = true;


CMy2DObject4B::CMy2DObject4B()

{

	std::cout << "Figure was created" << std::endl;

}

//�������� ������� ������ CMy2DObject4B

CMy2DObject4B::CMy2DObject4B(double A, double A1, double A2, double A3, double Angle, CMy2DPoint centre) {

	CMy2DObject4B::m_A = A;

	CMy2DObject4B::m_A1 = A1;

	CMy2DObject4B::m_A2 = A2;

	CMy2DObject4B::m_A3 = A3;

	CMy2DObject4B::m_Angle = Angle;

	CMy2DObject4B::m_center = centre;

	std::cout << "Figure with parameters was created" << std::endl;

}


CMy2DObject4B::~CMy2DObject4B()

{

	std::cout << "Figure was destructed" << std::endl;

}

//���������� ���������� �, �1 � ��

const double CMy2DObject4B::GetA() {

	return m_A;

}


const double CMy2DObject4B::GetA1() {

	return m_A1;

}


const double CMy2DObject4B::GetA2() {

	return m_A2;

}


const double CMy2DObject4B::GetA3() {

	return m_A3;

}


const double CMy2DObject4B::GetAngle() {

	return m_Angle;

}


const CMy2DPoint CMy2DObject4B::GetCenter() {

	return CMy2DObject4B::m_center;

}

//�������� ��������� �

void CMy2DObject4B::SetA(const double A) {

	if ((A >= m_A1 + m_A2) && (A / 2 > m_A1) && (A > (m_A2 + m_A1 + m_A3)) && (A >= m_A3 + m_A1)) {

		m_A = A;

		cout << "New A = " << A << endl;

	}

	else {

		cout << "It's impossible to change variable A. Last A = " << m_A << endl;

	}

}

//�������� ��������� �1

void CMy2DObject4B::SetA1(const double A1) {

	if ((A1 < m_A) && (m_A > m_A1 + A1) && (m_A > A1 + m_A2 + m_A3) && (m_A > m_A3 + A1)) {

		m_A1 = A1;

		cout << "New A1 = " << A1 << endl;

	}

	else {

		cout << "It's impossible to change variable A1. Last A1 = " << m_A1 << endl;

	}

}

//�������� ��������� �2

void CMy2DObject4B::SetA2(const double A2) {

	//��������������� ����� - ���������� ����� ������� ������� �������� �� �������� �1

	double cx = m_center.m_x + (m_A / 2 - m_A1);

	double cy = m_center.m_y + (m_A / 2 - m_A1 / 2);

	//���������� ����� ���� ������� �������� �� �������� �, ��� �� - ����� ���������� ������� �2

	double v2x = m_center.m_x - m_A / 2;

	double v2y = m_center.m_y + m_A / 2;

	// �������� - �� �� �����, ����� ���������� ������� �2 "�������" �� ��������� �������

	if ((pow(v2x - cx, 2) + pow(v2y - cy, 2) > A2*A2) && (A2 + m_A3 < m_A)) {

		m_A2 = A2;

		cout << "New A2 = " << A2 << endl;

	}

	else {

		cout << "It's impossible to change variable A2. Last A2 = " << m_A2 << endl;

	}

}

//�������� ��������� �3

void CMy2DObject4B::SetA3(const double A3) {

	//��������������� ����� - ���������� ����� ������� ������� �������� �� �������� �1

	double cx = m_center.m_x + (m_A / 2 - m_A1);

	double cy = m_center.m_y - (m_A / 2 - m_A1 / 2);

	//���������� ����� ������ ������� �������� �� �������� �

	double v3x = m_center.m_x - m_A / 2;;

	double v3y = m_center.m_y - m_A / 2;

	//�������� - ������� �� �������� �3 �� ������ ������� �� ��������� �������

	if (((v3x + A3 < cx) && (v3y + A3 < cy)) && (A3 + m_A2 < m_A)) {

		m_A3 = A3;

		cout << "New A3 = " << A3 << endl;

	}

	else {

		cout << "It's impossible to change variable A3. Last A3 = " << m_A3 << endl;

	}

}


void CMy2DObject4B::SetAngle(const double Angle) {

	m_Angle = Angle;

	if (m_Angle > 360) {

		while (m_Angle > 360) {

			m_Angle -= 360;

		}

	}

	else if (m_Angle < 360) {

		while (m_Angle < 360) {

			m_Angle += 360;

		}

	}

	cout << "New Angle = " << m_Angle << endl;

}


void CMy2DObject4B::SetCenter(const CMy2DPoint center) {

	m_center = center;

	cout << "New Center = " << m_center << endl;

}


void CMy2DObject4B::SetCenter(const double x, const double y) {

	CMy2DPoint a(x, y);

	m_center = a;

	cout << "New Center = " << m_center << endl;

}

// c������� ������� �� ������ dX, dY � ������� �� dAngle

void CMy2DObject4B::Move(double m_x, double m_y, double dAngle) {

	CMy2DPoint a(m_x, m_y);

	m_center += a;

	m_Angle += dAngle;

	if (m_Angle > 360) {

		while (m_Angle > 360) {

			m_Angle -= 360;

		}

	}

	else if (m_Angle < 360) {

		while (m_Angle < 360) {

			m_Angle += 360;

		}

	}

	cout << "New Center = " << m_center << ", " << "New Angle = " << m_Angle << endl;

}

// c������� ������� �� ������ ������ � ������� �� dAngle

void CMy2DObject4B::Move(const CMy2DPoint &delta, double dAngle) {

	m_center += delta;

	m_Angle += dAngle;

	if (m_Angle > 360) {

		while (m_Angle > 360) {

			m_Angle -= 360;

		}

	}

	else if (m_Angle < 360) {

		while (m_Angle < 360) {

			m_Angle += 360;

		}

	}

	cout << "New Center = " << m_center << ", " << "New Angle = " << m_Angle << endl;

}

// ������� ������ �� ���� dAngle

void CMy2DObject4B::Rotate(double dAngle) {

	CMy2DObject4B::m_Angle += dAngle;

	while (CMy2DObject4B::m_Angle >= 360) {

		CMy2DObject4B::m_Angle -= 360;

	}


	while (CMy2DObject4B::m_Angle < 0) {

		CMy2DObject4B::m_Angle += 360;

	}

	std::cout << "Figure was rotated on: " << dAngle << ". New angle = " << CMy2DObject4B::m_Angle << std::endl;

}


//��������, ����� �� ����� ������ ����� ������

const bool CMy2DObject4B::IsInside(const CMy2DPoint &point) {

	//������� � ����� ������� ��������� (������� �� ����)

	CMy2DPoint newpoint(point.m_x*cos(-m_Angle) - point.m_y*sin(-m_Angle), -point.m_x*sin(-m_Angle) + point.m_y*cos(-m_Angle));

	//���������� ������ �������� � �������� �������, ����� ������ ������� �������

	double v1x = m_center.m_x + m_A / 2;

	double v1y = m_center.m_y + m_A / 2;

	double v2x = m_center.m_x - m_A / 2;

	double v2y = v1y;

	double v3x = v2x;

	double v3y = m_center.m_y - m_A / 2;

	double v4x = v1x;

	double v4y = v3y;

	//�������� ����� �� ����� ��� �������� �*� � �������� �������

	if ((newpoint.m_x > v1x) || (newpoint.m_x < v2x) ||

		(newpoint.m_y > v1y) || (newpoint.m_y < v4y)) {

		cout << "Your point " << point << " isn't inside!" << endl;

		fl = false;

	}

	else {

		//��������, ����� �� �������� ����� ������ ���-�� � ������ � ����� v2x, v2y

		//���� ���, �� ���� ������

		if (pow(v2x - newpoint.m_x, 2) + pow(v2y - newpoint.m_y, 2) < m_A2*m_A2) {

			cout << "Your point " << point << " isn't inside!" << endl;

			fl = false;

		}

		else {

			//�������� ����� �� ����� ������ ���������� � ������� v3x, v3y �� �������� �3

			if ((newpoint.m_x < (v3x + m_A3)) && (newpoint.m_y < (v2y + m_A3))) {

				cout << "Your point " << point << " isn't inside!" << endl;

				fl = false;

			}

			else {

				//�������� ����� �� ����� ������ �������� �� �������� A1

				if ((newpoint.m_x > m_center.m_x) && (newpoint.m_y < m_center.m_y + m_A1 / 2) && (newpoint.m_y > m_center.m_y - m_A1 / 2)) {

					cout << "Your point" << point << " isn't inside!" << endl;

					fl = false;

				}

			}

		}

		if (fl) {

			cout << "Your point " << point << " is inside!" << endl;

			return true;

		}

		else {

			return false;

		}

	}


}

// ���������� true ���� ����� � ������������ (x,y) ����� ������ ������ � false � ��������� ������

//������������ ����� CMy2DObject4B ��� const CMy2dPoint &point

const bool CMy2DObject4B::IsInside(double x, double y) {

	CMy2DPoint point(x, y);

	return IsInside(point);

}