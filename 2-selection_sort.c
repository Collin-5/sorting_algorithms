#include "sort.h"

/**
 * selection_sort - Sorts an array of integers
 * @array: Pointer to array
 * @size: Size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int index = 0, mn, temp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		mn = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < mn)
			{
				mn = array[j];
				index = j;
			}
		}
		if (mn != array[i])
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;
			print_array(array, size);
		}
	}
}
