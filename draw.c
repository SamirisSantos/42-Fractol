/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:05:54 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/25 15:04:18 by sade-ara         ###   ########.fr       */
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

static void	malloc_error(void)
{
	perror("Memory error");
	exit(EXIT_FAILURE);
}

void	fractol_init(t_fractol *f)
{
	f->mlx_ptr = mlx_init();
	if(f->mlx_ptr == NULL)
		malloc_error();
	f->win_ptr =mlx_new_window(f->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, f->name);
	if (f->win_ptr == NULL)
	{
		mlx_destroy_display(f->mlx_ptr);
 		free(f->win_ptr);
		malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (f->img.img_ptr == NULL)
	{
		mlx_destroy_window(f->mlx_ptr,f->win_ptr);
		mlx_destroy_display(f->mlx_ptr);
 		free(f->win_ptr);
		malloc_error();
	}
	f->img.img_data = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp,
											&f->img.line_len, &f->img.endian);
	//event_init(f);
	//data_init(f);

}
