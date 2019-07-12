/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 13:55:31 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 13:55:32 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../printf/ft_printf.h"
# define A s->a->stack
# define B s->b->stack

typedef struct		s_elements
{
	int				*stack;
	int				mid;
	int				len;
}					t_elements;

/*
** sort: amount of sorted ints in stack a
** len: total len of numbers
*/

typedef struct		s_push_swap
{
	t_elements		*a;
	t_elements		*b;
	int				*sorted;
	int				*midians;
	int				i;
	int				sort;
	int				len;
	short			fix_b;
	short			fix_a;
	short			a_goodie;
}					t_swap;

/*
** Error functions
*/

void				error_push_swap(char *text);

/*
** Init functions
*/

void				get_a(t_swap *a, char **argv, int argc);
void				init_a(t_swap *a, int argc);
void				copy_arrays(t_swap *a, int *tmp);
void				sort_int_tab(int *tab, int size);

/*
** Sort functions
*/

void				sort(t_swap *s);
void				sort_6(t_swap *s);
void				divide_a(t_swap *s);
void				divide_b(t_swap *s);
void				sort_a(t_swap *s);
int					sorted(t_swap *s);
void				a_empty(t_swap *s, int b);
void				a_full(t_swap *s, int b);
void				edge_case(t_swap *s);
int					sum_mid(t_swap *s);

/*
** Midian functions
*/

void				get_mid_a(t_swap *s);
void				get_mid_b(t_swap *s);
int					sum_medians(t_swap *s);

/*
** Push functions
*/

int					pushing_a2b(t_swap *s);
int					pushing_b2a(t_swap *s, int tmp);
void				fix_b(t_swap *s);
void				fix_a(t_swap *s);

/*
** Opperations
*/

void				select_print(t_swap *s, char *str);
void				ss_checker(t_swap *s, char c);
void				rr_checker(t_swap *s, char c);
void				rrr_checker(t_swap *s, char c);
void				move_stack(int *dst, const int *src, int len);
void				swap(t_swap *s, char c);
void				push(t_swap *s, char c, int tmp);
void				rotate(t_swap *s, char c);
void				rev_rotate(t_swap *s, char c);

#endif
