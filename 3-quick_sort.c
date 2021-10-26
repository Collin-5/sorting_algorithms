#include "sort.h"
/**
 * partition - partitions the array
 * @array: array to take in
 * @start: start of array;
 * @end: end of array
 * @size: full size of array
 * Return: pvt position
 */
int partition(int *array, int start, int end, int size)
{
	int pvt = array[end];
	int i = start, j, tmp;

	for (j = start; j < end; j++)
	{
		if (array[j] <= pvt)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	printf("return i=%d\n", i);
	return (i);
}
/**
 * quickSort - quick sorts with recursion
 * @array: array to sort through
 * @start: start of array or subarray
 * @end: end of array or subarray
 * @size: size of full array
 */
void quickSort(int *array, int start, int end, int size)
{
	int pvt;

	if (start < end)
	{
		pvt = partition(array, start, end, size);
		printf("first recursive, start [%d] to pivot-1[%d]\n", start, pvt - 1);
		quickSort(array, start, pvt - 1, size);
		printf("second recursive, pivot+1 [%d] to end [%d]\n", pvt + 1, end);
		quickSort(array, pvt + 1, end, size);
	}
}
/**
 * quick_sort - quick sorts an array
 * @array: array to sort
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}
