# ****************************************************************************
#                                   ft_printf
# ****************************************************************************

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
MKDIR		= mkdir -p

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS		= ft_printf.c \
			  ft_handle_conversion.c \
			  ft_print_char.c \
			  ft_print_string.c \
			  ft_print_pointer.c \
			  ft_print_int.c \
			  ft_print_uint.c \
			  ft_print_hex.c \
			  ft_print_percent.c \
			  ft_utils.c

# Acrescenta aqui os ficheiros so-de-bonus quando desenhares o parsing
# de flags/largura/precisao (ex: ft_parse_flags_bonus.c). Tem de ficar
# em ficheiros *_bonus.c, conforme pedido no subject.
BONUS_SRCS	=

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
BONUS_OBJS	= $(addprefix $(OBJS_DIR)/, $(BONUS_SRCS:.c=.o))

INCLUDES	= -I.

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: CFLAGS += -DBONUS
bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c ft_printf.h | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
