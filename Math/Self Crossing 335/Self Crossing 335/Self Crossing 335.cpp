// Self Crossing 335.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

/*               i-2
	case 1 : i-1┌─┐
				└─┼─>i
				 i-3

					i-2
	case 2 : i-1 ┌────┐
				 └─══>┘i-3
				 i  i-4      (i overlapped i-4)

	case 3 :    i-4
			   ┌──┐
			   │i<┼─┐
			i-3│ i-5│i-1
			   └────┘
				i-2

*/

bool isSelfCrossing(vector<int>& x) {
	for (int i = 3; i < x.size(); i++)
	{
		if (x[i - 1] <= x[i - 3] && x[i] >= x[i - 2]) {
			return true;
		}

		if (i > 3 && x[i] + x[i - 4] >= x[i - 2] && x[i - 1] == x[i - 3]) {
			return true;
		}

		if (i > 4 && x[i - 1] + x[i - 5] >= x[i - 3] && x[i - 1] <= x[i - 3] && x[i] + x[i - 4] >= x[i - 2] && x[i - 4] <= x[i - 2]) {
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> input = { 2,1,1,2 };
	vector<int> input1 = { 1,2,3,4 };
	vector<int> input2 = { 1,1,1,1 };
	vector<int> input3 = { 2,2,1,1 };
    std::cout << "true == " << (isSelfCrossing(input) == true ? "true": "false") << endl; 
	std::cout << "false == " << (isSelfCrossing(input1) == true ? "true" : "false") << endl;
	std::cout << "true == " << (isSelfCrossing(input2) == true ? "true" : "false") << endl;
	std::cout << "false == " << (isSelfCrossing(input3) == true ? "true" : "false") << endl;
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
