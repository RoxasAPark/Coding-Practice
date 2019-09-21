#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int array[], int low, int high)
{
	int x = array[high];

	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= x)
		{
			i = i + 1;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[high]);
	return i + 1;
}

void quickSort(int array[], int low, int high)
{
	if (low < high)
	{
		int q = partition(array, low, high);
		quickSort(array, low, q - 1);
		quickSort(array, q + 1, high);
	}
}

int kthSmallest(int arr[], int k, int size)
{
	if (k > size)
		return INT_MAX;

	quickSort(arr, 0, size - 1);

	return arr[k - 1];
}

int largestElement(int arr[], int size)
{
	quickSort(arr, 0, size - 1);

	return arr[size-1];
}

bool searchElement(int arr[], int size, int target)
{
	bool found = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == target)
			found = true;
	}

	return found;
}

void missingNumbers(int arr[], int size)
{
	int largest = largestElement(arr, size);

	for (int i = 0; i < largest; i++)
	{
		if (searchElement(arr, size, i) == false)
			cout << i << endl;
	}
}

void perfectSquare(int rows)
{
	int count = 0;

	if (rows == 0)
		return;

	while (count != rows)
	{
		for (int i = 0; i < rows; i++)
			cout << rows << " ";

		cout << endl;
		count++;
	}
}

int main()
{
	int x[] = {1, 6, 11, 19, 10};
	int y[] = {142, 11, 46, 57, 2, 19 };

	int size = sizeof(x) / sizeof(x[0]);

	missingNumbers(x, size);

	perfectSquare(0);
	system("pause");
}

