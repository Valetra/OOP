#ifndef HEIGHT_H
#define HEIGHT_H

#include "Body.h"

class CHeight : public CBody
{
public:
	CHeight(double height, double volume, double density);
	~CHeight();
	// ���������� ������
	double GetHight() const;

private:
	// ������
	double m_height;
};
#endif