#include<iostream>
using namespace std;

int string_length(char arr[]);  // Возвращант размер строки
void print(char arr[]);         // Выводит на экран массив символов (строку)
char* shrink(char* arr);       // Удаляет из строки лишние пробелы
void to_lower(char* arr);      // Переводит строку в нижний регистр
void to_upper(char arr[]);      // Переводит строку в верхний регистр
bool is_palindrome(char arr[]); // Определяет является ли строка палиндромом
bool is_int_number(char arr[]); // Определяет является ли строка целым числом
int to_int_number(char arr[]);  // Если строка является целым числом, возвращает его значение

#define end_string '\0'
#define SPACE 32

void main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Strings:" << endl << endl;

	//char arr[] = "Хорошо     живет   на  свете    Винни   Пух";
	char arr[] = "аргентина манит негра";
	//char arr[] = "АБввБА";
	//char arr[] = "5479745";

	int length_string = string_length(arr);

	print(arr);
	cout << "Количество символов в строке: " << length_string << endl << endl;

	char* new_arr = shrink(arr);
	cout << "Строка с удалёнными лишними пробелами:" << endl;
	print(new_arr);

	cout << "Строка в нижнем регистре:" << endl;
	to_lower(new_arr);
	print(new_arr);

	cout << "Строка в верхнем регистре:" << endl;
	to_upper(new_arr);
	print(new_arr);

	if (is_palindrome(new_arr)) cout << "Это же ПАЛИНДРОМ!" << endl << endl;
	else cout << "Это вообще ни разу не ПАЛИНДРОМ!" << endl << endl;

	cout << '\t' << 'И' << endl << endl;

	if (is_int_number(new_arr))
	{
		cout << "Это ЧИСЛО:" << endl << endl;
		cout << to_int_number(new_arr) << endl << endl;
	}
	else cout << "Это даже близко не ЧИСЛО!" << endl << endl;

	delete[] new_arr;
}

int string_length(char arr[])
{
	int count = 0;
	while (arr[count] != end_string) count++;
	return count;
}

void print(char arr[])
{
	int n = string_length(arr);
	for (int i = 0; i < n; i++) cout << arr[i];
	cout << endl << endl;
}

char* shrink(char* arr)
{
	int length = string_length(arr);
	int i = 1;
	int extra_space_count = 0;

	while (arr[i] != end_string)
	{
		if ((int)arr[i] == SPACE && (int)arr[i - 1] == SPACE) extra_space_count++;
		i++;
	}

	int new_length = length - extra_space_count;
	char* new_arr = new char[new_length + 1];
	int index = 0;
	for (int j = 0; j < (length); j++)
	{
		if ((int)arr[j] == SPACE && (int)arr[j + 1] == SPACE) continue;
		new_arr[index] = arr[j];
		index++;
	}
	new_arr[new_length] = '\0';

	return new_arr;
}

void to_lower(char* arr)
{
	int n = string_length(arr);
	for (int i = 0; i < n; i++)
	{
		if (((int)arr[i] > 64 && (int)arr[i] < 91) || ((int)arr[i] > (-65) && (int)arr[i] < (-32)))
		{
			arr[i] = (char)((int)arr[i] + 32);
		}
		else
		{
			arr[i] = arr[i];
		}
	}
}

void to_upper(char* arr)
{
	int n = string_length(arr);
	for (int i = 0; i < n; i++)
	{
		if (((int)arr[i] > 96 && (int)arr[i] < 123) || ((int)arr[i] > (-33) && (int)arr[i] < (-0)))
		{
			arr[i] = (char)((int)arr[i] - 32);
		}
		else
		{
			arr[i] = arr[i];
		}
	}
}

bool is_palindrome(char arr[])
{
	int n = string_length(arr);
	int count = 0;
	for (int i = 0, j = (n - 1); i < (n / 2); i++, j--)
	{
		if (arr[i] == arr[j]) count++;
	}

	if (count == n / 2) return true;
	else return false;
}

bool is_int_number(char arr[])
{
	int n = string_length(arr);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((int)arr[i] > 47 && (int)arr[i] < 58) count++;
	}

	if (count == n) return true;
	else return false;
}

int to_int_number(char arr[])
{
	int n = string_length(arr);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((int)arr[i] > 47 && (int)arr[i] < 58) count++;
	}

	if (count == n)
	{
		int number = 0;
		int* arr_numbers = new int[n];

		for (int i = 0; i < n; i++)
		{
			switch ((int)arr[i])
			{
			case 48: arr_numbers[i] = 0; break;
			case 49: arr_numbers[i] = 1; break;
			case 50: arr_numbers[i] = 2; break;
			case 51: arr_numbers[i] = 3; break;
			case 52: arr_numbers[i] = 4; break;
			case 53: arr_numbers[i] = 5; break;
			case 54: arr_numbers[i] = 6; break;
			case 55: arr_numbers[i] = 7; break;
			case 56: arr_numbers[i] = 8; break;
			case 57: arr_numbers[i] = 9; break;
			}
		}

		for (int i = (n - 1), j = 1; i >= 0; i--, j *= 10)
		{
			number += arr_numbers[i] * j;
		}

		delete[] arr_numbers;
		return number;
	}
	else return -1;
}