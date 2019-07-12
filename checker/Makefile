#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kpereira <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/03 18:08:05 by kpereira      #+#    #+#                  #
#    Updated: 2019/06/03 18:08:05 by kpereira      ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME= checker
SOURCES= checker.c checker_ops.c checker_init.c checker_opz.c
LIBFT= ../printf/libftprintf.a
FLAGS= -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME):
	@echo Makeing checker!
	@make re -C ../printf/
	@gcc $(FLAGS) -I./ $(SOURCES) $(LIBFT) -o $(NAME)

clean:
	@make clean -C ../printf/
	@rm -rf *~

fclean: clean
	@make fclean -C ../printf/
	@rm -rf $(NAME)

re : fclean all
