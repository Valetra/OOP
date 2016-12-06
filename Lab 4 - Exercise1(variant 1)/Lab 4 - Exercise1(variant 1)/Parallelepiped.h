#include "Height.h"

class CParallelepiped : public CHeight
{
public:
	CParallelepiped(double height, double width, double depth, double volume, double density);
	~CParallelepiped();
	// ���������� ������
	double GetWidth() const;
	// ���������� �������
	double GetDepth() const;

	std::string ToString() const;
private:
	// ������
	double m_width;
	// �������
	double m_depth;
};

