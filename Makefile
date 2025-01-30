NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = algo_utils.c push.c push_swap.c rotate.c sort_alg.c stack_utils.c extra_function.c swap.c utils.c check_input.c  lib.c rotate_2.c more_func.c
SRCBONUS = bonus_part/checker_bonus.c \
	   bonus_part/check_input_bonus.c \
	   bonus_part/get_next_line_bonus.c \
	   bonus_part/push_bonus.c \
	   bonus_part/rotate_bonus.c \
	   bonus_part/stack_utils_bonus.c \
	   bonus_part/swap_bonus.c \
	   bonus_part/utils_bonus.c \
	   bonus_part/lib_bonus.c \
	   bonus_part/extra_function_bonus.c \
	   bonus_part/rotate_2_bonus.c \

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJBONUS)
	$(CC) $(CFLAGS) $(OBJBONUS) -o $(BONUS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJBONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
