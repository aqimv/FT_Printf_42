
NAME = libftprintf.a

SRC_DIR = ./srcs/
SRC = ft_printf.c \
		setters.c \
		init.c \
		int.c \
		char.c \
		string.c \
		octal.c \
		hex.c \
		float.c \
		float2.c \
		float3.c \
		utils.c \
		utils2.c \
		utils3.c \
		unsignedint.c \
		pointer.c \


SRCS = $(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR = ./obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

INC = ft_printf.h
INC_DIR = ./includes/
INCS = $(addprefix $(INC_DIR), $(INC))

LIB_OBJ = *.o
LIB_OBJ_DIR = ./libft/obj/
LIB_OBJS = $(addprefix $(LIB_OBJ_DIR), $(LIB_OBJ))


LIB_INC = libft.h get_next_line.h
LIB_INCS = $(addprefix $(INC_DIR), $(LIB_INC))

LIB_SRC_DIR = ./libft/srcs/

FLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIB_OBJS) $(OBJS)
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

$(OBJ_DIR):
		mkdir -p $@
		mkdir -p $(LIB_OBJ_DIR)

$(LIB_OBJ_DIR)%.o: $(LIB_SRC_DIR)%.c $(LIB_INCS)
		make -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
		clang $(FLAGS) -o $@ -c $<

clean:
		@make clean -C libft
		@rm -f $(OBJS)
		@rm -rf $(OBJ_DIR)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re norme