#include <iostream>
#include <ctime>

using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");

    cout << "������� ����� N: ";
    int N;
    cin >> N;

    srand(time(0)); 

    int num_check = rand() % N + 1;
    int num = rand() % N + 1;
    int pred_num = num;

    while (num_check != num)
    {
        cout << num << endl;
        if (num < num_check)
        {
            cout << "������!!!" << endl;
            pred_num = num; 
            num = rand() % (N - pred_num) + pred_num + 1; 
        }
        else
        {
            cout << "������!!!" << endl;
            pred_num = num; 
            num = rand() % (pred_num - 1) + 1; 
        }
    }

    cout << "�� �������! ���������� �����: " << num_check << endl;

	int i = 0;
	while (pow(2, i) <= N)
	{
		i++;
	}
		
	cout << "��� ��������� ������ ����������� " << i << " �������.";
	
}