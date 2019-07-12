/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 17:58:21 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/03 17:58:22 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../printf/ft_printf.h"

typedef struct	s_checker
{
	int			*stack;
	int			len;
	int			original_len;
	int			sorted_amount;
	int			mid;
}				t_checker;

/*
** Operations
*/

void			swap(t_checker *stack);
void			swap_a_b(t_checker *a, t_checker *b);
void			push(t_checker *a, t_checker *b);
void			move_stack(int *dst, const int *src, int len);
void			rotate_a_b(t_checker *a, t_checker *b);
void			rotate(t_checker *s);
void			reverse_rotate_a_b(t_checker *a, t_checker *b);
void			reverse_rotate(t_checker *s);

/*
** Checker functions
*/

void			init_stacks_checker(t_checker *a, t_checker *b, int len);
int				get_args(t_checker *a, char **argv);
int				read_move(t_checker *a, t_checker *b, char *line);
int				read_and_check(t_checker *a, t_checker *b);
int				control_stack(t_checker *a, t_checker *b, int len);
int				build(int argc, char **argv);

#endif
