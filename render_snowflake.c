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

*/

// Implementação do algoritmo de Bresenham para desenhar uma linha
void	draw_line(t_img *img, t_point p1, t_point p2, int color)
{


}
/*
p1: ponto inicial, p5: ponto final
angle: angulo do pico do triangulo,ex: 60° = pi/3 radianos
iter: numero de interação
*/
static void koch_curve(t_fractol *f, t_point p1, t_point p5, int iter, double angle)
{
	t_point p2;
	t_point p3;
	t_point p4;
	// 1 - Iniciador
	if (iter == 0)
	{
		draw_line(&f->img, p1, p5, WHITE);
		return ;
	}
	//2 - Gerador
	// Divida o segmento em três partes iguais.
	// Calcula os 3 pontos intermediários
	f->koch.delta_x = p5.x - p1.x;
	f->koch.delta_y = p5.y - p1.y;
	// um terço do caminho
	p2.x = p1.x + f->koch.delta_x / 3;
	p2.y = p1.y + f->koch.delta_y / 3;
	// dois terço do caminho
	p4.x = p1.x + (f->koch.delta_x * 2) / 3;
	p4.y = p1.y + (f->koch.delta_y * 2) / 3;

	// Ponto do pico (p3), calculado rotacionando o vetor (p2 -> p4)
	// em torno de p2 pelo ângulo fornecido.
	// A matemática de rotação é: 
	//x' = x*cos(a) - y*sin(a); y' = x*sin(a) + y*cos(a)
	p3.x = p2.x + (p4.x - p2.x) * cos(angle) - (p4.y - p2.y) * sin(angle);
	p3.y = p2.y + (p4.x - p2.x) * sin(angle) + (p4.y - p2.y) * cos(angle);

	//3 - Recursão para os 4 novos segmentos ate iter = 0;
	draw_koch_curve(f, p1, p2, iter - 1, angle);
	draw_koch_curve(f, p2, p3, iter - 1, angle);
	draw_koch_curve(f, p3, p4, iter - 1, angle);
	draw_koch_curve(f, p4, p5, iter - 1, angle);
}

void	render_koch(t_fractol *fractol)
{

}