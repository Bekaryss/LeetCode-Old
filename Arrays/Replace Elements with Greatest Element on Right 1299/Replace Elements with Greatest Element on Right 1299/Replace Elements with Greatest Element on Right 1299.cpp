// Replace Elements with Greatest Element on Right 1299.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int bIn = 0;
    int biggest = 0;
    for (int i = 0; i < arr.size()-1; i++) {
        int j = i+1;
        if (i == bIn) {
            biggest = 0;
            while (j < arr.size()) {
                if (biggest < arr[j]) {
                    biggest = arr[j];
                    bIn = j;
                }
                j++;
            }
        }
        arr[i] = biggest;
    }
    arr[arr.size() - 1] = -1;
    return arr;
}

vector<int> replaceElementsSolution(vector<int>& arr) {
    int mx = -1, a;
    for (int i = arr.size() - 1; i >= 0; --i) {
        a = arr[i];
        arr[i] = mx;
        mx = max(mx, a);
    }
    return arr;
}

int main()
{
    vector<int> input = { 17,18,5,4,6,1 };
    input = replaceElementsSolution(input);
    for (int i : input) {
        cout << i << " ";
    }
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
