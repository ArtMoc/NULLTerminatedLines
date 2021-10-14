#include <iostream>
using namespace std;
#include <Windows.h>

int StringLength(char str[]);

void to_upper(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);

void main()
{
	//for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
	cout << 'A' << "\t" << 'a' << endl;
	cout << (int)'A' << "\t" << (int)'a' << endl;
	cout << 'A' - 'a' << endl;
	setlocale(LC_ALL, "Rus");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";
	const int n = 256;
	//char str[n] = "Хорошо       живет    на   свете         Винни-пух";
	char str[n] = "Аргентина манит негра";
	//cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//cin.getline(str, n); //принимает строку и размер строки, str - строка, n - размер строки
	cout << str << endl;
	cout << "Длина введенной строки: " << StringLength(str) << " символов" << endl;
	//to_upper(str);
	shrink(str);
	cout << str << endl;
	cout << "Строка " <<( is_palindrome(str) ? "" : "не " )<< "является палиндромом" << endl;
	cout << str << endl;

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
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	to_upper(buffer);
	remove_symbol(buffer, ' ');
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return true;
		}
	}
	delete[] buffer;
	return false;
}