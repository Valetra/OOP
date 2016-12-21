#pragma once

#include <iostream>

//�����, ������������ ������������ �����

class CRational final
{
public:
	CRational(int numerator = 0, int denominator = 1);

	// ���������� ���������
	int GetNumerator() const;

	// ���������� �����������
	int GetDenominator() const;

	// ������������� ����� �������� ���������
	void SetNumerator(int numerator);

	// ������������� ����� �������� �����������
	void SetDenominator(int denominator);

	// ���������� ��������� ��������� � ����������� � ���� ����� double
	double ToDouble() const;

	// ���������� ������������ �����, ������ ��������
	const CRational operator+() const;

	// ���������� ������������ ����� � �������� ������ ���������
	const CRational operator-() const;

	// ��������� ���������� ������������� ����� �� �������� ������� �������������,
	//	���� ������ �����:
	CRational & operator+=(CRational const& r);

	// ��������� ���������� ������������� ����� �� �������� ������� ������������� ���� ������ ����� :
	CRational & operator-=(CRational const& r);

	// �������� �������� ������� ������������� ����� �� ������ ������������, 
	//	���� �����:
	CRational & operator*=(CRational const& r);

	// ����� ������ ������������ ����� �� ������ ������������, 
	//	���� �����:
	CRational & operator/=(CRational const& r);

private:
	int m_numerator;
	int m_denominator;

	void Assign(int numerator, int denominator);
	// ����������� ������������ �����
	void Normalize();
};

// ��������� ���������� ����� �������� (greatest common denominator) ����� a � b
unsigned GCD(unsigned a, unsigned b);

// ��������� ���������� ����� ������� (least common multiple) ����� a � b
unsigned LCM(unsigned a, unsigned b);

// ���������� ��������� �������� ���� ������������ �����, 
//	������������� ����� � �����, ������ ����� � ������������.
const CRational operator+(CRational const& r1, CRational const& r2);

// ���������� �������� ���� ������������ �����, 
//	������������� ����� � ������, ���� ������ ����� � �������������:
const CRational operator-(CRational const& r1, CRational const& r2);

// ���������� ��������� ������������ ������������ �����, 
//	������������� � ������, ���� ������ � ������������� :
const CRational operator*(CRational const& r1, CRational const& r2);

// ���������� ������� ���� ������������ �����, 
//	������������� � ������, ������ � ������������� :
const CRational operator/(CRational const& r1, CRational const& r2);

// ���������� ��� ������������ �����, ������������ � �����, 
//	����� � ������������:
const bool operator<(CRational const& r1, CRational const& r2);
const bool operator>(CRational const& r1, CRational const& r2);
const bool operator<=(CRational const& r1, CRational const& r2);
const bool operator>=(CRational const& r1, CRational const& r2);

// ��������� ��������� (� �����������) ���� ������������ �����, 
//	������ � �������������, ������������� � ������:
const bool operator != (CRational const& r1, CRational const& r2);
const bool operator == (CRational const& r1, CRational const& r2);

// ����� ������������� ����� � �������� ����� 
//	std::ostream � ������� <���������>/<�����������>, 
std::ostream & operator<<(std::ostream & out, const CRational & r);

// ���� ������������� ����� �� �������� ������ 
bool operator >> (std::istream & in, CRational & r);