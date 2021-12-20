/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:10:13 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 16:48:15 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	ft_heredoc(int fd, char	*limiter, int pipecnt)
{
	int		i;
	int		ret;
	char	*line;

	while (true)
	{
		i = -1;
		while (++i < pipecnt)
			ft_putstr_fd(STDOUT, "pipe ");
		ft_putstr_fd(STDOUT, "heredoc> ");
		ret = get_next_line(STDIN, &line);
		if (ret == -1)
			break ;
		ret = ft_strcmp(line, limiter);
		if (ret)
			ft_putendl_fd(fd, line);
		ft_strdel(&line);
		if (ret == 0)
			break ;
	}
	return (ret);
}

static int	ft_pipeheredoc(int fdin, int fdout, char *limiter, int pipecnt)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (pid == -1)
		ft_handle_error("Failed to create a fork.");
	else if (pid == 0)
	{
		close(fdin);
		ret = ft_heredoc(fdout, limiter, pipecnt);
		if (ret == -1)
			ft_handle_error("Failed to handle heredoc.");
		exit(SUCCESS);
	}		
	else
	{
		close(fdout);
		dup2(fdin, STDIN);
		wait(NULL);
	}
	return (fdin);
}

void	ft_pipex_heredoc(int argc, char **argv, char **envp)
{
	int		i;
	int		status;
	int		tmpfd[2];
	int		pipefd[2];

	i = 2;
	while (i < argc - 1)
	{
		if (pipe(pipefd) == -1)
			ft_handle_error("Failed to create a pipe.");
		if (i == 2)
			tmpfd[0] = ft_pipeheredoc(pipefd[0], pipefd[1], argv[2], argc - 5);
		else
		{	
			tmpfd[1] = pipefd[1];
			if (i == argc - 2)
				tmpfd[1] = ft_openoutfile(argv[argc - 1], 2);
			ft_pipe(tmpfd[0], tmpfd[1], argv[i], envp);
			tmpfd[0] = pipefd[0];
		}
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
}

void	ft_pipex_bonus(int argc, char **argv, char **envp)
{
	int		i;
	int		status;
	int		tmpfd[2];
	int		filefd[2];
	int		pipefd[2];

	filefd[0] = ft_openinfile(argv[1], 0);
	filefd[1] = ft_openoutfile(argv[argc - 1], 1);
	i = 2;
	while (i < argc - 1)
	{
		if (pipe(pipefd) == -1)
			ft_handle_error("Failed to create a pipe.");
		tmpfd[1] = pipefd[1];
		if (i == 2)
			tmpfd[0] = filefd[0];
		else if (i == argc - 2)
			tmpfd[1] = filefd[1];
		ft_pipe(tmpfd[0], tmpfd[1], argv[i], envp);
		tmpfd[0] = pipefd[0];
		i++;
	}
	while (waitpid(-1, &status, 0) > 0)
		;
}
