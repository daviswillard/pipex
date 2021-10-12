NAME = pipex
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = ./sources/pipex.c ./sources/reading.c \
		./sources/get_func.c ./sources/main.c \
		./sources/filename.c
# BNS_SRCS =
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	$(MAKE) all -sC $(LIB_DIR)
	gcc $(CFLAGS) -I. $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME)
bonus: $(NAME)
re: fclean all
.PHONY: all clean fclean re bonus
-include	$(OBJS:.o=.d)
