NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -Iincludes
AR = ar rcs
RM = rm -f

SRCS_DIR = srcs
SRC_NAMES = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
			ft_isdigit ft_isprint ft_memchr ft_memcmp ft_memcpy ft_memmove \
			ft_memset ft_strchr ft_strdup ft_strlcat ft_strlcpy ft_strlen \
			ft_strncmp ft_strnstr ft_strrchr ft_tolower ft_toupper
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(SRC_NAMES)))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
