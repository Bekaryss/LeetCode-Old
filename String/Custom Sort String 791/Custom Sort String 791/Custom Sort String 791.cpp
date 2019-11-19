// Custom Sort String 791.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

std::string customSortStringSolution(std::string S, std::string T) {
	std::sort(T.begin(), T.end(), [&](char a, char b) {
		return S.find(a) < S.find(b);
	});
	return T;
}

std::string customSortString(std::string S, std::string T) {
	std::unordered_map<char, int> uMap;

	for (size_t i = 0; i < S.size(); i++) {
		auto found = T.find(S[i]);
		if (found != std::string::npos) {
			uMap.insert(std::make_pair(T[found], found));
			T.erase(found, 1);
			T.push_back(S[i]);
			auto f = T.find(S[i]);
			int n = 0;
			while (f != std::string::npos) {
				T.erase(f, 1);
				f = T.find(S[i]);
				n++;
			}		
			while (n > 0) {
				T.push_back(S[i]);
				n--;
			}
		}	
	}
	
	return T;
}

int main()
{
	std::string  S = "cba", T = "abcd";
	std::cout << "cbad == " << customSortStringSolution(S, T) << std::endl;

	std::string S1 = "kqep", T1 = "pekeq";
	std::cout << "kqeep == " << customSortStringSolution(S1, T1) << std::endl;
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
