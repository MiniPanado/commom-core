NAME                    = libftprintf.a

CC                      = cc
CFLAGS                  = -Wall -Wextra -Werror
CPPFLAGS                = -MMD -MP

AR                      = ar rcs
CP                      = cp
RM                      = rm -f
RMDIR                   = rm -rf
MKDIR                   = mkdir -p

LIBFT_DIR               = libft
MANDATORY_DIR           = mandatory
BONUS_DIR               = bonus
OBJS_DIR                = objs

LIBFT                   = $(LIBFT_DIR)/libft.a
MODE_FILE               = $(OBJS_DIR)/.mode

MANDATORY_HEADER        = ft_printf.h
BONUS_HEADER            = ft_printf_bonus.h

DEBUG_FLAGS             = -g3
SANITIZE_FLAGS          = -fsanitize=address,undefined -fno-omit-frame-pointer

RESET                   = \033[0m
BOLD                    = \033[1m
RED                     = \033[31m
GREEN                   = \033[32m
YELLOW                  = \033[33m
CYAN                    = \033[36m
MAGENTA                 = \033[35m

# ─────────────────────────────────────────────
# Source files (one per line: add or remove a line, nothing else)
# ─────────────────────────────────────────────

MANDATORY_FILES :=
MANDATORY_FILES += ft_printf.c
MANDATORY_FILES += ft_print_text.c
MANDATORY_FILES += ft_print_num.c
MANDATORY_FILES += ft_utils.c

BONUS_FILES :=
BONUS_FILES += ft_printf_bonus.c
BONUS_FILES += ft_parse_flags_bonus.c
BONUS_FILES += ft_handle_conversion_bonus.c
BONUS_FILES += ft_print_char_bonus.c
BONUS_FILES += ft_print_string_bonus.c
BONUS_FILES += ft_print_pointer_bonus.c
BONUS_FILES += ft_print_int_bonus.c
BONUS_FILES += ft_print_uint_bonus.c
BONUS_FILES += ft_print_hex_bonus.c
BONUS_FILES += ft_print_percent_bonus.c
BONUS_FILES += ft_assemble_bonus.c
BONUS_FILES += ft_finalize_conv_bonus.c
BONUS_FILES += ft_printf_precision_bonus.c
BONUS_FILES += ft_zero_padding_applies_bonus.c
BONUS_FILES += ft_utils_bonus.c
BONUS_FILES += ft_utils2_bonus.c

# ─────────────────────────────────────────────
# Build mode (mandatory, bonus, debug, sanitize)
# Set from the command line by the rules below, never edit by hand.
# ─────────────────────────────────────────────

MODE                    = mandatory
V                       = 0

ifeq ($(V),1)
    Q =
else
    Q = @
endif

ifeq ($(MODE),bonus)
    SRC_DIR   = $(BONUS_DIR)
    SRC_FILES = $(BONUS_FILES)
else
    SRC_DIR   = $(MANDATORY_DIR)
    SRC_FILES = $(MANDATORY_FILES)
endif

ifeq ($(MODE),debug)
    CFLAGS += $(DEBUG_FLAGS)
endif

ifeq ($(MODE),sanitize)
    CFLAGS += $(SANITIZE_FLAGS)
endif

BUILD_DIR               = $(OBJS_DIR)/$(MODE)
SRCS                    = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS                    = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS                    = $(OBJS:.o=.d)

# ─────────────────────────────────────────────
# Main
# ─────────────────────────────────────────────

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(MODE_FILE)
	@$(CP) $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJS)
	@printf "$(GREEN)$(BOLD)[ OK ]$(RESET) $(MODE) $(NAME) built successfully!\n"

bonus:
	@$(MAKE) --no-print-directory MODE=bonus $(NAME)

debug:
	@$(MAKE) --no-print-directory MODE=debug $(NAME)

sanitize:
	@$(MAKE) --no-print-directory MODE=sanitize $(NAME)

# ─────────────────────────────────────────────
# Libft
# ─────────────────────────────────────────────

$(LIBFT): FORCE
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

# ─────────────────────────────────────────────
# Mode tracking (rewritten only when the mode changes)
# ─────────────────────────────────────────────

$(MODE_FILE): FORCE
	@$(MKDIR) $(OBJS_DIR)
	@echo "$(MODE)" | cmp -s - $@ || echo "$(MODE)" > $@

FORCE:

# ─────────────────────────────────────────────
# Objects
# ─────────────────────────────────────────────

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(MKDIR) $(dir $@)
	@printf "$(CYAN)[CC %-9s]$(RESET) %-42s" "$(MODE)" "$<"
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) -I$(SRC_DIR) -I$(LIBFT_DIR) -c $< -o $@
	@printf "$(GREEN)OK$(RESET)\n"

# ─────────────────────────────────────────────
# Project checks
# ─────────────────────────────────────────────

check:
	@printf "\n$(BOLD)$(CYAN)Checking project files...$(RESET)\n\n"
	@status=0; \
	for file in $(LIBFT_DIR)/Makefile $(LIBFT_DIR)/libft.h \
		$(MANDATORY_DIR)/$(MANDATORY_HEADER) \
		$(BONUS_DIR)/$(BONUS_HEADER) \
		$(addprefix $(MANDATORY_DIR)/,$(MANDATORY_FILES)) \
		$(addprefix $(BONUS_DIR)/,$(BONUS_FILES)); do \
		if [ -f "$$file" ]; then \
			printf "$(GREEN)[ OK ]$(RESET) %s\n" "$$file"; \
		else \
			printf "$(RED)[FAIL]$(RESET) missing %s\n" "$$file"; \
			status=1; \
		fi; \
	done; \
	if [ $$status -eq 0 ]; then \
		printf "\n$(GREEN)$(BOLD)Project structure looks good ✓$(RESET)\n\n"; \
	fi; \
	exit $$status

# ─────────────────────────────────────────────
# Norminette
# ─────────────────────────────────────────────

norm:
	@if command -v norminette >/dev/null 2>&1; then \
		printf "$(CYAN)Running Norminette...$(RESET)\n\n"; \
		norminette -R CheckForbiddenSourceHeader; \
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
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Mandatory files:" "$(words $(MANDATORY_FILES))"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Bonus files:" "$(words $(BONUS_FILES))"
	@printf "$(BOLD)%-20s$(RESET) %s\n" "Libft directory:" "$(LIBFT_DIR)"
	@printf "$(BOLD)%-20s$(RESET) %s\n\n" "Object directory:" "$(OBJS_DIR)"

# ─────────────────────────────────────────────
# Cleaning
# ─────────────────────────────────────────────

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@$(RMDIR) $(OBJS_DIR)
	@printf "$(YELLOW)[CLEAN]$(RESET) objects and dependencies removed\n"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@$(RM) $(NAME)
	@printf "$(YELLOW)[FCLEAN]$(RESET) $(NAME) removed\n"

re: fclean
	@$(MAKE) --no-print-directory all

rebonus: fclean
	@$(MAKE) --no-print-directory bonus

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
	@printf "  $(GREEN)make rebonus$(RESET)       Rebuild bonus\n"
	@printf "  $(GREEN)make V=1 <rule>$(RESET)    Show the full compiler commands\n"
	@printf "  $(GREEN)make help$(RESET)          Show this help\n\n"

# ─────────────────────────────────────────────
# Dependencies
# ─────────────────────────────────────────────

-include $(DEPS)

.PHONY: all bonus debug sanitize check norm info clean fclean re rebonus help FORCE
