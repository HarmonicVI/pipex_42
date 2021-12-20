/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:49:54 by llornel           #+#    #+#             */
/*   Updated: 2021/08/20 10:04:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			slen;
	char			*str;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < start)
		slen = 0;
	else
		slen -= start;
	if (slen > len)
		slen = len;
	str = (char *)malloc(sizeof(char) * (slen + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (slen > 0 && i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
