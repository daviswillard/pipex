NAME = pipex
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = ./sources/pipex.c ./sources/reading.c \
		./sources/get_func.c ./sources/main.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) all -sC $(LIB_DIR)
	$(MAKE) bonus -sC $(LIB_DIR)
$(NAME): $(OBJS) $(LIBFT)
	gcc $(CFLAGS) -I. -L$(LIB_DIR) -lft  -o $(NAME)
clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(NAME)
	rm -rf pipex
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)
