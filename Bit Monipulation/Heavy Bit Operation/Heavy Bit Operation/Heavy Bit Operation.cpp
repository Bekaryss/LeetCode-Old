﻿// Heavy Bit Operation.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

//Определение знака 32 битового числа
int getSign(int x) {
	int mask = 0;
	if (x != 0) {
		mask = 1;
	}
	x = x >> 31; //сдвигаем до первого бита
	return mask | x; //результатом будет -1, 0, или +1 
}

//Вычисление модуля 32 битового числа без использования условного оператора (x + mask) ^ mask = x
int absBit(int x) {
	int mask = x >> 31;
	x = x + mask;
	return x ^ mask;
}

//Нахождение минимума и максимума из двух чисел без использования условного оператора
//если x<y, то ((x−y)>>(n−1))=−1, а если x⩾y, то ((x−y)>>(n−1))=0. Выражение ((x−y)&((x−y)>>(n−1)) принимает значение 0, если x⩾y, и (x−y), если x<y
int min(int x, int y) {
	return y + ((x - y) & ((x - y) >> 31));
}

int max(int x, int y) {
	return x - ((x - y) & ((x - y) >> 31));
}

//Проверка на то, является ли число степенью двойки
//Пусть дано число x. Тогда, если результатом выражения (x && !(x & (x−1))) является единица, то число x — степень двойки.
bool isPowerOfTwo(int n) {
	return n != 0 && !(n & (n - 1));
}

//Нахождение младшего единичного бита
int lsb(int x) {
	return (x & ~(x - 1));
}

//Нахождение старшего единичного бита

int msb(int x) {	
	int power = 1;
	int num = x;
	while (num != 0) {
		x |= x >> power;
		power <<= 1;
		num /= 2;
	}
	return x ^ (x >> 1);
}

int bit2(int x) {
	x |= x >> 1;
	x |= x >> 2;
	x |= x >> 4;
	x |= x >> 8;
	x |= x >> 16;
	return x ^ (x >> 1);
}

int main()
{
	cout << absBit(-1) << endl;
	cout << "min == " << min(-3, 3) << " max == " << max(4,5) << endl;
	cout << "2 == " << lsb(10) << endl;
	cout << "4 == " << msb(5) << endl;
	cout << "4 == " << msb(7) << endl;
	cout << "8 == " << msb(10) << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
