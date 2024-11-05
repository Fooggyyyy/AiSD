#include <iostream>
#include <ctime>

using namespace std;

int check_priser(int array[], int size)
{
	int max = 0, prew_max = 0, prew2_max = 0;
	int sum_max = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] > prew_max && array[i] < max)
			prew_max = array[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] > prew2_max && array[i] < prew_max)
			prew2_max = array[i];
	}

	for (int i = 0; i < size; i++)
	{
		if (array[i] == max || array[i] == prew_max || array[i] == prew2_max)
			sum_max++;
	}

	cout << "��������� �������� �������, ������� ������� " << max << ", " << prew_max << " � " << prew2_max << " ������!!!" << endl;
	cout << "���������� �������� ����� " << sum_max << endl;
	return sum_max;
}
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));

	cout << "������� ������ �������: ";
	int N; cin >> N;

	int* array = new int[N];

	//���� �� 0 �� 10
	for (int i = 0; i < N; i++)
		array[i] = rand() % 11 ;

	cout << "������� �� ���������: " << endl;
	for (int i = 0; i < N; i++)
		cout << array[i] << " ";

	check_priser(array, N);

	
	return 0;
}