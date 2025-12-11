#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: The array to sort
 * @low: Start index of the partition
 * @high: End index of the partition
 * @size: Size of the array (for print)
 * Return: The final index of the pivot
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j, tmp;

	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
		j++;
	}

	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);

}

/**
 * quick_sort_recursive - Recursively apply quick sort
 * @array: The array to sort
 * @low: Lower index
 * @high: Higher index
 * @size: Size of the array (for print)
 */


void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array of integers using Quick sort algorithm
 * @array: Pointer to array
 * @size: Size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
