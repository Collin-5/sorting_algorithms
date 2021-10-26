#include "sort.h"
/**
 * partition - partitions the array
 * @array: array to take in
 * @low: the low
 * @high: the high
 * @size: full size of array
 * Return: pvt position
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - implementation of the quick sort algorithm
 * @array: the array to sort
 * @low: the low
 * @high: the high
 * @size: size of the array
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort - implementation of the quick sort algorithm
 * @array: the array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
