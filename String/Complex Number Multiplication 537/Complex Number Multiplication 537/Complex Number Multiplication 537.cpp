// Complex Number Multiplication 537.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> stringArray(string s) {
	auto it = s.find('+');
	vector<string> out;
	out.push_back(s.substr(0, it));
	out.push_back(s.substr(it + 1, s.size()));
	return out;
}

string complexNumberMultiply(string a, string b) {
	vector<string> wordsA = stringArray(a);
	vector<string> wordsB = stringArray(b);
	int first = stoi(wordsA[0]) * stoi(wordsB[0]);
	auto itSecondA = wordsA[1].find('i');
	auto itSecondB = wordsB[1].find('i');
	int second = stoi(wordsA[1].substr(0, itSecondA)) * stoi(wordsB[1].substr(0, itSecondB)) * -1;
	first = first + second;

	int thirdF = stoi(wordsB[0]) * stoi(wordsA[1].substr(0, itSecondA));
	int thirdS = stoi(wordsA[0]) * stoi(wordsB[1].substr(0, itSecondB));
	int third = thirdF + thirdS;
	string ans = to_string(first) + "+" + to_string(third) + "i";
	return ans;
}

int main()
{
	string a = "1+1i", b = "1+1i";
	std::cout << "0 + 2i == " << complexNumberMultiply(a, b) << endl;

	string a1 = "1+-1i", b1 = "1+-1i";
	std::cout << "0+-2i == " << complexNumberMultiply(a1, b1) << endl;

	string a2 = "1+-1i", b2 = "0+0i";
	std::cout << "0 + 0i == " << complexNumberMultiply(a2, b2) << endl;
	
		
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
