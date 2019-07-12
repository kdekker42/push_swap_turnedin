/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 18:18:56 by rcorke        #+#    #+#                 */
/*   Updated: 2019/01/25 15:17:54 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlow(char *str)
{
	size_t x;

	x = 0;
	while (str[x] != '\0')
	{
		if (str[x] >= 'A' && str[x] <= 'Z')
			str[x] += 32;
		x++;
	}
	return (str);
}