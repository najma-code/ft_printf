CC := cc
CFLAGS := -Wall -Werror -Wextra
NAME := libftprintf.a
SRC := \
	ft_printf.c \
	ft_printf_alpha_nmbr.c \
	ft_printf_nmbr.c \

OBJ := $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
