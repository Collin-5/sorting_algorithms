#include "sort.h"
/**
 * partition - partitions the array
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: pvt position
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int i, j, pivot, tmp;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
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
	if (i + 1 != hi)
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - implementation of the quick sort algorithm
 * @array: the array to sort
 * @lo: the lo
 * @hi: the high
 * @size: size of the array
 *
 * Return: void
 */
void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
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
