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


void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	const int n = 256;
	char str[n]{};
	cout << "Введите строку: ";
	cin.getline(str, n); //можно ввести строку с пробелами
	cout << "Длина введенной строки: " << StringLength(str) << " символов" << endl;
	to_upper(str);
	cout << "Верхний регистр: " << str << endl;
	to_lower(str);
	cout << "Нижний регистр: " << str << endl;
	cout << "Введите строку с лишними пробелами:";
	cin.getline(str, n);
	shrink(str);
	cout << "Без лишних пробелов: " << str << endl;
	cout << "Введите строку: ";
	cin.getline(str, n);
	cout << "Строка " <<( is_palindrome(str) ? "" : "не " )<< "является палиндромом" << endl;
	cout << "Введите строку: ";
	cin.getline(str, n);
	cout << "Строка " <<( is_int_number(str) ? "" : "не " )<< "является целым десятичным числом" << endl;
	cout << "Введите строку: ";
	cin.getline(str, n);
	cout << "Строка " << (is_bin_number(str) ? "" : "не ") << "является целым двоичным числом" << endl;
	cout << "Введите строку: ";
	cin.getline(str, n);
	cout << "Строка " << (is_hex_number(str) ? "" : "не ") << "является целым шестнадцатиричным числом" << endl;
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
		if (      //Если 
			str[i] >= 'a' && str[i] <= 'z' || //элемент строки маленькая английская буква или
			str[i] >= 'а' && str[i] <= 'я' //маленькая русская буква
			)
			str[i] -= 32; //то переводим его в верхний регистр
	}
}
void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'A' && str[i] <= 'Z' || 
			str[i] >= 'А' && str[i] <= 'Я' 
			)
			str[i] += 32; 
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
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
		for (int i = 0; i < n; i++)
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
		if ((str[i] < '0' || (str[i] > '9' && str[i] < 'a') || str[i] > 'f')) return false;
	}
	return true;
}


