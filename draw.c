/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:05:54 by sade-ara          #+#    #+#             */
/*   Updated: 2025/07/29 16:05:54 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Formula do Fractal Mandelbrot
Z(n+1) = Z(n)^2 + C
Z0 = 0 
Z é um número complexo
C (um número complexo que representa cada ponto no plano)
O ponto C pertence ao conjunto de Mandelbrot se a sequência Z(n) 
nao tende ao infinito

Formula do Fractal Julia
Z(n+1) = Z(n)^2 + C

No Julia, você fixa um valor de C e varia o valor inicial Z0
*/

// void change_color(int keysym, t_fractol *data)
// {
// 	if()
// }

void	render_fractal(t_fractol *f)
{
	
}