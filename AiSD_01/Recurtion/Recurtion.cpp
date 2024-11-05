#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int pred_number = 0, number = 1, sum = 0, N;
    clock_t start, end;

    cout << "������� �����: ";
    cin >> N;

    if (N == 1)
    {
        cout << "����� �������� ��� " << N << " ����� " << 1;
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

    cout << "����� �������� ��� " << N << " ����� " << sum << endl;

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "����� ���������� ���������: " << time_taken << " ������" << endl;

    return 0;
}
