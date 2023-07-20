#include "variadic_functions.h"

/**
 * sum_them_all - sums variable arguments
 * @n: number of arguments passed to the function
 * @...: the integers to sum
 *
 * Return: the integer sum
 */
int sum_them_all(const unsigned int n, ...)
{
	int sum = 0, i = n;
	va_list list;

	if (!n)
		return (0);
	va_start(list, n);

	while (i--)
		sum += va_arg(list, int);

	va_end(list);

	return (sum);
}
