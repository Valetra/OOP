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

unsigned char ReverseBytes(unsigned char byte)
{
	byte = (byte & 0xF0) >> 4 | (byte & 0x0F) << 4;
	byte = (byte & 0xCC) >> 2 | (byte & 0x33) << 2;
	byte = (byte & 0xAA) >> 1 | (byte & 0x55) << 1;
	return byte;
}

bool CheckArguments(int countOfOptions, string firstOption)
{
	string digits = "0123456789";
	if (countOfOptions != 2)
	{
		cout << "Error!\nExpected Exercise2.exe <integer[0 - 255]>";
		return false;
	}

	for (unsigned int i = 0; i < firstOption.length(); ++i)
	{
		if (!isdigit(firstOption[i]))
		{
			cout << "Error!\nIt was not handed over to the digital option";
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!CheckArguments(argc, argv[1]))
	{
		return 1;
	}
	else
	{
		string firstOption = argv[1];
		int digit = atoi(firstOption.c_str());
		if (digit >= 0 && digit <= 255)
		{
			unsigned char byte = digit;
			cout << static_cast<int>(ReverseBytes(byte));
			return 0;
		}
		else
		{
			cout << "Error!\nInvalid sourse number. Expected number from 0 to 255";
			return 1;
		}
	}
}