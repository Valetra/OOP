#include "../Lab 2 - Exercise1(variant 1)/processVector.h"
#include "stdafx.h"

using namespace std;
// ������� ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// ������� ������ ������ �� ������� �������
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> numbers;
	ProcessVector(numbers);
	BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()

// ��� ��������� ������� � ����������� �������������� ����������
BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_several_positive_elements)
// ������ �������� �� ������� �������������� � ������� ��������
BOOST_AUTO_TEST_CASE(should_add_their_average_to_each_element)
{
	vector<double> numbers = { -1, 1, 2, 3 };
	ProcessVector(numbers);

	const double average = (1.0 + 2.0 + 3.0) / 3;
	BOOST_CHECK(VectorsAreEqual(numbers,
	{ (-1 + average), (1 + average), (2 + average), (3 + average) }
	));
}
BOOST_AUTO_TEST_SUITE_END()