#include "sort.h"
/**
* bubble_sort - Sorts an array of integers in ascending order
*               using the Bubble sort algorithm.
* @array: Pointer to the array of integers to sort.
* @size: Number of elements in the array.
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		swp = 0;
		j = 0;

		while (j < size - 1 - i)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swp = 1;
			}
			j++;
		}
		if (swp == 0)
			break;

		i++;
	}
}
