APP_NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = inc/libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR = inc
INC = -I$(INC_DIR) -I$(LIBFT_DIR)
SRC_DIR = src
OBJ_DIR = obj
RM = rm -rf

SRCS = \
	main.c\
	push_swap.c\
	check_parsing/check_parsing.c\
	check_parsing/check_parsing_utils.c\
	moves/s_moves.c\
	moves/p_moves.c\
	moves/r_moves.c\
	moves/rr_moves.c\
	moves/utils_moves.c\
	stack/init_stack.c\
	stack/init_target.c\
	stack/stack.c\
	sort/sort_stack.c\
	sort/sort_stack_utils.c
SRC = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: logo $(APP_NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(APP_NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT) $(INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "🧹 Cleaned up object files."

fclean: clean
	@$(RM) $(APP_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "🗑️ Cleaned up all files."

re: fclean all

logo:
	@echo "\033[38;5;196m██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗\033[0m"
	@echo "\033[38;5;202m██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\033[0m"
	@echo "\033[38;5;208m██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\033[0m"
	@echo "\033[38;5;214m██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \033[0m"
	@echo "\033[38;5;220m██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \033[0m"
	@echo "\033[38;5;226m╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     \033[0m"
	@echo "                                                                            "

.PHONY: fclean re all clean logo
