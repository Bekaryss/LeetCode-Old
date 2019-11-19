// Unique Email Addresses 929.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
	unordered_set<string> ans;
	for (int i = 0; i < emails.size(); i++) {
		int start = 0, end = 0;
		bool started = false;
		bool dog = false;
		for (int j = 0; j < emails[i].size(); j++)
		{
			if (emails[i][j] == '@') {
				if (started == true) {
					emails[i].erase(start, end);
					j -= end;
					started = false;
					start = 0;
					end = 0;
				}
				dog = true;
			}
			else {
				if (emails[i][j] == '.' && dog == false) {
					emails[i].erase(j, 1);
				}
			}
			if (started != true && emails[i][j] == '+') {
				start = j;
				started = true;
			}
			if (started == true) {
				end++;
			}

		}
		ans.insert(emails[i]);
	}
	return ans.size();
}

int main()
{
	vector<string> input = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };
    std::cout << "2 == " << numUniqueEmails(input) << endl; 

	vector<string> input1 = { "test.email+alex@leetcode.com", "test.email@leetcode.com" };
	std::cout << "1 == " << numUniqueEmails(input1) << endl;
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
