# ft_printf
![C Language](https://img.shields.io/badge/language-C-blue.svg)
![Status](https://img.shields.io/badge/status-finished-brightgreen)
![42 100/100](https://img.shields.io/badge/42-100%2F100-gree?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-lightgrey)
-
##  🧠 ft_printf

A ft_printf consiste em reimplementação da função `printf` da biblioteca C.  
💡 Isso permite entender a lógica e os algoritmos por trás das funções da biblioteca padrão do C.

---

## 📚 Conteúdo

- **Recriar o comportamento da função:** `printf`.
- **Suportar os especificadores:** `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` e `%%`.
---

## 🧱 Estrutura da ft_printf

- Ficheiro ft_printf.h com as declarações das funções.
- Makefile para compilar a biblioteca (libftprintf.a).
- Os ficheiros *.c implementam a lógica da formatação e impressão.

## 🛠️ Compilação

Para compilar a biblioteca, basta usar o `Makefile`:

```bash
make            # Compila libftprintf.a
make clean      # Remove os ficheiros objetos (.o)
make fclean     # Remove os ficheiros objetos e libftprintf.a
make re         # Limpa e recompila tudo
```
## 📁 Estrutura do Projeto

```bash
ft_printf/
├── ft_printf.c         # Função principal ft_printf
├── utils/              # Funções auxiliares para formatação e escrita
│   ├── ft_putchar.c
│   ├── ft_puthex.c
│   ├── ft_putnbr.c
│   ├── ft_putptr.c
│   ├── ft_putstr.c
│   └── ft_putuint.c
├── ft_printf.h         # Header com todas as declarações
├── Makefile            # Para compilar a biblioteca
└── libftprintf.a       # Arquivo gerado com as funções compiladas, criado via Makefile
```
## 🧪 Testes

Testers externos
- [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
- [printf-tester](https://github.com/Tripouille/printfTester)
- [francinette](https://github.com/xicodomingues/francinette)
---
👩‍💻 Autora
Samiris Santos — [LinkedIn](https://www.linkedin.com/in/samiris-santos/)