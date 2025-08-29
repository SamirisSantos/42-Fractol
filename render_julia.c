/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:25:54 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/29 16:25:54 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Formula do Fractal Julia
	Z(n+1) = Z(n)^2 + C
	Z0 é o ponto que você está testando na tela.
	C é uma constante fixa, escolhida antes de começar a renderizar. 
	Mudar essa constante altera completamente a forma do fractal.
	
	sistema de coordenadas da janela (MiniLibX / X11) comparado 
	ao plano cartesiano/complexo:
	Na janela (sistema gráfico):
	(0,0) está no canto superior esquerdo.
		O eixo X cresce para a direita (igual ao plano complexo).
		O eixo Y cresce para baixo (diferente do plano complexo).
	No plano complexo (que é o que usamos para Mandelbrot/Julia):
		O eixo real (Re) está no horizontal → igual ao X.
	O eixo imaginário (Im) está no vertical, mas cresce para cima 
	→ o oposto da janela.

	X vai de -2 até 2 (esquerda → direita).
	Y vai de 2 até -2 (topo → baixo).
*/

static void	handle_julia_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.real_nbr = (map(x, -2, 2, WIN_WIDTH) * fractol->zoom) + fractol->offset_x;
	z.im_nbr = (map(y, 2, -2, WIN_HEIGHT) * fractol->zoom) + fractol->offset_y;
	c.real_nbr = fractol->julia.real_nbr;
	c.im_nbr = fractol->julia.im_nbr;
	i = 0;
	while (i < fractol->defined_img)
	{
		z = sum_nbr(square_nbr(z), c);
		if ((z.real_nbr * z.real_nbr + z.im_nbr * z.im_nbr)
			> fractol->not_valid)
		{
			color = get_color(i, fractol->defined_img, fractol->color_mode);
			ft_pixel_put(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	ft_pixel_put(x, y, &fractol->img, BLACK);
}

void	render_julia(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			handle_julia_pixel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img_ptr, 0, 0);
}
