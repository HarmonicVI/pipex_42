/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:49:02 by llornel           #+#    #+#             */
/*   Updated: 2021/07/31 20:49:08 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*tmp_b;

	i = 0;
	tmp_b = (unsigned char *) b;
	while (i < len)
	{
		*(tmp_b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
