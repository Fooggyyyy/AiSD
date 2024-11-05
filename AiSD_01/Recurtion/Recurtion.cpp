#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int pred_number = 0, number = 1, sum = 0, N;
    clock_t start, end;

    cout << "Введите число: ";
    cin >> N;

    if (N == 1)
    {
        cout << "Число Фибоначи для " << N << " равно " << 1;
        return 0;
    }

    start = clock();

    for (int i = 0; i < N - 2; i++) 
    {
        sum = number + pred_number;
        pred_number = number;
        number = sum;
    }

    end = clock();

    cout << "Число Фибоначи для " << N << " равно " << sum << endl;

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Время выполнения программы: " << time_taken << " секунд" << endl;

    return 0;
}
