/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:55:13 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/25 14:43:12 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>

# define MALLOC_ERROR	"Memory error"
// Window size
# define WIN_WIDTH	800
# define WIN_HEIGHT	800

// KEYS 
# define ESC_KEY		XK_Escape
# define UP 			XK_Up //65362
# define DOWN 		XK_Down //65364
# define LEFT		XK_Left //65361
# define RIGHT		XK_Right //65363
# define PLUS		XK_plus 
# define MINUS		XK_minus
# define CLOSE		17

// MOUSE
# define SCROLL_UP	4
# define SCROLL_DOWN	5

// JULIA SET DEFAULT - STARFISH
# define JULIA_STARFISH_REAL		-0.3740
# define JULIA_STARFISH_IMAG		-0.6597

//COLORS
# define BLACK	0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF

//PSYCHEDELIC COLORS
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define ORANGE		0xFFA500
# define PURPLE		0x800080
# define LIME		0xBFFF00
# define PINK		0xFF69B4
# define TEAL		0x008080
# define VIOLET		0xEE82EE
# define GOLD		0xFFD700
# define AQUA		0x7FFFD4
# define HOTPINK	0xFF1493

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
	void	*img_ptr; //pointer to image struct
	char	*img_data; //pointer to the actual pixels poixels_ptr
	//informaçao da imagem
	int		bpp; //bits por pixel
	int		line_len; //bytes por linha
	int		endian; //endianess da imagem dados em multi-bytes
}	t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_ptr; // mlx_init()
	void		*win_ptr; // mlx_new_window()
	t_img		img;
	int			max_iter;
	// Zoom, eixo x e y
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		not_valid; // hipotenusa
	int			defined_img; // rending quality image iterartions_defintion
	//fractal
	int			fractal_type;
	t_complex	julia;
}	t_fractol;

void		fractol_init(t_fractol *f);
void		mandel_render(t_fractol *fractol);
void		handle_pixel(int x, int y, t_fractol *fractol);

int			handle_close(t_fractol *data);
int			handle_input(int keysym, t_fractol *data);
int			handle_mouse(int button, int x, int y, t_fractol *f);

int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *s);

t_complex	square_nbr(t_complex z);
t_complex	sum_nbr(t_complex z1, t_complex z2);
double		map(double unscaled_num, double new_min,
				double new_max, double old_max);

#endif