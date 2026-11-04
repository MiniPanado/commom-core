This project has been created as part of the 42 curriculum by lucerque

“Description”

O projeto libft consiste no desenvolvimento de uma biblioteca própria em linguagem C, recriando diversas funções da biblioteca padrão do C (Libc), bem como implementando funções adicionais para manipulação de strings, memória e listas ligadas.

O principal objetivo é compreender melhor o funcionamento das funções fundamentais da linguagem C, desenvolver competências de programação e aprofundar conhecimentos sobre gestão de memória, ponteiros e estruturas de dados.

Esta biblioteca serve como uma base reutilizável para projetos futuros, permitindo utilizar funções desenvolvidas e testadas pelo próprio programador, sem depender diretamente das implementações da biblioteca padrão.

“Instructions”

make

cc main.c -L. -lft -I.

make clean   # Remove os ficheiros objeto (.o)
make fclean  # Remove os ficheiros objeto e a biblioteca libft.a
make re      # Limpa e recompila o projeto

“Resources”

A detailed description of the library created for this project must also be included.

Descrição detalhada da biblioteca
A libft é uma biblioteca desenvolvida em linguagem C que reúne um conjunto de funções recriadas a partir da biblioteca padrão do C (Libc), juntamente com funções adicionais criadas para facilitar a manipulação de dados.

O objetivo principal é compreender e implementar, de forma autónoma, algumas das funcionalidades fundamentais da linguagem C, aprofundando conhecimentos sobre ponteiros, arrays, strings, alocação dinâmica de memória e estruturas de dados.

A biblioteca está organizada em diferentes categorias de funções:

1. Funções de verificação de caracteres
Funções utilizadas para identificar e verificar diferentes tipos de caracteres.

ft_isalpha: verifica se um carácter é uma letra.

ft_isdigit: verifica se um carácter é um número.

ft_isalnum: verifica se um carácter é alfanumérico.

ft_isascii: verifica se um carácter pertence à tabela ASCII.

ft_isprint: verifica se um carácter é imprimível.

2. Funções de manipulação de strings
Funções que permitem trabalhar com strings, incluindo a sua análise, comparação e manipulação.

ft_strlen: calcula o comprimento de uma string.

ft_strlcpy: copia uma string com controlo do tamanho.

ft_strlcat: concatena strings com controlo do tamanho.

ft_strchr: procura a primeira ocorrência de um carácter.

ft_strrchr: procura a última ocorrência de um carácter.

ft_strncmp: compara duas strings.

ft_strnstr: procura uma substring dentro de outra string.

ft_strdup: duplica uma string através de alocação dinâmica de memória.

ft_substr: extrai uma substring.

ft_strjoin: junta duas strings.

ft_strtrim: remove caracteres definidos do início e do fim de uma string.

ft_split: divide uma string em várias strings utilizando um delimitador.

ft_strmapi: aplica uma função a cada carácter de uma string.

ft_striteri: aplica uma função a cada carácter, permitindo modificar a string original.

3. Funções de manipulação de memória
Funções destinadas à gestão e manipulação de blocos de memória.

ft_memset: preenche uma área de memória com um determinado valor.

ft_bzero: coloca uma área de memória a zero.

ft_memcpy: copia dados entre áreas de memória.

ft_memmove: copia dados entre áreas de memória, permitindo sobreposição.

ft_memchr: procura um determinado valor numa área de memória.

ft_memcmp: compara duas áreas de memória.

ft_calloc: reserva memória dinâmica e inicializa-a a zero.

4. Funções de conversão e escrita
Funções utilizadas para converter valores e apresentar informação.

ft_atoi: converte uma string num número inteiro.

ft_itoa: converte um número inteiro numa string.

ft_putchar_fd: escreve um carácter num determinado file descriptor.

ft_putstr_fd: escreve uma string num determinado file descriptor.

ft_putendl_fd: escreve uma string seguida de uma quebra de linha.

ft_putnbr_fd: escreve um número inteiro num determinado file descriptor.

5. Manipulação de listas ligadas (Linked Lists)
A biblioteca inclui também funções para criar e manipular listas ligadas, permitindo armazenar e gerir conjuntos de elementos de forma dinâmica.

ft_lstnew: cria um novo elemento da lista.

ft_lstadd_front: adiciona um elemento no início da lista.

ft_lstsize: calcula o número de elementos da lista.

ft_lstlast: devolve o último elemento da lista.

ft_lstadd_back: adiciona um elemento no final da lista.

ft_lstdelone: elimina um elemento da lista.

ft_lstclear: elimina todos os elementos de uma lista.

ft_lstiter: aplica uma função a cada elemento da lista.

ft_lstmap: cria uma nova lista através da aplicação de uma função aos elementos da lista original.

Conclusão
A libft representa uma base fundamental para o desenvolvimento de projetos futuros em C. Através da implementação destas funções, é possível compreender melhor o funcionamento interno das operações da linguagem, desenvolver boas práticas de programação e ganhar autonomia na gestão de memória e manipulação de dados.
