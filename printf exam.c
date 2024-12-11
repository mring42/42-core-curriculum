#include <stdarg.h>
#include <unistd.h>

void	printNr(unsigned int n, unsigned int b, char *d, int *pc)
{
	if (n >= b)
		printNr(n / b, b, d, pc);
	*pc += (int)write(1, &d[n % b], 1);
}

void	handleSN(long n, int b, char *d, int *pc)
{
	if (n < 0)
	{
		*pc += (int)write(1, "-", 1);
		printNr(-n, b, d, pc);
	}
	else
	{
		printNr(n, b, d, pc);
	}
}

ssize_t	printStr(char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (str ? write(1, str, len) : write(1, "(null)", 6));
}

int	ft_printf(const char *format, ...)
{
	int pc = 0;
	va_list args;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			format += 2;
			pc += (int)printStr(va_arg(args, char *));
		}
		else if (*format == '%' && *(format + 1) == 'x')
		{
			format += 2;
			printNr(va_arg(args, unsigned int), 16, "0123456789abcdef", &pc);
		}
		else if (*format == '%' && *(format + 1) == 'd')
		{
			format += 2;
			handleSN(va_arg(args, int), 10, "0123456789", &pc);
		}
		else
		{
			pc += (int)write(1, format++, 1);
		}
	}
	va_end(args);
	return (pc);
}