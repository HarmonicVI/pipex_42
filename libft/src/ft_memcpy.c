/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:48:53 by llornel           #+#    #+#             */
/*   Updated: 2021/07/31 20:48:56 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	if ((n == 0) || (dst == src))
		return (dst);
	i = 0;
	tmp_dst = (unsigned char *) dst;
	tmp_src = (unsigned char *) src;
	while (i < n)
	{
		*(tmp_dst + i) = *(tmp_src + i);
		i++;
	}
	return (dst);
}
