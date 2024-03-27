# Compiler and flags
CC = cc
CFLAGS = -Werror -Wextra -Wall -g

# Name
NAME = push_swap

# Dir
SRC_DIR = .
UTILS_DIR = utils
OBJ_DIR = $(UTILS_DIR)

# Source files
SRC_FILES = push_swap.c
UTILS_FILES = checks.c  ft_atol.c   lf_node.c  node_rotation2.c  node_setter.c \
			   push.c    sort.c		sturct_tools.c errors.c  ft_split.c \
			   my_free.c  node_rotation.c   push_and_set.c  rotate.c  struct_creation.c \
			   swap.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(UTILS_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))


# Rules
all: $(NAME)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^
	# @echo "⬜🟥🟥🟥🟥⬜⬜⬜"
	# @echo "🟥🟥🟥🟥🟥🟥🟥🟥"
	# @echo "🟫🟫🟫🟧🟫🟧⬜⬜"
	# @echo "🟧🟫🟧🟧🟫🟧🟧🟧"
	# @echo "🟧🟫🟫🟧🟧🟫🟧🟧"
	# @echo "⬜🟧🟧🟧🟫🟫🟫⬜ YOUR PIPE(X) IS READY"
	# @echo "⬜⬜🟧🟧🟧🟧⬜⬜"
	# @echo "⬜🟫🟥🟫🟫🟥🟫⬜"
	# @echo "🟫🟫🟥🟫🟫🟥🟫🟫"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

