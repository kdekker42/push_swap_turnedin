/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap_error.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: kpereira <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/04 14:02:22 by kpereira      #+#    #+#                 */
/*   Updated: 2019/06/04 14:02:22 by kpereira      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_push_swap(char *text)
{
	write(2, text, ft_strlen(text));
	exit(0);
}
