#include "sort.h"

/**
 * bubble_sort - the bubble sort alforithm
 * @array: sort this
 * @size: array size
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t x = 0;
	size_t y = 0;
	int the_bool = 1;
	int holder = 1;

	if (size < 2)
		return;

	while (x < size && the_bool)
	{
		the_bool = 0;
		while (y < size - 1)
		{
			if (array[y] > array[y + 1])
			{
				holder = array[y];
				array[y] = array[y + 1];
				array[y + 1] = holder;
				the_bool = 1;
				print_array(array, size);
			}
			y++;
		}
		x++;
	}
}
