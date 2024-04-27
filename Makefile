NAME = so_long

SRCS =	srcs/key_handlers/movement.c \
		srcs/key_handlers/wasd_handler.c \
		srcs/key_handlers/close_handler.c \
		srcs/parsing/map_parse.c	\
		srcs/parsing/assets_ini.c	\
		srcs/parsing/error_management.c	\
		srcs/parsing/map_verification.c	\
		srcs/rendering/render.c \
		srcs/rendering/data_init.c \
		srcs/main.c

GNL =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS =	$(SRCS:.c=.o)

GNL_OBJS =	$(GNL:.c=.o)

LIBFT =	libft/libftprintf.a

CFLAGS =	-Wall -Wextra -Werror

HEADERS =	includes/rendering.h \
			includes/key_handlers.h \
			includes/parsing.h \
			includes/so_long.h

GNL_HEADER =	includes/get_next_line.h

LIBFT_HEADER =	includes/libft.h

all: $(NAME)

$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT)
	@echo "Compiling so_long sources..."
	@cc $(CFLAGS) -Lmlx -lmlx -framework AppKit -framework OpenGL $(OBJS) $(GNL_OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "Archiving libftprintf..."
	@make re -s -C libft
	@make clean -s -C libft

%.o: %.c $(SRCS) $(GNL) $(HEADERS) $(GNL_HEADER)
	@cc $(CFLAGS) -c $< -o $@ 

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS) $(GNL_OBJS)
	@make fclean -s -C libft

fclean:
	@echo "Cleaning object files and executable..."
	@make clean
	@rm -f $(NAME)

re:
	@make fclean
	@echo "Recompiling..."
	@make all

.PHONY: clean fclean re