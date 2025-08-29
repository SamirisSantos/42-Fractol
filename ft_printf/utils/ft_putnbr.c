/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:55:17 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/21 19:59:54 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//%d Prints a decimal (base 10) number AND %i Prints an integer in base 10
int	ft_putnbr(int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
	}
	count += ft_putchar(nb % 10 + '0');
	return (count);
}
/*int main()
{
	int	Original;
	int	myfuntion;
	int	n = -2147483648;
	int	n2 = 2147483647;
	int	n3 = 0;

	// decimal
	printf("Decimal\n");
	Original = printf("%d", n);
	printf("\n");
	myfuntion = ft_putnbr(n);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%d", n2);
	printf("\n");
	myfuntion = ft_putnbr(n2);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%d", n3);
	printf("\n");
	myfuntion = ft_putnbr(n3);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	// integer
	printf("\nInteger\n");
	Original = printf("%i", n);
	printf("\n");
	myfuntion = ft_putnbr(n);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%i", n2);
	printf("\n");
	myfuntion = ft_putnbr(n2);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	Original = printf("%i", n3);
	printf("\n");
	myfuntion = ft_putnbr(n3);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);

	return (0);
}*/