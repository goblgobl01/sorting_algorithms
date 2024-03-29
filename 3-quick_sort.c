#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - a function that implements
 * the Lomuto partition scheme.
 *
 * @array: points to the array used for partition.
 * @size: array's size.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Return: returns above.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}


/**
 * lomuto_sort - a function that implements
 * the quicksort algorithm through recursion.
 *
 * @array: array of integers to sort.
 * @size: the size of the array.
 * @left: the starting index of the array partition to order.
 * @right: the ending index of the array partition to order.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}


/**
 * quick_sort - a function that sorts
 * an array of integers in ascending order
 * using the Quick sort algorithm.
 *
 * @array: points to the array we look to sort.
 * @size: array's size.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
