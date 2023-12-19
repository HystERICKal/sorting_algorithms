#include "sort.h"
/**
 * shell_sort -the shell sort algorithm (using Knuth sequence)
 * @array: the array
 * @size: array size
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	unsigned int space = 1;
	unsigned int x;
	unsigned int y;
	int holder, num = 3;

	if (array == NULL)
		return;
	if (size < 2)
		return;
	for (; space < size / num; space = space * num + 1)
		continue;

	for (; space > 0; space /= 3)
	{
		for (x = space; x < size; x++)
		{
			holder = array[x];

			for (y = x; y >= space && array[y - space] > holder; y -= space)
			{
				array[y] = array[y - space];
			}
			array[y] = holder;
		}
		print_array(array, size);
	}
}
