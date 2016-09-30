/*������������ ���������� flipbyte.exe, ����������� ��������� �������
���������� �������� ����� � 8-������� ����� ����� (�����), �������� �
���������� �������������, �� ���������������. ��� ����� �����������
��������� ��� ������ � ������. ������������� ���� ��������� � output
����� � ���������� ������������� � ����������� �������� �������� ������ \n.
������ ��������� ������ ����������:

flipbyte.exe <������� ����>

��������, � ���������� ������
flipbyte.exe 6
� output ������ ���� �������� 96 (6(10) = 00000110(2), ����� ��������� ������� ����� ������ ����� ����������� � 01100000(2) = 9610)
������������ ������� ������ (��������, �������� ������, �� ���������� ���������� ������, ��� �����, ���������� �� ������� 0-255)
������ ���������� �������������� ��������� �� ������.

� ��������� � ���������� ������ ����������� ������������ �����, ����������� ��������� �� ������ � �������������� ������
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

unsigned char Reverse(unsigned char byte)
{
	byte = (byte & 0b11110000) >> 4 | (byte & 0b00001111) << 4;
	byte = (byte & 0b11001100) >> 2 | (byte & 0b00110011) << 2;
	byte = (byte & 0b10101010) >> 1 | (byte & 0b01010101) << 1;
	return byte;
}

bool IsError(int countOfOptions, string firstOption)
{
	string digits = "0123456789";
	if (countOfOptions < 2)
	{
		cout << "Error!\nExpected Exercise2.exe <integer[0 - 255]>";
		return true;
	}

	for (unsigned int i = 0; i < firstOption.length(); ++i)
	{
		bool found = false;
		for (unsigned int j = 0; j < digits.length(); ++j)
		{
			if (firstOption[i] == digits[j])
			{
				found = true;
			}
		}
		if (found == false)
		{
			cout << "Error!\nIt was not handed over to the digital option";
			return true;
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	if (!IsError(argc, argv[1]))
	{
		string firstOption = argv[1];
		int digit = atoi(firstOption.c_str());
		if (digit >= 0 && digit <= 255)
		{
			unsigned char byte = digit;
			cout << (int)Reverse(byte) << endl;
			return 0;
		}
		else
		{
			cout << "Error!\nInvalid sourse number. Expected number from 0 to 255";
			return 1;
		}
	}
	else
	{
		return 1;
	}
	return 0;
}