#include <iostream>
#include <conio.h>

using namespace std;

void InputLine(char str[], const int n);
void FindNumber(char str[], int *numbers, const int n);
void FindChar(char str[], char *operation, const int n);
void IntMerge(int *numbers, const int n);
void Clear(int *numbers, int*clear, const int n);
double MainMath(int*clear, char*operations, const int n);

void main()
{
	const int n = 30;
	char str[n] = {};
	char operation[n] = {};
	int numbers[n] = {};
	int ClearNumbers[n] = {};
	InputLine(str, n);
	FindNumber(str, numbers, n);
	FindChar(str, operation, n);
	IntMerge(numbers, n);
	Clear(numbers, ClearNumbers, n);
	cout << "=" << MainMath(ClearNumbers, operation, n);
	cout << endl<<"All the integers from string are: ";
	for (int i = 0; i < n; i++)
	{
		if (ClearNumbers[i] != 0)
		{
			cout << ClearNumbers[i] << " ";
		}
	}
	cout << endl << "All the operations from string are: ";
	for (int i = 0; i < n; i++)
	{
		cout << operation[i] << " ";
	}
	cout << endl;
}

void InputLine(char str[], const int n)
{
	cin.getline(str, n);
}
void FindNumber(char str[], int *numbers, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= '0'&&str[i] <= '9')
		{
			switch (int(str[i]))
			{
			case 48:numbers[i] = 0; break;
			case 49:numbers[i] = 1; break;
			case 50:numbers[i] = 2; break;
			case 51:numbers[i] = 3; break;
			case 52:numbers[i] = 4; break;
			case 53:numbers[i] = 5; break;
			case 54:numbers[i] = 6; break;
			case 55:numbers[i] = 7; break;
			case 56:numbers[i] = 8; break;
			case 57:numbers[i] = 9; break;
				break;
			}
		}
		else numbers[i] = 777;
	}
}
void FindChar(char str[], char *operation, const int n)
{
	for (int i = 0, j = 0; str[i]; i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^' || str[i] == '(' || str[i] == ')')
		{
			operation[j] = str[i];
			j++;
		}
	}
}
void IntMerge(int *numbers, const int n)
{
	int total = 0;
	for (int i = 0; i < n; i++)
	{
		if ((numbers[i] <= 9 && numbers[i] >= 0) && (numbers[i + 1] <= 9 && numbers[i + 1] >= 0) && numbers[i + 2] == 777)
		{
			numbers[i] = numbers[i] * 10 + numbers[i + 1];
			numbers[i + 1] = 0;
		}
		if ((numbers[i] <= 9 && numbers[i] >= 0) && (numbers[i + 1] <= 9 && numbers[i + 1] >= 0) && (numbers[i + 2] <= 9 && numbers[i + 2] >= 0) && numbers[i + 3] == 777)
		{
			numbers[i] = numbers[i] * 100 + numbers[i + 1] * 10 + numbers[i + 2];
			numbers[i + 1] = 0;
			numbers[i + 2] = 0;
		}
		if ((numbers[i] <= 9 && numbers[i] >= 0) && (numbers[i + 1] <= 9 && numbers[i + 1] >= 0) && (numbers[i + 2] <= 9 && numbers[i + 2] >= 0) && (numbers[i + 3] <= 9 && numbers[i + 3] >= 0) && numbers[i + 4] == 777)
		{
			numbers[i] = numbers[i] * 1000 + numbers[i + 1] * 100 + numbers[i + 2] * 10 + numbers[i + 3];
			numbers[i + 1] = 0;
			numbers[i + 2] = 0;
			numbers[i + 3] = 0;
		}
	}
}
void Clear(int *numbers, int*clear, const int n)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (numbers[i] != 0 && numbers[i] != 777)
		{
			clear[j] = numbers[i];
			j++;
		}
	}
}
double MainMath(int*clear, char*operations, const int n)
{
	//plus
	double result = 0;
	if ((operations[0] != '*'&&operations[0] != '/') && operations[0] == '+')
	{
		result += clear[0];
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '+'&&operations[i + 1] == 0 && operations[i - 1] != '-')
		{
			result += clear[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '+'&&operations[i + 1] == '+')
		{
			result += clear[i + 1];
		}
	}
	//minus
	if ((operations[0] != '*'&&operations[0] != '/') && operations[0] == '-')
	{
		result -= clear[0];
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '-'&&operations[i + 1] == 0)
		{
			result -= clear[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '-'&&operations[i + 1] == '-')
		{
			result -= clear[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '-'&&operations[i + 1] == '+')
		{
			result += clear[i + 1];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (operations[i] == '+'&&operations[i + 1] == '-')
		{
			result -= clear[i + 1];
		}
	}
	return result;
}
