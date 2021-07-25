NAME = pipex.a
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror
DFLAG = -MMD
SRCS = ./sources/pipex.c ./sources/reading.c \
		./sources/get_func.c ./sources/main.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)
all:  $(LIBFT) $(NAME)
.c.o:
	gcc $(CFLAGS) $(DFLAG) -c $< -o $@
$(LIBFT):
	$(MAKE) all -C $(LIB_DIR)
	$(MAKE) bonus -C $(LIB_DIR)
$(NAME): $(OBJS)
	cp ./libft/libft.a $(NAME)
	ar -rcs $(NAME) $?
	gcc $(CFLAGS) $(NAME) -o pipex
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