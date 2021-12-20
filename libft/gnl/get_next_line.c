/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:22:47 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 08:11:10 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	ft_read(t_list *lstfd, int fd)
{
	char	*buffer;
	char	*tmp_str;
	int		byte_read;

	byte_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (-1);
	while (byte_read > 0 && ft_strchr(lstfd->data, '\n') == NULL)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
			break ;
		buffer[byte_read] = '\0';
		tmp_str = lstfd->data;
		lstfd->data = ft_strjoin(tmp_str, buffer);
		ft_strdel(&tmp_str);
		if (lstfd->data == NULL)
		{
			byte_read = -1;
			break ;
		}	
	}
	ft_strdel(&buffer);
	return (byte_read);
}

static int	ft_get_str_from_line(t_list *lstfd, char **line)
{
	char	*tmp_str;
	char	*endl_str;
	int		ret;

	endl_str = ft_strchr(lstfd->data, '\n');
	if (endl_str != NULL)
	{
		tmp_str = lstfd->data;
		*endl_str = '\0';
		*line = ft_substr(tmp_str, 0, endl_str - tmp_str);
		lstfd->data = ft_strdup(++endl_str);
		ft_strdel(&tmp_str);
		ret = 1;
	}
	else
	{
		*line = ft_strdup(lstfd->data);
		ret = 0;
	}		
	if (lstfd->data == NULL || *line == NULL)
		return (-1);
	return (ret);
}

int	get_next_line(int fd, char **line)
{
	static t_list	*lst;
	t_list			*lstfd;
	int				ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	ret = 1;
	lstfd = ft_lstadd(&lst, fd);
	if (lstfd == NULL)
		return (-1);
	if (ft_strchr(lstfd->data, '\n') == NULL)
		ret = ft_read(lstfd, fd);
	if (ret != -1)
		ret = ft_get_str_from_line(lstfd, line);
	if (ret <= 0)
		ft_lstdelone(&lst, lstfd);
	if (ret > 0)
		return (1);
	return (ret);
}
