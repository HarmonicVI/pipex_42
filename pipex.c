/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:36:10 by llornel           #+#    #+#             */
/*   Updated: 2021/08/29 16:21:55 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd(STDERR, ERR_MSG_INVALID_AGRS);
		ft_putstr_fd(STDERR, " Usage : ");
		ft_putendl_fd(STDERR, ERR_MSG_USAGE);
		exit(FAILURE);
	}
	ft_pipex(argc, argv, envp);
	return (SUCCESS);
}
