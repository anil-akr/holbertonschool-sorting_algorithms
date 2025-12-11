#include "sort.h"
/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm and Knuth sequence.
* @array: Pointer to the array of integers to sort.
* @size: Number of elements in the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = tmp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
