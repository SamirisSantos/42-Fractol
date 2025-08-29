/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:13:25 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/30 20:23:53 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formats(char format, va_list ap)
{
	if (format == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format == 'p')
		return (ft_putptr(va_arg(ap, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format == 'u')
		return (ft_putuint(va_arg(ap, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_formats(*format, ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}
/*int main()
{
	char 			c;
	unsigned int	n;
	int				nbr;
	int				*ptr;
	unsigned int	Original;
	unsigned int	myfuntion;

	//%c Prints a single character
	c = 'a';
	Original = printf("Original char: %c\n", c);
	myfuntion = ft_printf("My print char: %c\n",c);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("-----------------------------------------\n\n");

	//%x or %X Prints an  hexadecimal (base 16) number in lowercase or uppercase
	n = 305441741; // 1234abcd or 1234ABCD
	Original = printf("Original hexa: %x\n", n);
	myfuntion = ft_printf("My print hexa: %x\n",n);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("\n");

	Original = printf("Original HEXA: %X\n", n);
	myfuntion = ft_printf("My print HEXA: %X\n",n);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("-----------------------------------------\n\n");

	//%d Prints a decimal (base 10) number AND %i Prints an integer in base 10
	nbr = -2147483648;
	Original = printf("Original dec/int: %i\n", nbr);
	myfuntion = ft_printf("My print dec/int: %i\n",nbr);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("\n");
	
	nbr = 2147483648;
	Original = printf("Original dec/int: %d\n", nbr);
	myfuntion = ft_printf("My print dec/int: %d\n",nbr);
	printf("\nReturn values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("-----------------------------------------\n\n");

	//%p Prints a pointer address
	ptr = NULL;
	Original = printf("Original dec/int: %p\n", ptr);
	myfuntion = ft_printf("My print dec/int: %p\n",ptr);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("\n");

	ptr = &n;
	Original = printf("Original dec/int: %p\n", ptr);
	myfuntion = ft_printf("My print dec/int: %p\n",ptr);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
	printf("-----------------------------------------\n\n");

	//%u Prints an unsigned decimal (base 10) number
	n = 4294967295;
	Original = printf("Original: %u\n", n);
	myfuntion = ft_printf("My print: %u\n",n);
	printf("Return values - Original: %d", Original);
	printf(", My print: %d\n", myfuntion);
}*/