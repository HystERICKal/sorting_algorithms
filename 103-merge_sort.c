#include "sort.h"
#include <stdio.h>

/**
 * combine -  helper function
 * @the_array: the array
 * @sz: array size
 * @point_left: left pointer
 * @point_right: right pointer
 * Return: nothing
 */
void combine(int *the_array, int *point_left, int *point_right, size_t sz)
{
	int x = 0;
	int y = 0;
	int z = 0;
	int kushoto_kiwango, kulia_kiwango;

	kushoto_kiwango = sz / 2;
	kulia_kiwango = sz - kushoto_kiwango;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(point_left, kushoto_kiwango);
	printf("[right]: ");
	print_array(point_right, kulia_kiwango);

	for (; x < kushoto_kiwango && y < kulia_kiwango;)
	{
		if (point_left[x] < point_right[y])
			the_array[z++] = point_left[x++];
		else
			the_array[z++] = point_right[y++];
	}

	for (; x < kushoto_kiwango;)
		the_array[z++] = point_left[x++];

	for (; y < kulia_kiwango;)
		the_array[z++] = point_right[y++];
	printf("[Done]: ");
	print_array(the_array, sz);
}

/**
 * merge_sort - the Merge sort algorithm
 * @array: the array
 * @size: array size
 * Return: nothing
 */
void merge_sort(int *array, size_t size)
{
	size_t x;
	size_t temp = 0;
	int kushoto[1000], kulia[1000], num = 2;

	if (!array)
		return;

	if (size < 2)
		return;

	temp = size / num;

	x = 0;
	while (x < temp)
	{
		kushoto[x] = array[x];
		x++;
	}

	x = temp;
	while (x < size)
	{
		kulia[x - temp] = array[x];
		x++;
	}

	merge_sort(kushoto, temp);
	merge_sort(kulia, size - temp);
	combine(array, kushoto, kulia, size);
}
