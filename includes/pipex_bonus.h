/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 11:11:47 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 15:22:37 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define SUCCESS 0
# define FAILURE 1

# define ERR_MSG_INVALID_AGRS "Invalid number of arguments."
# define ERR_MSG_USAGE_BONUS "./pipex [here_doc] infile cmd1 cmd2 ... outfile"
# define ERR_MSG_NO_FILE_OR_DIR ": No such file or directory"
# define ERR_MSG_PERMISSION_DENIED ": Permission denied"
# define ERR_MSG_CANNOT_READ "Cannot read file."
# define ERR_MSG_CANNOT_DELETE "Cannot delete file."
# define TMP_FILE "/tmp/.heredoc"

void		ft_handle_error(char *str);

void		ft_free_tab(char **tab);
char		*ft_getpath(char **env, char *cmd);
char		**ft_getargs(const char *cmd);

void		ft_unlink(char *filename);
int			ft_openinfile(char *filename, int flags);
int			ft_openoutfile(char *filename, int flags);

void		ft_pipe(int fdin, int fdout, char *cmd, char **envp);
void		ft_execute(char *cmd, char **envp);

void		ft_pipex_bonus(int argc, char **argv, char **envp);
void		ft_pipex_heredoc(int argc, char **argv, char **envp);

#endif
