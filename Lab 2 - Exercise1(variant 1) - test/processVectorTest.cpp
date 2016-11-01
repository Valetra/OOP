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
	BOOST_CHECK(VectorsAreEqual(numbers, { (-1 + average), (1 + average), (2 + average), (3 + average) }));
}
BOOST_AUTO_TEST_SUITE_END()

// ��� ��������� ������ ������������� ����� ��� ������ �����
BOOST_AUTO_TEST_SUITE(when_passed_a_vector_consists_of_only_negative_numbers_or_zeros)

// ��� ��������� ������� ���������� ������ �� ������������� �����, ������ ������� ����� ��� ���������, � ��������������� �������
BOOST_AUTO_TEST_CASE(when_processing_a_vector_consisting_only_of_a_negative_number_should_return_numbers_without_changing_in_sorted_order)
{
	vector<double> numbers = { -1.00, -5.3435, -25.5689, -3 };
	ProcessVector(numbers);

	BOOST_CHECK(VectorsAreEqual(numbers, { -25.5689, -5.3435, -3, -1.00 }));
}

// ��� ��������� ������� ���������� ������ �����, ������ ������� ����
BOOST_AUTO_TEST_CASE(when_processing_a_vector_consisting_only_of_zeros_must_return_zeros)
{
	vector<double> numbers = { 0, 0, 0, 0 };
	ProcessVector(numbers);

	BOOST_CHECK(VectorsAreEqual(numbers, { 0, 0, 0, 0 }));
}

BOOST_AUTO_TEST_SUITE_END()