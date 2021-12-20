/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:50:45 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 12:45:19 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_tab(char **tab)
{
	int	i;

	if (tab == NULL)
		return ;
	i = 0;
	while (tab[i])
	{
		ft_memdel(tab[i]);
		i++;
	}
	ft_memdel(tab);
}

char	**ft_getargs(const char *cmd)
{
	char	**args;

	if (cmd == NULL)
		return (NULL);
	args = ft_split(cmd, ' ');
	if (args == NULL || *args == NULL)
		return (NULL);
	return (args);
}

static char	*ft_parsepath(char *path, const char *cmd)
{
	char	**dir;
	char	*curr;
	char	*tmp;
	int		i;

	dir = ft_split(path, ':');
	if (dir == NULL)
		ft_handle_error("ERROR: PATH is empty.");
	i = 0;
	curr = NULL;
	while (dir[i])
	{
		tmp = ft_strjoin(dir[i], "/");
		curr = ft_strjoin(tmp, (char *)cmd);
		ft_strdel(&tmp);
		if (access(curr, X_OK) != -1)
			break ;
		ft_strdel(&curr);
		i++;
	}
	ft_free_tab(dir);
	return (curr);
}

char	*ft_getpath(char **env, char *cmd)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_parsepath(env[i] + 5, cmd);
			if (path == NULL)
			{
				ft_putstr_fd(STDERR, "Error: ");
				ft_putstr_fd(STDERR, cmd);
				ft_putstr_fd(STDERR, ": command not found ");
				ft_handle_error("");
			}	
		}
		i++;
	}
	return (path);
}
