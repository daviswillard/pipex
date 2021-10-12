NAME = pipex
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = sources/pipex.c sources/reading.c \
		sources/get_func.c  sources/main.c \
		sources/filename.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  lib $(NAME)
lib:
	$(MAKE) all -sC $(LIB_DIR)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	gcc $(CFLAGS) -I. $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all lib clean fclean re
-include	$(OBJS:.o=.d)
