/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 15:05:58 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/25 15:05:58 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

 /*
	Formula do Fractal Mandelbrot
	Z(n+1) = Z(n)^2 + C
	z inicia = [0,0] e C = o ponto atual

	sistema de coordenadas da janela (MiniLibX / X11) comparado ao plano cartesiano/complexo:
	Na janela (sistema gráfico):
	(0,0) está no canto superior esquerdo.
		O eixo X cresce para a direita (igual ao plano complexo).
		O eixo Y cresce para baixo (diferente do plano complexo).
	No plano complexo (que é o que usamos para Mandelbrot/Julia):
		O eixo real (Re) está no horizontal → igual ao X.
	O eixo imaginário (Im) está no vertical, mas cresce para cima → o oposto da janela.

	X vai de -2 até 2 (esquerda → direita).
	Y vai de 2 até -2 (topo → baixo).
 */


void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	
	z.real_nbr = 0;
	z.im_nbr = 0;
	c.real_nbr = map(x, -2, 2, WIN_WIDTH);
	c.im_nbr = map(y, 2, -2, WIN_HEIGHT);

	while()
	{
		
	}
}

void	mandel_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while(y < WIN_HEIGHT)
	{
		x = -1;
		while(x < WIN_WIDTH)
		{
			handle_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
}