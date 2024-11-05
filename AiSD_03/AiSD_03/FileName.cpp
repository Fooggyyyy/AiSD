#include<iostream>
#include<ctime>

using namespace std;

void bubbleSort(int array[], int size) 
{
	for (int step = 0; step < size - 1; ++step)
	{
		for (int i = 0; i < size - step - 1; ++i) 
		{
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

int shellSort(int arr[], int N)
{
	for (int gap = N / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < N; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return 0;
}

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
		std::swap(array[start_index], array[min_index]);
		start_index++;
	}
}

void qsortRecursive(int* mas, int size) {
	
	int i = 0;
	int j = size - 1;

	
	int mid = mas[size / 2];

	
	do {
		
		while (mas[i] < mid) {
			i++;
		}
		
		while (mas[j] > mid) {
			j--;
		}

		
		if (i <= j) {
			int tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0) 
		qsortRecursive(mas, j + 1);
	
	if (i < size) 
		qsortRecursive(&mas[i], size - i);
	
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");

	cout << "Введите число N: ";
	int N; cin >> N; 

	int* arrayA = new int[N];
	for (int i = 0; i < N; i++)
		arrayA[i] = rand() % 100 + 1;
	

	cout << "arrayA = ";
	for (int i = 0; i < N; i++)
		cout << arrayA[i] << " ";
	

	int* arrayB = new int[N]; 
	int* arrayC = new int[N];
	int* arrayD = new int[N];
	int* arrayE = new int[N];

	for (int i = 0; i < N; i++)
	{
		arrayB[i] = arrayA[i];
		arrayC[i] = arrayA[i];
		arrayD[i] = arrayA[i];
		arrayE[i] = arrayA[i];
	}
		

	cout << endl << "Пузырьковый метод: " << endl;
	bubbleSort(arrayB, N);
	for (int i = 0; i < N; i++)
		cout << arrayB[i] << " ";

	cout << endl << "Сортировка методом Шелла: " << endl;
	shellSort(arrayC, N);
	for (int i = 0; i < N; i++)
		cout << arrayB[i] << " ";

	cout << endl << "Сортировка методом выбора: " << endl;
	selection_sort(arrayD, N);
	for (int i = 0; i < N; i++)
		cout << arrayD[i] << " ";

	cout << endl << "Быстрая сортировка: " << endl;
	qsortRecursive(arrayE, N);
	for (int i = 0; i < N; i++)
		cout << arrayD[i] << " ";
}