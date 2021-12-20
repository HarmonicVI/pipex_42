/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:10:13 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 16:06:36 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_pipein(int *pipefd, int fdin, char *cmd, char **envp)
{
	if (dup2(fdin, STDIN) == -1)
		ft_handle_error("Failed to connect infile with STDIN");
	close(fdin);
	close(pipefd[0]);
	if (dup2(pipefd[1], STDOUT) == -1)
		ft_handle_error("Failed to connect pipe[1] with STDOUT");
	close(pipefd[1]);
	ft_execute(cmd, envp);
}

static void	ft_pipeout(int *pipefd, int fdout, char *cmd, char **envp)
{
	close(pipefd[1]);
	if (dup2(pipefd[0], STDIN) == -1)
		ft_handle_error("Failed to connect pipe[0] with STDIN");
	close(pipefd[0]);
	if (dup2(fdout, STDOUT) == -1)
		ft_handle_error("Failed to connect outfile with STDOUT");
	close(fdout);
	ft_execute(cmd, envp);
}

void	ft_pipex(int argc, char **argv, char **envp)
{
	pid_t	pid;
	int		filefd[2];
	int		pipefd[2];

	filefd[0] = ft_openinfile(argv[1], 0);
	filefd[1] = ft_openoutfile(argv[argc - 1], 1);
	if (pipe(pipefd) == -1)
		ft_handle_error("Failed to create a pipe.");
	pid = fork();
	if (pid == -1)
		ft_handle_error("Failed to fork the process.");
	if (pid == 0)
		ft_pipein(pipefd, filefd[0], argv[2], envp);
	ft_pipeout(pipefd, filefd[1], argv[3], envp);
	wait(NULL);
}
