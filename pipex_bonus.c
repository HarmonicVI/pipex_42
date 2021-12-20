/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:36:10 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 15:48:07 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		heredoc;
	int		new_argc;

	heredoc = 0;
	new_argc = argc;
	if (argc > 1 && ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")) == 0)
	{
		new_argc--;
		heredoc = 1;
	}	
	if (new_argc < 5)
	{
		ft_putstr_fd(STDERR, ERR_MSG_INVALID_AGRS);
		ft_putstr_fd(STDERR, " Usage : ");
		ft_putendl_fd(STDERR, ERR_MSG_USAGE_BONUS);
		exit(FAILURE);
	}
	if (heredoc == 0)
		ft_pipex_bonus(argc, argv, envp);
	else
		ft_pipex_heredoc(argc, argv, envp);
	return (SUCCESS);
}
