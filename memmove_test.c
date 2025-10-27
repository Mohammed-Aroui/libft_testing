#include "libft.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void	memmove_test()
{
	const int TESTS = 100000; // number of random tests
	int pass = 1;

	for (int t = 0; t < TESTS; t++)
	{
		size_t size = rand() % 100; // random buffer size 0–99
		char *src = malloc(size);
		char *dst1 = malloc(size);
		char *dst2 = malloc(size);

		// Fill source with random data
		for (size_t i = 0; i < size; i++)
			src[i] = random_number(0, 255);

		// Random n (could be less than size)
		size_t n = (size == 0) ? 0 : (rand() % (size + 1));

		// Run both functions
		ft_memmove(dst1, src, n);
		memmove(dst2, src, n);

		// Compare results
		if (memcmp(dst1, dst2, n) != 0)
		{
			printf("❌ Mismatch on test %d (n = %zu)\n", t, n);
			printf("src      = #%s#\n", src);
			printf("my_res   = #%s#\n", src);
			printf("auto_res = #%s#\n", src);
			pass = 0;
			free(src);
			free(dst1);
			free(dst2);
			break;
		}
		free(src);
		free(dst1);
		free(dst2);
	}

	if (pass)
		printf("✅ All %d random tests passed!\n", TESTS);
}

int	main(int c, char **v)
{
	memmove_test();
	return (0);
}