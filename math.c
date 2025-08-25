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
