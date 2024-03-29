# Compiler and flags
CC = cc
CFLAGS = -Werror -Wextra -Wall -g

# Name
NAME = push_swap
BONUS_NAME = checker

# Dir
SRC_DIR = .
UTILS_DIR = utils
OBJ_DIR = $(UTILS_DIR)

# Source files
SRC_FILES = push_swap.c
BONUS_FILES = checker.c
UTILS_FILES = checks.c  ft_atol.c   lf_node.c  node_rotation2.c  node_setter.c \
			   push.c    sort.c		struct_tools.c errors.c  ft_split.c \
			   my_free.c  node_rotation.c   push_and_set.c  rotate.c  struct_creation.c \
			   swap.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o) $(UTILS_FILES:.c=.o)
BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o) $(UTILS_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC = $(addprefix $(SRC_DIR)/, $(BONUS_FILES))
UTILS = $(addprefix $(UTILS_DIR)/, $(UTILS_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJ_FILES))

# Rules
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all bonus

.PHONY: all bonus clean fclean re

