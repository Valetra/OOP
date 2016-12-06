#include "Car.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <boost\algorithm\string.hpp>

using namespace std;

//TODO: ������� ��� � git`e
//	1)������� ���, ����� ��������� �������� � ������������� ������!
void PrintInfo(const CCar &car)
{
	string engineState;
	engineState = (car.GetStateOfEngine() ? "�������" : "��������");

	string drivingDirection;

	switch (car.GetDirection())
	{
		case Direction::BACKWARD:
		{
			drivingDirection = "�����";
			break;
		}
		case Direction::FORWARD:
		{
			drivingDirection = "�����";
			break;
		}
		case Direction::NO_DIRECTION:
		{
			drivingDirection = "���";
			break;
		}
		default:
		break;
	}

	string gear;
	switch (car.GetGear())
	{
		case Gear::REVERSE:
		{
			gear = "������";
			break;
		}
		case Gear::NEUTRAL:
		{
			gear = "�����������";
			break;
		}
		case Gear::FIRST:
		{
			gear = "������";
			break;
		}
		case Gear::SECOND:
		{
			gear = "������";
			break;
		}
		case Gear::THIRD:
		{
			gear = "������";
			break;
		}
		case Gear::FOURTH:
		{
			gear = "��������";
			break;
		}
		case Gear::FIFTH:
		{
			gear = "�����";
			break;
		}
		default:
			break;
	}


	cout << "��������� ����������: " << engineState
		<< "\n����������� �������: " << drivingDirection
		<< "\n�������� ���������� �����: " << car.GetSpeed()
		<< "\n���������� " << gear << " ��������.\n";
}

bool EngineOn(CCar &car)
{
	return car.TurnOnEngine();
}

bool EngineOff(CCar &car)
{
	return car.TurnOffEngine();
}

bool SetGear(CCar &car, int gear)
{
	if (car.SetGear(gear))
	{
		return true;
	}
	else
	{
		cout << "�� ������� ����������� ��������, ��� ���\n";
		if (!car.GetStateOfEngine())
		{
			cout << "- ��������� ��������\n";
		}

		else if (car.IsSpeedInGearRange(car.GetSpeed(), static_cast<Gear>(gear)))
		{
			cout << "- �������� ���������� �� ������ � �������� ��������\n";
		}
		
		else
		{
			cout << "������� �������� �� �������� �� ������������� ������������ ����������\n";
		}
		return false;
	}
}

bool SetSpeed(CCar &car, size_t speed)
{
	if (speed >= 0 && speed <= 150)
	{
		return(car.SetSpeed(speed));
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	CCar car;

	string userRequest;
	while (userRequest != "exit")
	{
		getline(cin, userRequest);
		std::transform(userRequest.begin(), userRequest.end(), userRequest.begin(), ::tolower);

		vector<string> requestDiv;
		boost::split(requestDiv, userRequest, boost::is_any_of(" "));

		if (userRequest == "info")
		{
			PrintInfo(car);
		}

		else if (userRequest == "engineon")
		{
			if (EngineOn(car))
			{
				cout << "��������� �������\n";
			}
			else
			{
				cout << "��������� ��� ������� �����\n";
			}
		}

		else if (userRequest == "engineoff")
		{
			if (EngineOff(car))
			{
				cout << "��������� ��������\n";
			}
			else
			{
				cout << "��������� �� ����� ���� ��������, �������� ����� ����� ����:\n" 
					<< "1) ����������� ���������\n"
					<< "2) �� ����������� �� �������� ��������\n"
					<< "3) �������� ����������\n";
			}
		}

		
		if (requestDiv.size() == 2 && requestDiv.at(0) == "setgear" 
			&& requestDiv.at(1) != "" 
			&& isdigit(requestDiv.at(1).at(0)) &&
			stoi(requestDiv.at(1)) >= -1 && stoi(requestDiv.at(1)) <= 5)
		{
			if (SetGear(car, stoi(requestDiv.at(1))))
			{
				cout << "�������� �����������\n";
			}
		}
		
		if (requestDiv.size() == 2 && requestDiv.at(0) == "setspeed"
			&& requestDiv.at(1) != ""
			&& isdigit(requestDiv.at(1).at(0)) &&
			stoi(requestDiv.at(1)) >= 0 && stoi(requestDiv.at(1)) <= 150)
		{
			if (SetSpeed(car, stoi(requestDiv.at(1))))
			{
				cout << "�������� �����������\n";
			}
			else
			{
				cout << "���������� ���������� �������� ��� ������ ��������\n";
			}
		}
		

	}
	return EXIT_SUCCESS;
}