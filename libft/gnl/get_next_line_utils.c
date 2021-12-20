/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llornel <llornel@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 18:25:27 by llornel           #+#    #+#             */
/*   Updated: 2021/09/04 08:13:09 by llornel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

void	ft_lstfreeone(t_list *lst)
{
	if (lst)
	{
		ft_strdel(&(lst->data));
		free(lst);
	}
}

void	ft_lstdelone(t_list **lst, t_list *del)
{
	t_list	*curr;

	if (*lst == del)
	{
		curr = *lst;
		*lst = (*lst)->next;
		ft_lstfreeone(curr);
		return ;
	}
	else
	{
		curr = *lst;
		while (curr->next != NULL)
		{
			if (curr->next == del)
			{
				curr->next = del->next;
				ft_lstfreeone(del);
				return ;
			}
			curr = curr->next;
		}
	}
}

t_list	*ft_lstnew(int fd)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->data = ft_strdup("\0");
	if (lst->data == NULL)
		return (NULL);
	lst->fd = fd;
	lst->next = NULL;
	return (lst);
}

t_list	*ft_lstadd(t_list **lst, int fd)
{
	t_list	*new;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(fd);
		return (*lst);
	}	
	new = *lst;
	if (new->fd == fd)
		return (new);
	while (new->next != NULL)
	{
		if (new->next->fd == fd)
			return (new->next);
		new = new->next;
	}
	new->next = ft_lstnew(fd);
	return (new->next);
}
