#include "main.h"
/**
 * get_flags - looks for flags
 * @format: pointer string from which to print
 * the arguments
 * @i: pointer takes parameters
 * Return: flags;
 */
int get_flags(const char *format, int *i)
{
	int j, n;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (n = *i + 1; format[n] != '\0'; n++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[n] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = n - 1;
	return (flags);
}
