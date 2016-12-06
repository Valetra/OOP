#include "stdafx.h"
#include"../Lab 3 - Exercise1(variant 2)/Car.h"

BOOST_AUTO_TEST_SUITE(Test_the_correct_operation_of_the_machine)

	//�������� ������ TurnOnEngine, ��� ���������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_TurnOnEngine_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
	}

	//�������� ������ TurnOnEngine, ��� ��������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_TurnOnEngine_for_turn_on_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.TurnOnEngine() == false);
	}
	
	//�������� ������ TurnOffEngine, ��� ��������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_TurnOffEngine_for_turn_on_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.TurnOffEngine() == true);
	}

	//�������� ������ TurnOffEngine, ��� ���������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_TurnOffEngine_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.TurnOffEngine() == false);
	}

	//�������� ������ SetGear ��� ����������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_SetGear_for_turn_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(-1) == false);
		BOOST_CHECK(car.SetGear(1) == false);
		BOOST_CHECK(car.SetGear(3) == false);
		BOOST_CHECK(car.SetGear(5) == false);
	}

	//�������� ������ SetGear ��� ���������� ��������� �� ��������� ����
	BOOST_AUTO_TEST_CASE(Check_method_SetGear_for_turn_on_engine_with_zero_speed)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(-2) == false);
		BOOST_CHECK(car.SetGear(2) == false);
	}

	//�������� ������ SetSpeed ��� ����������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_for_off_engine)
	{
		CCar car;
		BOOST_CHECK(car.SetSpeed(5) == false);
		BOOST_CHECK(car.SetSpeed(20000) == false);
		BOOST_CHECK(car.SetSpeed(-5) == false);
		BOOST_CHECK(car.SetSpeed(-5000) == false);
	}

	//�������� ������ SetSpeed ��� ���������� ��������� �� ����������� ��������
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_for_on_engine_and_on_neutral_gear)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetSpeed(5) == false);
		BOOST_CHECK(car.SetSpeed(100) == false);
	}

	//�������� ������ SetSpeed � SetGear ��� ���������� ��������� �� ��������� ���������
	BOOST_AUTO_TEST_CASE(Check_method_SetSpeed_and_SetGear_for_on_engine_and_on_variable_gears)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(-1));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(21) == false);


		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(1));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(30) == true);
		BOOST_CHECK(car.SetSpeed(31) == false);
		
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(2));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(19) == false);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(51) == false);

		BOOST_CHECK(car.SetGear(3) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(3));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(29) == false);
		BOOST_CHECK(car.SetSpeed(30) == true);
		BOOST_CHECK(car.SetSpeed(60) == true);
		BOOST_CHECK(car.SetSpeed(61) == false);

		BOOST_CHECK(car.SetGear(4) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(4));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(39) == false);
		BOOST_CHECK(car.SetSpeed(40) == true);
		BOOST_CHECK(car.SetSpeed(90) == true);
		BOOST_CHECK(car.SetSpeed(91) == false);

		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(5));
		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(49) == false);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(150) == true);
		BOOST_CHECK(car.SetSpeed(151) == false);

		//������� ���������� �������� �� ������������ ��������
		BOOST_CHECK(car.SetGear(0) == true);

		BOOST_CHECK(car.SetSpeed(-1) == false);
		BOOST_CHECK(car.SetSpeed(150) == false);
		BOOST_CHECK(car.SetSpeed(100) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetSpeed(10) == false);
		
		
		
		
	}

	//�������� ������ SetDirection � ������� ����� ���������� ������
	BOOST_AUTO_TEST_CASE(Check_methods_SetDirection_and_main_fuctions_of_car)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetSpeed(10) == true);
		BOOST_CHECK(car.GetDirection() == Direction::BACKWARD);
		BOOST_CHECK(car.GetSpeed() == 10);

		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetSpeed() == 0);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(2) == false);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(31) == false);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(2));

		BOOST_CHECK(car.SetSpeed(45) == true);
		BOOST_CHECK(car.GetSpeed() == 45);
		BOOST_CHECK(car.SetSpeed(55) == false);
		BOOST_CHECK(car.SetGear(3) == true);
		BOOST_CHECK(car.GetGear() == static_cast<Gear>(3));

		BOOST_CHECK(car.SetGear(1) == false);
		BOOST_CHECK(car.SetGear(5) == false);
		BOOST_CHECK(car.SetGear(6) == false);
		BOOST_CHECK(car.SetGear(4) == true);

		BOOST_CHECK(car.SetSpeed(85) == true);
		BOOST_CHECK(car.SetGear(0) == true);

		BOOST_CHECK(car.SetSpeed(90) == false);
		BOOST_CHECK(car.SetSpeed(80) == true);
		BOOST_CHECK(car.GetSpeed() == 80);

		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.GetSpeed() == 50);
		BOOST_CHECK(car.SetSpeed(49) == false);
		BOOST_CHECK(car.SetSpeed(150) == true);
		BOOST_CHECK(car.GetSpeed() == 150);
		BOOST_CHECK(car.SetSpeed(151) == false);
		BOOST_CHECK(car.GetSpeed() == 150);
		BOOST_CHECK(car.SetSpeed(-50) == false);
		BOOST_CHECK(car.SetSpeed(0) == false);

		BOOST_CHECK(car.TurnOffEngine() == false);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetGear(5) == true);
		BOOST_CHECK(car.GetDirection() == Direction::FORWARD);
		BOOST_CHECK(car.TurnOffEngine() == false);
		BOOST_CHECK(car.SetSpeed(50) == true);
		BOOST_CHECK(car.SetGear(2) == true);
		BOOST_CHECK(car.SetSpeed(20) == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.TurnOffEngine() == true);

	}

	//�������� ����������� �������� �������� �� ����������� ��������
	BOOST_AUTO_TEST_CASE(Check_possibility_of_reducing_speed_at_neutral_gear)
	{
		CCar car;
		BOOST_CHECK(car.TurnOnEngine() == true);
		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);

		BOOST_CHECK(car.GetGear() == static_cast<Gear>(0));
		BOOST_CHECK(car.GetSpeed() == 0);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(-1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.GetDirection() == Direction::BACKWARD);
		BOOST_CHECK(car.SetGear(0) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.GetDirection() == Direction::NO_DIRECTION);

		BOOST_CHECK(car.SetGear(1) == true);
		BOOST_CHECK(car.SetSpeed(15) == true);
		BOOST_CHECK(car.SetSpeed(0) == true);
		BOOST_CHECK(car.SetGear(-1) == true);

		BOOST_CHECK(car.SetSpeed(5) == true);
		BOOST_CHECK(car.SetGear(1) == false);
	}

BOOST_AUTO_TEST_SUITE_END()