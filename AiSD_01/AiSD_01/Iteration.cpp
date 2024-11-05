#include <iostream>
#include <ctime> // Для измерения времени

using namespace std;

int Fibonachi(int n)
{
    // Считаем значения по формуле

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return Fibonachi(n - 1) + Fibonachi(n - 2);
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Вводим число, которое равно количеству выводимых чисел из последовательности Фибоначчи
    cout << "Сколько чисел вывести в последовательности: ";
    int num; cin >> num;

    // Измеряем время выполнения
    clock_t start = clock();

    // Выводим числа
    cout << "Ваша последовательность: ";
    for (int i = 0; i < num; i++)
    {
        cout << Fibonachi(i) << " ";
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n\nВремя выполнения: " << duration << " секунд." << endl;
}
