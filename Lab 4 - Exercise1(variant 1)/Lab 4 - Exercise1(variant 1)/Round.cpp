#include "Round.h"

CRound::CRound(double radius, double volume, double density) : CBody(volume, density),
	m_radius(radius)
{
}


CRound::~CRound()
{
}


// ���������� ������
double CRound::GetRadius() const
{
	return m_radius;
}
