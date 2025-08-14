/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:55:13 by sade-ara          #+#    #+#             */
/*   Updated: 2025/07/22 16:55:13 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define MALLOC_ERROR	1
#define MLX_ERROR	1
// Window size
#define WIN_WIDTH	800
#define WIN_HEIGHT	600

// KEYS 
#define ESC_KEY		XK_Escape
#define UP 			65362
#define DOWN 		65364

// MOUSE
#define SCROLL_UP 	4
#define SCROLL_DOWN 5

// JULIA SET DEFAULT - STARFISH
#define JULIA_STARFISH_REAL		-0.3740
#define JULIA_STARFISH_IMAG		-0.6597

typedef struct s_complex
{
	//      x-axis
	double	real_nbr;
	//      y-axis
	double	im_nbr;
}	t_complex;

typedef struct s_img
{
	// points for image
	void		*img_ptr;
	char		*img_data;
	//informaçao da imagem
	int		bpp; //bits por pixel
	int		line_len; //bytes por linha
	int		endian; //endianess da imagem dados em multi-bytes
}	t_img;



typedef struct s_fractol
{	
	void	*mlx_ptr; // mlx_init()
	void	*win_ptr; // mlx_new_window()
	t_img	img;
	
	int			color;
	int			max_iter;
	
	// Zoom, eixo x e y
	double		zoom;
	double		offset_x;
	double		offset_y;
	//fractal
	int			fractal_type;
	t_complex	julia;
}	t_fractol;



int	handle_close(t_fractol *data);
int	handle_input(int keysym, t_fractol *data);
int	handle_mouse(int button, int x, int y, t_fractol *f);

int	ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
#endif