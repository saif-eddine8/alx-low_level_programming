#include "main.h"

/**
 * flip_bits - Returns the number of bits needed to flip to get from n to m.
 * transform one number to another
 *
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to flip to convert numbers
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int count = 0;

	while (xor_result)
	{
		if (xor_result & 1ul)
			count++;
		xor_result = xor_result >> 1;
	}
	return (count);
}
