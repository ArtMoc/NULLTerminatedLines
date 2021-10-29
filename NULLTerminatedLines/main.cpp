#include <iostream>
using namespace std;
#include <Windows.h>

int StringLength(char str[]);

void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);
int to_int_number(char str[]);
int bin_to_dec(char str[]);
int hex_to_dec(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 256;
	char str[n]{};
	cout << "������� ������: ";
	cin.getline(str, n); //����� ������ ������ � ���������
	cout << "����� ��������� ������: " << StringLength(str) << " ��������" << endl;
	to_upper(str);
	cout << "������� �������: " << str << endl;
	to_lower(str);
	cout << "������ �������: " << str << endl;
	cout << "������� ������ � ������� ���������:";
	cin.getline(str, n);
	shrink(str);
	cout << "��� ������ ��������: " << str << endl;
	cout << "������� ������: ";
	cin.getline(str, n);
	cout << "������ " <<( is_palindrome(str) ? "" : "�� " )<< "�������� �����������" << endl;
	cout << "������� ������: ";
	cin.getline(str, n);
	cout << "������ " <<( is_int_number(str) ? "" : "�� " )<< "�������� ����� ���������� ������" << endl;
	cout << "�������� ����� �����: " << to_int_number(str) << endl;
	cout << "������� ������: ";
	cin.getline(str, n);
	cout << "������ " << (is_bin_number(str) ? "" : "�� ") << "�������� ����� �������� ������" << endl;
	cout << "�������� ����� ����� � ���������� �������: " << bin_to_dec(str) << endl;
	cout << "������� ������: ";
	cin.getline(str, n);
	cout << "������ " << (is_hex_number(str) ? "" : "�� ") << "�������� ����� ����������������� ������" << endl;
	cout << "�������� ����� �����: " << hex_to_dec(str) << endl;
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (      //���� 
			str[i] >= 'a' && str[i] <= 'z' || //������� ������ ��������� ���������� ����� ���
			str[i] >= '�' && str[i] <= '�' //��������� ������� �����
			)
			str[i] -= 32; //�� ��������� ��� � ������� �������
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' || 
			str[i] >= '�' && str[i] <= '�' 
			)
			str[i] += 32; 
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && (str[i + 1] == ' ' || str[i + 1] == 0))
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}

void remove_symbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n / 2; i++)
	{
		if (str[i] != str[n - 1 - i])return false;
	}
	return true;
	/*char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	n=strlen(buffer);
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])return false;
	}
	return true;*/
}
bool is_int_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || str[i] > '9')return false;
	}
	return true;
}
bool is_bin_number(char str[])
{
	{
		int n = strlen(str);
		for (int i = 0; i < n - 1; i++)
		{
			if ((str[i] < '0' || str[i] > '1') && str[n - 1] != 'b') return false;
		}
		return true;
	}
}
bool is_hex_number(char str[])
{
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'a') || str[i] > 'f' && str[i] < 'A' || str[i] > 'F') return false;
	}
	return true;
}

int to_int_number(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_int_number(str))
	{
		for (int i = 0; i < n; i++)
		{
			sum = sum + ((str[i] - 48) * pow(10, n - 1 - i));
		}
		return sum;
	}
	else return 0;
}
int bin_to_dec(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_bin_number(str))
	{
		for (int i = 0; i < n - 1; i++)
		{
			sum = sum + ((str[i] - 48) * pow(2, n - 2 - i));
		}
		return sum;
	}
	else return 0;
}
int hex_to_dec(char str[])
{
	int sum = 0;
	int n = strlen(str);
	if (is_hex_number(str))
	{
		for (int i = 0; i < n - 1; i++)
		{
			sum = sum + (str[i] - ((str[i] >= 'A' && str[i] <= 'F') ? 55 : (str[i] >= 'a' && str[i] <= 'f') ? ('a' - 10) : 48)) * pow(16, n - 2 - i);
		}
		return sum;
	}
	else return 0;
}

