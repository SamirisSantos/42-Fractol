/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 19:41:16 by sade-ara          #+#    #+#             */
/*   Updated: 2025/05/21 20:06:44 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//%c Prints a single character
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
/*int main()
{
	char c = 'a';
	int	Original;
	int	myfuntion;

	Original = printf("%c", c);
	printf("\n");
	myfuntion = ft_putchar(c);
	printf("\nReturn values - Original: %d", Original);
	printf(", Myfuntion: %d\n", myfuntion);
	return (0);
}*/