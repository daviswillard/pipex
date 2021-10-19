NAME = pipex
LIBFT = libft.a
LIB_DIR = ./libft/
CFLAGS = -Wall -Wextra -Werror -MMD

SRCS_DIR = sources/
SRCS = $(SRCS_DIR)pipex.c $(SRCS_DIR)reading.c \
		$(SRCS_DIR)get_func.c  $(SRCS_DIR)main.c \
		$(SRCS_DIR)filename.c
OBJS = ${SRCS:.c=.o}
DEP = $(SRCS:.c=.d)

BNS_DIR = bonus/sources/
BNS_SRCS = $(BNS_DIR)pipex_bonus.c $(BNS_DIR)reading_bonus.c \
			$(BNS_DIR)main_bonus.c $(BNS_DIR)filename_bonus.c \
			$(BNS_DIR)get_func_bonus.c $(BNS_DIR)get_next_line_bonus.c
BNS_OBJS = ${BNS_SRCS:.c=.o}
BNS_DEP = $(BNS_SRCS:.c=.d)

all:  lib $(NAME)
lib:
	$(MAKE) all -sC $(LIB_DIR)
bonus:	lib $(BNS_OBJS)
	gcc $(CFLAGS) -Ibonus/ $(BNS_OBJS) -L$(LIB_DIR) -lft -o $(NAME)
.c.o:
	gcc $(CFLAGS) -c $< -o $@
$(NAME): $(OBJS)
	gcc $(CFLAGS) -I. $(OBJS) -L$(LIB_DIR) -lft -o $(NAME)
clean:
	$(MAKE) clean -sC $(LIB_DIR)
	rm -rf $(OBJS) $(DEP) $(BNS_OBJS) $(BNS_DEP)
fclean: clean
	$(MAKE) fclean -sC $(LIB_DIR)
	rm -rf $(NAME)
re: fclean all
.PHONY: all lib clean fclean re bonus
-include	$(OBJS:.o=.d) $(BNS_OBJS:.o=.d)
