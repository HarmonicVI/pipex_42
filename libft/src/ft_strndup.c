/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:49:35 by llornel           #+#    #+#             */
/*   Updated: 2021/08/15 13:57:50 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	dst = (char *)malloc(sizeof(*src) * (len + 1));
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len + 1);
	return (dst);
}
