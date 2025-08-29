/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsnnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:46:31 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/20 16:05:55 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//%u Prints an unsigned decimal (base 10) number
int	ft_putuint(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n >= 10)
		count += ft_putuint(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
	return (count);
}
/*int main()
{
	unsigned int	n = 4294967295;
	unsigned int	Original;
	unsigned int	myfuntion;

	Original = printf("%u", n);
	printf("\n");
	myfuntion = ft_putuint(n);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);
}*/