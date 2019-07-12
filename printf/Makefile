# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rcorke <rcorke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/09 18:10:06 by rcorke         #+#    #+#                 #
#    Updated: 2019/05/04 19:24:57 by rcorke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME= libftprintf.a
SOURCES= bonus_colors.c buff_manager.c flags_precision.c flags_struct.c \
		flags_width.c ft_change_base.c ft_change_base_small.c \
		ft_get_decimal.c ft_get_decimal_long.c \
		ft_get_decimal_unsigned_long.c ft_get_flags.c ft_printf.c \
		ft_search_until_specifier.c ft_strjoin_free.c \
		ft_strlen_numbers.c ft_strrpl.c ft_unsigned_itoa.c \
		ft_wildcard_in_string.c binary_path.c path_char.c path_char_hexa.c \
		path_float.c path_hexa.c path_int.c path_null.c path_octal.c \
		path_percent.c path_pointer.c path_small_hexa.c path_string.c \
		path_unsigned_int.c buff_manager_2.c \
		ft_unsigned_long_long_itoa.c flags_width_tools.c \
		flags_struct_2.c
OBJECTS= $(SOURCES:.c=.o)
LIBFT= libft/libft.a
FLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo making printf libft...
	@make re -C libft/
	@mv ./libft/libft.a $(NAME)
	@gcc $(FLAGS) -I./ -c $(SOURCES)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@make clean -C libft/
	@rm -rf *~ $(OBJECTS)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all

poop:
	@yes poop

pee:
	@yes pee
