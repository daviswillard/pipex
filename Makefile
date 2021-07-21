NAME = pipex.a
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD
SRCS = pipex.c reading.c \
		get_func.c

OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(LIBFT):
	$(MAKE) all -C $(LIB_DIR)
	$(MAKE) bonus -C $(LIB_DIR)
$(NAME): $(OBJS)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $?
	$(MAKE) clean
clean:
	$(MAKE) clean -C $(LIB_DIR)
	rm -rf $(OBJS) $(DEP)
fclean: clean
	$(MAKE) fclean -C $(LIB_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
-include	$(OBJS:.o=.d)