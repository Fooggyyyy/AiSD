#include <iostream>
#include <ctime> // ��� ��������� �������

using namespace std;

int Fibonachi(int n)
{
    // ������� �������� �� �������

    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return Fibonachi(n - 1) + Fibonachi(n - 2);
}

int main()
{
    setlocale(LC_ALL, "ru");

    // ������ �����, ������� ����� ���������� ��������� ����� �� ������������������ ���������
    cout << "������� ����� ������� � ������������������: ";
    int num; cin >> num;

    // �������� ����� ����������
    clock_t start = clock();

    // ������� �����
    cout << "���� ������������������: ";
    for (int i = 0; i < num; i++)
    {
        cout << Fibonachi(i) << " ";
    }

    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC;

    cout << "\n\n����� ����������: " << duration << " ������." << endl;
}
