/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 20:14:00 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/21 20:14:00 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_puthex_long(unsigned long long int n, const char format)
{
	int		count;
	char	*hexbase;
	char	c;

	hexbase = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_puthex_long(n / 16, format);
	c = hexbase[n % 16];
	count += write(1, &c, 1);
	return (count);
}

//%p Prints a pointer address
int	ft_putptr(void *ptr)
{
	int		count;
	char	*hex;

	count = 0;
	hex = (char *)ptr;
	if (!ptr)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_puthex_long((unsigned long long)hex, 'x');
	return (count);
}
/*int main()
{
	int	Original;
	int	myfuntion;
	int	*ptr = NULL;
	int	n = 42;
	int	*ptr2 = &n;

	// pointer
	printf("Pointer\n");
	Original = printf("%p", ptr);
	printf("\n");
	myfuntion = ft_putpointer(ptr);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%p", ptr2);
	printf("\n");
	myfuntion = ft_putpointer(ptr2);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	return (0);
}*/