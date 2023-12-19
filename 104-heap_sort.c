#include "sort.h"

/**
 * the_shift_down - the shift down algorithm
 * @the_array: the array
 * @the_pile: the heap
 * @idx: the position indx
 * @sz: array size
 * Return: nothing
 */

void the_shift_down(int *the_array, int the_pile, int idx, int sz)
{
	int temp = idx;
	int kushoto = 2 * idx + 1;
	int kulia = 2 * idx + 2;
	int holder;

	if (kushoto < the_pile && the_array[kushoto] > the_array[temp])
		temp = kushoto;
	if (kulia < the_pile && the_array[kulia] > the_array[temp])
		temp = kulia;
	if (temp != idx)
	{
		holder = the_array[idx];
		the_array[idx] = the_array[temp];
		the_array[temp] = holder;
		print_array(the_array, sz);
		the_shift_down(the_array, the_pile, temp, sz);
	}
}

/**
 * heap_sort - the heap sort algorithm
 * @array: the array
 * @size: array size
 * Return: nothing
 */

void heap_sort(int *array, size_t size)
{
	int x = size / 2 - 1;
	int holder;

	if (array == NULL || size < 2)
		return;
	while (x >= 0)
	{
		the_shift_down(array, size, x, size);
		x--;
	}

	x = size - 1;
	while (x >= 0)
	{
		holder = array[0];
		array[0] = array[x];
		array[x] = holder;
		if (x > 0)
			print_array(array, size);
		the_shift_down(array, x, 0, size);

		x--;
	}

}
