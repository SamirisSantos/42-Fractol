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

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return;
	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_data + offset) = (unsigned int)color;
}

static void	handle_pixel_mandel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	z.real_nbr = 0.0;
	z.im_nbr = 0.0;
	c.real_nbr = (map(x, -2, 2, WIN_WIDTH) * fractol->zoom) + fractol->offset_x;
	c.im_nbr   = (map(y,  2, -2, WIN_HEIGHT) * fractol->zoom) + fractol->offset_y;
	i = 0;

	while (i < fractol->defined_img)
	{
		z = sum_nbr(square_nbr(z), c);
		if ((z.real_nbr * z.real_nbr + z.im_nbr * z.im_nbr) > fractol->not_valid)
		{
			color = get_color(i, fractol->defined_img, fractol->color_mode);
			ft_pixel_put(x, y, &fractol->img, color);
			return;
		}
		i++;
	}
	/* pontos dentro do conjunto (não escaparam) */
	ft_pixel_put(x, y, &fractol->img, BLACK);
}

void	mandel_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			handle_pixel_mandel(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img_ptr, 0, 0);
}
