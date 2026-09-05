#include <stdio.h>

int	main(void)
{
	char *str = NULL;

	printf("%-p\n", &str);
	printf("%0p\n", &str);
	printf("%#p\n", &str);
	printf("%+p\n", &str);
	printf("% p\n", &str);
	printf("%.32p\n", &str);
	printf("%32p\n", &str);
}
