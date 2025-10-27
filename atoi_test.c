#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void	atoi_test()
{
	const int TESTS = 100000; // number of random tests
	int pass = 1;

	for (int t = 0; t < TESTS; t++)
	{
		size_t size = random_number(0, 25);
		char *s = malloc(size);
		if (!s)
			return ;
		for (size_t i = 0; i < size; i++)
			s[i] = random_number('0', '9');

		int sign = random_number(0, 1);
			s[0] = sign ? '0' : '-';

		int n1 = ft_atoi(s);
		int n2 = atoi(s);
		// Compare results
		if (n1 != n2)
		{
			printf("❌ Mismatch on test %d\n", t);
			printf("s = #%s#\n", s);
			printf("n1 = #%d#\n", n1);
			printf("n2 = #%d#\n", n2);
			pass = 0;
			free(s);
			break;
		}
		free(s);
	}

	if (pass)
		printf("✅ All %d random tests passed!\n", TESTS);
}

int	main(int c, char **v)
{
	atoi_test();
	return (0);
}