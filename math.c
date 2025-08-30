/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:27:20 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/25 15:27:20 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// [0,799] -> [-2,2]

double	map(double coord, double new_min, double new_max, double old_max)
{
	double	result;

	result = (new_max - new_min) * coord / old_max;
	return (result + new_min);
}

t_complex	sum_nbr(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.real_nbr = z1.real_nbr + z2.real_nbr;
	result.im_nbr = z1.im_nbr + z2.im_nbr;
	return (result);
}
/*
	(x + yi) * (x + yi)
	i^2 = -1
	real number = (x^2 - y^2)
	imag number = (2xyi);
*/

t_complex	square_nbr(t_complex z)
{
	t_complex	result;

	result.real_nbr = (z.real_nbr * z.real_nbr) - (z.im_nbr * z.im_nbr);
	result.im_nbr = 2 * (z.real_nbr * z.im_nbr);
	return (result);
}
