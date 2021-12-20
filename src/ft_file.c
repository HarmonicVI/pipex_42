/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:21:12 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 16:06:03 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_unlink(char *filename)
{
	if (unlink(filename) == -1)
	{
		ft_putendl_fd(STDERR, ERR_MSG_CANNOT_DELETE);
		exit(FAILURE);
	}
}

int	ft_openinfile(char *filename, int mode)
{
	int	flags;

	if (mode == 0)
		flags = O_RDONLY;
	if (access(filename, F_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_NO_FILE_OR_DIR);
		exit(FAILURE);
	}
	else if (access(filename, R_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_PERMISSION_DENIED);
		exit(FAILURE);
	}
	return (open(filename, flags));
}

int	ft_openoutfile(char *filename, int mode)
{
	int	flags;

	if (mode == 1)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else if (mode == 2)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	if (access(filename, F_OK) != -1 && access(filename, W_OK) == -1)
	{
		ft_putstr_fd(STDERR, filename);
		ft_putendl_fd(STDERR, ERR_MSG_PERMISSION_DENIED);
		exit(FAILURE);
	}
	return (open(filename, flags));
}
