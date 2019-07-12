#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kpereira <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/04 13:55:22 by kpereira      #+#    #+#                  #
#    Updated: 2019/06/04 13:55:23 by kpereira      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME= push_swap
SOURCES= push_swap.c push_swap_error.c push_swap_init.c push_swap_mid.c \
		push_swap_push.c push_swap_sort.c push_swap_ops.c push_swap_opz.c \
		push_swap_push_a.c push_swap_sort2.c
LIBFT= ../printf/libftprintf.a
FLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@echo Makeing The GrEaTe PuShSwAp browsky!
	@make re -C ../printf/
	@gcc $(FLAGS) -I./ $(SOURCES) $(LIBFT) -o $(NAME)

clean:
	@make clean -C ../printf/
	@rm -rf *~

fclean: clean
	@make fclean -C ../printf/
	@rm -rf $(NAME)

re : fclean all
