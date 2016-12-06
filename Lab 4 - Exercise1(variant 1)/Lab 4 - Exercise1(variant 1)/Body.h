#pragma once
#include <string>
class CBody
{
public:
	CBody(double volume, double density);
	~CBody() = default;

	// ���������
	double GetDensity() const;

	// �����
	double GetVolume() const;

	// �����
	double GetMass() const;

	// ����� ���������� � ����
	virtual std::string ToString() const = 0;

private:
	// ���������
	double m_density;
	double m_volume;
};

