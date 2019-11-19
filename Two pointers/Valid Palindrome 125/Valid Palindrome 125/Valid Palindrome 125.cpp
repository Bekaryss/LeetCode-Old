// Valid Palindrome 125.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		while (!isalnum(s[i]) && i < j) {
			i++;
		}
		while (!isalnum(s[j]) && i < j) {
			j--;
		}
		if (tolower(s[i]) != tolower(s[j])) {
			return false;
		}
		else {
			i++;
			j--;
		}

	}
	return true;
}

int main()
{
    std::cout << "true == " << (isPalindrome("A man, a plan, a canal: Panama") == true ? "true" : "false") << endl;

	std::cout << "false == " << (isPalindrome("0P") == true ? "true" : "false") << endl;
	std::cout << "true == " << (isPalindrome(".,") == true ? "true" : "false") << endl;
	std::cout << "true == " << (isPalindrome("a") == true ? "true" : "false") << endl;
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
