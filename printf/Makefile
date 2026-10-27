NAME			= libftprintf.a

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
CPPFLAGS		= -MMD -MP

AR				= ar rcs
RM				= rm -f
RMDIR			= rm -rf
MKDIR			= mkdir -p

MANDATORY_DIR	= mandatory
BONUS_DIR		= bonus
OBJS_DIR		= objs

MANDATORY_HEADER	= ft_printf.h
BONUS_HEADER		= ft_printf_bonus.h

MANDATORY_SRCS	= \
	$(MANDATORY_DIR)/ft_printf.c \
	$(MANDATORY_DIR)/ft_handle_conversion.c \
	$(MANDATORY_DIR)/ft_print_char.c \
	$(MANDATORY_DIR)/ft_print_string.c \
	$(MANDATORY_DIR)/ft_print_pointer.c \
	$(MANDATORY_DIR)/ft_print_int.c \
	$(MANDATORY_DIR)/ft_print_uint.c \
	$(MANDATORY_DIR)/ft_print_hex.c \
	$(MANDATORY_DIR)/ft_print_percent.c \
	$(MANDATORY_DIR)/ft_utils.c

BONUS_SRCS		= \
	$(BONUS_DIR)/ft_printf_bonus.c \
	$(BONUS_DIR)/ft_parse_flags_bonus.c \
	$(BONUS_DIR)/ft_handle_conversion_bonus.c \
	$(BONUS_DIR)/ft_print_char_bonus.c \
	$(BONUS_DIR)/ft_print_string_bonus.c \
	$(BONUS_DIR)/ft_print_pointer_bonus.c \
	$(BONUS_DIR)/ft_print_int_bonus.c \
	$(BONUS_DIR)/ft_print_uint_bonus.c \
	$(BONUS_DIR)/ft_print_hex_bonus.c \
	$(BONUS_DIR)/ft_print_percent_bonus.c \
	$(BONUS_DIR)/ft_assemble_bonus.c \
	$(BONUS_DIR)/ft_finalize_conv_bonus.c \
	$(BONUS_DIR)/ft_printf_precision_bonus.c \
	$(BONUS_DIR)/ft_zero_padding_applies_bonus.c \
	$(BONUS_DIR)/ft_utils_bonus.c \
	$(BONUS_DIR)/ft_utils2_bonus.c

MANDATORY_OBJS	= $(MANDATORY_SRCS:$(MANDATORY_DIR)/%.c=$(OBJS_DIR)/mandatory/%.o)
BONUS_OBJS		= $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(OBJS_DIR)/bonus/%.o)
DEBUG_OBJS		= $(MANDATORY_SRCS:$(MANDATORY_DIR)/%.c=$(OBJS_DIR)/debug/%.o)
SANITIZE_OBJS	= $(MANDATORY_SRCS:$(MANDATORY_DIR)/%.c=$(OBJS_DIR)/sanitize/%.o)

MANDATORY_DEPS	= $(MANDATORY_OBJS:.o=.d)
BONUS_DEPS		= $(BONUS_OBJS:.o=.d)
DEBUG_DEPS		= $(DEBUG_OBJS:.o=.d)
SANITIZE_DEPS	= $(SANITIZE_OBJS:.o=.d)

DEBUG_FLAGS		= -g3
SANITIZE_FLAGS	= -fsanitize=address,undefined -fno-omit-frame-pointer

RESET			= \033[0m
BOLD			= \033[1m
RED				= \033[31m
GREEN			= \033[32m
YELLOW			= \033[33m
CYAN			= \033[36m
MAGENTA			= \033[35m

# ─────────────────────────────────────────────
# Main
# ─────────────────────────────────────────────

all: mandatory

mandatory: $(MANDATORY_OBJS)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(MANDATORY_OBJS)
	@printf "$(GREEN)$(BOLD)[ OK ]$(RESET) mandatory $(NAME) built successfully!\n"

bonus: $(BONUS_OBJS)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(BONUS_OBJS)
	@printf "$(MAGENTA)$(BOLD)[ OK ]$(RESET) bonus $(NAME) built successfully!\n"

# ─────────────────────────────────────────────
# Mandatory
# ─────────────────────────────────────────────

$(OBJS_DIR)/mandatory/%.o: $(MANDATORY_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(CYAN)[CC]$(RESET) %-45s" "$<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -I$(MANDATORY_DIR) -c $< -o $@
	@printf "$(GREEN)OK$(RESET)\n"

# ─────────────────────────────────────────────
# Bonus
# ─────────────────────────────────────────────

$(OBJS_DIR)/bonus/%.o: $(BONUS_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(MAGENTA)[CC BONUS]$(RESET) %-38s" "$<"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -I$(BONUS_DIR) -c $< -o $@
	@printf "$(GREEN)OK$(RESET)\n"

# ─────────────────────────────────────────────
# Debug
# ─────────────────────────────────────────────

debug: $(DEBUG_OBJS)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(DEBUG_OBJS)
	@printf "$(GREEN)$(BOLD)[ DEBUG ]$(RESET) $(NAME) built with debug symbols!\n"

$(OBJS_DIR)/debug/%.o: $(MANDATORY_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(CYAN)[CC DEBUG]$(RESET) %-40s" "$<"
	@$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(CPPFLAGS) -I$(MANDATORY_DIR) -c $< -o $@
	@printf "$(GREEN)OK$(RESET)\n"

# ─────────────────────────────────────────────
# Sanitizer
# ─────────────────────────────────────────────

sanitize: $(SANITIZE_OBJS)
	@$(RM) $(NAME)
	@$(AR) $(NAME) $(SANITIZE_OBJS)
	@printf "$(GREEN)$(BOLD)[ SANITIZE ]$(RESET) $(NAME) built with sanitizers!\n"

$(OBJS_DIR)/sanitize/%.o: $(MANDATORY_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(CYAN)[CC SANITIZE]$(RESET) %-36s" "$<"
	@$(CC) $(CFLAGS) $(SANITIZE_FLAGS) $(CPPFLAGS) -I$(MANDATORY_DIR) -c $< -o $@
	@printf "$(GREEN)OK$(RESET)\n"

# ─────────────────────────────────────────────
# Project checks
# ─────────────────────────────────────────────

check:
	@printf "\n$(BOLD)$(CYAN)Checking project files...$(RESET)\n\n"
	@if [ ! -f "$(MANDATORY_DIR)/$(MANDATORY_HEADER)" ]; then \
		printf "$(RED)[FAIL]$(RESET) missing $(MANDATORY_DIR)/$(MANDATORY_HEADER)\n"; \
		exit 1; \
	fi
	@printf "$(GREEN)[ OK ]$(RESET) $(MANDATORY_DIR)/$(MANDATORY_HEADER)\n"
	@if [ ! -f "$(BONUS_DIR)/$(BONUS_HEADER)" ]; then \
		printf "$(RED)[FAIL]$(RESET) missing $(BONUS_DIR)/$(BONUS_HEADER)\n"; \
		exit 1; \
	fi
	@printf "$(GREEN)[ OK ]$(RESET) $(BONUS_DIR)/$(BONUS_HEADER)\n"
	@if [ -z "$(MANDATORY_SRCS)" ]; then \
		printf "$(RED)[FAIL]$(RESET) no mandatory source files found\n"; \
		exit 1; \
	fi
	@printf "$(GREEN)[ OK ]$(RESET) mandatory sources\n"
	@if [ -z "$(BONUS_SRCS)" ]; then \
		printf "$(RED)[FAIL]$(RESET) no bonus source files found\n"; \
		exit 1; \
	fi
	@printf "$(GREEN)[ OK ]$(RESET) bonus sources\n"
	@printf "\n$(GREEN)$(BOLD)Project structure looks good ✓$(RESET)\n\n"

# ─────────────────────────────────────────────
# Norminette
# ─────────────────────────────────────────────

norm:
	@if command -v norminette >/dev/null 2>&1; then \
		printf "$(CYAN)Running Norminette...$(RESET)\n\n"; \
		norminette $(MANDATORY_DIR) $(BONUS_DIR); \
	else \
		printf "$(YELLOW)[WARN]$(RESET) Norminette is not installed.\n"; \
	fi

# ─────────────────────────────────────────────
# Information
# ─────────────────────────────────────────────

info:
	@printf "\n$(BOLD)$(CYAN)╔══════════════════════════════════════════╗$(RESET)\n"
	@printf "$(BOLD)$(CYAN)║          ft_printf BUILD INFO            ║$(RESET)\n"
	@printf "$(BOLD)$(CYAN)╚══════════════════════════════════════════╝$(RESET)\n\n"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Name:" "$(NAME)"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Compiler:" "$(CC)"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Flags:" "$(CFLAGS)"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Mandatory header:" "$(MANDATORY_HEADER)"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Bonus header:" "$(BONUS_HEADER)"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Mandatory files:" "$(words $(MANDATORY_SRCS))"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Bonus files:" "$(words $(BONUS_SRCS))"
	@printf "$(BOLD)%-20s$(RESET) %s\n\n" "Object directory:" "$(OBJS_DIR)"

# ─────────────────────────────────────────────
# Cleaning
# ─────────────────────────────────────────────

clean:
	@$(RMDIR) $(OBJS_DIR)
	@printf "$(YELLOW)[CLEAN]$(RESET) objects and dependencies removed\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)[FCLEAN]$(RESET) $(NAME) removed\n"

re: fclean all

# ─────────────────────────────────────────────
# Help
# ─────────────────────────────────────────────

help:
	@printf "\n$(BOLD)$(CYAN)╔══════════════════════════════════════════╗$(RESET)\n"
	@printf "$(BOLD)$(CYAN)║          ft_printf MAKE HELP             ║$(RESET)\n"
	@printf "$(BOLD)$(CYAN)╚══════════════════════════════════════════╝$(RESET)\n\n"
	@printf "  $(GREEN)make$(RESET)               Build mandatory\n"
	@printf "  $(GREEN)make bonus$(RESET)         Build bonus\n"
	@printf "  $(GREEN)make debug$(RESET)         Debug build (-g3)\n"
	@printf "  $(GREEN)make sanitize$(RESET)      Address/UB sanitizer build\n"
	@printf "  $(GREEN)make check$(RESET)         Check project structure\n"
	@printf "  $(GREEN)make norm$(RESET)          Run Norminette\n"
	@printf "  $(GREEN)make info$(RESET)          Show build information\n"
	@printf "  $(GREEN)make clean$(RESET)         Remove objects/dependencies\n"
	@printf "  $(GREEN)make fclean$(RESET)        Remove objects + library\n"
	@printf "  $(GREEN)make re$(RESET)            Rebuild mandatory\n"
	@printf "  $(GREEN)make help$(RESET)          Show this help\n\n"

# ─────────────────────────────────────────────
# Dependencies
# ─────────────────────────────────────────────

-include $(MANDATORY_DEPS)
-include $(BONUS_DEPS)
-include $(DEBUG_DEPS)
-include $(SANITIZE_DEPS)

.PHONY: all mandatory bonus debug sanitize check norm info clean fclean re help
