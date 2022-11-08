#include <stdio.h>

int ft_printf(const char *str, ...);
char* ft_itoa(unsigned long num, int base);

int main(void)
{
	printf("# Expected result (next line) Your result #\n");
	printf("%d\n", printf("%10.2s\n", "toto"));
	printf("%d\n", ft_printf("%10.2s\n", "toto"));
	printf("---\n");
	printf("%d\n", printf("Magic %s is %5.3d\n", "number", -42));
	printf("%d\n", ft_printf("Magic %s is %5.3d\n", "number", -42));
	printf("---\n");
	printf("%d\n", printf("Hexadecimal for %d is %5.7x\n", -42, 42));
	printf("%d\n", ft_printf("Hexadecimal for %d is %5.7x\n", -42, 42));
	printf("%s\n", ft_itoa(123, 10));
	printf("%s\n", ft_itoa(42, 16));
}
