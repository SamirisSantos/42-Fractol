# fractol
![C Language](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-finished-brightgreen)
![42 125/100](https://img.shields.io/badge/42-125%2F100-gree?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
-

O **Fractol** é um projeto da [42 School](https://www.42porto.com/pt/) que tem como objetivo explorar fractais e a matemática por trás deles, utilizando a MiniLibX para renderização gráfica em C.
O programa visualiza fractais famosos Mandelbrot e Julia, com interação em tempo real através de teclado e mouse (zoom, movimento e mudança de cores).

## 📖 Sobre o Projeto 
Este projeto é uma forma de consolidar conhecimentos sobre:

- Aritmética com números complexos
- Algoritmos de renderização
- Manipulação de imagens com a [MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx.html)
- Interatividade gráfica com eventos de teclado e rato

No bônus eu implementei o fractal Koch Snowflake (Floco de Neve de Koch).

---

## ✨ Funcionalidades  
- Renderização dos fractais Mandelbrot e Julia
- Suporte a zoom in/out com o mouse 
- Movimentação no plano com setas do teclado
- Vários modos de cor
	- No meu projeto minhas mudanças de cores fiz via teclado, teclas I O e P
- Encerramento seguro com tecla ESC ou botão de fechar da janela

## 🌀 Fractais Implementados  

### Mandelbrot  
Fórmula:  Z(n+1) = Z(n)^2 + C e Z0 = 0

Um ponto **C** pertence ao conjunto se a sequência **não tende ao infinito**.  

### Julia  
Fórmula:  Z(n+1) = Z(n)^2 + C | C é fixo

```bash
#Os valores de c real e c imaginario eram fornecido pelo usario via terminal
exemplo:
./fractol julia -0.3740 -0.6597
```

### Koch Snowflake (*Bônus*)  
O **Floco de Neve de Koch** é um fractal gerado recursivamente a partir de um triângulo equilátero.  
- Cada segmento é dividido em 3 partes iguais.  
- O segmento do meio é substituído por dois que formam um triângulo equilátero.  
- O processo repete-se em cada iteração.  

Este fractal cria uma forma semelhante a um floco de neve infinito, com perímetro crescente e área finita.  
No código, foi implementado com:  
- Estrutura `t_koch` para gerir iterações, escala e ângulos.  
- Algoritmo de **Bresenham** para desenhar as linhas.

## 🎮 Controles  

### Teclado  
- `ESC` → Sair  
- `← ↑ ↓ →` ou `W A S D` → Navegação no plano  
- `+ / -` → Alterar definição da imagem (iterações)  
- `O / P / I` → Alternar esquemas de cores  

### Mouse  
- Scroll **para cima** → Zoom in  
- Scroll **para baixo** → Zoom out  


---
👩‍💻 Autora

Samiris Santos — [LinkedIn](https://www.linkedin.com/in/samiris-santos/)
