#include "sort.h"

/**
 * selection_sort - the Selection sort algorithm
 * @array: the array
 * @size: the array size
 * Return: nothin'
 */
void selection_sort(int *array, size_t size)
{
	size_t x = 0;
	size_t y = 1;
	size_t bucket;
	size_t holder, the_bool;

	if (array == NULL)
		return;

	while (x < size)
	{
		bucket = x;
		while (y < size)
		{
			if (array[y] < array[bucket])
			{
				bucket = y;
				the_bool = 1;
			}
			y++;
		}
		if (the_bool == 1)
		{
			holder = array[x];
			array[x] = array[bucket];
			array[bucket] = holder;
			print_array(array, size);
		}
		the_bool = 0;
		x++;
	}
}
