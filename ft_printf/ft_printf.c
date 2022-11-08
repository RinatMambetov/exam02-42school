#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int g_result;
int g_width;
int g_precision;

void ft_putchar(char ch)
{
	write(1, &ch, 1);
	g_result++;
}

int ft_strlen(char *str)
{
	int len = 0;

	while (*str++)
		len++;
	return (len);
}

void ft_putstr(char *str, int len)
{
	while (len--)
		ft_putchar(*str++);
}

char *ft_itoa(unsigned long num, int base)
{
	unsigned long temp = num;
	int len = 0;
	if (num == 0)
		len = 1;
	else
	{
		while (temp)
		{
			len++;
			temp /= base;
		}
	}
	char *str = malloc(len + 1);
	str[len] = '\0';
	while (len--)
	{
		if (num % base > 9)
			str[len] = num % base + 'a' - 10;
		else
			str[len] = num % base + '0';
		num /= base;
	}
	return (str);
}

void ft_printf_x(unsigned int num)
{
	char *str = ft_itoa(num, 16);
	int len = ft_strlen(str);

	if (g_precision > len)
	{
		while (g_width-- > g_precision)
			ft_putchar(' ');
		while (g_precision-- > len)
			ft_putchar('0');
	}
	else
	{
		while (g_width-- > len)
			ft_putchar(' ');
	}
	ft_putstr(str, len);
}

void ft_printf_d(int num)
{
	int minus = 0;
	if (num < 0)
	{
		minus = 1;
		g_width--;
		num *= -1;
	}
	char *str = ft_itoa(num, 10);
	int len = ft_strlen(str);

	if (g_precision > len)
	{
		while (g_width-- > g_precision)
			ft_putchar(' ');
		if (minus)
			ft_putchar('-');
		while (g_precision-- > len)
			ft_putchar('0');
	}
	else
	{
		while (g_width-- > len)
			ft_putchar(' ');
		if (minus)
			ft_putchar('-');
	}
	ft_putstr(str, len);
}

void ft_printf_s(char *str)
{
	int len = ft_strlen(str);

	if (g_precision != -1 && g_precision < len)
		len = g_precision;
	while (g_width-- > len)
		ft_putchar(' ');
	ft_putstr(str, len);
}

int ft_printf(const char *str, ... )
{
	va_list ap;
	g_result = 0;

	va_start(ap, str);
	while (*str)
	{
		g_width = 0;
		g_precision = -1;
		if (*str == '%')
		{
			str++;
			while (*str >= '0' && *str <= '9')
				g_width = g_width * 10 + (*str++ - '0');
			if (*str == '.')
			{
				str++;
				g_precision = 0;
				while (*str >= '0' && *str <= '9')
					g_precision = g_precision * 10 + (*str++ - '0');
			}
			if (*str == 's')
				ft_printf_s(va_arg(ap, char *));
			else if (*str == 'x')
				ft_printf_x(va_arg(ap, unsigned int));
			else if (*str == 'd')
				ft_printf_d(va_arg(ap, int));
			str++;
		}
		else
			ft_putchar(*str++);
	}
	va_end(ap);
	return (g_result);
}
