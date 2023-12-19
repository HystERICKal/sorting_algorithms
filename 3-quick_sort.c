#include "sort.h"

/**
 * the_partition_scheme - the scheme implementation
 * @the_array: the array
 * @element_one: array element 1
 * @element_final: array element final
 * @sz: array size
 * Return: int
 */
int the_partition_scheme(int *the_array, int element_one,
		int element_final, size_t sz)
{
	int anchor = the_array[element_final];
	int x = element_one - 1;
	int y = element_one;
	int holder;

	while (y <= element_final)
	{
		if (the_array[y] <= anchor)
		{
			x++;
			if (x != y)
			{
				holder = the_array[x];
				the_array[x] = the_array[y];
				the_array[y] = holder;
				print_array(the_array, sz);
			}
		}
		y++;
	}
	return (x);
}

/**
 * the_lomuto - the lomuto implementation
 * @the_array: the array
 * @element_one: array element 1
 * @element_final: array element final
 * @sz: array size
 * Return: void
 */
void the_lomuto(int *the_array, int element_one, int element_final, size_t sz)
{
	int temp = 0;

	if (element_one < element_final)
	{
		temp = the_partition_scheme(the_array, element_one, element_final, sz);
		the_lomuto(the_array, element_one, temp - 1, sz);
		the_lomuto(the_array, temp + 1, element_final, sz);
	}
}

/**
 * quick_sort - the Quick Sort algorithm
 * @array: the array
 * @size: the array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	the_lomuto(array, 0, size - 1, size);
}
