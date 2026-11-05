*This project has been created as part of the 42 curriculum by lucerque.*

# Libft

## Description

Libft is my first own C library. It gathers general-purpose functions that I will reuse in future 42 projects. The goal is to understand how common standard library functions work by reimplementing them myself, while practicing pointers, memory management, string manipulation and linked lists.

The project compiles into a static library called `libft.a`, and its public declarations are available in `libft.h`.

## Library Overview

The library is organized in three parts, following the subject.

### Part 1 — Libc functions

Reimplementations of standard functions, using the `ft_` prefix and following the behavior described in their `man` pages:

- **Character classification and conversion:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.
- **Memory operations:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`.
- **String operations:** `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`.
- **Conversion and allocation:** `ft_atoi`, `ft_calloc`, `ft_strdup`.

### Part 2 — Additional functions

Functions that are not in the libc, or exist in a different form:

- **`ft_substr`, `ft_strjoin`, `ft_strtrim`:** extract a substring, concatenate two strings, and remove a set of characters from both ends of a string.
- **`ft_split`:** splits a string using a delimiter character and returns a `NULL`-terminated array of strings.
- **`ft_itoa`:** converts an integer to a string, including negative numbers.
- **`ft_strmapi`, `ft_striteri`:** apply a function to each character, creating a new string or modifying the original one.
- **`ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`:** write a character, a string, a string followed by a newline, or an integer to a file descriptor.

All results returned by these functions are allocated with `malloc` and must be freed by the caller. For `ft_split`, each string must be freed first, and then the array itself.

### Part 3 — Linked lists

These functions work on the `t_list` structure, whose nodes hold a `content` pointer and a `next` pointer:

- **`ft_lstnew`:** creates a new node.
- **`ft_lstadd_front`, `ft_lstadd_back`:** add a node at the beginning or at the end of the list.
- **`ft_lstsize`, `ft_lstlast`:** return the number of nodes and the last node.
- **`ft_lstdelone`, `ft_lstclear`:** delete one node or a whole list, using a callback to free the content.
- **`ft_lstiter`, `ft_lstmap`:** apply a function to the content of each node, either in the same list or while creating a new one.

## Function Reference

Part 1 functions keep the same prototype as the original libc function, only with the `ft_` prefix and without `restrict`. Prototypes of Parts 2 and 3:

```c
/* Part 2 */
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s1, char const *set);
char    **ft_split(char const *s, char c);
char    *ft_itoa(int n);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

/* Part 3 */
t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new);
unsigned int ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

The `t_list` structure is declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

## Instructions

### Requirements

- A C compiler available as `cc`
- `make`
- `ar`

### Compilation

Run the following command at the root of the repository:

```sh
make
```

This creates `libft.a`. All source files are compiled with `-Wall -Wextra -Werror`.

Other available rules:

```sh
make clean   # Removes the object files (.o)
make fclean  # Removes the object files and libft.a
make re      # Cleans everything and recompiles
```

### Installation

There is no installation step. `libft.a` is a static library that is linked into your program at compile time.

### Usage

Include the header in your program:

```c
#include "libft.h"
```

Then compile and link it with the library. For a `main.c` at the root of the repository:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o example
./example
```

`main.c` is your own program that uses the library; `libft.a` cannot be executed by itself.

## Technical Choices

- No global variables.
- Helper functions used to break down complex functions are declared `static`, so their scope stays limited to their file.
- The library is created with `ar` (`libtool` is forbidden by the subject) and `libft.a` is placed at the root of the repository.
- The `restrict` qualifier is not used in the prototypes, and the code is not compiled with `-std=c99`, as required by the subject.
- The Makefile does not relink unnecessarily.

## Project Structure

All files are at the root of the repository, as required by the subject:

```
.
├── Makefile      # rules: $(NAME), all, clean, fclean, re
├── libft.h       # prototypes and the t_list structure
├── ft_*.c        # one source file per function
└── README.md
```

## Behavior Notes

Some behaviors required by the subject that are worth knowing when using the library:

- **Character classification** (`ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`) returns `1` if the character matches and `0` otherwise.
- **`ft_calloc`:** if `nmemb` or `size` is `0`, it returns a unique pointer that can be safely passed to `free()`.
- **`ft_split`:** returns `NULL` if any allocation fails, and the returned array is `NULL`-terminated.
- **`ft_lstdelone`:** frees the content and the node itself, but not the next node.
- **`ft_lstclear`:** frees the given node and all its successors, then sets the list pointer to `NULL`.
- **Memory:** every function that allocates memory returns `NULL` on allocation failure, and the caller is responsible for freeing the result.
- **Comparing with the system versions:** `strlcpy`, `strlcat` and `bzero` are not in glibc by default. To compare against them, include `<bsd/string.h>` and compile with `-lbsd`.

## Norm

All files follow the 42 Norm and compile with `-Wall -Wextra -Werror`.

## Testing

I tested the functions by writing a small `main` for each exercise, comparing the result with the original libc function whenever one exists. I skipped this for the simplest functions, such as `ft_strlen` and `ft_putchar_fd`. These tests are not part of the submission.

## Resources

### Documentation and references

- `man 3` pages of the reimplemented functions (e.g. `man 3 strlen`, `man 3 memmove`, `man 3 calloc`) — to understand the exact behavior, return values and edge cases of each function.
- 42 documentation (project subject and the Norm) — for requirements, allowed functions and coding style.
- *Linguagem C*, by Luís Damas (24th edition) — book used to study C fundamentals.
- [The Ultimate Guide to Structs in C](https://medium.com/@adithyaravichandran11/the-ultimate-guide-to-structs-in-c-from-beginner-to-pro-b62157d21c73) — to understand structs, which helped me start the linked list part.
- [cppreference — atoi](https://en.cppreference.com/c/string/byte/atoi) — to research which `atoi` cases are undefined behavior and which are not.
- [Abdul Bari](https://www.youtube.com/@abdul_bari) (YouTube) — video explanations of programming and data structure concepts.
- Peer learning with other 42 students — discussing approaches and edge cases.
- Python Tutor — to visualize step by step how code runs.

### AI usage

AI was used as a learning and review aid. I always tried to reason through each problem and debug on my own first (with Python Tutor or by debugging my own code) before asking AI. These were the tasks:

- **Learning concepts:** explanations of new concepts I did not understand yet.
- **Debugging and understanding:** to understand my own bugs and behaviors better, after trying to debug them myself first.
- **Alternative approaches:** to see other ways of solving a function.
- **Code quality:** suggestions to optimize and to choose better variable and function names.
- **Tests:** to generate long but easy and repetitive test files, avoiding repetition. I wrote my own tests for each exercise (see **Testing**) and, before submitting, I asked AI to run one more round of tests.
- **Gathering information:** to collect information from different websites in one place. I always verified that the information was correct.
