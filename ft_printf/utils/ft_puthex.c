/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:48:33 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/22 16:24:04 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

//%x or %X Prints an  hexadecimal (base 16) number in lowercase or uppercase
int	ft_puthex(unsigned int n, const char format)
{
	int		count;
	char	*hexbase;
	char	c;

	if (format == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, format);
	c = hexbase[n % 16];
	count += ft_putchar(c);
	return (count);
}
/*int	main()
{
	unsigned int	n = 305441741; // 1234abcd or 1234ABCD
	unsigned int	Original;
	unsigned int	myfuntion;

	Original = printf("%x", n);
	printf("\n");
	myfuntion = ft_puthex(n, 'x');
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%X", n);
	printf("\n");
	myfuntion = ft_puthex(n, 'X');
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	return (0);
}*/