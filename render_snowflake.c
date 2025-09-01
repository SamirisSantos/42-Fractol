/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_snowflake.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade-ara <sade-ara@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:49:06 by sade-ara          #+#    #+#             */
/*   Updated: 2025/08/29 16:49:06 by sade-ara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
Floco de Neve de Koch (Koch Snowflake)

Koch Snowflake: Você não testa cada pixel. Em vez disso, você desenha segmentos
 de linha de forma recursiva. A complexidade vem do número de linhas e seus 
 ângulos, não de uma fórmula no plano complexo.

Algoritmo do Floco de Neve de Koch

A ideia por trás do Koch Snowflake é baseada em um conceito chamado L-System
(Sistema de Lindenmayer), que usa um iniciador e uma regra 
(ou gerador) aplicados recursivamente.

1 - Iniciador (Initiator): Para o floco de neve, o iniciador 
é um triângulo equilátero.
2 - Gerador (Generator): A regra é aplicada a cada segmento de linha reto. 
A regra clássica é:
	- Divida o segmento em três partes iguais.
	- Remova o segmento do meio
	- Substitua-o por dois novos segmentos que formam uma 
	"tenda" ou um triângulo equilátero apontando para fora.
3 - Recursão e Iterações: Esta regra é aplicada repetidamente. O número 
de iterações que você mencionou determina o nível de detalhe do fractal. 
	- Iteração 0: Um triângulo simples
	- Iteração 1: Cada lado do triângulo se transforma numa forma de "tenda".
	- Iteração 2: Cada um dos novos segmentos de linha e assim por diante.
---------------------------------------------------------------------------
p1: ponto inicial, p5: ponto final
angle: angulo do pico do triangulo,ex: 60° = pi/3 radianos
iter: numero de interação

Ponto do pico (p3), calculado rotacionando o vetor (p2 -> p4)
	em torno de p2 pelo ângulo fornecido.
	A matemática de rotação é: 
	x' = x*cos(a) - y*sin(a); y' = x*sin(a) + y*cos(a)
*/

static t_koch_points	calc_koch_points(t_point p1, t_point p5, double angle)
{
	t_koch_points	points;
	double			delta_x;
	double			delta_y;

	delta_x = p5.x - p1.x;
	delta_y = p5.y - p1.y;
	points.p2.x = p1.x + delta_x / 3;
	points.p2.y = p1.y + delta_y / 3;
	points.p4.x = p1.x + (delta_x * 2) / 3;
	points.p4.y = p1.y + (delta_y * 2) / 3;
	points.p3.x = points.p2.x + (points.p4.x - points.p2.x) * cos(angle)
		- (points.p4.y - points.p2.y) * sin(angle);
	points.p3.y = points.p2.y + (points.p4.x - points.p2.x) * sin(angle)
		+ (points.p4.y - points.p2.y) * cos(angle);
	return (points);
}

static void	koch_curve(t_fractol *f, t_point p1, t_point p5, t_koch koch)
{
	t_koch_points	points;
	int				color;

	if (f->color_mode == 0)
		color = WHITE;
	else if (f->color_mode == 1)
		color = GREEN;
	else
		color = PINK;
	if (koch.iter == 0)
	{
		draw_line_bresenham(&f->img, p1, p5, color);
		return ;
	}
	points = calc_koch_points(p1, p5, koch.koch_angle);
	koch.iter--;
	koch_curve(f, p1, points.p2, koch);
	koch_curve(f, points.p2, points.p3, koch);
	koch_curve(f, points.p3, points.p4, koch);
	koch_curve(f, points.p4, p5, koch);
}

void	render_koch(t_fractol *fractol)
{
	t_point	p1;
	t_point	p2;
	t_point	p3;
	t_koch	koch;

	mlx_clear_window(fractol->mlx_ptr, fractol->win_ptr);
	p1.x = WIN_WIDTH / 2;
	p1.y = 100;
	p2.x = 200;
	p2.y = WIN_HEIGHT - 200;
	p3.x = WIN_WIDTH - 200;
	p3.y = WIN_HEIGHT - 200;
	koch.iter = fractol->max_iter;
	koch.koch_angle = fractol->koch.koch_angle * (M_PI / 180.0);
	koch_curve(fractol, p1, p2, koch);
	koch_curve(fractol, p2, p3, koch);
	koch_curve(fractol, p3, p1, koch);
	mlx_put_image_to_window(fractol->mlx_ptr, fractol->win_ptr,
		fractol->img.img_ptr, 0, 0);
	ft_putstr("Koch rendering completed\n");
}
