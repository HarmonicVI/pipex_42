/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 17:52:23 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 12:57:03 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_execute(char *cmd, char **envp)
{
	char			**args;
	const char		*path;

	args = ft_getargs(cmd);
	if (args[0][0] == '/')
	{
		if (access(args[0], X_OK) == -1)
		{
			ft_putstr_fd(STDERR, "Error: ");
			ft_putstr_fd(STDERR, args[0]);
			ft_handle_error(ERR_MSG_NO_FILE_OR_DIR);
		}	
		path = ft_strdup(args[0]);
	}	
	else
		path = ft_getpath(envp, args[0]);
	if (ft_strchr(path, '/') != NULL)
		execve(path, args, envp);
	ft_putstr_fd(STDERR, "Error: ");
	ft_putstr_fd(STDERR, (char *)path);
	ft_putstr_fd(STDERR, ": Failed to execve the process");
	ft_memdel((char *)path);
	ft_free_tab(args);
	ft_handle_error(".");
}

void	ft_pipe(int fdin, int fdout, char *cmd, char **envp)
{
	pid_t			pid;

	if (dup2(fdin, STDIN) == -1)
		ft_handle_error("Failed to connect fd in with STDIN");
	close(fdin);
	if (dup2(fdout, STDOUT) == -1)
		ft_handle_error("Failed to connect fd out with STDOUT");
	close(fdout);
	pid = fork();
	if (pid == -1)
		ft_handle_error("Failed to create a fork.");
	else if (pid == 0)
		ft_execute(cmd, envp);
}
