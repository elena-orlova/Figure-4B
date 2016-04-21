#include "My2DPoint.h"


//описание класса CMy2DPoint для заданной фигуры

class CMy2DObject4B

{

private:

	double m_A, m_A1, m_A2, m_A3, m_Angle;

	CMy2DPoint m_center;

public:

	CMy2DObject4B(void);

	CMy2DObject4B(double, double, double, double, double, CMy2DPoint);

	~CMy2DObject4B();


	const double GetA();

	const double GetA1();

	const double GetA2();

	const double GetA3();

	const double GetAngle();

	const CMy2DPoint GetCenter();

	//проверка параметров, чтобы не было самопересечений

	void SetA(const double A);

	void SetA1(const double A1);

	void SetA2(const double A2);

	void SetA3(const double A3);

	void SetAngle(const double Angle);

	void SetCenter(const CMy2DPoint center);

	void SetCenter(const double x, const double y);

	void Move(double dX, double dY, double dAngle = 0);

	void Move(const CMy2DPoint &delta, double dAngle = 0);

	void Rotate(double dAngle);

	const bool IsInside(const CMy2DPoint &point);

	const bool IsInside(double x, double y);

};