#include <iostream>
#include <ctime>

using namespace std;

void selection_sort(int array[], int size)
{
    int start_index = 0;
    while (start_index < size)
    {
        int min_index = start_index;
        for (int i = start_index + 1; i < size; i++)
        {
            if (array[i] < array[min_index])
            {
                min_index = i;
            }
        }
        swap(array[start_index], array[min_index]);
        start_index++;
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(0));

    cout << "������� ������ �������: ";
    int N; cin >> N;

    int* buy_array = new int[N];

    for (int i = 0; i < N; i++)
        buy_array[i] = rand() % 100 + 1;

    cout << "��� ����������� ����: " << endl;
    for (int i = 0; i < N; i++)
        cout << buy_array[i] << " ";

    selection_sort(buy_array, N);

    int* min_buy_array = new int[N / 2];
    int* max_buy_array = new int[N / 2 + 1];
    
    if (N % 2 == 0)
        int* max_buy_array = new int[N / 2];
 
    for (int i = 0, j = 0; i < N; i++)
    {
        if (i < N / 2)
            min_buy_array[i] = buy_array[i];
        else
        {
            max_buy_array[j] = buy_array[i];
            j++;
        }
            
    }
   
    //�������, ��� ������������� ����.
    int* check_min_buy_array = new int[N];
    int max = 0, min = 0;

    for (int i = 0; i < N; i++)
    {
        if (i % 2 == 0 and i != 1)
        {
            check_min_buy_array[i] = max_buy_array[max];
            max++;
        }
        else
        {
            check_min_buy_array[i] = min_buy_array[min];
            min++;
        }
            
    }

    cout << endl << "����� ������� ������������� ����: " << endl;
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(i % 2 == 0 and i != 1)
            sum += check_min_buy_array[i];
        cout << check_min_buy_array[i] << " ";
    }

    cout << endl << "����� ������������� ����: " << sum << endl;

    return 0;
}